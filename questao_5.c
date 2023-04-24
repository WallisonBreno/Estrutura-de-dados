#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct no {
    char dado;
    struct no* prox;
};

void inserir(struct no** cabeca, char novo_dado) {
    struct no* novo_no = (struct no*)malloc(sizeof(struct no));
    novo_no->dado = novo_dado;
    novo_no->prox = (*cabeca);
    (*cabeca) = novo_no;
}

void imprimirLista(struct no* no_atual) {
    while (no_atual != NULL) {
        printf("%c", no_atual->dado);
        no_atual = no_atual->prox;
    }
    printf("\n");
}

void inverterConsoantes(struct no** cabeca) {
    struct no* anterior = NULL;
    struct no* atual = (*cabeca);
    while (atual != NULL) {
        if (isalpha(atual->dado) && !islower(atual->dado) && !strchr("AEIOUaeiou", atual->dado)) {
            struct no* temp = atual;
            atual = atual->prox;
            temp->prox = NULL;
            if (anterior == NULL) {
                (*cabeca) = atual;
            } else {
                anterior->prox = atual;
            }
            struct no* fim = temp;
            while (atual != NULL && isalpha(atual->dado) && !islower(atual->dado) && !strchr("AEIOUaeiou", atual->dado)) {
                fim->prox = atual;
                fim = atual;
                atual = atual->prox;
                fim->prox = NULL;
            }
            struct no* inicio = NULL;
            struct no* atual2 = temp;
            while (atual2 != NULL) {
                if (isalpha(atual2->dado) && !islower(atual2->dado) && !strchr("AEIOUaeiou", atual2->dado)) {
                    struct no* temp2 = atual2;
                    atual2 = atual2->prox;
                    temp2->prox = NULL;
                    if (inicio == NULL) {
                        inicio = atual2;
                    }
                    struct no* temp3 = inicio;
                    while (temp3 != NULL && temp3->prox != NULL) {
                        temp3 = temp3->prox;
                    }
                    if (temp3 == NULL) {
                        temp3 = temp2;
                    } else {
                        temp3->prox = temp2;
                    }
                } else {
                    if (inicio == NULL) {
                        inicio = atual2;
                    }
                    atual2 = atual2->prox;
                }
            }
            fim->prox = inicio;
            if (anterior == NULL) {
                (*cabeca) = temp;
            } else {
                anterior->prox = temp;
            }
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

int main() {
    struct no* cabeca = NULL;
    char c;
    while ((c = getchar()) != '\n') {
        inserir(&cabeca, c);
    }
    inverterConsoantes(&cabeca);
    imprimirLista(cabeca);
    return 0;
}
