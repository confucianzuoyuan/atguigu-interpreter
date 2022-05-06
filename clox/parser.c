#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "parser.h"

static Node* expression();
static Node* equality();
static Node* comparison();
static Node* term();
static Node* factor();
static Node* unary();
static Node* primary();

typedef struct {
  Token current;
  Token previous;
  bool hadError;
  bool panicMode;
} Parser;

Parser parser;

static void errorAt(Token* token, const char* message) {
  if (parser.panicMode) return;
  parser.panicMode = true;
  fprintf(stderr, "[line %d] Error", token->line);

  if (token->type == TOKEN_EOF) {
    fprintf(stderr, " at end");
  } else if (token->type == TOKEN_ERROR) {
    // Nothing.
  } else {
    fprintf(stderr, " at '%.*s'", token->length, token->start);
  }

  fprintf(stderr, ": %s\n", message);
  parser.hadError = true;
}

static void error(const char* message) {
  errorAt(&parser.previous, message);
}

static void errorAtCurrent(const char* message) {
  errorAt(&parser.current, message);
}

static void advance() {
  parser.previous = parser.current;

  for (;;) {
    parser.current = scanToken();
    if (parser.current.type != TOKEN_ERROR) break;

    errorAtCurrent(parser.current.start);
  }
}

static void consume(TokenType type, const char* message) {
  if (parser.current.type == type) {
    advance();
    return;
  }

  errorAtCurrent(message);
}

static bool check(TokenType type) {
  return parser.current.type == type;
}

static bool match(TokenType type) {
  if (!check(type)) return false;
  advance();
  return true;
}

static char* copyString(const char* chars, int length) {
  char* heapChars = (char*)malloc(length + 1);
  memcpy(heapChars, chars, length);
  heapChars[length] = '\0';
  return heapChars;
}

static Node *new_node(NodeKind kind) {
  Node *node = calloc(1, sizeof(Node));
  node->kind = kind;
  return node;
}

static Node* new_binary(Node* lhs, NodeKind kind, Node* rhs) {
  Node* node = new_node(kind);
  node->lhs = lhs;
  node->rhs = rhs;
  return node;
}

static Node* new_unary(NodeKind kind, Node* rhs) {
  Node* node = new_node(kind);
  node->rhs = rhs;
  return node;
}

static Node* new_grouping(Node* rhs) {
  Node* node = new_node(ND_EXPR_GROUPING);
  node->rhs = rhs;
  return node;
}

static Node* new_literal(NodeKind kind, char* str, double value) {
  Node* node = new_node(kind);
  node->str = str;
  node->val = value;
  return node;
}

static Node* expression() {
  return equality();
}

static Node* equality() {
  Node* expr = comparison();

  for (;;) {
    if (match(TOKEN_BANG_EQUAL)) {
      Node* right = comparison();
      expr = new_binary(expr, ND_EXPR_NE, right);
      continue;
    }
    if (match(TOKEN_EQUAL_EQUAL)) {
      Node* right = comparison();
      expr = new_binary(expr, ND_EXPR_EQ, right);
      continue;
    }

    return expr;
  }
}

static Node* comparison() {
  Node* expr = term();

  for (;;) {
    if (match(TOKEN_GREATER)) {
      Node* right = term();
      expr = new_binary(expr, ND_EXPR_GT, right);
      continue;
    }
    if (match(TOKEN_GREATER_EQUAL)) {
      Node* right = term();
      expr = new_binary(expr, ND_EXPR_GE, right);
      continue;
    }
    if (match(TOKEN_LESS)) {
      Node* right = term();
      expr = new_binary(expr, ND_EXPR_LT, right);
      continue;
    }
    if (match(TOKEN_LESS_EQUAL)) {
      Node* right = term();
      expr = new_binary(expr, ND_EXPR_LE, right);
      continue;
    }

    return expr;
  }
}

