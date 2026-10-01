#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
    struct sNODE *prox;
};

struct sLISTA{
    struct sNODE *ini , *fim ;
};

typedef struct sLISTA LISTA;

void inserir_ord(LISTA *lst, char nome[], float nota1, float nota2){
    struct sNODE *novo;
    struct sNODE *auxilio;

    novo = (struct sNODE*) malloc(sizeof(struct sNODE));


    strcpy(novo->nome, nome);

    novo->nota1 = nota1;
    novo->nota2 = nota2;

    novo->media = (nota1 + nota2) / 2.0;

    novo->prox = NULL;

    if(lst->ini == NULL){
        lst->ini = novo;
        lst->fim = novo;
        return;
    }

    if(novo->media >= lst->ini->media){
        novo->prox = lst->ini;
        lst->ini = novo;
        return;
    }

    auxilio = lst->ini;

    while(auxilio->prox != NULL && auxilio->prox->media >= novo->media){
        auxilio = auxilio->prox;
    }

    novo->prox = auxilio->prox;
    auxilio->prox = novo;

    if(novo->prox == NULL){
        lst->fim = novo;
    }
}

void inicializar(LISTA *lst){

    lst->ini = NULL;
    lst->fim = NULL;
}


void imprimir(LISTA *lst){

    struct sNODE *aux;

    aux = lst->ini;

    printf("\n--- ALUNOS ---\n");

    while(aux != NULL){

        printf("Nome: %s\n", aux->nome);
        printf("Nota 1: %.1f\n", aux->nota1);
        printf("Nota 2: %.1f\n", aux->nota2);
        printf("Media: %.1f\n", aux->media);

        printf("----------------\n");

        aux = aux->prox;
    }
}

int main(){

    LISTA lst;

    inicializar(&lst);

    inserir_ord(&lst, "Joao", 8, 9);
    inserir_ord(&lst, "Maria", 10, 10);
    inserir_ord(&lst, "Pedro", 5, 6);
    inserir_ord(&lst, "Ana", 7, 8);

    imprimir(&lst);

    return 0;
}