//Isaque Gabriel Hellvig Rodrigues R.A: a2753103

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TAM 5

typedef struct {
    int dados[MAX];
    int topo1; 
    int topo2;
} Pilha;

void inicializar(Pilha* p) 
{
    p->topo1 = -1;
    p->topo2 = 4;
}

int pilhaVazia(Pilha* p,int q) 
{
    if (q == 1)
        return (p->topo1 == -1);
    else
        return (p->topo2 == 4);
}

int pilhaCheia(Pilha* p, int q) 
{
    if (q == 1)
        return (p->topo1 == TAM - 1);
    else
        return (p->topo2 == MAX - 1);
}

void push(Pilha* p, int valor,int q) 
{
    
    if (q == 1)
    {
        if (pilhaCheia(p, q))
        {
            printf("\n----------------A pilha esta cheia!----------------\n");
            return;
        }
        p->dados[++p->topo1] = valor;
    }
    else
    {
        if (pilhaCheia(p, q))
        {
            printf("\n----------------A pilha esta cheia!----------------\n");
            return;
        }
        p->dados[++p->topo2] = valor;
    }
}

int pop(Pilha* p,int q) {
    if (q == 1)
    {
        if (pilhaVazia(p, q)) {
            printf("\n----------------A pilha esta vazia!----------------\n");
            return -1;
        }
        return p->dados[p->topo1--];
    }
    else
    {
        if (pilhaVazia(p, q)) {
            printf("\n----------------A pilha esta vazia!----------------\n");
            return 4;
        }
        return p->dados[p->topo2--];
    }
}

void exibir(Pilha* p) {

    printf("\n--- PILHA 1 ---\n");
    for (int i = p->topo1; i >= 0; i--)
        printf("%d\n", p->dados[i]);
    printf("-------------\n");
    printf("\n--- PILHA 2 ---\n");
    for (int i = p->topo2; i >= 5; i--)
        printf("%d\n", p->dados[i]);
    printf("-------------\n");
}


int main()
{
    Pilha p;
    inicializar(&p);

    int q, valor;

    do {
        printf("\t0 - sair\n\t1 - preencher automatico\n\t2 - inserir elemento\n\t3 - remover elemento\n");
        scanf("%d", &q);

        switch (q)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                push(&p, i, 1);
                push(&p, i, 2);
            }
            break;
        case 2:
            printf("\nDigite a fila que voce deseja modificar (1 ou 2): ");
            scanf("%d",&q);
            getchar();
            printf("\nDigite o valor a adicionar: ");
            scanf("%d",&valor);
            push(&p,valor,q);
            break;
        case 3:
            printf("\nDigite a fila que voce deseja modificar (1 ou 2): ");
            scanf("%d", &q);
            valor = pop(&p,q);
            break;
        }
        exibir(&p);

    } while (q != 0);


    return 0;
}
