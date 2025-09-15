#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
1.Uma função para alocar dinamicamente uma string com um tamanho definido pelo usuario
2.leia a string e a coloque no vetor alocado no item 1
3.uma função que mostrea strng na tela
4.Uma função de libere o espaço de memória alocado para a string antes de
encerrar o programa.
*/

void aloca_str(char** nome, int tam);
void mostra_str(char** nome);
void libera_str(char** nome);


int main()
{
	char* nome = NULL;
	int tam;

	printf("Digite o tamanho da string: ");
	scanf("%d", &tam);

	aloca_str(&nome, tam);
	mostra_str(&nome);
	libera_str(&nome);
	

	return 0;
}

void aloca_str(char** nome, int tam)
{

	tam += 1; //Inclui o \0

	*nome = (char*)malloc(tam * sizeof(char));// alocar dinamicamente 

	if (*nome == NULL)
	{
		printf("Erro na alocação de memoria!!");
		exit(0);
	}

	printf("Digite um nome com o tamanho digitado a cima: ");
	getchar();
	fgets(*nome, tam, stdin);
}

void mostra_str(char** nome)
{
	printf("Nome alocado: %s\n", *nome);
}

void libera_str(char** nome)
{
	free(*nome);
}