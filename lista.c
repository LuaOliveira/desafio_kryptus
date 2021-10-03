#include "lista.h"



void create(Lista* l){

    if (l != NULL){
        l = (Lista*) malloc(sizeof(Lista));
        l->valor = 0;
        l->proximo = NULL;
    }

}
void put(Lista* l, int n ){
    while(l!=NULL){
        l = l->proximo;
    }

    create(l);
    l->valor = n;
    list(l);

}
int get(Lista* l, int pos){
    
    int a = 1;
    for(a; a == pos; a++){
        l = l->proximo;
    }
    
    return l->valor;

}
void list(Lista* l){

    while(l != NULL){
        printf("%d ", l->valor);
        l = l->proximo;
    }
    printf("\n");

}
Lista* remove(Lista* l, int pos){

    /*Se o valor a remover é o primeiro elemento da lista*/
    if(pos == 1){
        printf("%d \n", l->valor);
        list(l->proximo);

        Lista* inicio = l->proximo;
        free(l);
        return inicio;
    }
    /*Se o valor é qualquer outro que nao o primeiro*/

    int a= 1;
    Lista* removido;
    
    Lista* inicio = l;
    for(a; a== pos-1; a++){
        l= l->proximo;
    }
    printf("%d \n", l->proximo->valor);
    removido = l->proximo;
    l->proximo = l->proximo->proximo;
    free(removido);

    return inicio;


}
void clear(Lista* l){
    free(l);
}
int first(Lista* l){
    return get(l, 1);
}
int last(Lista* l){
    while(l!=NULL){
        l = l->proximo;
    }

    return l->valor;
}
