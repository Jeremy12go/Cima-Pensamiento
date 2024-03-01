#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo *next;
}Minodo;

Minodo *crear_listaEnlazada(int n){
    Minodo *head;
    Minodo *actual;
    for(int i=0;i<n;i++){
        if(i==0){
            head = malloc(sizeof (Minodo*));
            head->valor=rand() % (100-1+1)+1;
            actual=head;
        }else{
            Minodo *nuevo= malloc(sizeof (Minodo*));
            nuevo->valor=rand() % (100-1+1)+1;;
            nuevo->next=NULL;
            actual->next=nuevo;
            actual=nuevo;
        }
    }
    return head;
}

void Imprimir(Minodo *head){
    Minodo* temp = head;
    while(temp!=NULL){
        printf("%d-> ",temp->valor);
        temp=temp->next;
    }
    printf("NULL\n");
}

Minodo* crear_nodo(int valor) {
    Minodo* nuevo_nodo = malloc(sizeof (Minodo*));
    if (!nuevo_nodo) {
        printf("Error en la asignación de memoria\n");
        exit(0);
    }
    nuevo_nodo->valor = valor;
    nuevo_nodo->next = NULL;
    return nuevo_nodo;
}

Minodo* insertar_nodo(Minodo* head, int valor) {
    Minodo* nuevo_nodo = crear_nodo(valor);
    if (head == NULL) {
        return nuevo_nodo;
    }
    Minodo* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nuevo_nodo;
    return head;
}

Minodo* eliminar_nodo(Minodo* head, int valor_supr) {
    Minodo* temp = head, *prev;

    //comprueba si el nodo a eliminar es head
    if (temp != NULL && temp->valor == valor_supr) {
        head = temp->next;
        free(temp);
        return head;
    }

    //reccore hasta el valor a eliminar
    while (temp != NULL && temp->valor != valor_supr) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head;
    //el nodo previo al valor apunta al nodo siguiente al valor
    prev->next = temp->next;

    free(temp);
    return head;
}

Minodo* ordenar_lista_Mayor_Menor(Minodo* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Minodo* newHead = NULL;
    Minodo* actual = head;
    Minodo* prev = NULL;
    Minodo* maxPrev = NULL;
    Minodo* nodo_max = NULL;

    while (actual != NULL) {
        if (nodo_max == NULL || actual->valor < nodo_max->valor) { // < MENOR A MAYOR > MAYOR A MENOR
            nodo_max = actual;
            maxPrev = prev;
        }
        prev = actual;
        actual = actual->next;
    }

    if (maxPrev != NULL) {
        maxPrev->next = nodo_max->next;
    } else {
        head = nodo_max->next;
    }

    nodo_max->next = newHead;
    newHead = nodo_max;

    newHead->next = ordenar_lista_Mayor_Menor(head); //recursión

    return newHead;
}

int main() {
    srand(time(NULL));

    Minodo* head_1 = NULL;
    head_1 = insertar_nodo(head_1, 7);
    head_1 = insertar_nodo(head_1, 3);
    head_1 = insertar_nodo(head_1, 5);
    head_1 = insertar_nodo(head_1, 2);
    head_1 = insertar_nodo(head_1, 1);

    Minodo *head_2 = crear_listaEnlazada(10);
    Imprimir(head_2);
    head_2 = ordenar_lista_Mayor_Menor(head_2);
    Imprimir(head_2);
    return 0;
}
