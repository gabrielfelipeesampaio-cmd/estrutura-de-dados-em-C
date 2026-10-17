#include <stdio.h>
#include <stdlib.h>

struct sNODE {
    int dado;
    struct sNODE *prev;
    struct sNODE *next;  
};

struct sNODE *begin = NULL;
struct sNODE *end = NULL;


void inserir(int dado);
void imprimir();
struct sNODE *buscar(int dado);
void remover(int dado);
void inserir_ini(int data);
void inserir_ord(int data);

int main(){
    
    inserir(10);
    inserir(22);
    inserir(5);
    inserir(14);
    imprimir();
    remover(14);
    imprimir();
    
    return 0;
}

void imprimir(){
    printf("[");
    struct sNODE *auxilio = begin;
    while(auxilio){
        printf("%d", auxilio->dado);
        
        if(auxilio->next){printf(", ");}

        auxilio = auxilio->next;        
    }
    printf("]\n");
}

void inserir(int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prev = NULL;
    novo->next = NULL;

    if(!begin){     
        begin = novo;
        end = novo;
        return;
    }
    else{
        end->next = novo;
        novo->prev = end;
        end = novo;
        }       
    
}

struct sNODE *buscar(int dado){
    struct sNODE *auxilio = begin;
    while(auxilio){
        if(auxilio->dado == dado) return auxilio;
        auxilio = auxilio->next;
    }
    return NULL;
}

void remover(int data){
    struct sNODE *assistance = buscar(data);

    if(!assistance) return ;

    if(assistance->next == NULL && assistance->prev == NULL) {
        begin = end = NULL;

    }
    else if(assistance == begin){begin = assistance->next; begin->prev = NULL;}

    else if(assistance == end) {
        end = assistance->prev;
        end->next = NULL;

    }

    else{
        assistance->prev->next = assistance->next;
        assistance->next->prev = assistance->prev;
    }
    free(assistance);
}

void inserir_ini(int data){
    struct sNODE *new = (struct sNODE*) malloc(sizeof(struct sNODE));
    new->dado = data;
    new->prev = NULL;
    new->next = NULL:

    if(!begin) {begin = end = new};

    else{
        new->next = ini;
        ini = new;
    }
}

void inserir_ord(int dado){
    struct sNODE *new = (struct sNODE*) malloc(sizeof(struct sNODE));
    new->dado = dado;
    new->prev = NULL;
    new->next = NULL;

    if(!begin) {begin = end = new; return;}
    //achando a posicao corretaa
    struct sNODE *assistance = begin;
    
    while(assistance->dado < dado) {assistance = assistance->next;}

    if(!assistance){
        new->prev = end;
        end->next = new;
        end = new
    }

    else if(assistance = begin){
        new->next = begin;
        begin->prev = new;
        begin = new;
    }

    else{
        new->prox = assistance->prox;
        new->next = assistance;
        assistance->prev->next = new;
        assistance->prev = new;
    }
    
}