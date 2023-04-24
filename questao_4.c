#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        // printf("Erro: pilha vazia\n");
        // exit(EXIT_FAILURE);
    }

    return s->items[s->top--];
}

// Retorna o elemento no topo da pilha
int peek(Stack *s) {
    if (isEmpty(s)) {
        // printf("Erro: pilha vazia\n");
        // exit(EXIT_FAILURE);
    }

    return s->items[s->top];
}

// Realiza a operação correspondente ao operador
int performOperation(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: printf("Erro: operador inválido\n");
                 exit(EXIT_FAILURE);
    }
}

int main() {
    // Inicializa a pilha de operandos
    Stack operandStack;
    initialize(&operandStack);

    // Insere os elementos na pilha de operandos
    push(&operandStack, '1');
    push(&operandStack, '2');
    push(&operandStack, '-');
    push(&operandStack, '4');
    push(&operandStack, '5');
    push(&operandStack, '+');
    push(&operandStack, '*');

    // Inicializa a pilha de operações
    Stack operationStack;
    initialize(&operationStack);

    // Processa a pilha de operandos
    while (!isEmpty(&operandStack)) {
        int item = pop(&operandStack);

        if (isdigit(item)) {
            // Se o item é um número, insere na pilha de operações
            push(&operationStack, item - '0');
        } else {
            // Se o item é um operador, realiza a operação com os dois últimos operandos na pilha de operações
            int operand2 = pop(&operationStack);
            int operand1 = pop(&operationStack);
            int result = performOperation(item, operand1, operand2);
            push(&operationStack, result);
        }
    }

    // Imprime o resultado da operação
    printf("Resultado: %d\n", peek(&operationStack));
}