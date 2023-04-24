#include <stdio.h>
#include <stdlib.h>

struct Fila {
    int data;
    struct Fila *prox;
};

struct Pilha {
    struct Fila *fila1;
    struct Fila *fila2;
};

void enfileirar(struct Fila **fila, int item) {
    struct Fila *novo = (struct Fila*)malloc(sizeof(struct Fila));
    novo->data = item;
    novo->prox = *fila;
    *fila = novo;
}

int desenfileirar(struct Fila **fila) {
    if (*fila == NULL) {
        printf("Fila vazia\n");
        exit(1);
    }
    int item = (*fila)->data;
    struct Fila *temp = *fila;
    *fila = (*fila)->prox;
    free(temp);
    return item;
}

void empilhar(struct Pilha *pilha, int item) {
    enfileirar(&pilha->fila1, item);
}

int desempilhar(struct Pilha *pilha) {
    if (pilha->fila1 == NULL) {
        printf("Pilha vazia\n");
        exit(1);
    }
    while (pilha->fila1->prox != NULL) {
        enfileirar(&pilha->fila2, desenfileirar(&pilha->fila1));
    }
    int item = desenfileirar(&pilha->fila1);
    while (pilha->fila2 != NULL) {
        enfileirar(&pilha->fila1, desenfileirar(&pilha->fila2));
    }
    return item;
}

int main() {
    struct Pilha pilha;
    pilha.fila1 = pilha.fila2 = NULL;

    empilhar(&pilha, 1);
    empilhar(&pilha, 2);
    empilhar(&pilha, 3);

    printf("%d\n", desempilhar(&pilha));
    printf("%d\n", desempilhar(&pilha));
    printf("%d\n", desempilhar(&pilha));

    return 0;
}
