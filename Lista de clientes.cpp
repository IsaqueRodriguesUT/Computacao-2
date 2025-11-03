#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
1faça um progama computacional em linguagem c que resolva o seguinte  problema:
voce esta criando um cadastro de clientes.Voce deve armazenar o primeiro cliente,solicitando as informações para o usuario
Os dados são:nome completo,telefone e endereço.
voce de criar uma opção para atualizar o cadastro desse usuario.ele diz qual dado quer atualizar.
*/
#define NDADOS 3

void menu(int* opcao);
void entrada(char** dados, char temp[100], int n);
void saida(char** dados);
void limpa(char** dados);

int main()
{
	char** dados = NULL, temp[100];
	int opcao = 0;

	dados = (char**)malloc(NDADOS * sizeof(char*));
	if (dados == NULL) {
		printf("\nErro de alocacao de memoria.\n");
		exit(0);
	}

	entrada(dados, temp, NULL);

	do {
		menu(&opcao);
		switch (opcao) {
		case 1:
			entrada(dados, temp, 1);
			printf("\n");
			break;

		case 2:
			entrada(dados, temp, 2);
			printf("\n");
			break;

		case 3:
			entrada(dados, temp, 3);
			printf("\n");
			break;

		case 0:
			printf("Saindo...\n");
			break;
		default:
			printf("Opção invalida! Tente novamente.\n");
			break;


		}

	} while (opcao != 0);


	limpa(dados);

	return 0;
}
void menu(int* opcao) {
	printf("=======================\n");
	printf("(1)Modificar nome\n");
	printf("(2)Modificar endereco\n");
	printf("(3)Modificar telefone\n");
	printf("(0)SAIR!\n");
	printf("=======================\n");
	scanf("%d", opcao);
	system("cls");
	getchar();

}

void entrada(char** dados,char temp[100],int n)
{
	if (n == NULL) {
		printf("Digite o Nome: ");
		fgets(temp, 100, stdin);
		dados[0] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(dados[0], temp);

		printf("Digite o Endereco: ");
		fgets(temp, 100, stdin);
		dados[1] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(dados[1], temp);

		printf("Digite o telefone: ");
		fgets(temp, 100, stdin);
		dados[2] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(dados[2], temp);
	}

	switch (n) {
	case 1:
		printf("Digite o Nome: ");
		fgets(temp, 100, stdin);
		dados[0] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(dados[0], temp);
		break;

	case 2:
		printf("Digite o Endereco: ");
		fgets(temp, 100, stdin);
		dados[1] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(dados[1], temp);
		break;

	case 3:
		printf("Digite o telefone: ");
		fgets(temp, 100, stdin);
		dados[2] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(dados[2], temp);
		break;

	}
		
	saida(dados);
}

void saida(char** dados)
{
	printf("Nome: %s", dados[0]);
	printf("Endereco: %s", dados[1]);
	printf("Telefone: %s", dados[2]);
}
void limpa(char** dados)
{
	for (int i = 0; i < NDADOS; i++) {
		free(dados[i]);
	}
	free(dados);
}
                                                                                                                                                                                             
