#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *next;
}Nodo;

Nodo* annadir_final(Nodo *head, int valor){
    Nodo *actual = head;
    if(head == NULL){
        head = malloc(sizeof (Nodo));
        head->valor = valor;
        head->next = NULL;
    }else{
        while (actual!=NULL){
            if(actual->next==NULL){
                Nodo *nuevo= malloc(sizeof (Nodo));
                nuevo->valor = valor;
                nuevo->next = NULL;
                actual->next=nuevo;
                actual=nuevo;
            }
            actual=actual->next;
        }
    }
    return head;
}

Nodo* annadir_in_K(Nodo *head, int valor, int posicion){
    int indice = 1;
    Nodo *actual = head;
    if(head == NULL){
        head = malloc(sizeof (Nodo));
        head->valor = valor;
        head->next = NULL;
    }else{
        while (actual!=NULL){
            if(indice == posicion){
                Nodo *nuevo= malloc(sizeof (Nodo));
                nuevo->valor = valor;
                nuevo->next = NULL;
                actual->next=nuevo;
                actual=nuevo;
            }
            actual=actual->next;
            indice++;
        }
    }
    return head;
}

void Imprimir(Nodo *head){
    if(head==NULL){
        printf("Lista vacia\n");
    }else{
        while(head!=NULL){
            printf("%d->",head->valor);
            head=head->next;
        }
        printf("NULL\n");
    }
}


int main() {

    Nodo *lista = NULL;
    Imprimir(lista);
    printf("--------------------------------\n");
    lista = annadir_final(lista,1);
    lista = annadir_final(lista,2);
    lista = annadir_final(lista,3);
    lista = annadir_final(lista,4);
    lista = annadir_final(lista,5);
    Imprimir(lista);
    lista = annadir_in_K(lista,6,2);
    printf("--------------------------------\n");


    return 0;
}
