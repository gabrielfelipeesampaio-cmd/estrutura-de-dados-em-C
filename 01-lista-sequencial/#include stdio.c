#include <stdio.h>
#include <stdlib.h>

//QUESTÃO ASSISTIDA
//do jeito que está na atividade:
typedef struct {
 unsigned MAX;
 int *arr, pos;
} LISTA;


//seção de protótipos
void criar(LISTA *lst, int tam_MAX);
void apagar(LISTA *lst);

void inserir(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);

int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);


int contar(LISTA *lst, int valor);
void inserirPos(LISTA *lst, int pos, int valor);
void copiar(LISTA *lst1, LISTA *lst2);
void estender(LISTA *lst1, LISTA *lst2);
int contar(LISTA *lst, int valor);
int pop(LISTA *lst);
void inserirPost(LISTA *lst, int pos, int valor);
void inverter(LISTA *lst1, LISTA *lst2);
void redimensionar(LISTA *lst1, int MAX);


void inserir_v2(LISTA *lst, int elemento){
    //validação
    if (lst->pos >= lst->MAX)
    {
        redimensionar(lst, lst->MAX + 1);
    }
    
    //lógica ordinária
    lst->arr[lst->pos++] = elemento;
    //lst->pos++; // lst->pos = lst->pos + 1; // lst->pos += 1;

}

void inserir_post_v2(LISTA *lst, int pos, int valor){
    if(pos < 0 || pos > lst->pos){
        printf("Indexacao errada");
        return;
    }

    if(pos > lst->MAX){
        redimensionar(lst, lst->MAX+3);
    }

    for(int i = lst->pos; i > pos; i--){
        lst->arr[i] = lst->arr[i - 1];
    }
    lst->arr[pos++] = valor;
}

void copiar_v2(LISTA *lst1, LISTA *lst2){
    if(lst1 == NULL || lst2 == NULL){
        return ;
    }
    if(lst1->MAX < lst2->pos){
        redimensionar(lst1, lst2->pos);
    }
    for(int i = 0; i < lst2->pos; i++){
        lst1->arr[i] = lst2->arr[i];
    }


    lst1->pos = lst2->pos;
}

void inverter_v2(LISTA *lst1, LISTA *lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("Alguma lista ainda nao existe");
        return;

    }
    if(lst2->pos > lst1->MAX){
        redimensionar(lst1, lst2->pos);
    }

    int tam = 0;
    for(int i = lst2->pos - 1; i >= 0; i--){
        lst1->arr[tam++] = lst2->arr[i];

    }

    lst1->pos = lst2->pos;
}

void ordenar(LISTA *lst){
    for(int i = 0; i < lst->pos -1; i++){
        for(int j = i + 1; j < lst->pos; j++){
            if(lst->arr[i] > lst->arr[j]){
            

                int auxilio = lst->arr[i];
                lst->arr[i] = lst->arr[j];
                lst->arr[j] = auxilio;
            }
        }
    }
}



int main() {
    printf("teste");
    //programador "O quê?"
    LISTA lista1, lista2;
    criar(&lista1,10);
    criar(&lista2,30);
    
    //inserir(&lista1, 100);
    inserir(&lista1, 100);
    inserir(&lista1, 200);
    inserir(&lista1, 300);
    inserir(&lista1, 400);
    inserirPos(&lista1, 1, 50);
	imprimir(&lista1);
    printf("Antes do POP\n");
    printf("Ultimo elemento da lista %d\n", pop(&lista1));
	imprimir(&lista1);
    
    printf("contando o numero de 100 =  %d\n", contar(&lista1, 100));
    
    printf("Achei 30? %d\n",buscar(&lista1,30));
    printf("Achei 300? %d\n",buscar(&lista1,300));
    printf("Achei 100? %d\n",buscar(&lista1,100));
    
    printf("Antes de remover: ");
    imprimir(&lista1);
    remover(&lista1, 30);
    remover(&lista1, 200);
    
    printf("Depois de remover: ");
    imprimir(&lista1);
    printf("inserindo 500 na posiçã 2\n");
    inserirPos(&lista1, 2, 500);
    imprimir(&lista1);
    
    apagar(&lista1);
    apagar(&lista2);
    
    printf("Lista apagada: ");
    imprimir(&lista1);
    
    printf("Achei 300? %d\n",buscar(&lista1, 300));
    return 0;
    
}

//programador como?
void criar(LISTA *lst, int tam_MAX)
{
    lst->MAX = tam_MAX;
    lst->pos = 0;
    lst->arr = malloc(sizeof(int) * tam_MAX);
}

void apagar(LISTA *lst)
{
    lst->pos = lst->MAX = 0;
    
    free(lst->arr);
    lst->arr = NULL;
}

void inserir(LISTA *lst, int elemento)
{
    //validação
    if (lst->pos >= lst->MAX)
    {
        printf("Lista cheia!");
        exit(1);
    }
    
    //lógica ordinária
    lst->arr[lst->pos++] = elemento;
    //lst->pos++; // lst->pos = lst->pos + 1; // lst->pos += 1;
}

