#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    gramatica->alfabeto = malloc(sizeof(char) * 100);
    strcpy(gramatica->alfabeto, alfabeto);
    gramatica->estados = estados;
    gramatica->finais = finais;

    int tamanho = contar_tamanho_vetor(estados);
    gramatica->transicoes = malloc(sizeof(struct no) * tamanho);
    for(int i = 0; i < tamanho; i++)
        gramatica->transicoes[i] = NULL;
    
    return gramatica;
}

// Faz inserção na cauda da lista
// Entrada: ponteiro para a cabeça da lista, estado para onde vai e simbolo lido
// Saída: ponteiro para a lista com elemento inserido
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

// Busca um simbolo nas transições de um estado
// Entrada: ponteiro para a lista e o simbolo
// Saída: o estado para onde vai caso o simbolo exista, -1 caso não
int buscar_simbolo(struct no *l, char simbolo) {
    if(l == NULL)
        return -1;
    if(l->simbolo == simbolo)
        return l->estado;
    return buscar_simbolo(l->prox, simbolo);
}

// Insere uma transição na gramática
// Entrada: ponteiro para a gramática, estado de onde sai a transição, estado para onde vai e o simbolo lido
// Saída: 0 se o processo foi um sucesso, 1 se ocorreu erro nas inserções
int inserir_transicao(GRAMATICA *gramatica, int estado_origem, int estado_destino, char simbolo) {
    if(buscar_simbolo(gramatica->transicoes[estado_origem], simbolo) != -1) {
        printf("\n(Falha ao inserir transicao. Este automato nao eh deterministico)\n");
        return 1;
    }
    if(gramatica == NULL)
        printf("\n(Gramatica inexistente)\n");
    gramatica->transicoes[estado_origem] = inserir_cauda(gramatica->transicoes[estado_origem], estado_destino, simbolo);
    return 0;
}

// Imprime a lista de transições de um único estado
// Entrada: ponteiro para a cabeça da lista
// Saída: nenhuma
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

    if(!gramatica) {
        printf("\n(Gramatica vazia)\n");
        return;
    }

    printf("\nAlfabeto: ");
    for(char* c = gramatica->alfabeto; *c != 0; c++)
        printf("%c ", *c);

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

// Verifica se um estado é final
// Entrada: ponteiro para vetor de finais e o estado
// Saída: 1 se é final, 0 se não
int is_final(int *finais, int estado) {
    int tamanho = contar_tamanho_vetor(finais);

    for(int i = 0; i < tamanho; i++)
        if(finais[i] == estado)
            return 1;
    return 0;
}

// Simula o processamento da palavra no AFD especificado
// Entrada: ponteiro para a gramatica não nula e palavra
// Saída: nenhuma
void testar_palavra(GRAMATICA *gramatica, char *palavra) {
    if(!gramatica) {
        printf("\n(Teste de palavra falhou. Gramatica vazia)\n");
        return;
    }

    // Verificar se todos os símbolos foram lidos
    int i = 0;
    char *simbolo;

    printf("\n");
    for(simbolo = palavra; *simbolo != 0; simbolo++) {
        printf("[q%d]%s\n", i, simbolo);
        i = buscar_simbolo(gramatica->transicoes[i], *simbolo);
        if(i == -1) {
            break;
        }
    }
    if(i != -1)
        printf("[q%d]%s\n", i, simbolo);

    if(i == -1 || !is_final(gramatica->finais, i))
        printf("REJEITA\n");
    else
        printf("ACEITA\n");
}