static Node* term() {
  Node* expr = factor();

  for (;;) {
    if (match(TOKEN_PLUS)) {
      Node* right = factor();
      expr = new_binary(expr, ND_EXPR_ADD, right);
      continue;
    }
    if (match(TOKEN_MINUS)) {
      Node* right = factor();
      expr = new_binary(expr, ND_EXPR_SUB, right);
      continue;
    }

    return expr;
  }
}

static Node* factor() {
  Node* expr = unary();

  for (;;) {
    if (match(TOKEN_STAR)) {
      Node* right = unary();
      expr = new_binary(expr, ND_EXPR_MUL, right);
      continue;
    }
    if (match(TOKEN_SLASH)) {
      Node* right = unary();
      expr = new_binary(expr, ND_EXPR_DIV, right);
      continue;
    }

    return expr;
  }
}

static Node* unary() {
  if (match(TOKEN_BANG)) {
    Node* right = unary();
    return new_unary(ND_EXPR_NOT, right);
  }
  if (match(TOKEN_MINUS)) {
    Node* right = unary();
    return new_unary(ND_EXPR_NEG, right);
  }

  return primary();
}

static Node* primary() {
  if (match(TOKEN_FALSE)) return new_literal(ND_EXPR_FALSE, NULL, 0.0);
  if (match(TOKEN_TRUE)) return new_literal(ND_EXPR_TRUE, NULL, 0.0);
  if (match(TOKEN_NIL)) return new_literal(ND_EXPR_NIL, NULL, 0.0);

  if (match(TOKEN_NUMBER)) {
    double value = strtod(parser.previous.start, NULL);
    return new_literal(ND_EXPR_NUMBER, NULL, value);
  }

  if (match(TOKEN_STRING)) {
    char* str = copyString(parser.previous.start + 1,
                           parser.previous.length - 2);
    return new_literal(ND_EXPR_STRING, str, 0.0);    
  }

  if (match(TOKEN_LEFT_PAREN)) {
    Node* expr = expression();
    consume(TOKEN_RIGHT_PAREN, "Expect ')' after expression.");
    return new_grouping(expr);
  }
}

Node* parse(const char* source) {
  initScanner(source);
  advance();
  Node* expr = expression();
  consume(TOKEN_EOF, "Expect end of expression.");
  return expr;
}

void print_ast(Node* ast, int depth) {
  if (ast->kind == ND_EXPR_ADD) {
    printf("add\n");
    for (int i = 0; i < depth + 1; i++) {
      printf("  ");
    }
    printf("left -> ");
    print_ast(ast->lhs, depth + 1);
    for (int i = 0; i < depth + 1; i++) {
      printf("  ");
    }
    printf("right -> ");
    print_ast(ast->rhs, depth + 1);
  } else if (ast->kind == ND_EXPR_NUMBER) {
    printf("%f\n", ast->val);
  } else if (ast->kind == ND_EXPR_MUL) {
    printf("mul\n");
    for (int i = 0; i < depth + 1; i++) {
      printf("  ");
    }
    printf("left -> ");
    print_ast(ast->lhs, depth + 1);
    for (int i = 0; i < depth + 1; i++) {
      printf("  ");
    }
    printf("right -> ");
    print_ast(ast->rhs, depth + 1);
  } else if (ast->kind == ND_EXPR_GROUPING) {
    print_ast(ast->rhs, depth);
  } else if (ast->kind == ND_EXPR_OR) {
    for (int i = 0; i < depth; i++) {
      printf("  ");
    }
    printf("or\n");
    for (int i = 0; i < depth + 1; i++) {
      printf("  ");
    }
    printf("left -> ");
    print_ast(ast->lhs, depth + 1);
    for (int i = 0; i < depth + 1; i++) {
      printf("  ");
    }
    printf("right -> ");
    print_ast(ast->rhs, depth + 1);
  } else if (ast->kind == ND_EXPR_TRUE) {
    printf("true\n");
  } else if (ast->kind == ND_EXPR_NEG) {
    printf("neg -> ");
    print_ast(ast->rhs, depth);
  } else if (ast->kind == ND_EXPR_STRING) {
    printf("%s\n", ast->str);
  } else if (ast->kind == ND_EXPR_FALSE) {
    printf("false\n");
  }
}