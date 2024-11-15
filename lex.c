#include "lex.h"

void appendToken(struct TokenLinkedList** head, const char* token, const char* type, const int col, const int row) {
    struct Token* new_token = (struct Token*)malloc(sizeof(struct Token));
    strcpy(new_token->token, token);
    strcpy(new_token->type, type);
    new_token->col = col;
    new_token->row = row;

    struct TokenLinkedList* new_node = (struct TokenLinkedList*)malloc(sizeof(struct TokenLinkedList));
    struct TokenLinkedList* last = *head;

    new_node->token = *new_token;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void traverseTokenLinkedList(struct TokenLinkedList* node) {
    while (node != NULL) {
        printf("%s\n", node->token.type);
        printf("%s\n", node->token.token);
        printf("col %d row %d\n", node->token.col, node->token.row);
        printf("--- --- ---\n");
        node = node->next;
    }
}

int isKeyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isMathOperator(char ch) {
    return ch == math_operators[0] || ch == math_operators[1] || ch == math_operators[2] || ch == math_operators[3];
}

// Verifica se um caractere é um delimitador
int isDelimiter(char ch) {
    return isspace(ch) || ch == ';' || ch == '(' || ch == ')' || ch == ',' || ch == ':';
}

void parser(const char *source_code, int l) {
    int i = 0;
    int len = strlen(source_code);
    char token[MAX_TOKEN_LEN];
    
    while (i < len) {
        // Ignora espaços em branco
        if (isspace(source_code[i])) {
            i++;
            continue;
        }

        // Identifica operador de atribuicao
        if(source_code[i] == ':' && source_code[i+1] == '=') {
            appendToken(&head, ":=", token_type[6], l, i);
            i++;   
            i++;
            continue;
        }

        // Identifica delimitadores
        if (isDelimiter(source_code[i])) {
            char del_token[2];
            del_token[0] = source_code[i];
            del_token[1] = '\0';
            appendToken(&head, del_token, token_type[5], l, i);
            i++;
            continue;
        }

        if (isMathOperator(source_code[i])) {
            char math_token[2];
            math_token[0] = source_code[i];
            math_token[1] = '\0';
            appendToken(&head, math_token, token_type[3], l, i);
            i++;
            continue;
        }


        // identifica operadores relacionais
        if (source_code[i] == '=' || source_code[i] == '>' || source_code[i] == '<') {
            char rel_token[2];
            if(source_code[i+1] == '=') {
                rel_token[0] = source_code[i];
                rel_token[1] = source_code[i+1];
                rel_token[2] = '\0';
                appendToken(&head, rel_token, token_type[4], l, i);
                i++;    
                i++;
                continue;
            }
            if(source_code[i] == '<' || source_code[i+1] == '>') {
                rel_token[0] = source_code[i];
                rel_token[1] = source_code[i+1];
                rel_token[2] = '\0';
                appendToken(&head, rel_token, token_type[4], l, i);
                i++;    
                i++;
                continue;
            }
            char rel_token_variant[1];
            rel_token_variant[0] = source_code[i];
            rel_token_variant[1] = '\0';
            appendToken(&head, rel_token_variant, token_type[4], l, i);
            i++;
            continue;
        }

        // Identifica números
        if (isdigit(source_code[i])) {
            int j = 0;
            while (i < len && (isdigit(source_code[i]) || source_code[i] == '.')) {
                token[j++] = source_code[i++];
            }
            token[j] = '\0';
            appendToken(&head, token, token_type[1], l, i);
            continue;
        }

        // Identifica identificadores e palavras-chave
        if (isalpha(source_code[i])) {
            int j = 0;
            while (i < len && (isalpha(source_code[i]) || isdigit(source_code[i]))) {
                token[j++] = source_code[i++];
            }
            token[j] = '\0';
            if (isKeyword(token)) {
                appendToken(&head, token, token_type[0], l, i);
            } else {
                appendToken(&head, token, token_type[2], l, i);
            }
            continue;
        }

        if(source_code[i] == '.') {
            char final_token[1];
            final_token[0] = source_code[i];
            final_token[1] = '\0';
            appendToken(&head, final_token, token_type[7], l, i);
            i++;
            continue;
        }

        // Caso de erro para caracteres desconhecidos
        printf("Erro lexico: %c %d %d\n", source_code[i], i, l);
        printf("Linha %d Coluna %d\n", i, l);
        printf("--- --- ---\n");
        return;
    }
}