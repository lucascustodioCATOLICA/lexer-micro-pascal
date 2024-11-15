#include "types.h"

const char *token_type[] = {
    "KEYWORD", "NUMBER", "IDENTIFICATOR", "MATH_OP", "RELATIONAL_OP", "DELIMITER", "ASSIGNMENT_OP", "FINAL_DOT"
};
const char *keywords[] = {
    "begin", "end", "var", "if", "then", "else", "while", "do", "program", "integer", "real"
};
const char *relational_operators[] = {
    "=", "<>", "<=", ">=", "<", ">"
};
const char math_operators[] = {
    '-', '+', '/', '*'
};
int num_keywords = 10;
struct TokenLinkedList* head = NULL;