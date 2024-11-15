#ifndef TYPES
#define TYPES

#include <stdio.h>

#define MAX_TOKEN_LEN 100
#define MAX_LINE_LEN 1000

struct Token {
    char type[100];
    char token[100];
    int col;
    int row;
};

struct TokenLinkedList {
    struct Token token;
    struct TokenLinkedList* next;
};

extern const char *token_type[];
extern const char *keywords[];
extern const char *relational_operators[];
extern const char math_operators[];
extern int num_keywords;
extern struct TokenLinkedList* head;

#endif