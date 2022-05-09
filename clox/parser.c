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
static Node* statement();
static Node* printStatement();
static Node* returnStatement();
static Node* expressionStatement();
static Node* declaration();
static Node* varDeclaration();
static Node* classDeclaration();
static Node* ifStatement();
static Node* whileStatement();
static Node* forStatement();
static Node* or();
static Node* and();
static Node* assignment();
static Node* block();
static Node* function();
static Node* call();

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

static Node* new_var(NodeKind kind, char* name, Node* rhs) {
  Node* node = new_node(kind);
  node->str = name;
  node->rhs = rhs;
  return node;
}

static Node* new_if(NodeKind kind, Node* condition, Node* thenBranch, Node* elseBranch) {
  Node* node = new_node(kind);
  node->cond = condition;
  node->then = thenBranch;
  node->els = elseBranch;
  return node;
}

static Node* new_while(Node* condition, Node* body) {
  Node* node = new_node(ND_STMT_WHILE);
  node->cond = condition;
  node->body = body;
  return node;
}

static Node* new_assign(char* name, Node* rhs) {
  Node* node = new_node(ND_EXPR_ASSIGN);
  node->str = name;
  node->rhs = rhs;
  return node;
}

static Node* new_function(char* name, Node* parameters, Node* body) {
  Node* node = new_node(ND_STMT_FUNCTION);
  node->funcname = name;
  node->args = parameters;
  node->body = body;
  return node;
}

static Node* new_class(char* name, Node* superclass, Node* methods) {
  Node* node = new_node(ND_STMT_CLASS);
  node->str = name;
  node->lhs = superclass;
  node->rhs = methods;
  return node;
}

static Node* new_set(Node* object, char* name, Node* value) {
  Node* node = new_node(ND_EXPR_SET);
  node->lhs = object;
  node->str = name;
  node->rhs = value;
  return node;
}

static Node* new_get(Node* object, char* name) {
  Node* node = new_node(ND_EXPR_GET);
  node->lhs = object;
  node->str = name;
  return node;
}

static Node* statement() {
  if (match(TOKEN_FOR)) return forStatement();
  if (match(TOKEN_IF)) return ifStatement();
  if (match(TOKEN_PRINT)) return printStatement();
  if (match(TOKEN_RETURN)) return returnStatement();
  if (match(TOKEN_WHILE)) return whileStatement();
  if (match(TOKEN_LEFT_BRACE)) return new_unary(ND_STMT_BLOCK, block());

  return expressionStatement();
}

static Node* block() {
  Node head = {};
  Node* dummy = &head;
  while (!check(TOKEN_RIGHT_BRACE) && !check(TOKEN_EOF)) {
    dummy->next = declaration();
    dummy = dummy->next;
  }

  consume(TOKEN_RIGHT_BRACE, "Expect '}' after block.");
  return head.next;
}

static Node* ifStatement() {
  consume(TOKEN_LEFT_PAREN, "Expect '(' after 'if'.");
  Node* condition = expression();
  consume(TOKEN_RIGHT_PAREN, "Expect ')' after if condition.");

  Node* thenBranch = statement();
  Node* elseBranch = NULL;
  if (match(TOKEN_ELSE)) {
    elseBranch = statement();
  }

  return new_if(ND_STMT_IF, condition, thenBranch, elseBranch);
}

static Node* whileStatement() {
  consume(TOKEN_LEFT_PAREN, "Expect '(' after 'while'.");
  Node* condition = expression();
  consume(TOKEN_RIGHT_PAREN, "Expect ')' after condition.");
  Node* body = statement();

  return new_while(condition, body);
}

static Node* forStatement() {
  consume(TOKEN_LEFT_PAREN, "Expect '(' after 'for'.");

  Node* initializer = NULL;
  if (match(TOKEN_SEMICOLON)) {
    initializer = NULL;
  } else if (match(TOKEN_VAR)) {
    initializer = varDeclaration();
  } else {
    initializer = expressionStatement();
  }

  Node* condition = NULL;
  if (!check(TOKEN_SEMICOLON)) {
    condition = expression();
  }
  consume(TOKEN_SEMICOLON, "Expect ';' after loop condition.");

  Node* increment = NULL;
  if (!check(TOKEN_RIGHT_PAREN)) {
    increment = expression();
  }
  consume(TOKEN_RIGHT_PAREN, "Expect ')' after for clauses.");

  Node* body = statement();

  if (increment != NULL) {
    body->next = new_unary(ND_STMT_EXPRESSION, increment);
  }

  if (condition == NULL) {
    condition = new_literal(ND_EXPR_TRUE, NULL, 0.0);
  }
  body = new_while(condition, body);

  if (initializer != NULL) {
    initializer->next = body;
    body = new_unary(ND_STMT_BLOCK, initializer);
  }

  return body;
}

static Node* printStatement() {
  Node* value = expression();
  consume(TOKEN_SEMICOLON, "Expect ';' after value.");
  return new_unary(ND_STMT_PRINT, value);
}

