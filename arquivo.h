#ifndef ARQUIVO
#define ARQUIVO
#include "sistema.h"

// Le o alfabeto do arquivo (primeira linha)
// Entrada: nenhuma
// Retorno: vector contendo o alfabeto
// Pre-condicao: primeira linha no formato "alfabeto={a,b,c}"
// Pos-condicao: nenhuma
char* ler_alfabeto(char* buff);

// Le os estados do arquivo (segunda linha)
// Entrada: nenhuma
// Retorno: vector contendo os estados
// Pre-condicao: segunda linha no formato "estados={q0,q1,q2}"
// Pos-condicao: nenhuma
int* ler_estados(char* buff);

// Le os estados finais do arquivo (terceira linha)
// Entrada: nenhuma
// Retorno: vector contendo os estados finais
// Pre-condicao: terceira linha no formato "finais={q3,q4}"
// Pos-condicao: nenhuma
int* ler_finais(char* buff);

// Le as transicoes nas linhas seguintes do arquivo e guarda na estrutura de grafo
// Entrada: estrutura onde sera guardada
// Retorno: nova estrutura pre carregada
// Pre-condicao: linhas de transicao no formato "(q1,a)=q1"
// Pos-condicao: nenhuma
GRAMATICA* formar_gramatica(char *arquivo);

#endif