#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct Aluno
{
	int ra;
	char nome[100];
	float p1 = 0;
	float p2 = 0;
	float p3 = 0;
	float media;

}TAlunos;

TAlunos buscador(TAlunos alunos[TAM],int ra) 
{
	for (int i = 0; i < TAM; i++)
	{
		if (ra == alunos[i].ra)
		{
			return alunos[i];
		}
	}
}

int main()
{
	TAlunos alunos[TAM], aux;
	int maiorp1,maiorm,menorm;

	aux = alunos[0];
	
	strcpy(alunos[0].nome, "Isaque");
	alunos[0].ra = 56;
	alunos[0].p1 = 7.9;
	alunos[0].p2 = 6.3;
	alunos[0].p3 = 4.7;
	alunos[0].media = (alunos[0].p1 + alunos[0].p2 + alunos[0].p3) / 3;

	strcpy(alunos[1].nome, "Pedro");
	alunos[1].ra = 12;
	alunos[1].p1 = 2.9;
	alunos[1].p2 = 10;
	alunos[1].p3 = 6.8;
	alunos[1].media = (alunos[1].p1 + alunos[1].p2 + alunos[1].p3) / 3;

	strcpy(alunos[2].nome, "Ana");
	alunos[2].ra = 4;
	alunos[2].p1 = 1;
	alunos[2].p2 = 1;
	alunos[2].p3 = 1;
	alunos[2].media = (alunos[2].p1 + alunos[2].p2 + alunos[2].p3) / 3;

	strcpy(alunos[3].nome, "Lucas");
	alunos[3].ra = 90;
	alunos[3].p1 = 10;
	alunos[3].p2 = 5.4;
	alunos[3].p3 = 7.2;
	alunos[3].media = (alunos[3].p1 + alunos[3].p2 + alunos[3].p3) / 3;

	strcpy(alunos[4].nome, "Maria");
	alunos[4].ra = 45;
	alunos[4].p1 = 10;
	alunos[4].p2 = 10;
	alunos[4].p3 = 10;
	alunos[4].media = (alunos[4].p1 + alunos[4].p2 + alunos[4].p3) / 3;

	for (int i = 0; i < TAM; i++)
	{
		if (aux.p1 < alunos[i].p1)
		{
			maiorp1 = alunos[i].ra;
			aux = buscador(alunos, maiorp1);
		}

	}
	for (int i = 0; i < TAM; i++)
	{
		if (aux.media < alunos[i].media)
		{
			maiorm = alunos[i].ra;
			aux = buscador(alunos, maiorm);
		}
	}
	for (int i = 0; i < TAM; i++)
	{
		if (aux.media > alunos[i].media)
		{
			menorm = alunos[i].ra;
			aux = buscador(alunos, menorm);
		}
	}


	for (int i = 0; i < TAM; i++)
	{
		if (maiorp1 == alunos[i].ra) 
		{
			printf("Nome do aluno com a maior nota na p1: %s", alunos[i].nome);
		}
	}
	for (int i = 0; i < TAM; i++)
	{
		if (maiorm == alunos[i].ra)
		{
			printf("\nNome do aluno com a maior media: %s", alunos[i].nome);
		}
	}
	for (int i = 0; i < TAM; i++)
	{
		if (menorm == alunos[i].ra)
		{
			printf("\nNome do aluno com a menor media: %s", alunos[i].nome);
		}
	}



	return 0;
}