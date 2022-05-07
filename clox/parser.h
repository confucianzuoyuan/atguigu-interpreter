#include <string.h>

#include "scanner.h"

typedef struct Node Node;

typedef enum {
  ND_EXPR_ASSIGN,
  ND_EXPR_ADD,
  ND_EXPR_SUB,
  ND_EXPR_MUL,
  ND_EXPR_DIV,
  ND_EXPR_NE,
  ND_EXPR_EQ,
  ND_EXPR_LT,
  ND_EXPR_LE,
  ND_EXPR_GT,
  ND_EXPR_GE,
  ND_EXPR_CALL,
  ND_EXPR_GET,
  ND_EXPR_SET,
  ND_EXPR_GROUPING,
  ND_EXPR_NUMBER,
  ND_EXPR_STRING,
  ND_EXPR_NIL,
  ND_EXPR_TRUE,
  ND_EXPR_FALSE,
  ND_EXPR_AND,
  ND_EXPR_OR,
  ND_EXPR_SUPER,
  ND_EXPR_THIS,
  ND_EXPR_NEG,
  ND_EXPR_NOT,
  ND_EXPR_VARIABLE,
  ND_STMT_BLOCK,
  ND_STMT_CLASS,
  ND_STMT_EXPRESSION,
  ND_STMT_FUNCTION,
  ND_STMT_IF,
  ND_STMT_PRINT,
  ND_STMT_RETURN,
  ND_STMT_VAR,
  ND_STMT_WHILE,
} NodeKind;

struct Node {
  NodeKind kind;
  Node *next;

  Node *lhs;
  Node *rhs;

  Node *cond;
  Node *then;
  Node *els;
  Node *init;
  Node *inc;

  Node *body;

  char *funcname;
  Node *args;

  double val;
  char* str;
};

Node* parse(const char* source);
void print_ast(Node* ast, int depth);
void printast(Node* ast);