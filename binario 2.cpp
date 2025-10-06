#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitura(FILE* arq, char nome[3][100], char cpf[3][16]);
void gravar(FILE* arq, char nome[3][100], char cpf[3][16]);

int main()
{
    char nome[3][100],cpf[3][16];
    int i = 0;
    FILE* arq = NULL;

    for (i = 0; i < 3; i++)
    {
        printf("Digite ssso %d nome: ",i);
        fgets(nome[i], 100, stdin);
        printf("Digite o %d cpf: ",i);
        fgets(cpf[i], 16, stdin);
    }

    gravar(arq, nome,cpf);
    
    memset(nome, 0, sizeof(nome));
    memset(cpf, 0, sizeof(cpf));

    printf("-------antes de ler---------\n");
    for (i = 0; i < 3; i++)
    {
        //para conferir se as variaveis não ter valor
        printf("\nNome %d: %s", i, nome[i]);
        printf("\nCPF %d: %s", i, cpf[i]);
    }
    leitura(arq, nome, cpf);
    
    printf("-------depois de ler---------\n");
    for (i = 0; i < 3; i++)
    {
        
        printf("Nome %d: %s",i+1,nome[i]);
        printf("CPF %d: %s", i+1, cpf[i]);
    }

    return 0;
}
void leitura(FILE* arq, char nome[3][100], char cpf[3][16])
{
    int i = 0;

    arq = fopen("binario.bin", "rb");
    if (arq != NULL)
    {
        printf("\narquivo aberto\n");
        for (i = 0; i < 3; i++)
        {
            fread(nome[i], sizeof(char), 100, arq);
            fread(cpf[i], sizeof(char), 16, arq);
        }
        fclose(arq);
    }
    else
        printf("Problema de abertura");
}
void gravar(FILE* arq, char nome[3][100], char cpf[3][16])
{
    int i = 0;
    arq = fopen("binario.bin", "wb");
    if (arq != NULL)
    {
        printf("\narquivo aberto\n");
        for (i = 0; i < 3; i++)
        {
            fwrite(nome[i], sizeof(char), 100, arq);
            fwrite(cpf[i], sizeof(char), 16, arq);
        }
        fclose(arq);
    }
    else
        printf("Problema de abertura");
}

