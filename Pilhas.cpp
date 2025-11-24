#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int dados[MAX];
    int topo; // índice do último elemento
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

int pilhaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

void push(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("\nA pilha está cheia!\n");
        return;
    }
    p->dados[++p->topo] = valor;
}

int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("\nA pilha está vazia!\n");
        return -1;
    }
    return p->dados[p->topo--];
}

void exibir(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("\nPilha vazia.\n");
        return;
    }
    printf("\n--- PILHA ---\n");
    for (int i = p->topo; i >= 0; i--)
        printf("%d\n", p->dados[i]);
    printf("-------------\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    int op, n;

    do {
        printf("\n0 - Sair\n1 - Push\n2 - Pop\n3 - Exibir\nEscolha: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Valor para empilhar: ");
            scanf("%d", &n);
            push(&p, n);
            break;
        case 2:
            n = pop(&p);
            if (n != -1)
                printf("Removido: %d\n", n);
            break;
        case 3:
            exibir(&p);
            break;
        }
    } while (op != 0);

    return 0;
}
