# Analisador Lexico

Este projeto implementa um analisador léxico para a linguagem de programação MicroPascal. O analisador identifica e classifica tokens a partir de um código-fonte, além de relatar erros léxicos.

## Funções

- **Palavras-chave**: program, var, integer, real, begin, end, if, then, else, while, do.
- **Identificadores**: ID

### Funções

- **`isKeyword(const char *str)`**: 
  - **Propósito**: Verifica se a string passada é uma palavra-chave da linguagem.
  - **Parâmetros**: 
    - `str`: A string a ser verificada.
  - **Retorno**: Retorna 1 se for uma palavra-chave, 0 caso contrário.

- **`isDelimiter(char ch)`**:
  - **Propósito**: Verifica se o caractere passado é um delimitador (espaços em branco, ponto e vírgula, parênteses, etc.).
  - **Parâmetros**: 
    - `ch`: O caractere a ser verificado.
  - **Retorno**: Retorna 1 se for um delimitador, 0 caso contrário.

- **`isOperator(char ch)`**:
  - **Propósito**: Verifica se o caractere passado é um operador lógico-matemático (soma, subtração, multiplicação, etc.).
  - **Parâmetros**: 
    - `ch`: O caractere a ser verificado.
  - **Retorno**: Retorna 1 se for um operador, 0 caso contrário.

- **`parser(const char *source_code, int l)`**:
  - **Propósito**: Função principal do programa. Lê o código-fonte linha por linha, identifica e classifica os tokens, imprime os tokens encontrados, suas localizações e erros léxicos.
  - **Parâmetros**: 
    - `source_code`: A linha de código-fonte a ser analisada.
    - `l`: O número da linha atual.
  
## Como Executar

1. Mude a linha `122` do `main.c` para indicar o código fonte que deseja compilar.
2. Compile o código usando o comando: 
```
   gcc main.c -o output.exe
   ./output.exe
```
