
#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
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

void inserir_ord(LISTA *lst, int dado){
    struct sNODE *new = (struct sNODE*) malloc(sizeof(struct sNODE));
    new->dado = dado;
    new->ant = NULL;
    new->prox = NULL;

    if(!lst->ini) {lst->ini = lst->fim = new; return;}
    //achando a posicao corretaa
    struct sNODE *assistance = lst->ini;
    
    while(assistance->dado < dado) {assistance = assistance->prox;}

    if(!assistance){
        new->ant = lst->fim;
        lst->fim->prox = new;
        lst->fim = new;
    }

    else if(assistance = lst->ini){
        new->prox = lst->ini;
        lst->ini->ant = new;
        lst->ini = new;
    }

    else{
        new->prox = assistance->prox;
        new->prox = assistance;
        assistance->ant->prox = new;
        assistance->ant = new;
    }
    
}

