#include "types.h"
#include "lex.h"
#include "syntax.h"

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

    analiser(head);
    fclose(file);
    
    return 0;
}
