#ifndef LIST_H
#define LIST_H

typedef struct node * list;
struct node{
    int value;
    list prox;
};

list initList();
void endList(list);

void showList(list);

list listAppend(list, int);
list listRemove(list *, int);

void menu();


#endif 

