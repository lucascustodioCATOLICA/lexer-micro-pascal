# Explicacao tecnica do codigo

## Funcoes:

- isKeyword

        Verifica se a string passada eh igual a uma keyword da linguagem.

- isDelimiter

        Verifica se o caracter passado eh um delimitador.

- isOperator

        Verifica se o caracter passado eh um operador logico-matematico.

- parser

        Eh a funcao principal do programa, ela le linha por linha do codigo indentificando e qualificando os tokens. Quando um token eh encontrado, ela printa o token e sua localizacao no codigo fonte.
        Tambem indentifica erros lexicos.

# Como executar:

- mude a linha 122 da main.c para indicar o codigo fonte que quer compilar.
- rode o comando: gcc .\main.c -o main.exe
- rode o comando: ./main.exe
