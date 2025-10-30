#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_PRODUTOS 100

typedef struct{
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

void limpar_tela(void);
void pular_linha(void);
void visualizar_tela(void);
void imprimir_linha(int tamanho, char caractere);

void screen_create(void);
void screen_read(void);
void screen_update(void);
void screen_delete(void);

void adicionar_produto(Produto lista_produtos[], int *total_produtos);
void mostrar_produto(Produto lista_produtos[], int total_produtos);
void atualizar_produto(Produto lista_produtos[], int total_produtos);
void remover_produto(Produto lista_produtos[], int *total_produtos);
#endif // FUNCTIONS_H
