#ifndef LISTA_H
#define LISTA_H

typedef struct no * lista;
struct no{
    int valor;
    lista prox;
};

void mostraLista(lista);
lista iniciaLista();
lista insereLista_final(lista, int);
lista insereLista_ordenada(lista, int);
lista insereLista_inicio(lista, int);
lista removeLista_elemento(lista *, int);
lista removeLista_inicio(lista *);
lista removeLista_final(lista *);


void menu();


#endif 

