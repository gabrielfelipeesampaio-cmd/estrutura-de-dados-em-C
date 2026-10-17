
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sem casos de teste

struct NO_CANDIDATO {
    int numero;
    char status;
    struct NO_CANDIDATO *prox;
};

struct lista {
    struct NO_CANDIDATO *ini;
    struct NO_CANDIDATO *fim;
};

void iniciar_lista(struct lista *L){
    L->ini = NULL;
    L->fim = NULL;
}
struct lista minha_lista;
void limpar_repugnados();


int main(){

    iniciar_lista(&minha_lista);
    
    
    return 0;
}

void limpar_repugnados() {
    if (minha_lista.ini == NULL) { return; }
    
    struct NO_CANDIDATO *teste = minha_lista.ini;
    struct NO_CANDIDATO *ant = NULL;
    
    while (teste) {
        if (teste->status == 'i') {
            struct NO_CANDIDATO *aux = teste;
            
            if (teste == minha_lista.ini) {
                minha_lista.ini = teste->prox;
                teste = minha_lista.ini;
                if (minha_lista.ini == NULL) {
                    minha_lista.fim = NULL;
                }
            } else {
                ant->prox = teste->prox;
                if (teste == minha_lista.fim) {
                    minha_lista.fim = ant;
                }
                teste = teste->prox;
            }
            free(aux); 
        } else {
            ant = teste;
            teste = teste->prox;
        }
    }
}

