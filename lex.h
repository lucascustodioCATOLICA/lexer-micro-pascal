#ifndef LEX
#define LEX

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "types.h"

void appendToken(struct TokenLinkedList** head, const char* token, const char* type, const int col, const int row);
void traverseTokenLinkedList(struct TokenLinkedList* node);
int isKeyword(const char *str);
int isMathOperator(char ch);
int isDelimiter(char ch);
void parser(const char *source_code, int l);

#endif