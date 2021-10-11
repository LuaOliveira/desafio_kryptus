#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

int main(){

    char entrada [100];
    Lista* l=NULL;
    int init = 0;
    int valor;

    while(init == 0){

        printf("Digite o comando: \n");
        fgets(entrada, 100, stdin);


        char * comando = strtok(entrada, " \n");
        char * valor_string = strtok(NULL, " ");

        if(comando == NULL){
            continue;
        }
        if(valor_string != NULL){

            valor = atoi(valor_string);
        }
        if(strcmp(comando, "put") == 0){
            l = put(l, valor);
        }else if(strcmp(comando, "get") == 0){
            printf("%d\n",get(l, valor));
        }else if(strcmp(comando, "list") == 0){
            list(l);
        }else if(strcmp(comando, "remove") == 0){
            l = remove_(l, valor);
        }else if(strcmp(comando, "clear") == 0){
            clear(l);
            l =NULL;
        }else if(strcmp(comando, "first") == 0){
            printf("%d\n", first(l));
        }else if(strcmp(comando, "last") == 0){
            printf("%d\n", last(l));
            
        }else if(strcmp(comando, "sort")==0){
            sort(&l);
            list(l);
        }
        else if(strcmp(comando, "exit")==0){
            init = 1;
        }else{
            printf("ERRO: Comando inválido! \n");
        }

    }

    return 0;

}