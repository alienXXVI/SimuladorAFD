#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "sistema.h"
#include "arquivo.h"

// Imprime a logo do program
void imprimir_logo() {
  printf(" __                                 \n"
           "(_  o __     |  _  _| _  __    _| _ \n"
           "__) | ||||_| | (_|(_|(_) |    (_|(/_\n\n"
           "		  ___  ____________ \n"
           "		 / _ \\ |  ___|  _  \\\n"
           "		/ /_\\ \\| |_  | | | |\n"
           "		|  _  ||  _| | | | |\n"
           "		| | | || |   | |/ / \n"
           "		\\_| |_/\\_|   |___/\n\n");
}

// Lê o arquivo carregado na pasta do programa e guarda as especificações
// Entrada: ponteiro para a estrutura
// Saída: estrutura atualizada
GRAMATICA* ler_arquivo(GRAMATICA *gramatica) {
    char arquivo[20];

    printf("\nDigite o nome do arquivo.extensao:\n"
           "> ");
    scanf("%s", &arquivo);

    gramatica = formar_gramatica(arquivo);
    if(!gramatica) {
        printf("\n(Erro na formacao do AFD)\n");
        return NULL;
    }
    return gramatica;
}

// Testa palavras no AFD já carregado
// Entrada: ponteiro para a estrutura de AFD
// Saída: nenhuma
void testar_palavras(GRAMATICA *gramatica) {
    int opcao = 1;
    char palavra[20];

    while(opcao) {
        printf("\n1 - Digitar a palavra\n"
               "0 - Voltar\n"
               "> ");
        
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("> ");
            scanf("%s", &palavra);
            testar_palavra(gramatica, palavra);
            break;
        
        case 0:
            break;

        default:
            printf("\n(Digite uma opcao valida)\n");
            break;
        }

    }
}

// Reseta a memória ds estrutura para reutilização
// Entrada: ponteiro para a estrutura
// Saída: nenhuma
void resetar(GRAMATICA *gramatica) {
    int tamanho = contar_tamanho_vetor(gramatica->estados);

    free(gramatica->alfabeto);
    free(gramatica->estados);
    free(gramatica->finais);

    for(int i = 0; i < tamanho; i++)
        free(gramatica->transicoes[i]);

    free(gramatica->transicoes);
    free(gramatica);
}

// Chama o menu com as opções principais
void menu_principal() {
    int opcao = 1;
    GRAMATICA *gramatica = NULL;

    while(opcao) {
        printf("\n1 - Carregar um arquivo contendo especificacoes de um AFD\n"
               "2 - Imprimir especificacoes do AFD carregado\n"
               "3 - Testar palavras\n"
               "4 - Resetar memoria\n"
               "0 - Encerrar programa\n"
               "> ");

               scanf("%d", &opcao);

               switch (opcao) {
               case 1:
                    gramatica = ler_arquivo(gramatica);
                    break;

                case 2:
                    imprimir_gramatica(gramatica);
                    break;

               case 3:
                    testar_palavras(gramatica);
                    break;

                case 4:
                    resetar(gramatica);
                    break;

                case 0:
                    printf("\n(Programa encerrado\n");
                    break;
               
               default:
                    printf("\n(Numero invalido)\n");
                    break;
               }
    }
}