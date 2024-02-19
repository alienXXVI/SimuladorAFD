#include <stdio.h>
#include "sistema.h"
#include "arquivo.h"


// bacca
int main() {
    // int estados[] = {0, 1, 2, -1};
    // char alfabeto[] = {'a', 'b', 'c'};
    // int finais[] = {2, -1};
    GRAMATICA *gramatica = NULL;

    // inserir_transicao(gramatica, 0, 2, 'a');
    // inserir_transicao(gramatica, 0, 0, 'b');
    // inserir_transicao(gramatica, 1, 2, 'c');
    // inserir_transicao(gramatica, 1, 0, 'a');
    // inserir_transicao(gramatica, 2, 2, 'c');
    // inserir_transicao(gramatica, 2, 1, 'a');
    // inserir_transicao(gramatica, 2, 0, 'b');

    // imprimir_gramatica(gramatica);

    // testar_palavra(gramatica, "bacca");

    gramatica = formar_gramatica("afd.txt");
    imprimir_gramatica(gramatica);
    testar_palavra()

    return 0;
}