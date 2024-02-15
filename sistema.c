#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

// Conta o número de elementos de um vetor
// Entrada: ponteiro para um vetor que termina com -1
// Saída: número de elementos
int contar_tamanho_vetor(int *vetor) {
    int cont = 0;
    for(int *i = vetor; *i != -1; i++)
        cont++;
    return cont;
}

// Conta o número de elementos de um string
// Entrada: ponteiro para um string que termina com -1
// Saída: número de elementos
int contar_tamanho_string(char *string) {
    int cont = 0;
    for(char *i = string; *i != 0; i++)
        cont++;
    return cont;
}

// Constrói a especificação da gramática
// Entrada: ponteiro para alfabeto, estados e finais
// Saída: nenhuma
GRAMATICA* criar_gramatica(char *alfabeto, int *estados, int *finais) {
    GRAMATICA *gramatica = (GRAMATICA*) malloc (sizeof(GRAMATICA));

    gramatica->alfabeto = alfabeto;
    gramatica->estados = estados;
    gramatica->finais = finais;

    int tamanho = contar_tamanho_vetor(estados);
    gramatica->transicoes = malloc(sizeof(struct no) * tamanho);
    for(int i = 0; i < tamanho; i++)
        gramatica->transicoes[i] = NULL;
    
    return gramatica;
}

// Faz inserção na cauda da lista
// Entrada: ponteiro para a lista, estado para onde vai e simbolo lido
// Saída: ponteiro para a lista
struct no* inserir_cauda(struct no* l, int estado_destino, char simbolo) {
    if(l == NULL) {
        l = (struct no*) malloc(sizeof(struct no));

        l->estado = estado_destino;
        l->simbolo = simbolo;
        l->prox = NULL;
        return l;
    }
    l->prox = inserir_cauda(l->prox, estado_destino, simbolo);
    return l;
}

// Insere uma transição na gramática
// Entrada: ponteiro para a gramática, estado de onde sai a transição, estado para onde vai e o simbolo lido
// Saída: nenhuma
void inserir_transicao(GRAMATICA *gramatica, int estado_origem, int estado_destino, char simbolo) {
    if(gramatica == NULL)
        printf("(Gramatica inexistente)\n");
    gramatica->transicoes[estado_origem] = inserir_cauda(gramatica->transicoes[estado_origem], estado_destino, simbolo);
}

void imprimir_lista(struct no* l) {
    if(l == NULL)
        return;
    printf("{q%d, %c} ", l->estado, l->simbolo);
    imprimir_lista(l->prox);
}

// Imprime a gramática e suas transições
// Entrada: ponteiro para a gramática
// Saída: nenhuma
void imprimir_gramatica(GRAMATICA *gramatica) {
    int tamanho;

    printf("\nAlfabeto: ");
    tamanho = contar_tamanho_string(gramatica->alfabeto);
    for(int i = 0; i < tamanho; i++)
        printf("%c ", gramatica->alfabeto[i]);

    printf("\nEstados: ");
    tamanho = contar_tamanho_vetor(gramatica->estados);
    for(int i = 0; i < tamanho; i++)
        printf("q%d ", gramatica->estados[i]);

    printf("\nFinais: ");
    tamanho = contar_tamanho_vetor(gramatica->finais);
    for(int i = 0; i < tamanho; i++)
        printf("q%d ", gramatica->finais[i]);

    printf("\nTransicoes:\n");
    tamanho = contar_tamanho_vetor(gramatica->estados);
    for(int i = 0; i < tamanho; i++) {
        printf("q%d -> ", gramatica->estados[i]);
        imprimir_lista(gramatica->transicoes[i]);
        printf("\n");
    }
}

// Simula o processamento da palavra no AFD especificado
// Entrada: ponteiro para a gramatica não nula e palavra
// Saída: nenhuma
void testar_palavra(GRAMATICA *gramatica, char *palavra) {

}