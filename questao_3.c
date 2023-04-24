#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int weight;
    struct node * bottom;
}Hanoi;

//int sizeA = 0, sizeB = 0, sizeC = 0;

Hanoi * topA = NULL;
Hanoi * topB = NULL;
Hanoi * topC = NULL;

void heapCargo (int cargo){//função para adicionar nova carga na pilha preferencialmente na pilha A

    if ((cargo >= 3 || cargo <= 7) && cargo != 4){

        Hanoi * newCargo = malloc(sizeof(Hanoi));
        newCargo -> weight = cargo;
        newCargo -> bottom = NULL;

        if (topA == NULL){//pilha A vazia, então pode adicionar sem problema com a carga
            topA = newCargo;
        }else{//pilha A já existe

            if (cargo == 7 && topA -> weight == cargo){
                newCargo -> bottom = topA;
                topA = newCargo;
            }else if (cargo == 7){

                while (topA != NULL){

                    if (topA -> weight == 5){

                        Hanoi * auxStack = topA;
                        topA = topA -> bottom;
                        auxStack -> bottom = topB;
                        topB = auxStack;
                    }else{

                        Hanoi * auxStack = topA;
                        topA = topA -> bottom;
                        auxStack -> bottom = topC;
                        topC = auxStack;
                    }

                    if (topA != NULL){
                        if (topA -> weight == 7){break;}
                    }
                }

                newCargo -> bottom = topA;
                topA = newCargo;
            }else if (cargo == 5){

                while (topA != NULL){

                    if (topA -> weight == 3){

                        Hanoi * auxStack = topA;
                        topA = topA -> bottom;
                        auxStack -> bottom = topC;
                        topC = auxStack;
                    }

                    if (topA != NULL){
                        if ((topA -> weight == 5 || topA -> weight == 7)){break;}
                    }
                }

                newCargo -> bottom = topA;
                topA = newCargo;
            }else{

                newCargo -> bottom = topA;
                topA = newCargo;
            }
        }

        while (topB != NULL){

            Hanoi * auxSort = topB;
            topB = topB -> bottom;
            auxSort -> bottom = topA;
            topA = auxSort;
        }

        while (topC != NULL){

            Hanoi * auxSort = topC;
            topC = topC -> bottom;
            auxSort -> bottom = topA;
            topA = auxSort;
        }
    }else{ printf("Carga inválida para ser adicionada na pilha.\n"); }
}

void printStack(void){

    Hanoi * auxPrintA = topA;
    Hanoi * auxPrintB = topB;
    Hanoi * auxPrintC = topC;

    while (auxPrintA != NULL){

        printf("Carga: %dt\n", auxPrintA -> weight);
        auxPrintA = auxPrintA -> bottom;
    }
    if (auxPrintB == NULL && auxPrintC == NULL){
        printf("Stacks B e C estao vazias.\n");
    }else{ printf("Há algum elemento em B ou C.\n"); }
}

int main(void){

    heapCargo(3);
    heapCargo(7);
    heapCargo(5);

    printStack();

    return 0;
}