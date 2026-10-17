
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO_ELEITOR {
    char nome[50];
    int idade;
    struct NO_ELEITOR *prox;
};

struct lista {
    struct NO_ELEITOR *ini;
    struct NO_ELEITOR *fim;
};

void inserir_prioridade(struct lista *L, char *novo_nome, int idade);

int main() {
    struct lista minha_lista = {NULL, NULL};
    
    inserir_prioridade(&minha_lista, "Joao", 35);
    inserir_prioridade(&minha_lista, "Maria", 68);
    inserir_prioridade(&minha_lista, "Ana", 22);
    inserir_prioridade(&minha_lista, "Jose", 75);

    // Exibindo a lista para testar
    struct NO_ELEITOR *aux = minha_lista.ini;
    while (aux) {
        printf("nome do cidadao: %s / idade do cidadao: %d\n", aux->nome, aux->idade);
        aux = aux->prox;
    }

    return 0;
}

void inserir_prioridade(struct lista *L, char *novo_nome, int idade) {
    struct NO_ELEITOR *novo_NO = (struct NO_ELEITOR*) malloc(sizeof(struct NO_ELEITOR));
    if (!novo_NO) {
        printf("Erro na alocação de memória!\n");
        return;
    }

    strcpy(novo_NO->nome, novo_nome);
    novo_NO->idade = idade;
    novo_NO->prox = NULL;

    if (L->ini == NULL) {
        L->ini = novo_NO;
        L->fim = novo_NO;
        return;
    }

    if (idade > L->ini->idade) {
        novo_NO->prox = L->ini;
        L->ini = novo_NO;
        return;
    }

    struct NO_ELEITOR *aux = L->ini;
    while (aux->prox != NULL && aux->prox->idade >= idade) {
        aux = aux->prox;
    }


    novo_NO->prox = aux->prox;
    aux->prox = novo_NO;


    if (novo_NO->prox == NULL) {
        L->fim = novo_NO;
    }
}
