#include <stdio.h>
#include <malloc.h>

typedef struct Nodo{
    int valor;
    struct Nodo *left;
    struct Nodo *right;
}Minodo;

Minodo* CrearLista(int n){
    Minodo *head;
    Minodo *actual;

    for(int i=0;i<=n;i++){
        Minodo *nuevo;
        if(i==0){
            head=malloc(sizeof(Minodo*));
            head->valor=i;
            head->left=NULL;
            head->right=NULL;
            actual=head;
        }else{
            nuevo= malloc(sizeof (Minodo*));
            nuevo->valor=i;
            actual->right=nuevo;
            nuevo->right=NULL;
            nuevo->left=actual;
            actual=nuevo;
        }
    }
    return head;
}

Minodo *Imprimir_left(Minodo *head){
    Minodo *actual=head;
    if(head==NULL){
        return 0;
    }else{
        printf("%d-> ",actual->valor);
        Imprimir_left(actual->right);
        return 0;
    }
}

Minodo *Imprimir_right(Minodo *head){

    if(head==NULL){
        return 0;
    }else{
        Imprimir_right(head->right);
        printf("%d-> ",head->valor);
        return 0;
    }
}

Minodo *Agregar_final(int direccion, int valor,Minodo *head){
    Minodo *actual=head;
    Minodo *nuevo= malloc(sizeof (Minodo*));

    if(direccion==1) {
        while(actual->right!=NULL){
            actual=actual->right;
        }
        actual->right=nuevo;
        nuevo->valor=valor;
        nuevo->right=NULL;
        Imprimir_left(head);
        printf("NULL\n");
    }else if(direccion==2){
        nuevo->right = actual;
        nuevo->valor = valor;
        head = nuevo;
        Imprimir_right(head);
        printf("NULL\n");
    }else{
        printf("La direccion \"%d\" es invalida",direccion);
    }
    return head;
}

Minodo  *Eliminar(int direccion, int valor, Minodo *head){
    Minodo *actual=head;
    Minodo *nuevo= malloc(sizeof (Minodo*));

    if(direccion==1) {
        while(actual->right->right!=NULL){
            if(actual->right->valor==valor){
                break;
            }
            actual=actual->right;
        }
        if(actual->right->right==NULL){
            printf("No se encontro el valor");
            return 0;
        }else{
            actual->right=actual->right->right;
        }
        Imprimir_left(head);
        printf("NULL\n");
    }else if(direccion==2){
        while(actual->right!=NULL){
            if(actual->valor==valor){
                break;
            }
            actual=actual->right;
        }
        if(actual->right==NULL){
            printf("No se encontro el valor");
            return 0;
        }else{
            actual->left->right=actual->right->right;
        }
        Imprimir_right(head);
        printf("NULL\n");
    }else{
        printf("La direccion \"%d\" es invalida",direccion);
    }
    return head;
}

int Buscar(int direccion, int valor, Minodo *head){
    Minodo *actual=head;
    int contador=1;
    if(direccion==1) {
        while(actual->right!=NULL){
            if(actual->valor==valor){
                printf("El valor -%d- se encuentra en la posicion:%d\n",valor,contador);
                break;
            }
            contador++;
            actual=actual->right;
        }
        if(actual->right->right==NULL){
            printf("No se encontro el valor\n");
            contador=-1;
            return contador;
        }
    }else if(direccion==2){
        int maximo=0;
        while(actual->right!=NULL){
            actual=actual->right;
            maximo++;
        }
        actual=head;
        while(actual->right!=NULL){
            if(actual->valor==valor) {
                break;
            }
            contador++;
            actual=actual->right;
        }

        if(actual->left->left==NULL){
            printf("No se encontro el valor\n");
            contador=-1;
            return contador;
        }else{
            contador=maximo-contador;
            printf("El valor -%d- se encuentra en la posicion:%d\n",valor,contador);
        }

    }else{
        printf("La direccion \"%d\" es invalida\n",direccion);
    }
    return contador;
}

int main() {
    Minodo *head= CrearLista(10);
    Imprimir_left(head);
    printf("NULL\n");
    head=Agregar_final(1,13,head);
    head= Agregar_final(2,25,head);
    head= Eliminar(1,8,head);
    head= Eliminar(2,5,head);
    Buscar(1,3,head);
    Buscar(2,3,head);
    return 0;
}
