#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo *next;
}Minodo;

Minodo *crear_lista(int n){
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
    while(head!=NULL){
        printf("%d-> ",head->valor);
        head=head->next;
    }
    printf("NULL\n");
}

Minodo *ordenar_lista(Minodo *head){
    Minodo *actual=head;
    Minodo *pre;
    Minodo *min;
    Minodo *nueva_lista;

    while(actual!=NULL) {
        int valor_min=actual->valor;

        //buscar el menor
        while(actual->next->next!=NULL) {
            if (valor_min > actual->valor) {
                valor_min = actual->valor;
                printf("Anterior:%d -- Actual:%d -- Min:%d\n",actual->valor,actual->next->valor,valor_min);
                pre=actual;
                min=actual->next;
            }
            actual=actual->next;
        }
        if(valor_min==head->valor){
            head=actual;
        }
        if(min->next!=NULL){
            printf("Pre_Nodo:%d -- Pos_Nodo:%d\n", pre->valor,min->next->valor);
            pre->next=min->next;
        }
        actual=head;

        Imprimir(head);

        //Colocar el nodo en la nueva lista
        if(nueva_lista==NULL){
            nueva_lista=min;
        }else{
            nueva_lista->next=min;
        }
    }

    return nueva_lista;
}

int main() {
    srand(time(NULL));

    Minodo *nodo= crear_lista(10);
    Imprimir(nodo);

    nodo= ordenar_lista(nodo);
    Imprimir(nodo);
    return 0;
}
