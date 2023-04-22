#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definição da estrutura de pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Inicializa a pilha
void initialize(Stack *s) {
    s->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Insere um elemento na pilha
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Erro: pilha cheia\n");
        exit(EXIT_FAILURE);
    }

    s->items[++s->top] = item;
}

// Remove um elemento da pilha
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }

    return s->items[s->top--];
}

// Retorna o elemento do topo da pilha
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }

    return s->items[s->top];
}

int main() {
    // Inicializa as pilhas A, B e C
    Stack a, b, c;
    initialize(&a);
    initialize(&b);
    initialize(&c);

    // Insere as caixas na pilha A (para teste, insere-se em ordem decrescente de peso)
    push(&a, 7);
    push(&a, 5);
    push(&a, 3);

    // Insere uma nova caixa na pilha A
    int newBox = 5;
    if (newBox > peek(&a)) {
        // Move todas as caixas da pilha A para as pilhas auxiliares B e C
        while (!isEmpty(&a) || peek(&a) == 7) {
            if (peek(&a) == 5) {
                push(&b, pop(&a));
            } else if (peek(&a) == 3) {
                push(&c, pop(&a));
            } else {
                break;
            }
        }

        // Insere a nova caixa na pilha A
        push(&a, newBox);

        // Move todas as caixas de volta para a pilha A
        while (!isEmpty(&b)) {
            push(&a, pop(&b));
        }
        while (!isEmpty(&c)) {
            push(&a, pop(&c));
        }
    } else {
        // Insere a nova caixa diretamente na pilha A
        push(&a, newBox);
    }

    // Imprime o conteúdo das pilhas para verificação
    printf("Pilha A:\n");
    while (!isEmpty(&a)) {
        printf("%d\n", pop(&a));
    }

    printf("Pilha B:\n");
    while (!isEmpty(&b)) {
        printf("%d\n", pop(&b));
    }

    printf("Pilha C:\n");
    while (!isEmpty(&c)) {
        printf("%d\n", pop(&c));
    }

    return 0;
}