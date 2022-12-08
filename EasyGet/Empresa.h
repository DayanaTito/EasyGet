#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_EMPRESAS 100
#define MAX_PRODUTOS 100

// Define os tipos de dados para clientes
typedef struct {
    char nome[100];
    char CNPJ[100];
    char email[100];
    char telefone[100];
    char cep[100];
    char bairro[100];
    char cidade[100];
   
} Empresa;


// Cria as listas para armazenar os clientes e produtos
Empresa empresas[MAX_EMPRESAS];
int num_empresas = 0;

// Define as funções para adicionar, deletar, atualizar e exibir clientes e produtos
void adicionar_empresa(char* nome, char* CNPJ, char* email, char* telefone, char* cep, char* bairro, char* cidade) {
    if (num_empresas >= MAX_EMPRESAS) {
        printf("Não é possível adicionar mais Empresas. A lista está cheia.\n");
        return;
    }

    strcpy(empresas[num_empresas].nome, nome);
    strcpy(empresas[num_empresas].CNPJ, CNPJ);
    strcpy(empresas[num_empresas].email, email);
    strcpy(empresas[num_empresas].telefone, telefone);
    strcpy(empresas[num_empresas].cep, cep);
    strcpy(empresas[num_empresas].bairro, bairro);
    strcpy(empresas[num_empresas].cidade, cidade);


    num_empresas++;
}

void deletar_empresa(char* nome) {
    for (int i = 0; i < num_empresas; i++) {
        if (strcmp(empresas[i].nome, nome) == 0) {
            for (int j = i; j < num_empresas - 1; j++) {
                empresas[j] = empresas[j + 1];
            }
            num_empresas--;
            return;
        }
    }

    printf("Não foi possível encontrar a empresa com o nome fornecido.\n");
}

void atualizar_empresa(char* nome, char* CNPJ, char* email, char* telefone, char* cep, char* bairro, char* cidade) {
    for (int i = 0; i < num_empresas; i++) {
        if (strcmp(empresas[i].nome, nome) == 0) {
            strcpy(empresas[i].CNPJ, CNPJ);
            strcpy(empresas[i].email, email);
            strcpy(empresas[i].telefone, telefone);
            strcpy(empresas[i].cep, cep);
            strcpy(empresas[i].bairro, bairro);
            strcpy(empresas[i].cidade, cidade);
            return;
        }
    }

    printf("Não foi possível encontrar o cliente com o nome fornecido.\n");
}

void mostrar_empresa() {
    for (int i = 0; i < num_empresas; i++) {

        printf("\n%s", empresas[i].nome);
        printf("\n%s", empresas[i].CNPJ);
        printf("\n%s", empresas[i].email);
        printf("\n%s", empresas[i].telefone);
        printf("\n%s", empresas[i].cep);
        printf("\n%s", empresas[i].bairro);
        printf("\n%s", empresas[i].cidade);
    }

};
