#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100

// Define os tipos de dados para clientes
typedef struct {
    char nome[100];
    char email[100];
    char telefone[100];
} Cliente;


// Cria as listas para armazenar os clientes e produtos
Cliente clientes[MAX_CLIENTES];
int num_clientes = 0;

// Define as funções para adicionar, deletar, atualizar e exibir clientes e produtos
void adicionar_cliente(char* nome, char* email, char* telefone) {
    if (num_clientes >= MAX_CLIENTES) {
        printf("Não é possível adicionar mais clientes. Lista está cheia.\n");
        return;
    }

    strcpy(clientes[num_clientes].nome, nome);
    strcpy(clientes[num_clientes].email, email);
    strcpy(clientes[num_clientes].telefone, telefone);
    num_clientes++;
}

void deletar_cliente(char* nome) {
    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            for (int j = i; j < num_clientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            num_clientes--;
            return;
        }
    }

    printf("Não foi possível encontrar o cliente com o nome fornecido.\n");
}

void atualizar_cliente(char* nome, char* email, char* telefone) {
    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            strcpy(clientes[i].email, email);
            strcpy(clientes[i].telefone, telefone);
            return;
        }
    }

    printf("Não foi possível encontrar o cliente com o nome fornecido.\n");
}

void mostrar_cliente() {
    for (int i = 0; i < num_clientes; i++) {
     
        printf("\n%s", clientes[i].nome);
        printf("\n%s", clientes[i].email);
        printf("\n%s", clientes[i].telefone);
    }

}