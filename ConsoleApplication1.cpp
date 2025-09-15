#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* vet = NULL;
	int* aux;
	
	vet = (int*) malloc(5 * sizeof(int));

	aux = vet;
	if (vet == NULL)
	{
		printf("\nProblema ao alocar memoria");
		return 0;
	}

	aux = vet;
	for (int i = 1; i < 6; i++)
	{
		*vet = i;
		vet++;

	}

	
	aux = (int*) realloc(aux, 10 * sizeof(int));
	vet = aux;

	for (int i = 1; i < 6; i++)
		vet++;

	for (int i = 6; i < 11; i++)
	{
		*vet = i;
		vet++;

	}

	vet = aux;

	printf("VETOR: [%d %d %d %d %d %d %d %d %d %d]",vet[0], vet[1], vet[2], vet[3], vet[4], vet[5], vet[6], vet[7], vet[8], vet[9]);

	free(vet);
	return 0;
}
