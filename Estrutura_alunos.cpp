#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

typedef struct Aluno
{
	int ra;
	char nome[100];
	float p1;
	float p2;
	float p3;
	float media;

}TAlunos;

TAlunos buscador(TAlunos alunos[TAM], int ra)
{
	for (int i = 0; i < TAM; i++)
	{
		if (ra == alunos[i].ra)
		{
			return alunos[i];
		}
	}
	TAlunos vazio = { 0 };
	return vazio;
}

void entrada(TAlunos alunos[TAM])
{
	for (int i = 0;i< TAM;i++)
	{
		printf("Digite o nome do aluno: ");
		fgets(alunos[i].nome, 100, stdin);

		printf("Digite o R.A do aluno: ");
		scanf("%d",&alunos[i].ra);

		printf("Digite a primeira nota do aluno: ");
		scanf("%f",&alunos[i].p1);

		printf("Digite a segunda nota do aluno: ");
		scanf("%f",&alunos[i].p2);

		printf("Digite a terceira nota do aluno: ");
		scanf("%f",&alunos[i].p3);
		getchar();
	}
}

void media(TAlunos* alunos)
{
	for (int i = 0;i < TAM;i++)
	{
		alunos[i].media = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3) / 3;
	}
}

int main()
{
	TAlunos alunos[TAM], aux;
	int maiorp1, maiorm, menorm;
	
	entrada(alunos);
	media(alunos);
	maiorp1 = alunos[0].ra;
	maiorm = alunos[0].ra;
	menorm = alunos[0].ra;
	aux = alunos[0];

	for (int i = 0; i < TAM; i++)
	{
		if (aux.p1 < alunos[i].p1)
		{
			maiorp1 = alunos[i].ra;
			aux = alunos[i];
		}
		
	}
	aux = alunos[0];
	for (int i = 0; i < TAM; i++)
	{
		if (aux.media < alunos[i].media)
		{
			maiorm = alunos[i].ra;
			aux = alunos[i];
		}
	}
	aux = alunos[0];
	for (int i = 0; i < TAM; i++)
	{
		if (aux.media > alunos[i].media)
		{
			menorm = alunos[i].ra;
			aux = alunos[i];
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
