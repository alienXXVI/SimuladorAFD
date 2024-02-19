#include <stdio.h>
#include "sistema.h"
#include "arquivo.h"


// ab00cb
// abbac
// @
int main() {
    GRAMATICA *gramatica = NULL;

    gramatica = formar_gramatica("afd.txt");
    if(!gramatica)
        printf("\n(Erro na formacao da gramatica)\n");
    imprimir_gramatica(gramatica);
    testar_palavra(gramatica, "@");

    return 0;
}