#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*_________________________________________________________
                                                      /*|*/
//WHERE YOUR DATA WILL BE APPENDED IN YOUR LIST?    | /*|*/
//insert a "x" below in front of the chosen option  V /*|*/
#define APP_BEGINNING(x)/*-----------------------*/ x  /*|*/
#define APP_ORGANIZED(x)/*-----------------------*/   /*|*/
#define APP_END(x)/*-----------------------------*/   /*|*/
/*_______________________________________________________*/


/*________________________________________________________
                                                      /*|*/
//HOW DO YOU WANT TO REMOVE ITEMS FROM YOUR LIST?   | /*|*/
//insert a "x" below in front of the chosen option  V /*|*/
#define REM_BEGINNING(x)/*-----------------------*/ x  /*|*/
#define REM_ELEMENT(x)/*-------------------------*/   /*|*/
#define REM_END(x)/*-----------------------------*/   /*|*/
/*_______________________________________________________*/



list initList(){
    list ptrList = (list)malloc(sizeof(list));
    ptrList = NULL;
    return ptrList;
}

void endList(list ptrList){
    list aux = ptrList;
    
    while(ptrList != NULL){
        aux = ptrList;
        ptrList = ptrList->prox;
        free(aux);
    }
    free(ptrList);
    
    printf("\n List Ended!");
}

void showList(list ptrList){
    if(ptrList != NULL){

    list aux = ptrList;
        while(aux != NULL){
            printf(" [%d|]->", aux->value);

            aux=aux->prox;	
        }
		printf(" NULL\n");
    }

}

list listAppend(list ptrList, int value){
    list aux, par;

    par = (list)malloc(sizeof(struct node));

    par->value = value;
    
APP_BEGINNING(
    
    par->prox = ptrList;
    ptrList = par;
    
)
            
APP_ORGANIZED(
        
    aux = ptrList;
    list prev = NULL;

    while(aux != NULL && aux->value < value){
        prev = aux;
        aux = aux->prox;
    }

    if(prev == NULL){
        par->prox = ptrList;
        ptrList= par;
    }
    else{
        par->prox = prev->prox;
        prev->prox = par;     
    }
)

APP_END(
    aux = ptrList;
    list prev = NULL;

    while(aux != NULL){
        prev = aux;
        aux = aux->prox;
    }

    if(prev == NULL){
        par->prox = ptrList;
        ptrList= par;
    }
    else{
        par->prox = prev->prox;
        prev->prox = par;     
    }
)
    return ptrList;
}

list listRemove(list *ptrList, int value){
REM_BEGINNING(
    list aux = NULL;
    
    if(*ptrList != NULL){
        aux = *ptrList;
        *ptrList = aux->prox;
    }          
)
        
REM_ELEMENT(
    list aux = *ptrList;
    list prev = NULL;

    while(aux != NULL && value != aux->value){
        prev = aux;
        aux = aux->prox;
    }

    if(aux != NULL){
        prev->prox = aux->prox;
    }
)
            
REM_END(
    list prev;
    list aux = *ptrList;
    
    if(*ptrList == NULL)
        return 0;

    while(aux->prox != NULL){
        prev = aux;
        aux = aux->prox;
    }

    prev->prox = NULL;      
)
    return aux;
}

void menu(){
    
    list ptrList = initList();
    int op = 0;
       
    while(op != 5){
        
        printf("\nENTER COMMAND:\n");
        printf("1 - APPEND ELEMENT\n");
        printf("2 - SHOW LIST\n");
        printf("3 - REMOVE FROM LIST\n");
        printf("5 - EXIT\n");
        scanf("%d",&op);

        switch (op){
            case 1:
            {
                int valueA = 0;
                printf("\nENTER POSITIVE NUMBERS TO APPEND IN THE LIST: \n");
                printf("(negative numbers = EXIT)\n\n");
                scanf("%d",&valueA);
                while(valueA >= 0){
                    ptrList = listAppend(ptrList,valueA);
                    scanf("%d",&valueA);                   
                }
                printf("LIST FILLED!\n");
                
            }
                break;
                
            case 2:
            {
                showList(ptrList);
            }
                break;
                
            case 3:
            {
                int valueR = 0;
            REM_ELEMENT(
                printf("\nDIGITE O VALOR A SER REMOVIDO DA LISTA ENCADEADA: \n");
                scanf("%d",&valueR);
            )
                list node = listRemove(&ptrList,valueR);
                if(node == NULL)
                    printf("EMPTY LIST OR VALUE NOT FOUND\n");
                else
                    printf("VALUE REMOVED: %d\n", node->value);
            }
                break;
          
            
            default:
                printf("INVALID KEY, ENTER ANOTHER ONE!\n\n");
                break;
           
        }
        
    }
    endList(ptrList);
}
