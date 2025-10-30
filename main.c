#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"

Produto lista_produtos[MAX_PRODUTOS];
int total_produtos = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    limpar_tela();
    int opcao = 0;

    while (1) {
        imprimir_linha(50, '=');
        printf("             | MERCADINHO S�O FRANCISCO |             \n");
        imprimir_linha(50, '=');

        printf("| 1. ADICIONAR PRODUTOS\n");
        printf("| 2. REMOVER PRODUTOS\n");
        printf("| 3. MOSTRAR PRODUTOS\n");
        printf("| 4. ATUALIZAR PRODUTOS\n");

        printf("Escolha uma op��o: ");
        scanf("%d",&opcao);
        getchar();
        switch (opcao) {
            case 1:
                adicionar_produto(lista_produtos, &total_produtos);
                visualizar_tela();
                break;

            case 2:
                remover_produto(lista_produtos, &total_produtos);
                visualizar_tela();
                break;

            case 3:
                mostrar_produto(lista_produtos, total_produtos);
                visualizar_tela();
                break;

            case 4:
                atualizar_produto(lista_produtos, total_produtos);
                visualizar_tela();
                break;

            case 5:
                printf("Saindo...\n\n");
                return 0;


            default:
                printf("\nERROR!! OP��O INV�LIDA!\n");
                printf("TENTE NOVAMENTE!\n");
                visualizar_tela();
                break;
        }

    }
    return 0;
}
