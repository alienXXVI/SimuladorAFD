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