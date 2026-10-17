#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int data;
    struct sNODE *prev;
    struct sNODE *next;
};

struct sNODE *begin = NULL;
struct sNODE *end = NULL;

void inserir(int data);
void imprimir();
struct sNODE *buscar(int dado);
void remover(int dado);
void inserir_ini(int dado);
void imprimir_reverso();


int main(){

    printf("OLÁ! lista duplamente encadeada\n");
    inserir_ini(1);
    inserir(3);
    inserir_ini(0);
    inserir_ini(44);
    imprimir();
    printf("imprimindo ao contrario");
    imprimir_reverso();

    return 0;
}

void inserir(int data){
    struct sNODE *new = (struct sNODE*) malloc(sizeof(struct sNODE));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(!begin) { begin = end = new; return; }

    end->next = new;
    new->prev = end;
    end = new;
}

void imprimir(){
    printf("[");
    struct sNODE *assistance = begin;
    while(assistance){
        printf("%d", assistance->data);
        
        if(assistance->next) printf(", ");

        assistance = assistance->next;
    }
    printf("]\n");
}

struct sNODE *buscar(int dado){
    struct sNODE *assistance = begin;
    while(assistance){
        if(assistance->data == dado) return assistance;

        assistance = assistance->next;
    }
    return NULL;
}

void inserir_ini(int dado){
    struct sNODE *new = (struct sNODE*) malloc(sizeof(struct sNODE));
    new->data = dado;
    new->prev = NULL;
    new->next = NULL;

    if(!begin) {begin = end = new; return;}

    begin->prev = new;
    new->next = begin;
    begin = new;
}

void imprimir_reverso(){
    printf("[");
    struct sNODE *assistance = end;
    while(assistance){
        printf("%d", assistance->data);

        if(assistance->prev) printf(", ");

        assistance = assistance->prev;
    }
    printf("]\n");
}