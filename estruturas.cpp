#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente
{
	char* nome = NULL;
	int telefone;
	char endereco[100];
}TCliente;

int main() 
{
	TCliente clientes[10];

	//alocação de memoria para o nome do cliente 0
	clientes[0].nome = (char*)malloc(sizeof(char) * 50);
	if (clientes[0].nome == NULL)
	{
		printf("Erro de alocação de memoria.");
		exit(0);
	}

	//atribuir dados ao cliente 0
	strcpy(clientes[0].nome, "Isaque Gab");
	clientes[0].telefone = 123456789;
	strcpy(clientes[0].endereco, "Ladislau");

	//mostra cliente 0
	printf("CLIENTE 0:");
	printf("\nNome: %s", clientes[0].nome);
	printf("\nTelefone: %d", clientes[0].telefone);
	printf("\nEndereco: %s\n", clientes[0].endereco);

	//copia cliente 0 para o cliente 1
	clientes[1] = clientes[0];
	
	//mostra client 1
	printf("\nCLIENTE 1:");
	printf("\nNome: %s", clientes[1].nome);
	printf("\nTelefone: %d", clientes[1].telefone);
	printf("\nEndereco: %s\n", clientes[1].endereco);

	//troca o nome do cliente 1 
	// mostrando o erro de usar o mesmo endereço de memoria
	strcpy(clientes[1].nome, "Rodrigo");

	//mostra cliente 0
	printf("\nCLIENTE 0:");
	printf("\nNome: %s", clientes[0].nome);
	printf("\nTelefone: %d", clientes[0].telefone);
	printf("\nEndereco: %s\n", clientes[0].endereco);

	//mostra cliente 1
	printf("\nCLIENTE 1:");
	printf("\nNome: %s", clientes[1].nome);
	printf("\nTelefone: %d", clientes[1].telefone);
	printf("\nEndereco: %s\n", clientes[1].endereco);

	//alocação de memoria para o nome do cliente 1
	clientes[1].nome = (char*)malloc(sizeof(char) * 50);
	if (clientes[1].nome == NULL)
	{
		printf("Erro de alocação de memoria.");
		exit(0);
	}

	strcpy(clientes[0].nome, "Isaque Gab");
	strcpy(clientes[1].nome, "Rodrigo");

	//mostra cliente 0
	printf("\nCLIENTE 0:");
	printf("\nNome: %s", clientes[0].nome);
	printf("\nTelefone: %d", clientes[0].telefone);
	printf("\nEndereco: %s\n", clientes[0].endereco);

	//mostra cliente 1
	printf("\nCLIENTE 1:");
	printf("\nNome: %s", clientes[1].nome);
	printf("\nTelefone: %d", clientes[1].telefone);
	printf("\nEndereco: %s\n", clientes[1].endereco);


	//libera a memoria
	free(clientes[0].nome);
	free(clientes[1].nome);

	return 0;
}