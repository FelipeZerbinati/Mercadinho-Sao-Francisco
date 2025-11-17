#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void limpar_tela(void) {
    system("cls");
}

void pular_linha(void) {
    printf("\n");
}

void visualizar_tela(void) {
    printf("APERTE ENTER PARA CONTINUAR.");
    getchar();

    limpar_tela();
}

void imprimir_linha(int tamanho, char caractere){
    int i;
    for (i = 0; i < tamanho; i++) {
        putchar(caractere);
    }
    putchar('\n');
}

void screen_create(void) {
    imprimir_linha(34, '=');
    printf("     | CADASTRO DE PRODUTOS |     \n");
    imprimir_linha(34, '=');
}

void adicionar_produto(Produto lista_produtos[], int *total_produtos){
    limpar_tela();
    screen_create();
    if (*total_produtos >= MAX_PRODUTOS){
        printf("Estoque cheio! Impossível adicionar mais produtos.\n");
    }

    Produto p;
    p.id = *total_produtos + 1;
    printf("Digite o nome do produto: ");
    fgets(p.nome, 50, stdin);
    printf("Digite a descrição do produto: ");
    fgets(p.descricao, 100, stdin);
    printf("Digite o preço: ");
    scanf("%f", &p.preco);
    printf("Digite a quantidade: ");
    scanf("%d", &p.quantidade);

    lista_produtos[*total_produtos] = p;
    (*total_produtos)++;
    printf("Produto(s) adicionado(s) com sucesso!\n");
}

void screen_read(void) {
    imprimir_linha(34, '*');
    printf("   | VISUALIZAÇÃO DO ESTOQUE |  \n");
    imprimir_linha(34, '*');
}

void mostrar_produto(Produto lista_produtos[], int total_produtos){
    limpar_tela();
    screen_read();

    if (total_produtos == 0) {
        printf("\nNenhum produto cadastrado no estoque.\n\n");
        return;
    }

    for (int i =0; i< total_produtos; i++){
        printf("----------------------------------\n");
        printf("Produto ID: %d\n", lista_produtos[i].id);
        printf("Nome: %s\n", lista_produtos[i].nome);
        printf("Descrição: %s\n", lista_produtos[i].descricao);
        printf("Preço: R$ %.2f\n", lista_produtos[i].preco);
        printf("Quantidade: %d\n", lista_produtos[i].quantidade);
    }
    imprimir_linha(34, '-');
    pular_linha();
}

void screen_update(void) {
    imprimir_linha(34, '*');
    printf("  | ATUALIZAÇÃO DOS PRODUTOS |  \n");
    imprimir_linha(34, '*');
}

void atualizar_produto(Produto lista_produtos[], int total_produtos){
    limpar_tela();
    screen_update();
    if (total_produtos == 0){
        printf("\nEstoque vazio. Nada para atualizar.\n\n");
        return;
    }

    int id_busca;
    int encontrado = 0;

    printf("\nDigite o ID do produto que deseja atualizar: ");
    scanf("%d", &id_busca);
    getchar();

    for (int i = 0; i < total_produtos; i++){
        if (lista_produtos[i].id == id_busca) {
            encontrado = 1;

            printf("\n--- Produto Encontrado (ID: %d) ---\n", lista_produtos[i].id);
            printf("Nome Atual: %s\n", lista_produtos[i].nome);
            printf("Preço Atual: R$ %.2f\n", lista_produtos[i].preco);
            imprimir_linha(34, '-'); //

            printf("Digite o novo nome: ");
            fgets(lista_produtos[i].nome, 50, stdin);

            lista_produtos[i].nome[strcspn(lista_produtos[i].nome, "\n")] = 0;

            printf("Digite a nova descrição: ");
            fgets(lista_produtos[i].descricao, 100, stdin);
            lista_produtos[i].descricao[strcspn(lista_produtos[i].descricao, "\n")] = 0;

            printf("Digite o novo preço: ");
            scanf("%f", &lista_produtos[i].preco);

            printf("Digite a nova quantidade: ");
            scanf("%d", &lista_produtos[i].quantidade);

            getchar();

            printf("\nProduto atualizado com sucesso!\n\n");
            break;
        }
    }
    if(encontrado == 0){
        printf("\nERRO: Produto com ID %d não encontrado.\n\n", id_busca);
    }
}

void screen_delete(void) {
    imprimir_linha(34, '=');
    printf("     | REMOÇÃO DE PRODUTOS |     \n");
    imprimir_linha(34, '=');
}

void remover_produto(Produto lista_produtos[], int *total_produtos){
    limpar_tela();
    screen_delete();
    if (*total_produtos == 0) {
        printf("\nNenhum produto cadastrado para remover.\n\n");
        return;
    }

    int id_busca;
    int achou_index = -1;

    printf("Digite o ID do produto que deseja remover: ");
    scanf("%d", &id_busca);
    getchar();

    for (int i = 0; i < *total_produtos; i++) {
        if (lista_produtos[i].id == id_busca) {
            achou_index = i;
            break;
        }
    }

    if (achou_index == -1) {
        printf("\nERRO: Produto com ID %d não encontrado.\n\n", id_busca);
        return;
    }

    for (int i = achou_index; i < (*total_produtos - 1); i++) {
        lista_produtos[i] = lista_produtos[i + 1];
    }
    (*total_produtos)--;

    printf("\nProduto removido com sucesso!\n\n");
}

void salvar_produtos(Produto lista_produtos[], int total_produtos) {
    FILE *file = fopen(ARQUIVO_ESTOQUE, "wb");

    if (file == NULL) {
        printf("ERRO CRÍTICO: Não foi possível abrir o arquivo para salvar!\n");
        printf("Seus dados NÃO foram salvos.\n");
        return;
    }
    fwrite(&total_produtos, sizeof(int), 1, file);
    fwrite(lista_produtos, sizeof(Produto), total_produtos, file);
    fclose(file);
}

void carregar_produtos(Produto lista_produtos[], int *total_produtos) {
    FILE *file = fopen(ARQUIVO_ESTOQUE, "rb");

    if (file == NULL) {
        *total_produtos = 0;
        return;
    }

    if (fread(total_produtos, sizeof(int), 1, file) != 1) {
        *total_produtos = 0;
        fclose(file);
        return;
    }

    fread(lista_produtos, sizeof(Produto), *total_produtos, file);
    fclose(file);
}
