#include <stdio.h>
#include <stdlib.h>
//fila de pilhas
struct Pilha {
    int dado;
    struct Pilha *proximo;
};

struct Fila {
    struct Pilha *entrada;
    struct Pilha *saida;
};

void push(struct Pilha **pilha, int item) {
    struct Pilha *novo_no = (struct Pilha*)malloc(sizeof(struct Pilha));
    novo_no->dado = item;
    novo_no->proximo = *pilha;
    *pilha = novo_no;
}

int pop(struct Pilha **pilha) {
    if (*pilha == NULL) {
        printf("Pilha vazia\n");
        exit(1);
    }
    int item = (*pilha)->dado;
    struct Pilha *temp = *pilha;
    *pilha = (*pilha)->proximo;
    free(temp);
    return item;
}

void enfileirar(struct Fila *fila, int item) {
    push(&fila->entrada, item);
}

int desenfileirar(struct Fila *fila) {
    if (fila->saida == NULL) {
        while (fila->entrada != NULL) {
            push(&fila->saida, pop(&fila->entrada));
        }
    }
    return pop(&fila->saida);
}

int main() {
    struct Fila fila;
    fila.entrada = fila.saida = NULL;

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);

    printf("%d\n", desenfileirar(&fila));
    printf("%d\n", desenfileirar(&fila));
    printf("%d\n", desenfileirar(&fila));

    return 0;
}