static Node* returnStatement() {
  Node* value = NULL;
  if (!check(TOKEN_SEMICOLON)) {
    value = expression();
  }

  consume(TOKEN_SEMICOLON, "Expect ';' after return value.");
  return new_unary(ND_STMT_RETURN, value);
}

static Node* expressionStatement() {
  Node* expr = expression();
  consume(TOKEN_SEMICOLON, "Expect ';' after expression.");
  return new_unary(ND_STMT_EXPRESSION, expr);
}

static Node* declaration() {
  if (match(TOKEN_CLASS)) return classDeclaration();
  if (match(TOKEN_FUN)) return function();
  if (match(TOKEN_VAR)) return varDeclaration();

  return statement();
}

static Node* classDeclaration() {
  consume(TOKEN_IDENTIFIER, "Expect function name.");

  char* name = copyString(parser.previous.start,
                          parser.previous.length);

  Node* superclass = NULL;
  if (match(TOKEN_LESS)) {
    consume(TOKEN_IDENTIFIER, "Expect superclass name.");
    char* superclass_name = copyString(parser.previous.start,
                            parser.previous.length);
    superclass = new_literal(ND_EXPR_VARIABLE, superclass_name, 0.0);
  }

  consume(TOKEN_LEFT_BRACE, "Expect '{' before class body.");

  Node head = {};
  Node* dummy = &head;
  while (!check(TOKEN_RIGHT_BRACE) && !check(TOKEN_EOF)) {
    dummy = dummy->next = function();
  }

  consume(TOKEN_RIGHT_BRACE, "Expect '}' after class body.");

  return new_class(name, superclass, head.next);
}

static Node* function() {
  consume(TOKEN_IDENTIFIER, "Expect function name.");

  char* name = copyString(parser.previous.start,
                          parser.previous.length);

  consume(TOKEN_LEFT_PAREN, "Expect '(' after function name.");

  Node head = {};
  Node* dummy = &head;
  int params_count = 0;

  if (!check(TOKEN_RIGHT_PAREN)) {
    do {
      if (params_count >= 255) {
        error("Can't have more than 255 parameters.");
      }

      consume(TOKEN_IDENTIFIER, "Expect parameter name.");
      char* param_name = copyString(parser.previous.start,
                                    parser.previous.length);
      dummy = dummy->next = new_literal(ND_STMT_VAR, param_name, 0.0);
      params_count++;
    } while (match(TOKEN_COMMA));
  }
  consume(TOKEN_RIGHT_PAREN, "Expect ')' after parameters.");
  consume(TOKEN_LEFT_BRACE, "Expect '{' before function body.");
  Node* body = block();
  return new_function(name, head.next, body);
}

static Node* varDeclaration() {
  consume(TOKEN_IDENTIFIER, "Expect variable name.");
  char* name = copyString(parser.previous.start,
                          parser.previous.length);

  Node* initializer = NULL;
  if (match(TOKEN_EQUAL)) {
    initializer = expression();
  }

  consume(TOKEN_SEMICOLON, "Expect ';' after variable declaration.");
  return new_var(ND_STMT_VAR, name, initializer);
}

static Node* expression() {
  return assignment();
}

static Node* assignment() {
  Node* expr = or();

  if (match(TOKEN_EQUAL)) {
    Node* value = assignment();

    if (expr->kind == ND_EXPR_VARIABLE) {
      return new_assign(expr->str, value);
    } else if (expr->kind == ND_EXPR_GET) {
      // get.object, get.name, value
      return new_set(expr->lhs, expr->str, value);
    }

    error("Invalid assignment target.");
  }

  return expr;
}

static Node* or() {
  Node* expr = and();

  for (;;) {
    if (match(TOKEN_OR)) {
      Node* right = and();
      expr = new_binary(expr, ND_EXPR_OR, right);
      continue;
    }

    return expr;
  }
}

static Node* and() {
  Node* expr = equality();

  for (;;) {
    if (match(TOKEN_AND)) {
      Node* right = equality();
      expr = new_binary(expr, ND_EXPR_AND, right);
      continue;
    }

    return expr;
  }
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

  return call();
}

static Node* finishCall(Node* callee) {
  Node head = {};
  Node* dummy = &head;
  int args_count = 0;
  if (!check(TOKEN_RIGHT_PAREN)) {
    do {
      if (args_count >= 255) {
        error("Can't have more than 255 arguments.");
      }
      dummy = dummy->next = expression();
    } while (match(TOKEN_COMMA));
  }

  consume(TOKEN_RIGHT_PAREN, "Expect ')' after arguments.");
  return new_binary(callee, ND_EXPR_CALL, head.next);
}

