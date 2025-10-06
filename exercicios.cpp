#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escrita(FILE* arq, char* nome, int idade);
void leitura(FILE* arq, char* nome, int idade);



int main()
{
    char nome[30];
    int idade, erro;

    FILE* arq = NULL;

    
    
    printf("Digite um nome: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &idade);

    escrita(arq,nome,idade);
    leitura(arq,nome,idade);

    return 0;
}

void escrita(FILE* arq, char* nome, int idade)
{
    arq = fopen("arquivo.txt", "a");
    if (arq == NULL)
    {
        printf("erro no caminho do arquivo");
        exit(0);
    }
    else
    {
        fprintf(arq, "%s\t%d\n", nome, idade);
    }
    fclose(arq);
}

void leitura(FILE* arq, char* nome, int idade)
{
    arq = fopen("arquivo.txt", "r");
    if (arq == NULL)
    {
        printf("erro no caminho do arquivo");
        exit(0);
    }
    else
    {
        while (!feof(arq))
        {
            if (fscanf(arq, "%[^\t]\t%d\n", nome, &idade) != 2)
            {
                printf("\nERRO na leitura");
                exit(0);
            }
            printf("Nome : %s, idade: %d\n", nome, idade);
        }
        fclose(arq);
    }
}