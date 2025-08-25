//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ML 3
#define MC 2

//prenche a matriz com número aleatorio de 1 a 9
void preencheMatriz(int mat[ML][MC], int LINHA, int COLUNA) {
	for (int i = 0; i < LINHA; i++) {
		for (int j = 0; j < COLUNA; j++) {
			mat[i][j] = (rand() % 9 + 1) * 10;
		}
	}
}

//Pede ao usuario atribuir valor a matriz
/*void preencheMatriz(int mat[ML][MC], int LINHA, int COLUNA) {
	int n;
	for (int i = 0; i < LINHA; i++) {
		for (int j = 0; j < COLUNA; j++) {
			//scanf_s("%d", &mat[i][j]);
		}
	}
}*/

void imprimeMatriz(int mat[ML][MC], int LINHA, int COLUNA) {
	for (int i = 0; i < LINHA; i++) {
		for (int j = 0; j < COLUNA; j++) {
			printf("%2d ", mat[i][j]);
		}
		printf("\n");
	}
}

void somaMatriz(int mat[ML][MC],int LINHA,int COLUNA,int* soma) {
	for (int i = 0; i < LINHA; i++) {
		for (int j = 0; j < COLUNA; j++) {
			*soma += mat[i][j];
		}
	}
	printf("Soma dos termos da matriz: %d",*soma);
}

int main()
{
	srand(time(NULL));
	int mat[3][2], soma = 0;


	preencheMatriz(mat,ML,MC);
	imprimeMatriz(mat,ML,MC);
	somaMatriz(mat,ML,MC,&soma);

}

