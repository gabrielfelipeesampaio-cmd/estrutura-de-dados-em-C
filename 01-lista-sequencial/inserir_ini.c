#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int lista[MAX];
int pos = 0;

void imprimir();

void inserir_ini(int elemento); //funçãozinha que insere elementos no começo

void inserir_mod(int elemento);

int buscar(int elemento);

void remove_ocorrencias(int elemento);


int main(){

    for(int i = 0; i < 4; i++){
		
        lista[i] = i *2;
        pos++;

    }
    imprimir();
    inserir_ini(45);
    imprimir();
    inserir_ini(10);
    inserir_ini(10);
    imprimir();
    remove_ocorrencias(10);
    imprimir();

    return 0;
}

void imprimir(){
    printf("[");
    for(int i = 0; i < pos; i++){
        printf(" %d ", lista[i]);
    }
    printf("]\n");
}

void inserir_ini(int elemento){
    
    if(pos >= MAX){
        printf("lista cheia");
        exit(1);
    }

    for(int i = pos - 1; i >= 0; i--){
        lista[i + 1] = lista[i];
    }

    lista[0] = elemento;
    pos++;

}

void inserir_mod(int elemento){
    if(buscar(elemento) != -1){
        printf("esse elemento ja existe");
        exit(2);
    }
    lista[pos++] = elemento;



}

int buscar(int elemento){
    for(int i = 0; i< pos; i++){
        if(lista[i] == elemento){
            return i;
        } 
    }

    return -1;
}

void remove_ocorrencias(int elemento){
    //tentando pensar em uma maneira inteligente que nao chame a remover muitas vezes
    if (pos == 0){
        printf("Tem uma lista vazia");
        exit(3);
    }

    int j = 0;

    for(int i = 0 ; i< pos; i++){
        if(lista[i] != elemento){
            lista[j] = lista[i];
            j++;
        }
    }

    int removidos = pos - j;

    if(removidos == 0){
        printf("Elemento %d nao encontrado\n", elemento);
    } else{
        printf("foram removidos [%d] vezes\n", removidos);
    }
    pos = j;
}
