# Analisador Lexico

Este projeto implementa um analisador léxico para a linguagem de programação MicroPascal. O analisador identifica e classifica tokens a partir de um código-fonte, além de relatar erros léxicos.

- **Palavras-chave**: program, var, integer, real, begin, end, if, then, else, while, do.
- **Identificadores**: ID

## Funções

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
## Exemplos

**Exemplo 1**
program Exemplo;

var
  x, y : integer;
  z : real;

begin
  x := 10;
  y := (20);
  z := x + y * 2.5;
  if x > y then
    x := x - 1
  else
    y := y + 1;
  while z <= 100 do
  begin
    z := z * 1.5;
    x := x + 2
  end
end.

  **Resumo (correto 1):**  
- Inicializa as variáveis x = 10, y = 20, e z = 60.0.
- Verifica se x é maior que y. Como não é, incrementa y para 21.
- Em seguida, entra em um laço while que continua executando enquanto z for menor ou igual a 100.
- Durante o laço:
- O valor de z é multiplicado por 1.5 a cada iteração.
- O valor de x é incrementado em 2 a cada iteração.
- O laço ocorre duas vezes antes de z ultrapassar 100 e o programa terminar.
- Após a execução, o programa terminará com x = 12 e z = 135.0.



**Exemplo 2**

program exemplo;
var x, y: integer;
begin
  x := 10;
  if x > 5 then
    y := x + 1;
end.

**Resumo (correto 2):**  
- Inicializa a variável x com o valor 10.
- Verifica se x é maior que 5 (o que é verdade, já que x = 10).
- Como a condição é verdadeira, a variável y recebe o valor x + 1, ou seja, y = 11.
- O programa termina sem erros.

**Exemplo 3**

program exemplo;
var x, y: integer;
begin
  x := 10;
  y := 20;
  if x > y then
    x := x + 1
  else
    y := y + 1;
end.

**Resumo (correto 3):**  
- Inicializa as variáveis x = 10 e y = 20.
- A condição if x > y é falsa, porque x = 10 e y = 20.
- Como a condição é falsa, o else é executado e y é incrementado de 20 para 21.
- O programa termina com x = 10 e y = 21.

**Exemplo 4**

program exemplo;
var x, y: integer;
begin
  x := 10 @;
  y := 20;
end.

**Resumo (incorreto 1):**
- O @ após 10 na linha x := 10 @; não é um símbolo válido na linguagem MicroPascal.
- @ geralmente não é utilizado em MicroPascal para operações padrão. No Pascal, esse símbolo pode ser usado, por exemplo,
para referências de ponteiros em outras versões da linguagem, mas não no contexto atual.

**Exemplo 5**

program exemplo;
var x: integer;@
begi'
  x := 1234;
end.

**Resumo (incorreto 2):**
- O @ após a declaração da variável x: integer; é um caractere inválido no contexto da linguagem MicroPascal. Esse símbolo não é permitido e não tem função no código.
- A palavra begi' está incorreta, pois begin está faltando a última letra n e tem uma aspa simples (**) após a letra i, que também é inválida.


**Exemplo 6**

progra exemplo;
var x: integer;
begin
  x % 10;
end.

**Resumo (incorreto 3):**
- % é o operador de módulo (resto da divisão), 
mas ele está sendo usado de forma isolada, 
ou seja, ele está tentando calcular o resto da divisão de x por 10, 
mas o resultado não está sendo atribuído a nenhuma variável.

## Como Executar

1. Mude a linha `122` do `main.c` para indicar o código fonte que deseja compilar.
2. Compile o código usando o comando: 
```
   gcc .\main.c .\types.c .\lex.c .\syntax.c -o main.exe
   ./main.exe
```
<br>

# Integrantes do projeto
 
| Foto | Nome | GitHub | Linkedin |
| ------ | ---- | ------ |--------- |
| <img src="https://avatars.githubusercontent.com/u/82902852?v=4" width="55" height="55"> | Pedro Carneiro de Lima | <a href="https://github.com/pedrocarneirodev"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/pedro-carneiro-lima/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="https://github.com/user-attachments/assets/49a7fe12-5e88-42c7-a428-399f5d8d7389" width="55" height="55"> | Lucas Francisco Custódio | <a href="https://github.com/afslucass"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/afslucass/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="https://avatars.githubusercontent.com/u/133895618?v=4" width="55" height="55"> |  Arthur Faria dos Santos | <a href="https://github.com/Arthur-Faria-dos-Santos"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/arthur-faria-5a0378210/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="https://github.com/user-attachments/assets/a32546a4-720d-483f-a91a-5b87a12eb912" width="55" height="55"> | João Paulo | <a href="https://github.com/JooJPaulo"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="" width="55" height="55"> | Bruno |

