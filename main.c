#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LEN 100
#define MAX_LINE_LEN 1000

// Definição de palavras-chave do Micro Pascal
const char *keywords[] = {
    "begin", "end", "var", "if", "then", "else", "while", "do", "program", "integer", "real"
};
const char *relational_operators[] = {
    "=", "<>", "<=", ">=", "<", ">"
};
const char *math_operators[] = {
    "-", "+", "/", "*"
};
int num_keywords = 10;

int isKeyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isRelationalOperator(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, relational_operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isMathOperator(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, math_operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Verifica se um caractere é um delimitador
int isDelimiter(char ch) {
    return isspace(ch) || ch == ';' || ch == '(' || ch == ')' || ch == ',' || ch == ':';
}

// Verifica se um caractere é um operador
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>';
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
            printf("Operador: %c\n", source_code[i], source_code[i+1]);
            printf("Linha %d Coluna %d\n", i, l);
            printf("--- --- ---\n");
            i++;   
            i++;
            continue;
        }

        // Identifica operadores
        if (isOperator(source_code[i])) {
            printf("Operador: %c\n", source_code[i]);
            printf("Linha %d Coluna %d\n", i, l);
            printf("--- --- ---\n");
            i++;
            continue;
        }

        // Identifica delimitadores
        if (isDelimiter(source_code[i])) {
            if (source_code[i] == ';') {
                printf("Delimitador: %c\n", source_code[i]);
                printf("Linha %d Coluna %d\n", i, l);
                printf("--- --- ---\n");
            }
            i++;
            continue;
        }

        // Identifica números
        if (isdigit(source_code[i])) {
            int j = 0;
            while (i < len && isdigit(source_code[i])) {
                token[j++] = source_code[i++];
            }
            token[j] = '\0';
            printf("Numero: %s\n", token);
            printf("Linha %d Coluna %d\n", i, l);
            printf("--- --- ---\n");
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
                printf("Palavra-chave: %s\n", token);
                printf("Linha %d Coluna %d\n", i, l);
                printf("--- --- ---\n");
            } else {
                printf("Identificador: %s\n", token);
                printf("Linha %d Coluna %d\n", i, l);
                printf("--- --- ---\n");    
            }
            continue;
        }

        if(source_code[i] == '.') {
            i++;
            continue;
        }

        // Caso de erro para caracteres desconhecidos
        printf("Erro lexico: %c %d %d\n", source_code[i], i, l);
        printf("Linha %d Coluna %d\n", i, l);
        printf("--- --- ---\n");
        i++;
    }
}

int main() {
    FILE *file = fopen("example.lex", "r");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    char line[MAX_LINE_LEN];
    int l = 0;

    while (fgets(line, MAX_LINE_LEN, file)) {
        parser(line, l);
        l++;
    }

    fclose(file);
    
    return 0;
}
