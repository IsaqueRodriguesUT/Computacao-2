#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *proximo;
}No;

void inserir(No** fila, int n)
{
	No *aux,*novo = (No*) malloc(sizeof(No));

	if (novo)
	{
		novo->valor = n;
		novo->proximo = NULL;
		if (*fila == NULL)
			*fila = novo;
		else
		{
			aux = *fila;
			while (aux->proximo)
				aux = aux->proximo;
			aux->proximo = novo;
		}
	}
	else
		printf("\nErro ao alocar memoiria\n");
}

No* remover(No** fila)
{
	No* remove = NULL;

	if (*fila)
	{
		remove = *fila;
		*fila = remove->proximo;
	}
	else
		printf("\nfila vazia.\n");
	return remove;

}

void inverte(No **fila)
{
	No *atual = *fila,*proximo = NULL, *anterior = NULL;

	if (*fila)
	{
		while (atual)
		{
			proximo = atual->proximo;
			atual->proximo = anterior;
			anterior = atual;
			atual = proximo;
		}

		*fila = anterior;
	}
	else
		printf("\nfila vazia.\n");

}

void exibir(No* fila)
{
	printf("\n---------- FILA ----------\n");
	while (fila)
	{
		printf("%d ",fila->valor);
		fila = fila->proximo;
	}
	printf("\n---------- FILA ----------\n");
}

int main()
{
	No *removida,*fila = NULL;
	int p,n;
	do
	{
		printf("\t0 - Sair\n\t1 - adicionar\n\t2 - remover\n\t3 - exibir\n\t4 - inverte fila\n\topcao escolhida: ");
		scanf("%d",&p);

		switch (p) {
		case 1:
			printf("\ndigite um valor para adicionar");
			scanf("%d", &n);
			inserir(&fila,n);
			break;
		case 2:
			removida = remover(&fila);
			if (removida)
			{
				printf("\nValor removido %d",removida->valor);
				free(removida);
			}
			break;
		case 3:
			exibir(fila);
			break;
		case 4:
			inverte(&fila);
			break;
		default:
			printf("\nopcao invalida");
		}

	} while (p != 0);



	return 0;
}