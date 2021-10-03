#include<stdio.h>
#include<stdlib.h>

/*Tipo Abstrato de dados: definicao das funções*/ 

struct lista
{
    /* data */
    int valor;
    struct lista *proximo;

};

typedef struct lista Lista;


void create(Lista* l);
void put(Lista* l, int n );
int get(Lista* l, int pos);
void list(Lista* l);
Lista* remove(Lista* l, int pos);
void clear(Lista* l);
int first(Lista* l);
int last(Lista* l);
