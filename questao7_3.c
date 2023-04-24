#include <stdio.h>
#include <stdlib.h>

struct No {
    struct Fila *dados;
    struct No *prox;
};

struct Fila {
    int dados;
    struct Fila *prox;
};

struct FilaDeFilas {
    struct No *frente;
    struct No *tras;
};

void enfileira(struct Fila **fila, int item) {
    struct Fila *novo_no = (struct Fila*)malloc(sizeof(struct Fila));
    novo_no->dados = item;
    novo_no->prox = *fila;
    *fila = novo_no;
}

int desenfileira(struct Fila **fila) {
    if (*fila == NULL) {
        printf("Fila vazia\n");
        exit(1);
    }
    int item = (*fila)->dados;
    struct Fila *temp = *fila;
    *fila = (*fila)->prox;
    free(temp);
    return item;
}

void enfileiraFila(struct FilaDeFilas *fila_de_filas, struct Fila *fila) {
    struct No *novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->dados = fila;
    novo_no->prox = NULL;
    if (fila_de_filas->tras == NULL) {
        fila_de_filas->frente = fila_de_filas->tras = novo_no;
        return;
    }
    fila_de_filas->tras->prox = novo_no;
    fila_de_filas->tras = novo_no;
}

struct Fila* desenfileiraFila(struct FilaDeFilas *fila_de_filas) {
    if (fila_de_filas->frente == NULL) {
        printf("Fila de filas vazia\n");
        exit(1);
    }
    struct No *temp = fila_de_filas->frente;
    struct Fila *fila = temp->dados;
    fila_de_filas->frente = fila_de_filas->frente->prox;
    if (fila_de_filas->frente == NULL) {
        fila_de_filas->tras = NULL;
    }
    free(temp);
    return fila;
}

void enfileiraElemento(struct FilaDeFilas *fila_de_filas, int item) {
    if (fila_de_filas->tras == NULL || fila_de_filas->tras->dados == NULL) {
        struct Fila *fila = (struct Fila*)malloc(sizeof(struct Fila));
        fila->dados = item;
        fila->prox = NULL;
        enfileiraFila(fila_de_filas, fila);
    } else {
        enfileira(&fila_de_filas->tras->dados, item);
    }
}

int desenfileiraElemento(struct FilaDeFilas *fila_de_filas) {
    if (fila_de_filas->frente == NULL) {
        printf("Fila de filas vazia\n");
        exit(1);
    }
    int item = desenfileira(&fila_de_filas->frente->dados);
    if (fila_de_filas->frente->dados == NULL) {
        desenfileiraFila(fila_de_filas);
    }
    return item;
}

int main() {
    struct FilaDeFilas fila_de_filas;
    fila_de_filas.frente = fila_de_filas.tras = NULL;

    enfileiraElemento(&fila_de_filas, 1);
    enfileiraElemento(&fila_de_filas, 2);
    enfileiraElemento(&fila_de_filas,3);
        printf("%d\n", desenfileiraFila(&fila_de_filas));
    printf("%d\n", desenfileiraFila(&fila_de_filas));
    printf("%d\n", desenfileiraFila(&fila_de_filas));
    return 0;
}
