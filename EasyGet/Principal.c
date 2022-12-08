#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Empresa.h"
#include "Produto.h"

// Função para ler a entrada do usuário
void ler_entrada(char* nome, char* senha) {
	printf("Insira o nome de usuário: ");
	scanf("%s", nome);
	printf("Insira a senha: ");
	scanf("%s", senha);
}

// Função para verificar se a entrada do usuário é válida
int verificar_entrada(char* nome, char* senha) {
	// Verifica se o nome de usuário e a senha são iguais a "admin"
	if (strcmp(nome, "admin") == 0 && strcmp(senha, "admin") == 0) {
		return 1; // Entrada válida
	}
	else {
		return 0; // Entrada inválida
	}
}

int main() {
	void center_print(const char* s, int width);
	char nome[100]; // Nome de usuário
	char senha[100]; // Senha
	int opcao;
	int sair = 2;
	char CNPJ[100];
	char email[100];
	char telefone[100];
	char cep[100];
	char bairro[100];
	char cidade[100];
	char nomeEmpresa[100];
	char preco[100];
	char estoque[100];
	char status[100];
	


	// Lê a entrada do usuário
	ler_entrada(nome, senha);

	// Verifica se a entrada é válida
	if (!verificar_entrada(nome, senha)) {
		printf("Nome de usuário ou senha inválidos.\n");

	}
	else {
		while (1)
		{

			printf("------------------------------------------------------------------------------------\n");
			center_print("EasyGet", 84);
			printf("------------------------------------------------------------------------------------\n\n");

			printf("Seja Bem Vindo, usuario %s\n", nome);
			printf("====================================================================================\n ");
			printf("1-Cadastrar empresa\n ");
			printf("2-Acessar empresa\n ");
			printf("3-Exibir empresa\n ");
			printf("4-Alterar empresa\n ");
			printf("5-Deletar empresa\n ");
			printf("6-Sair\n ");
			printf("------------------------------------------------------------------------------------\n\n");
			printf("\nQual opcao voce deseja acessar? ");
			scanf("%d", &opcao);


			switch (opcao)
			{
			case 1:
				printf("Digite os dados da empresa:\n");

				printf("Nome:");
				scanf(" %[^\n]s", nome);

				printf("CNPJ:");
				scanf(" %[^\n]s", CNPJ);

				printf("E-mail:");
				scanf(" %[^\n]s", email);

				printf("Telefone:");
				scanf(" %[^\n]s", telefone);

				printf("CEP:");
				scanf(" %[^\n]s", cep);

				printf("Bairro:");
				scanf(" %[^\n]s", bairro);
				
				printf("Cidade:");
			
				scanf(" %[^\n]s", cidade);

				adicionar_empresa(nome, CNPJ, email, telefone, cep, bairro, cidade);
				printf("\n");
				break;

			case 2:
				printf("Digite o nome da empresa:\n");
				scanf("%s", &nomeEmpresa);

				while (1)
				{
					printf("------------------------------------------------------------------------------------\n");
					center_print("EasyGet", 84);
					printf("------------------------------------------------------------------------------------\n\n");

					printf("Seja Bem Vindo, %s\n", nomeEmpresa);
					printf("====================================================================================\n ");
					printf("1-Cadastrar\n ");
					printf("2-Exibir Dados\n ");
					printf("3-Alterar\n ");
					printf("4-Excluir\n ");
					printf("5-Produtos\n ");
					printf("6-Sair\n");
					printf("------------------------------------------------------------------------------------\n\n");
					printf("\nQual opcao voce deseja acessar? ");
					scanf("%d", &opcao);

					switch (opcao)
					{
					case 1:

						printf("Digite os dados do cliente:\n");

						printf("Nome:");
						scanf(" %[^\n]s", nome);

						printf("E-mail:");
						scanf(" %[^\n]s", email);

						printf("Telefone:");
						scanf(" %[^\n]s", telefone);

						adicionar_cliente(nome, email, telefone);
						printf("\n");
						break;
					case 2:
						mostrar_cliente();
						printf("\n");
						system("pause");
						break;
					case 3:
						printf("Digite os dados do cliente:\n");

						printf("Nome:");
						scanf(" %[^\n]s", nome);

						printf("E-mail:");
						scanf(" %[^\n]s", email);

						printf("Telefone:");
						scanf(" %[^\n]s", telefone);

						atualizar_cliente(nome, email, telefone);
						printf("\n");
						break;
					case 4:
						printf("Digite o nome do cliente: ");

						scanf(" %[^\n]s", nome);
						deletar_cliente(nome);

						printf("\n");
						break;
					case 5:
						while (1)
						{
							printf("------------------------------------------------------------------------------------\n");
							center_print("EasyGet", 84);
							printf("------------------------------------------------------------------------------------\n\n");
							printf("Seja Bem Vindo, %s\n", nomeEmpresa);
							printf("====================================================================================\n ");
							printf("1-Cadastrar produto\n ");
							printf("2-Exibir dados do produto\n ");
							printf("3-Alterar dados do produto\n ");
							printf("4-Excluir produto\n ");
							printf("5-Sair\n");
							printf("------------------------------------------------------------------------------------\n\n");
							printf("\nQual opcao voce deseja acessar? ");
							scanf("%d", &opcao);

							switch (opcao)
							{
							case 1:
								printf("Digite os dados do produto:\n");

								printf("Nome:");
								scanf(" %[^\n]s", nome);

								printf("Preco:");
								scanf(" %[^\n]s", preco);

								printf("Estoque:");
								scanf(" %[^\n]s", estoque);

								printf("Status:");
								scanf(" %[^\n]s", status);

								adicionar_produto(nome, preco, estoque, status);
								printf("\n");
								break;
							case 2:
								mostrar_produto();
								printf("\n");
								system("pause");
								break;
							case 4:
								printf("Digite o nome do prooduto: ");

								scanf(" %[^\n]s", nome);
								deletar_produto(nome);

								printf("\n");
								break;
							case 5:
								printf(" 1- Sim\n 2- Nao");
								printf("\n Voce realmente deseja sair do sistema: ");
								scanf("%d", &sair);
								break;

							default:
								break;
							}
							if (sair == 1)
								break;
						
						}


					case 6:
						printf(" 1- Sim\n 2- Nao");
						printf("\n Voce realmente deseja sair do sistema: ");
						scanf("%d", &sair);
						break;
					default:
						
						break;
					}
					if (sair == 1)
						break;
				};
				
			case 3:
				mostrar_empresa();
				mostrar_produto();
				printf("\n");
				system("pause");
				break;

			case 4:
				printf("Digite os dados da empresa:\n");

				printf("Nome:");
				scanf(" %[^\n]s", nome);

				printf("CNPJ:");
				scanf(" %[^\n]s", CNPJ);

				printf("E-mail:");
				scanf(" %[^\n]s", email);

				printf("Telefone:");
				scanf(" %[^\n]s", telefone);

				printf("CEP:");
				scanf(" %[^\n]s", cep);

				printf("Bairro:");
				scanf(" %[^\n]s", bairro);

				printf("Cidade:");
				scanf(" %[^\n]s", cidade);

				atualizar_empresa(nome, CNPJ, email, telefone, cep, bairro, cidade);
				printf("\n");
				break;
			
			case 5:
				printf("Digite o nome da empresa: ");

				scanf(" %[^\n]s", nome);
				deletar_empresa(nome);

				printf("\n");
				break;

			case 6:
				printf(" 1- Sim\n 2- Nao");
				printf("\n Voce realmente deseja sair do sistema: ");
				scanf("%d", &sair);
				if (sair == 1) {
					printf("Volte sempre!");	
				}
				break;
			default:
				break;
			}
			fflush(stdin);



		}
	}

	return 0;
}

void center_print(const char* s, int width)
{
	int length = strlen(s);
	int i;
	for (i = 0; i <= (width - length) / 2; i++) {
		fputs(" ", stdout);
	}
	printf("%s\n", s);
}