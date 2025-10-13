//Isaque Gabriel Hellvig Rodrigues R.A: a2753103

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *arq = NULL;
    int linha, coluna, nlinha, ncoluna, anuladas;
    int** mat = NULL;

   arq = fopen("matriz.txt", "r");

    if (arq == NULL)
    {
        printf("erro no caminho do arquivo");
        exit(0);
    }
    else
    {
        //l� a primeira linha, onde contem o tamanho da matriz e quantas anuladas
            if (fscanf(arq, "%d %d %d\n", &nlinha, &ncoluna, &anuladas) != 3)
            {
                printf("\nERRO na leitura");
                exit(0);
            }

            mat = (int**)malloc(nlinha * sizeof(int*));

            for (int i = 0; i < nlinha; i++)
            {
                mat[i] = (int*)malloc(ncoluna * sizeof(int));
            }
            for (int i = 0; i < nlinha; i++) {
                for (int j = 0; j < ncoluna; i++) {
                    mat[i][j] = 1;
                }
            }
  
            //uma la�o for para ler quais ser�o anuladas
                for (int i = 0; i < anuladas; i++)
            {
                if (fscanf(arq, "%d %d\n", &linha, &coluna) != 2)
                {
                    printf("\nERRO na leitura");
                    exit(0);
                }
                else {
                    mat[linha][coluna] = 0;
                }
            }
        }
	fclose(arq);
    arq =fopen("matriz_saida.txt", "+");

    for (int i = 0; i < nlinha; i++) {
        for (int j = 0; j < ncoluna; i++) {
            fprintf(arq, "%d ",mat[i][j]);
        }
        fprintf(arq,"\n");
    }

    fclose(arq);

    for (int i = 0; i < linha; i++) {
        free(mat[i]);
    }
    free(mat);

	return 0;
}