int buscar(LISTA *lst, int elemento)
{
    for (int i = 0 ; i < lst->pos ; i++)
    {
        if (elemento == lst->arr[i])
        {
            return i;
        }
    }
    
    return -1;
}

void remover(LISTA *lst, int elemento)
{
    //saber se elemento existe na lista
    int bi = buscar(lst, elemento);
    
    //se o elemento não existe na lista, ok!
    if (bi == -1)
        return;
        
    //vamos remover
    for (int i = bi ; i < lst->pos -1; i++)
    {
        lst->arr[i] = lst->arr[i+1];
    }
    
    lst->pos--; //ajustando o pos
}

int obter(LISTA *lst, int indice)
{
    //validação
    if (indice < 0 || indice >= lst->pos)
    {
        printf("Oooops. Indice fora do array.");
        exit(1);
    }
    
    return lst->arr[indice];
}

int tamanho(LISTA *lst)
{
    return lst->pos;
}

void imprimir(LISTA *lst)
{
    printf("[");
    for (int i = 0 ; i < lst->pos ; i++)
    {
        printf("%d ",lst->arr[i]);
    }
    printf("]\n");
}

int contar(LISTA *lst, int valor){
    int contador = 0;
    for(int i = 0; i < lst->pos; i++){
        if(lst->arr[i] == valor){
            contador++;
        }
    }
    return contador;
    
}

void inserirPos(LISTA *lst, int pos, int valor){
    
    if (pos < 0 || (pos >= lst->MAX || pos > lst->pos)){
        printf("Indexação Errada");
        return;
    }
    

    for(int i = lst->pos ; i >= pos ;i--){
        lst->arr[i + 1] = lst->arr[i];
    }
    lst->arr[pos] = valor;
    lst->pos++;
}

void copiar(LISTA *lst1, LISTA *lst2){
    //testar se tudo existe, ou e um delirio
    if(lst1 == NULL || lst2 == NULL){
        printf("Endereço de lista invalido");
        return;
    }
    if(lst1->MAX < lst2->pos){
        //lst1 nao serve para nada
        free(lst1->arr);

        lst1->MAX = lst2->pos;

        lst1->arr = (int *) malloc(sizeof(int) * lst1->MAX);
    }
    for (int i = 0; i < lst2->pos; i++){
        lst1->arr[i] = lst2->arr[i];
    }
    lst1->pos = lst2->pos;
    
}

void estender(LISTA *lst1, LISTA *lst2){
    //testando se tudo nao e uma fantasia
    if(lst1 == NULL || lst2 == NULL){
        printf("Listas ainda nao existem");
        return;
    }

    int elementos_totais = lst1->pos + lst2->pos;

    if (elementos_totais > lst1->MAX){
        int nova_capacity = elementos_totais; //é so um multiplicador
        int *novo_arr = NULL;
        novo_arr = (int *) malloc(sizeof(int) * nova_capacity);

        for(int i = 0; i < lst1->pos; i++){
            novo_arr[i] = lst1->arr[i];
            
        }
        free(lst1->arr);
        //atualizando 
        lst1->arr = novo_arr;
        lst1->MAX = elementos_totais;
        
    }
    for (int i = 0; i < lst2->pos; i++){
        lst1->arr[lst1->pos + i] = lst2->arr[i];
    }
    lst1->pos = elementos_totais;
}

int pop(LISTA *lst){
    int ultimo = lst->arr[lst->pos - 1];
    lst->pos--;
    return ultimo;
}

void inserirPost(LISTA *lst, int pos, int valor){
	if(pos < 0 || pos > lst->pos || pos > lst->MAX){
		printf("posicao invalida");
		return;
	}
	for(int i = (lst->pos - 1); i >= pos; pos--){
		lst->arr[i+1] = lst->arr[i];
	}
	lst->arr[pos++] = valor;
	
}

void inverter(LISTA *lst1, LISTA *lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("alguma lista ainda nao existe");
        return;
    }

    if(lst2->pos > lst1->MAX){
        free(lst1->arr);


        int *novo_arr = (int *) malloc(sizeof(int) * lst2->pos);

        int tam = 0;
        for(int i = lst2->pos -1; i >=0; i--){
            novo_arr[tam] = lst2->arr[i];
            tam++;
        }

        lst1->arr = novo_arr;
        lst1->pos = lst2->pos;
        lst1->MAX = lst2->MAX;
        
       //free(novo_arr);

    }
    else{
        int tam = 0;
        for(int i = lst2->pos -1; i >=0; i--){
                lst1->arr[tam] = lst2->arr[i];
                tam++;
            }

        lst1->pos = lst2->pos;
    }
}

void redimensionar(LISTA *lst1, int MAX){

    if(lst1 == NULL){
        printf("A lista ainda nao existe");
        return;
    }

    if(MAX < lst1->pos){
        printf("Não será possivel reduzir: haveria perda de conteudo");
        return ;
    }

    int *novo_arr = (int *) malloc(sizeof(int) * MAX);

    for(int i = 0; i < lst1->pos ; i++){
        novo_arr[i] = lst1->arr[i];
    }

    free(lst1->arr);

    lst1->arr = novo_arr;
    lst1->MAX = MAX;
}