static Node* call() {
  Node* expr = primary();

  while (true) {
    if (match(TOKEN_LEFT_PAREN)) {
      expr = finishCall(expr);
    } else if (match(TOKEN_DOT)) {
      consume(TOKEN_IDENTIFIER, "Expect property name after '.'.");
      char* name = copyString(parser.previous.start,
                              parser.previous.length);
      expr = new_get(expr, name);
    } else {
      break;
    }
  }

  return expr;
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

  if (match(TOKEN_SUPER)) {
    consume(TOKEN_DOT, "Expect '.' after 'super'.");
    consume(TOKEN_IDENTIFIER, "Expect superclass method name.");
    char* method = copyString(parser.previous.start,
                              parser.previous.length);
    return new_literal(ND_EXPR_SUPER, method, 0.0);
  }

  if (match(TOKEN_THIS)) return new_literal(ND_EXPR_THIS, NULL, 0.0);

  if (match(TOKEN_IDENTIFIER)) {
    char* name = copyString(parser.previous.start,
                            parser.previous.length);
    return new_literal(ND_EXPR_VARIABLE, name, 0.0);
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
  Node head = {};
  Node* dummy = &head;
  while (!match(TOKEN_EOF)) {
    dummy->next = declaration();
    dummy = dummy->next;
  }
  return head.next;
}

int node_count;
void printast(Node* ast) {
  node_count = 0;
  printf("digraph G {\n");
  Node* dummy = ast;
  while (dummy != NULL) {
    print_ast(dummy, -1);
    dummy = dummy->next;
  }
  printf("}");
}

void print_ast(Node* ast, int count) {
  if (ast->kind == ND_EXPR_NUMBER) {
    int curr_node = node_count;
    printf("node%d [label=\"%.1f\"];\n", node_count++, ast->val);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
  } else if (ast->kind == ND_EXPR_ADD) {
    int curr_node = node_count;
    printf("node%d [label=\"+\"];\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->lhs, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_STMT_EXPRESSION) {
    print_ast(ast->rhs, count);
  } else if (ast->kind == ND_EXPR_GROUPING) {
    print_ast(ast->rhs, count);
  } else if (ast->kind == ND_EXPR_MUL) {
    int curr_node = node_count;
    printf("node%d [label=\"*\"];\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->lhs, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_EXPR_DIV) {
    int curr_node = node_count;
    printf("node%d [label=\"/\"];\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->lhs, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_EXPR_SUB) {
    int curr_node = node_count;
    printf("node%d [label=\"-\"];\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->lhs, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_EXPR_OR) {
    int curr_node = node_count;
    printf("node%d [label=\"or\"];\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->lhs, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_EXPR_AND) {
    int curr_node = node_count;
    printf("node%d [label=\"and\"];\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->lhs, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_EXPR_NEG) {
    int curr_node = node_count;
    printf("node%d [label=\"-\"]\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->rhs, curr_node);
  } else if (ast->kind == ND_EXPR_TRUE) {
    int curr_node = node_count;
    printf("node%d [label=\"true\"]\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
  } else if (ast->kind == ND_EXPR_FALSE) {
    int curr_node = node_count;
    printf("node%d [label=\"false\"]\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
  } else if (ast->kind == ND_EXPR_STRING) {
    int curr_node = node_count;
    printf("node%d [label=\"\\\"%s\\\"\"]\n", node_count++, ast->str);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
  } else if (ast->kind == ND_EXPR_VARIABLE) {
    int curr_node = node_count;
    printf("node%d [label=\"varAccess(%s)\"]\n", node_count++, ast->str);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
  } else if (ast->kind == ND_STMT_VAR) {
    int curr_node = node_count;
    printf("node%d [label=\"varDef(%s)\"]\n", node_count++, ast->str);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    if (ast->rhs) {
      print_ast(ast->rhs, curr_node);
    }
  } else if (ast->kind == ND_STMT_BLOCK) {
    int curr_node = node_count;
    printf("node%d [label=\"block\"]\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    Node* dummy = ast->rhs;
    while (dummy) {
      print_ast(dummy, curr_node);
      dummy = dummy->next;
    }
  } else if (ast->kind == ND_STMT_FUNCTION) {
    int curr_node = node_count;
    printf("node%d [label=\"function(%s)\"]\n", node_count++, ast->funcname);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    int args_node = node_count;
    printf("node%d [label=\"args\"]\n", node_count++);
    printf("node%d -> node%d;\n", curr_node, args_node);
    if (ast->args) {
      Node* dummy = ast->args;
      while (dummy) {
        print_ast(dummy, args_node);
        dummy = dummy->next;
      }
    }
    int body_node = node_count;
    printf("node%d [label=\"body\"]\n", node_count++);
    printf("node%d -> node%d;\n", curr_node, body_node);
    if (ast->body) {
      Node* dummy = ast->body;
      while (dummy) {
        print_ast(dummy, body_node);
        dummy = dummy->next;
      }
    }
  } else if (ast->kind == ND_STMT_RETURN) {
    int curr_node = node_count;
    printf("node%d [label=\"return\"]\n", node_count++);
    if (count != -1)
      printf("node%d -> node%d;\n", count, curr_node);
    print_ast(ast->rhs, curr_node);
  }
}