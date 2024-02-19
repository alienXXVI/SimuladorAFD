/*
Podemos fazer o menu principal, onde a gente pode
- carregar um novo arquivo de texto
- testar palavras
    pode usar "void testar_palavra(GRAMATICA *gramatica, char *palavra)"
- imprimir a gramatica
    pode usar "void imprimir_gramatica(GRAMATICA *gramatica)"
*/

#include <stdio.h>
#include "menu.h"
#include "sistema.h"
#include "arquivo.h"

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

GRAMATICA* ler_arquivo(GRAMATICA *gramatica) {
    char* arquivo;

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

void testar_palavras(GRAMATICA *gramatica) {
    int opcao = 1;
    char *palavra;

    while(opcao) {
        printf("1 - Digitar a palavra\n"
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

GRAMATICA* resetar(GRAMATICA *gramatica) {
    int tamanho = contar_tamanho_vetor(gramatica->estados);

    free(gramatica->alfabeto);
    free(gramatica->estados);
    free(gramatica->finais);

    for(int i = 0; i < tamanho; i++)
        free(gramatica->transicoes[i]);
}

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
                    testar_palavras(gramatica);
                    break;

                case 3:
                    gramatica = resetar(gramatica);
               
               default:
                break;
               }
    }
}