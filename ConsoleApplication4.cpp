#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipo_produto
{
	int codigo; // Código do produto
	double preco; // Preço do produto
	struct tipo_produto* proximo; /* Próximo
	elemento da lista encadeada de Produtos */
} TProduto;

void listar(TProduto* noatual);
void inserir(TProduto** cabeca);
void remover(TProduto** cabeca);
void buscar_por_id(TProduto* noatual);
TProduto* buscador(TProduto** cabeca, int id);
void remover_ultimo(TProduto** cabeca);
void remover_primeiro(TProduto** cabeca);


int main()
{

	/* Ponteiro para a cabeca da lista */
	TProduto* cabeca = NULL;
	TProduto* noatual; /* Ponteiro a ser usado para
	percorrer a lista no momento de desalocar seus
	elementos*/
	char q; // Caractere para receber a opção do usuário
	do {
		printf("\n\nOpcoes: \nI -> para inserir novoproduto; \nL->para listar os produtos; \nP->para remover um item \nS->para sair. \nDigite a sua opcao : ");
		scanf("%c", &q); /* Le a opção do usuário */
		switch (q)
		{
		case 'i': case 'I':
			inserir(&cabeca);
			break;
		case 'l': case 'L':
			listar(cabeca);
			break;
		case 'P': case 'p':
			remover(&cabeca);
			break;
		case 's': case 'S':
			break;
		default:
			printf("\n\n Opcao invalida");
		}
		getchar(); /* Limpa o buffer de entrada */
	} while ((q != 's') && (q != 'S'));
	/* Desaloca a memória que foi alocada para
os elementos da lista */
	noatual = cabeca;
	while (noatual != NULL)
	{
		cabeca = noatual->proximo;
		free(noatual);
		noatual = cabeca;
	}


	return 0;
}

void listar(TProduto* noatual)
{
	int i = 0;
	printf("\n ------------------");
	/* Enquanto não chega no fim da lista */
	while (noatual != NULL)
	{
		i++;
		printf("\n\nProduto numero %d\n", i);
		printf("Codigo: %d\n", noatual->codigo);
		printf("Preco:R$%.2lf\n", noatual->preco);
		printf("endereco: %p\n", noatual->proximo);
		noatual = noatual->proximo;
		/* Faz noatual apontar para o próximo nó */
	}
	printf("\n\n ------------------");
}

void inserir(TProduto** cabeca)
{
	TProduto* noatual, * novono;
	int cod;
	double preco;
	printf("\n Codigo do novo produto: ");
	scanf("%d", &cod);
	printf("\n Preco do produto:R$");
	scanf("%lf", &preco);
	/* Se ainda não existe nenhum produto na lista */
	if (*cabeca == NULL)
	{/* cria o nó cabeça */
		*cabeca = (TProduto*)malloc(sizeof(TProduto));
		(*cabeca)->codigo = cod;
		(*cabeca)->preco = preco;
		(*cabeca)->proximo = NULL;
	}
	else
	{ /* Se já existem elementos na lista, deve percorre-la até o
	seu final e inserir o novo elemento */
		noatual = *cabeca;
		/* Ao final do while noatual aponta para o ultimo nó */
		while (noatual->proximo != NULL)
			noatual = noatual->proximo;
		/* Aloca memória para o novo nó */
		novono = (TProduto*)malloc(sizeof(TProduto));
		novono->codigo = cod;
		novono->preco = preco;
		novono->proximo = NULL;
		/* Faz o ultimo nó apontar para o novo nó */
		noatual->proximo = novono;
	}
}

TProduto* buscador(TProduto* cabeca, int id)
{
	TProduto* noatual = cabeca;

	while (noatual != NULL)
	{
		if (noatual->codigo == id)
		{
			return noatual;
		}
		noatual = noatual->proximo;
	}
	printf("\n-----------Produto nao encontrado-----------\n");
	return NULL;
}

void buscar_por_id(TProduto *cabeca)
{
	int id;
	printf("Digite o codigo do Produto: ");
	scanf("%d", &id);

	TProduto* noatual = buscador(cabeca,id);
	if (noatual != NULL)
	{
		printf("\n ------------------\n");
		printf("\nCodigo: %d\n", noatual->codigo);
		printf("Preco:R$%.2lf", noatual->preco);
		printf("\n\n ------------------");
	}
}

void remover(TProduto** cabeca)
{
	char q;

	do {
		printf("\n-----------------");
		printf("\nOpcoes:");
		printf("\nI -> remover o primeiro produto");
		printf("\nL -> remover o ultimo produto");
		printf("\nP -> buscar por codigo");
		printf("\nS -> voltar ao menu principal");
		printf("\nDigite sua opcao: ");

		scanf(" %c", &q); 

		switch (q)
		{
		case 'i': case 'I':
			remover_primeiro(cabeca);
			break;

		case 'l': case 'L':
			remover_ultimo(cabeca);
			break;

		case 'p': case 'P':
			buscar_por_id(*cabeca);
			break;

		case 's': case 'S':
			return;   
		default:
			printf("\nOpcao invalida\n");
		}

	} while (1);

}

void remover_primeiro(TProduto** cabeca)
{
	if (*cabeca != NULL) 
	{
		TProduto* temp = *cabeca;  
		*cabeca = (*cabeca)->proximo;  
		free(temp);  
	}
	else
	{
		printf("A lista está vazia!\n");
	}
}

void remover_ultimo(TProduto** cabeca)
{
	if (*cabeca == NULL)  
	{
		printf("A lista está vazia!\n");
		return;
	}

	// Se a lista tem apenas um nó
	if ((*cabeca)->proximo == NULL)
	{
		free(*cabeca);  
		*cabeca = NULL;  
	}
	else
	{
		TProduto* noatual = *cabeca, *penultimo = NULL;

		while (noatual->proximo != NULL)
		{
			penultimo = noatual;
			noatual = noatual->proximo;
		}

		free(noatual); 
		penultimo->proximo = NULL;
	}
}

void remover_por_id(TProduto** cabeca)
{
	if (*cabeca == NULL)
	{
		printf("\nA lista está vazia!\n");
		return;
	}

	int id;
	printf("Digite o codigo do produto que deseja remover: ");
	scanf("%d", &id);

	// 1. usa o buscador para achar o nó
	TProduto* alvo = buscador(*cabeca, id);

	if (alvo == NULL)
	{
		printf("\nProduto nao encontrado!\n");
		return;
	}


	if (*cabeca == alvo)
	{
		*cabeca = alvo->proximo;
		free(alvo);
		printf("\nProduto removido com sucesso!\n");
		return;
	}

	TProduto* anterior = *cabeca;

	while (anterior->proximo != alvo)
	{
		anterior = anterior->proximo;
	}

	anterior->proximo = alvo->proximo;
	free(alvo);

	printf("\nProduto removido com sucesso!\n");
}