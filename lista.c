#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

lista iniciaLista(){
    lista ptlista = (lista)malloc(sizeof(lista));
    ptlista = NULL;
    return ptlista;
}

void encerraLista(lista ptlista){
    lista aux = ptlista;
    
    while(ptlista != NULL){
        aux = ptlista;
        ptlista = ptlista->prox;
        free(aux);
    }
    free(ptlista);
    
    printf("\n Lista Encerrada!");
}

void mostraLista(lista ptlista){
    if(ptlista != NULL){

    lista aux = ptlista;
        while(aux != NULL){
            printf(" [%d|]->", aux->valor);

            aux=aux->prox;	
        }
		printf(" NULL\n");
    }

}

lista insereLista_final(lista ptlista, int valor){
    lista aux, par;

    par = (lista)malloc(sizeof(struct no));

    par->valor = valor;

    aux = ptlista;
    lista ant = NULL;

    while(aux != NULL){
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL){
        par->prox = ptlista;
        ptlista= par;
    }
    else{
        par->prox = ant->prox;
        ant->prox = par;     
    }

    return ptlista;
}

lista insereLista_ordenada(lista ptlista, int valor){
    lista aux, par;

    par = (lista)malloc(sizeof(struct no));

    par->valor = valor;

    aux = ptlista;
    lista ant = NULL;

    while(aux != NULL && aux->valor < valor){
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL){
        par->prox = ptlista;
        ptlista= par;
    }
    else{
        par->prox = ant->prox;
        ant->prox = par;     
    }

    return ptlista;
}

lista insereLista_inicio(lista ptlista, int valor){
    lista par;

    par = (lista)malloc(sizeof(struct no));

    par->valor = valor;
    
    par->prox = ptlista;
    ptlista = par;

    return ptlista;
}

lista removeLista_elemento(lista *ptlista, int valor){
    
    lista aux = *ptlista;
    lista ant = NULL;

    while(aux != NULL && valor != aux->valor){
        ant = aux;
        aux = aux->prox;
    }

    if(aux != NULL){
        ant->prox = aux->prox;
    }
    
    return aux;
}

lista removeLista_inicio(lista *ptlista){
    
    lista aux = NULL;
    
    if(*ptlista != NULL){
        aux = *ptlista;
        *ptlista = aux->prox;
    }
    
    return aux;
}

lista removeLista_final(lista *ptlista){
    
    lista ant, aux = *ptlista;
    
    if(*ptlista == NULL)
        return 0;

    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;
    
    return aux;
}

void menu(){
    
    lista ptlista = iniciaLista();
    int op = 0;
       
    while(op != 5){
        
        printf("\nDIGITE O COMANDO DESEJADO\n");
        printf("1 - INSERIR\n");
        printf("2 - MOSTRAR\n");
        printf("3 - REMOVER\n");
        printf("5 - SAIR\n");
        scanf("%d",&op);

        switch (op){
            case 1:
            {
                int valorI = 0;
                printf("\nDIGITE OS VALORES NATURAIS DA LISTA ENCADEADA: \n");
                scanf("%d",&valorI);
                while(valorI >= 0){
                    //ptlista = insereLista_inicio(ptlista,valorI);
                    ptlista = insereLista_final(ptlista,valorI);
                    //ptlista = insereLista_ordenada(ptlista,valorI);
                    scanf("%d",&valorI);                   
                }
                printf("PREENCHIMENTO DA LISTA CONCLUÍDO\n");
                
            }
                break;
                
            case 2:
            {
                mostraLista(ptlista);
            }
                break;
                
            case 3:
            {
//                int valorR = 0;
//                printf("\nDIGITE O VALOR A SER REMOVIDO DA LISTA ENCADEADA: \n");
//                scanf("%d",&valorR);
                //lista no = removeLista_inicio(&ptlista);
               // lista no = removeLista_elemento(&ptlista,valorR);
                lista no = removeLista_final(&ptlista);
                if(no == NULL)
                    printf("VALOR NAO ENCONTRADO\n");
                else
                    printf("VALOR REMOVIDO: %d\n", no->valor);
            }
                break;
          
            
            default:
                printf("ENTRADA INVALIDA, DIGITE OUTRO COMANDO\n\n");
                break;
           
        }
        
    }
    encerraLista(ptlista);
}
