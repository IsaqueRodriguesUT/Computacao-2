#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


#define TAM 30


int main()
{
	char nome1[TAM], nome2[TAM], nome3[TAM],temp[TAM];

	printf("Digite o primeiro nome: ");
	gets_s(&nome1[0], 29);

	printf("Digite o segundo nome: ");
	gets_s(&nome2[0], 29);

	printf("Digite o terceiro nome: ");
	gets_s(&nome3[0], 29);

	if (nome2[0] < nome1[0]) {
		strcpy(temp, nome1);
		strcpy(nome1, nome2);
		strcpy(nome2, temp);
	}

	if (nome3[0] < nome1[0]) {
		strcpy(temp, nome1);
		strcpy(nome1, nome3);
		strcpy(nome3, temp);
	}
	if (nome3[0] < nome2[0]) {
		strcpy(temp, nome2);
		strcpy(nome2, nome3);
		strcpy(nome3, temp);
	}

	printf("%s\n", nome1);
	printf("%s\n", nome2);
	printf("%s", nome3);

	return 0;
}
