#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    int chave;
    struct no * prox;
    struct no * ant;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int valor){
    

    //Passo 1 - aloco espaco de memoria e coloco os valores no NO novo
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    //Passo 2 - encaixo esse no na lista
    if(inicio == NULL){//vazia
        inicio = novo;
        fim = novo;
    }else{//fim!
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
    }
    tam++;
    novo->chave = tam;
    
}

void imprimir(){
    
     NO * aux = inicio;
                   
    for(int i = 0; i<tam; i++){
        printf("%d: %d\n",aux->chave, aux->valor);
        aux = aux->prox;
    }
    
    
}

void remover_por_valor(int valor){
    
    NO * lixo = NULL;
    if ((inicio -> chave == valor) && (fim -> chave == valor)){

        lixo = inicio;
        inicio = NULL;
        fim = NULL;
    }else if (inicio -> chave == valor){

        lixo = inicio;
        inicio = inicio -> prox;
        inicio -> ant = NULL;
    }else if (fim -> chave == valor){

        lixo = fim;
        fim = fim -> ant;
        fim -> prox = NULL;
    }else{

        NO * aux;
        if ((valor - inicio -> chave) < (fim -> chave - valor)){

            aux = inicio;
            while ((aux -> chave != valor) && (aux -> prox != NULL)){
                aux = aux -> prox;
            }

            if (aux -> ant == NULL){

                return -1;
            }else{

                lixo = aux;
                aux -> ant -> prox = aux -> prox;
                aux -> prox -> ant = aux -> ant;
            }
        }else{

            aux = fim;
            while ((aux -> chave != valor) && (aux -> ant != NULL)){
                aux = aux -> ant;
            }

            if (aux -> ant == NULL){

                return -1;
            }else{

                lixo = aux;
                aux -> ant -> prox = aux -> prox;
                aux -> prox -> ant = aux -> ant;
            }
        }
    }

    int aux = lixo->chave;
    free(lixo);
    tam--;
    return aux;
    
}


int main(){
    add(18);
    add(19);
    add(17);
    add(21);
    add(15);
    add(20);
    remover_por_valor(3);
    imprimir();
    return 0;
}


