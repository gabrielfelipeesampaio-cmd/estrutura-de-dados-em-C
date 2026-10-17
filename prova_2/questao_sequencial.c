#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct LISTA{   
    int arr[10];
    int pos;
};

void filtrar_validos(struct LISTA *L);
void imprimir(struct LISTA *L);
void inserir(struct LISTA *L, int elemento);
void inicializar(struct LISTA *l){
    l->pos = 0;
}

int main(){
    struct LISTA minha_lista;
    inicializar(&minha_lista);
    inserir(&minha_lista, 8);
    inserir(&minha_lista, 0);
    inserir(&minha_lista, 9);
    
    filtrar_validos(&minha_lista);
    imprimir(&minha_lista);
    return 0;
}

void filtrar_validos(struct LISTA *L){
    int i = 0;

    while(i < L->pos){
        if(L->arr[i] == 0){
            for(int j =i; j < L->pos; j++){
                L->arr[j] = L->arr[j+1];
            }
            L->pos--;
        }
        else{
            i++;
        }

    }
}

void imprimir(struct LISTA *L){
    printf("[");
    for(int i = 0; i < L->pos; i++){
        printf("%d", L->arr[i]);
        if(i < L->pos - 1) printf(", ");
    }
    printf("]");
}

void inserir(struct LISTA *L, int elemento)
{
    if (L->pos >= MAX)
    {
       printf("Lista cheia!!");
       exit(1);
   }

    L->arr[L->pos++] = elemento;
}

