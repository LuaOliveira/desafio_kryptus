#include "lista.h"


Lista* create(Lista* l){

    if (l == NULL){
        l = (Lista*) malloc(sizeof(Lista));
        l->valor = 0;
        l->proximo = NULL;
    }

    return l;

}
Lista* put(Lista* l, int n ){

    if (l == NULL){
        l = create(NULL);
        l->valor = n;
        list(l);
        return l;
    }

    Lista* inicio = l;

    while(l->proximo!=NULL){
        l = l->proximo;
    }

    l->proximo = create(l->proximo);
    l->proximo->valor = n;
    list(inicio);

    return inicio;

}
int get(Lista* l, int pos){

    int a;
    for(a=1; a != pos; a++){
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

Lista* remove_(Lista* l, int pos){

    /*Se o valor a remover é o primeiro elemento da lista*/
    if(pos == 1){
        printf("%d \n", l->valor);
        list(l->proximo);

        Lista* inicio = l->proximo;
        free(l);
        return inicio;
    }
    /*Se o valor é qualquer outro que nao o primeiro*/

    int a;
    Lista* removido;
    
    Lista* inicio = l;
    for(a=1; a!= pos-1; a++){
        l= l->proximo;
    }
    printf("%d \n", l->proximo->valor);
    removido = l->proximo;
    l->proximo = l->proximo->proximo;
    free(removido);

    return inicio;


}
void clear(Lista* l){

    Lista* inicio = l;

    /*desalocando todos os nós*/
    while(inicio != NULL){
        Lista* anterior=NULL;
        while(l->proximo != NULL){
            anterior = l;
            l = l->proximo;
        }

        free(l);
        if(anterior != NULL){
            anterior->proximo = NULL; 
        }
        if(l == inicio){
            inicio = NULL;
        }

        l = inicio;
    }

}
int first(Lista* l){
    return get(l, 1);
}
int last(Lista* l){

    while(l->proximo!=NULL){

        l = l->proximo;
    }

    return l->valor;
}

void sort(Lista** l){

    int val_temp=0;
    Lista* temp=NULL;
    Lista* inicio = *l;

    while(inicio != NULL){

        temp = *l;
        while(temp->proximo != NULL){

            if(temp->valor > temp->proximo->valor){

                val_temp=temp->valor;
                temp->valor = temp->proximo->valor;
                temp->proximo->valor = val_temp;
            }

            temp=temp->proximo;
        }
        inicio=inicio->proximo;
    }
}
