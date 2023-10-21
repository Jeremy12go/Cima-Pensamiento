#include <stdio.h>
#include <malloc.h>

typedef struct Nodo{
    struct Nodo *next;
    int valor;
}Nodo;

Nodo *crear_Lista(int n){
    Nodo *head;
    Nodo *actual;

    for(int i = 0; i < n; i++){
        if( i == 0){
            head = (Nodo*)malloc(sizeof (Nodo));
            head->valor = i;
            actual = head;
        }else{
            Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
            nuevo->valor = i;
            nuevo->next = NULL;
            actual->next = nuevo;
            actual = nuevo;
        }
    }
    return head;
}

void imprimir(Nodo *head){
    while (head != NULL){
        printf("%d -> ",head->valor);
        head = head->next;
    }
    printf("NULL");
}



int main() {
    Nodo *head = crear_Lista(6);

    imprimir(head);

    return 0;
}
