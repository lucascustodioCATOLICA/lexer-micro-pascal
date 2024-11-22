#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TOKEN_PROGRAM,
    TOKEN_IDENTIFICADOR,
    TOKEN_VAR,
    TOKEN_INTEGER,
    TOKEN_REAL,
    TOKEN_BEGIN,
    TOKEN_END,
    TOKEN_IF,
    TOKEN_THEN,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_DO,
    TOKEN_NUMERO,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_PERIOD,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_REL_OP,
    TOKEN_ADD_OP,
    TOKEN_MUL_OP,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType tipo;
    char lexema[100];
    int linha;
} Token;

typedef struct {
    Token token_atual;
    int posicao;
    Token *tokens;
    int total_tokens;
} AnalisadorLexico;

AnalisadorLexico analisadorLexico;

// Função para reportar erros
void erro(const char *mensagem, int linha, const char *lexema) {
    fprintf(stderr, "%d: %s [%s]\n", linha, mensagem, lexema);
    exit(1);
}

// Verifica e consome um token esperado
void casa_token(TokenType tipo_esperado) {
    if (analisadorLexico.token_atual.tipo == tipo_esperado) {
        if (++analisadorLexico.posicao < analisadorLexico.total_tokens) {
            analisadorLexico.token_atual = analisadorLexico.tokens[analisadorLexico.posicao];
        }
    } else {
        erro("token não esperado", analisadorLexico.token_atual.linha, analisadorLexico.token_atual.lexema);
    }
}

// Declaração de funções do analisador sintático
void programa(), bloco(), declaracao_de_variaveis(), lista_de_identificadores();
void tipo(), comando_composto(), comando(), atribuicao(), comando_condicional();
void comando_repetitivo(), expressao(), relacao(), expressao_simples(), termo();
void fator(), variavel(), parte_de_declaracoes_de_variaveis();

// Função principal do programa
void programa() {
    casa_token(TOKEN_PROGRAM);
    casa_token(TOKEN_IDENTIFICADOR);
    casa_token(TOKEN_SEMICOLON);
    bloco();
    casa_token(TOKEN_PERIOD);
}

// Analisa um bloco
void bloco() {
    parte_de_declaracoes_de_variaveis();
    comando_composto();
}

// Analisa declarações de variáveis
void parte_de_declaracoes_de_variaveis() {
    while (analisadorLexico.token_atual.tipo == TOKEN_VAR) {
        casa_token(TOKEN_VAR);
        do {
            declaracao_de_variaveis();
            casa_token(TOKEN_SEMICOLON);
        } while (analisadorLexico.token_atual.tipo == TOKEN_IDENTIFICADOR);
    }
}

// Declara variáveis
void declaracao_de_variaveis() {
    lista_de_identificadores();
    casa_token(TOKEN_COLON);
    tipo();
}

// Lista identificadores
void lista_de_identificadores() {
    do {
        casa_token(TOKEN_IDENTIFICADOR);
    } while (analisadorLexico.token_atual.tipo == TOKEN_COMMA && (casa_token(TOKEN_COMMA), 1));
}

// Verifica tipo
void tipo() {
    if (analisadorLexico.token_atual.tipo == TOKEN_INTEGER || 
        analisadorLexico.token_atual.tipo == TOKEN_REAL) {
        casa_token(analisadorLexico.token_atual.tipo);
    } else {
        erro("tipo não esperado", analisadorLexico.token_atual.linha, analisadorLexico.token_atual.lexema);
    }
}

// Analisa comando composto
void comando_composto() {
    casa_token(TOKEN_BEGIN);
    do {
        comando();
    } while (analisadorLexico.token_atual.tipo == TOKEN_SEMICOLON && (casa_token(TOKEN_SEMICOLON), 1));
    casa_token(TOKEN_END);
}

// Analisa comando
void comando() {
    switch (analisadorLexico.token_atual.tipo) {
        case TOKEN_IDENTIFICADOR: atribuicao(); break;
        case TOKEN_BEGIN: comando_composto(); break;
        case TOKEN_IF: comando_condicional(); break;
        case TOKEN_WHILE: comando_repetitivo(); break;
        default: erro("comando não esperado", analisadorLexico.token_atual.linha, analisadorLexico.token_atual.lexema);
    }
}

// Analisa atribuição
void atribuicao() {
    casa_token(TOKEN_IDENTIFICADOR);
    casa_token(TOKEN_ASSIGN);
    expressao();
}

// Analisa comando condicional
void comando_condicional() {
    casa_token(TOKEN_IF);
    expressao();
    casa_token(TOKEN_THEN);
    comando();
    if (analisadorLexico.token_atual.tipo == TOKEN_ELSE) {
        casa_token(TOKEN_ELSE);
        comando();
    }
}

// Analisa comando repetitivo
void comando_repetitivo() {
    casa_token(TOKEN_WHILE);
    expressao();
    casa_token(TOKEN_DO);
    comando();
}

// Analisa expressão
void expressao() {
    expressao_simples();
    if (analisadorLexico.token_atual.tipo == TOKEN_REL_OP) {
        relacao();
        expressao_simples();
    }
}

// Verifica relação
void relacao() {
    casa_token(analisadorLexico.token_atual.tipo);
}

// Analisa expressão simples
void expressao_simples() {
    if (analisadorLexico.token_atual.tipo == TOKEN_ADD_OP) casa_token(analisadorLexico.token_atual.tipo);
    termo();
    while (analisadorLexico.token_atual.tipo == TOKEN_ADD_OP) {
        casa_token(analisadorLexico.token_atual.tipo);
        termo();
    }
}

// Analisa termo
void termo() {
    fator();
    while (analisadorLexico.token_atual.tipo == TOKEN_MUL_OP) {
        casa_token(analisadorLexico.token_atual.tipo);
        fator();
    }
}

// Analisa fator
void fator() {
    switch (analisadorLexico.token_atual.tipo) {
        case TOKEN_IDENTIFICADOR: variavel(); break;
        case TOKEN_NUMERO: casa_token(TOKEN_NUMERO); break;
        case TOKEN_LPAREN:
            casa_token(TOKEN_LPAREN);
            expressao();
            casa_token(TOKEN_RPAREN);
            break;
        default: erro("fator não esperado", analisadorLexico.token_atual.linha, analisadorLexico.token_atual.lexema);
    }
}

// Analisa variável
void variavel() {
    casa_token(TOKEN_IDENTIFICADOR);
}

// Função principal do analisador sintático
void analiser(Token *tokens, int total_tokens) {
    analisadorLexico.tokens = tokens;
    analisadorLexico.total_tokens = total_tokens;
    analisadorLexico.posicao = 0;
    analisadorLexico.token_atual = analisadorLexico.tokens[analisadorLexico.posicao];
    programa();
}

