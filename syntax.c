#include "syntax.h"

void analiser(struct TokenLinkedList* node) {
    // implementar analisador sintatico aqui, abaixo realizo um loop pela lista de tokens:
    while (node != NULL) {
        printf("%s\n", node->token.type);
        printf("%s\n", node->token.token);
        printf("col %d row %d\n", node->token.col, node->token.row);
        printf("--- --- ---\n");
        node = node->next;
    }
}