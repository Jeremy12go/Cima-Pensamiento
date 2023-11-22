#include <stdio.h>
#include <malloc.h>

typedef struct Nodo{
    int valor;
    struct Nodo *next;
}Minodo;

Minodo* CrearLista(int n){
    Minodo *head;
    Minodo *actual;

    for(int i=0;i<=n;i++){
        Minodo *nuevo;
        if(i==0){
            head=malloc(sizeof(Minodo*));
            head->valor=i;
            actual=head;
        }else{
            nuevo= malloc(sizeof (Minodo*));
            nuevo->valor=i;
            actual->next=nuevo;
            nuevo->next=NULL;
            actual=nuevo;
        }
    }
    return head;
}

void Imprimir(Minodo *head){
    Minodo *actual=head;
    while(actual!=NULL){
        printf("%d-> ",actual->valor);
        actual=actual->next;
    }
    printf("NULL\n");
}

Minodo* Annadir_F_Pila(Minodo *head,int valor){
    Minodo *actual=head;
    Minodo *nuevo= malloc(sizeof (Minodo*));
    nuevo->next=actual;
    nuevo->valor=valor;
    head=nuevo;
    return head;
}

Minodo* Eliminar_F_Pila(Minodo *head){
    Minodo *actual=head->next;
    head->next=NULL;
    return actual;
}

Minodo* Annadir_F_Cola(Minodo *head,int valor){
    Minodo *actual=head;
    Minodo *nuevo= malloc(sizeof (Minodo*));

    //llegar al final
    while(actual->next!=NULL){
        actual=actual->next;
    }
    actual->next=nuevo;
    nuevo->valor=valor;
    nuevo->next=NULL;

    return head;
}

Minodo* Eliminar_F_Cola(Minodo *head){
    Minodo *actual=head->next;
    head->next=NULL;
    return actual;
}

int main() {

    Minodo *head=CrearLista(10);
    Imprimir(head);

    //pila
    head=Annadir_F_Pila(head,20);
    Imprimir(head);
    for(int i=0;i<5;i++){
        head=Eliminar_F_Pila(head);
    }
    Imprimir(head);

    //cola
    head= Annadir_F_Cola(head,44);
    Imprimir(head);
    head= Eliminar_F_Cola(head);
    Imprimir(head);

    return 0;
}
