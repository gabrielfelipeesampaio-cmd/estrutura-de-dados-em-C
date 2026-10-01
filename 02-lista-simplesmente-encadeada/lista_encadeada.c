
#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);


void inserir_ini(LISTA *lst, int dado);

int main(){
  LISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, 100);
  imprimir(&lst);

  apagar(&lst);

  return 0;
}


void inicializar(LISTA *lst){
    lst->ini = NULL;
    lst->fim = NULL;
}



void inserir_ini(LISTA *lst, int dado){
    struct sNODE *novo;
    novo = (struct sNODE*) malloc(sizeof(struct sNODE));

    novo->dado = dado;
    novo->prox = lst->ini;

    lst->ini = novo;

    if(lst->fim == NULL){
        lst->fim = novo;
    }
}

void imprimir(LISTA *lst){
    struct sNODE *auxilio;

    auxilio = lst->ini;

    printf("[");
    while(auxilio != NULL){
        printf("%d", auxilio->dado);

        if(auxilio->prox != NULL){
            printf(", "); //vai ficar legal
        }
        auxilio = auxilio->prox;
    }
    printf("]\n");
}

int tamanho(LISTA *lst){
    struct sNODE *auxilio;
    int contador = 0;

    auxilio = lst->ini;

    while(auxilio != NULL){
        contador++;
        auxilio = auxilio->prox;
    }

    return contador;
}

struct sNODE *buscar(LISTA *lst, int dado){
    struct sNODE *auxilio;

    auxilio = lst->ini;

    while(auxilio != NULL){
        if(auxilio->dado == dado){
            return auxilio;
        }
    }

    auxilio = auxilio->prox;

    return NULL;
}

int obter(struct sNODE *node){
    return node->dado;
}

void remover(LISTA *lst, int dado){
    struct sNODE *auxilio;
    struct sNODE *anterior;

    auxilio = lst->ini;
    anterior = NULL;

    while(auxilio != NULL && auxilio->dado != dado){
        anterior = auxilio;
        auxilio = auxilio->prox;
    }

    if(auxilio == NULL){
        return;
    }

    if(anterior == NULL){
        lst->ini = auxilio->prox;

    }

    else{
        anterior->prox = auxilio->prox;
    }

    if(auxilio == lst->fim){
        lst->fim = anterior;
    }

    free(auxilio);
}

void apagar(LISTA *lst){
    struct sNODE *auxilio;

    while(lst->ini != NULL){
        auxilio = lst->ini;
        lst->ini = lst->ini->prox;
        free(auxilio);
    }

    //free(auxilio);
    lst->fim = NULL;
}


void inserir_ord(LISTA *lst, int dado){
    struct sNODE *novo;
    struct sNODE *aux;

    novo = (struct sNODE*) malloc(sizeof(struct sNODE));

    novo->dado = dado;
    novo->prox = NULL;

    // Lista vazia
    if(lst->ini == NULL){
        lst->ini = novo;
        lst->fim = novo;
        return;
    }

    // Inserir no início
    if(dado <= lst->ini->dado){
        novo->prox = lst->ini;
        lst->ini = novo;
        return;
    }

    // Procurar a posição
    aux = lst->ini;

    while(aux->prox != NULL && aux->prox->dado < dado){
        aux = aux->prox;
    }

    // Inserir depois de aux
    novo->prox = aux->prox;
    aux->prox = novo;

    // Se foi inserido no final
    if(novo->prox == NULL){
        lst->fim = novo;
    }
}

LISTA juntar_ord(LISTA *lst1, LISTA *lst2){
    LISTA nova;
    struct sNODE *auxilio;

    inicializar(&nova);

    auxilio = lst1->ini;

    while(auxilio != NULL){
        inserir_ord(&nova, auxilio->dado);
        auxilio = auxilio->prox;_
    }

    auxilio = lst2->ini;

    while(auxilio != NULL){
        inserir_ord(&nova, auxilio->dado);
        auxilio = auxilio->prox;

    }

    return nova;
}