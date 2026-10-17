#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sem casos de teste

struct TELA_VOTO {
    char cargo[30];       // Ex: "Senador", "Presidente"
    int numero_digitado;  // Inicializa com -1
};

struct NO_NAVEGACAO {
    struct TELA_VOTO dados;
    struct NO_NAVEGACAO *ant, *prox;
};

struct LISTA { // duplamente
    struct NO_NAVEGACAO *ini;
    struct NO_NAVEGACAO *fim;
}; 
struct LISTA minha_lista;

void iniciar_lista(struct LISTA *L){
    L->ini = NULL;
    L->fim = NULL;
}


struct NO_NAVEGACAO *navegar(struct NO_NAVEGACAO *no_pisado, char action);
int checar_pendencias(struct NO_NAVEGACAO *comeco);

int main(){
    
    return 0;
}

struct NO_NAVEGACAO *navegar(struct NO_NAVEGACAO *no_pisado, char action){
    if (no_pisado == NULL) return NULL; 


    if(no_pisado == minha_lista.ini && action == 'T') return no_pisado;
    
    if(no_pisado == minha_lista.fim && action == 'F') return no_pisado;
    
    if(action == 'F'){
        return no_pisado->prox;
    }
    if(action == 'T'){
        return no_pisado->ant;
    }
    
    return no_pisado; 
}
int checar_pendencias(struct NO_NAVEGACAO *comeco){
    struct NO_NAVEGACAO *aux = comeco;
    while(aux != NULL){
      
        if(aux->dados.numero_digitado == -1) return 1; 
        aux = aux->prox;
    }
    return 0; 
}
