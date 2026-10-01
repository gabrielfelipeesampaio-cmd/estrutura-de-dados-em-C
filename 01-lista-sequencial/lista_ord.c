#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define TAM_STRING 21 //no minimo

char lista[MAX][TAM_STRING];
int pos = 0;

void imprimir();

int buscar(const char *str);

void inserir_ordenado(const char *str);

void remover_string(const char *str);

int main(){

    inserir_ordenado("Frodo");
    inserir_ordenado("Gandalf");
    inserir_ordenado("Aragorn");
    inserir_ordenado("Legolas");
    inserir_ordenado("Gimli");

    printf("Lista da Sociedade do Anel Ordenada:\n");
    imprimir();

    printf("\nTentando inserir 'frodo' novamente:\n");
    inserir_ordenado("Frodo");

    printf("\nRemovendo 'Legolas':\n");
    remover_string("Legolas");

    printf("Lista final\n");
    imprimir();



    return 0;
}

void imprimir(){
    printf("[");
    for(int i = 0; i < pos; i++){
        printf(" \"%s\" ", lista[i]);
    }

    printf("]\n");
}

int buscar(const char *str){
    for(int i = 0; i< pos; i++){
        if(strcmp(lista[i], str) == 0){
            return i;
        }
    }
    return -1;
}

void inserir_ordenado(const char *str){
    if(pos >= MAX){
        printf("Erro lista lotada");
        exit(1);
    }
    if(buscar(str) != -1){
        printf("Aviso a string [%s] ja esta presente na lista\n", str);
        return;
    }

    int i = pos -1;

    while(i >= 0 && strcmp(lista[i], str) > 0){
        strcpy(lista[i + 1], lista[i]);
        i--;
    }

    strcpy(lista[i+1], str);
    pos++;


}

void remover_string(const char *str){

    if(pos == 0){
        printf("erro de lista vazia");
        exit(2);
    }

    int p = buscar(str);

    if(p == - 1){
        printf("string nao encontrda");
        exit(3);
    }

    for (int i = p; i< pos - 1; i++){
        strcpy(lista[i], lista[i+1]);
    }
    pos--;
}