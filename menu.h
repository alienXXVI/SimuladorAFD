#ifndef MENU
#define MENU

#include "sistema.h"


// Imprime a logo do programa
void imprimir_logo();

// Lê o arquivo carregado na pasta do programa e guarda as especificações
// Entrada: ponteiro para a estrutura
// Saída: estrutura atualizada
GRAMATICA* ler_arquivo(GRAMATICA *gramatica);

// Testa palavras no AFD já carregado
// Entrada: ponteiro para a estrutura de AFD
// Saída: nenhuma
void testar_palavras(GRAMATICA *gramatica);

// Reseta a memória ds estrutura para reutilização
// Entrada: ponteiro para a estrutura
// Saída: nenhuma
void resetar(GRAMATICA *gramatica);

// Chama o menu com as opções principais
void menu_principal();

#endif