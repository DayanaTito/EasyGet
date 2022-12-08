#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPRESAS 100
#define MAX_PRODUTOS 100

typedef struct {
    char nome[100];
    char preco[100];
    char estoque[100];
    char status[100];
} Produto;

Produto produtos[MAX_PRODUTOS];
int num_produtos = 0;

void adicionar_produto(char* nome, char* preco, char* estoque, char* status) {
    if (num_produtos >= MAX_PRODUTOS) {
        printf("Não é possível adicionar mais Produtos. A lista está cheia.\n");
        return;
    }

    strcpy(produtos[num_produtos].nome, nome);
    strcpy(produtos[num_produtos].preco, preco);
    strcpy(produtos[num_produtos].estoque, estoque);
    strcpy(produtos[num_produtos].status, status);
    num_produtos++;
}

void deletar_produto(char* nome) {
    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            for (int j = i; j < num_produtos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            num_produtos--;
            return;
        }
    }

    printf("Não foi possível encontrar o produto com o nome fornecido.\n");
}

void mostrar_produto() {
    for (int i = 0; i < num_produtos; i++) {

        printf("\n%s", produtos[i].nome);
        printf("\n%s", produtos[i].preco);
        printf("\n%s", produtos[i].estoque);
        printf("\n%s", produtos[i].status);
        
    }
}