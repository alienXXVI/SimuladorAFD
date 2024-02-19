#ifndef SISTEMA
#define SISTEMA

// ----------- ESTRUTURAS -----------

// Estrutura para transições de um único estado
struct no {
    int estado;
    char simbolo;
    struct no *prox;
};

// Ponteiro para a cabeça da lista de transições
typedef struct no *transicao;

// Estrutura para a especificação da gramática
typedef struct{
    char *alfabeto;
    int *estados;
    int *finais;
    transicao *transicoes; // vetor de cabeças
} GRAMATICA;

// ----------- SISTEMA -----------

// Conta o número de elementos de um vetor
// Entrada: ponteiro para um vetor que termina com -1
// Saída: número de elementos
int contar_tamanho_vetor(int *vetor);

// Conta o número de elementos de um string
// Entrada: ponteiro para um string que termina com -1
// Saída: número de elementos
int contar_tamanho_string(char *string);

// Constrói a especificação da gramática
// Entrada: ponteiro para alfabeto, estados e finais
// Saída: nenhuma
GRAMATICA* criar_gramatica(char *alfabeto, int *estados, int *finais);

// Insere uma transição na gramática
// Entrada: ponteiro para a gramática, estado de onde sai a transição, estado para onde vai e o simbolo lido
// Saída: 0 se o processo foi um sucesso, 1 se ocorreu erro nas inserções
int inserir_transicao(GRAMATICA *gramatica, int estado_origem, int estado_destino, char simbolo);

// Imprime a gramática e suas transições
// Entrada: ponteiro para a gramática
// Saída: nenhuma
void imprimir_gramatica(GRAMATICA *gramatica);

// Simula o processamento da palavra no AFD especificado
// Entrada: ponteiro para a gramatica não nula e palavra
// Saída: nenhuma
void testar_palavra(GRAMATICA *gramatica, char *palavra);


#endif