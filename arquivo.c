/*
(Exemplo de arquivo de texto)

alfabeto={a,b,c,0,1,2}
estados={q0,q1,q2,q3,q4,q5}
finais={q2,q5}
(q0,a)= q1
(q1,a)= q2
(q1,b)= q1
(q1,0)= q4
(q2,c)= q3
(q3,b)= q2
(q3,0)= q5
(q4,0)= q2
(q4,1)= q5
(q5,2)= q4

*/

/*
Primeiramente, precisamos ler os três vetores do arquivo
- ler o alfabeto e guardar em (char*)
- ler os estados e guardar em (int*)
- ler os finais e guardar em (int*)

Depois, precisamos criar uma GRAMATICA com esses dados
- pode usar "GRAMATICA* criar_gramatica(char *alfabeto, int *estados, int *finais)"

Depois, precisamos ler as transições de cada linha até o final do arquivo
- ler o estado origem e guardar em (int)
- ler o simbolo e guardar em (char)
- ler o estado destino e guardar em (int)

Para cada linha, precisamos fazer uma inserção desses dados na lista de trasições
- pode usar "void inserir_transicao(GRAMATICA *gramatica, int estado_origem, int estado_destino, char simbolo)"

*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arquivo.h"
#include "sistema.h"

#define MAX 1000

// Le o alfabeto do arquivo (primeira linha)
// Entrada: nenhuma
// Retorno: vetor contendo o alfabeto
// Pre-condicao: primeira linha no formato "alfabeto={a,b,c}"
// Pos-condicao: nenhuma
char* ler_alfabeto(char* buff) {
    char *c;
    char *alfabeto = malloc(sizeof(char) * 100);
    char* buff_copia = strdup(buff);
    int i;
    
    c = buff_copia + 9;
    c = strtok (buff_copia, ",{}");
    c = strtok (NULL, ",{}");
    for(i = 0; c != NULL; i++) {
        alfabeto[i] = *c;
        c = strtok (NULL, ",{}");
    }
    alfabeto[i-1] = 0;
    free(buff_copia);
    return alfabeto;
}

// Le os estados do arquivo (segunda linha)
// Entrada: nenhuma
// Retorno: vector contendo os estados
// Pre-condicao: segunda linha no formato "estados={q0,q1,q2}"
// Pos-condicao: nenhuma
int* ler_estados(char* buff) {
    char *c;
    int estado, i;
    int *estados = malloc(sizeof(int) * 100);
    char* buff_copia = strdup(buff);
    
    c = buff_copia + 8;
    c = strtok (buff_copia, ",{}q");
    c = strtok (NULL, ",{}q");
    for(i = 0; c != NULL; i++) {
        estado = *c - '0';
        estados[i] = estado;
        c = strtok (NULL, ",{}q");
    }
    estados[i-1] = -1;
    free(buff_copia);
    return estados;
}

// Le os estados finais do arquivo (terceira linha)
// Entrada: nenhuma
// Retorno: vector contendo os estados finais
// Pre-condicao: terceira linha no formato "finais={q3,q4}"
// Pos-condicao: nenhuma
int* ler_finais(char* buff) {
    char *c;
    int final, i;
    int *finais = malloc(sizeof(int) * 100);
    char* buff_copia = strdup(buff);
    
    c = buff_copia + 8;
    c = strtok (buff_copia, ",{}q");
    c = strtok (NULL, ",{}q");
    for(i = 0; c != NULL; i++) {
        final = *c - '0';
        finais[i] = final;
        c = strtok (NULL, ",{}q");
    }
    finais[i-1] = -1;
    free(buff_copia);
    return finais;
}

// Le as transicoes nas linhas seguintes do arquivo e guarda na estrutura de gramatica
// Entrada: estrutura onde sera guardada
// Retorno: nova estrutura pre carregada
// Pre-condicao: linhas de transicao no formato "(q1,a)=q1"
// Pos-condicao: nenhuma
GRAMATICA* formar_gramatica(char *arquivo) {
    char buff[MAX];
    char *c;
    int estado_origem;
    char simbolo;
    int estado_destino;

    FILE *fin = fopen(arquivo, "r");
    if (fin == NULL) {
        printf("(Erro ao abrir o arquivo)\n");
        return NULL; // Saída com erro
    }
    
    fgets(buff, MAX, fin);
    char *alfabeto = ler_alfabeto(buff);

    fgets(buff, MAX, fin);
    int *estados = ler_estados(buff);
    int tamanho = contar_tamanho_vetor(estados);
    
    fgets(buff, MAX, fin);
    int *finais = ler_finais(buff);
    tamanho = contar_tamanho_vetor(finais);
    
    GRAMATICA *gramatica = criar_gramatica(alfabeto, estados, finais);

    fgets(buff, MAX, fin);
    while (!feof(fin)) { // enquanto nao for fim de arquivo
        c = buff + 2;
        estado_origem = *c - '0';

        c = c + 2;
        simbolo = *c;

        c = c + 5;
        estado_destino = *c - '0';

        inserir_transicao(gramatica, estado_origem, estado_destino, simbolo);
        fgets(buff, MAX, fin);
    }
    c = buff + 2;
    estado_origem = *c - '0';

    c = c + 2;
    simbolo = *c;

    c = c + 5;
    estado_destino = *c - '0';
    inserir_transicao(gramatica, estado_origem, estado_destino, simbolo);

    printf("(AFD carregado)\n");

    fclose(fin);
    free(alfabeto);
    free(estados);
    free(finais);

    return gramatica;
}