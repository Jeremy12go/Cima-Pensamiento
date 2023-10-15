#include <stdio.h>
#include <malloc.h>

void v_arreglo(int *arr, int largo){
    for (int i = 0; i < largo; ++i) {
        *(arr+i)=i;
    }
}

void imprimir_arreglo(int *arr, int largo){
    printf("|");
    for (int i = 0; i < largo; ++i) {
        printf("%d|",*(arr+i));
    }
    printf("\n");
}











void annadir(int *arr, int *largo, int v_ingresado){
    int aux_1, aux_2;

    for (int i = 0; i < (*largo+1); ++i) {
        if(i==0){
            aux_1 = *(arr+i);
            *(arr+i) = v_ingresado;
        }else{
            aux_2 = *(arr+i);
            *(arr+i) = aux_1;
            aux_1 = aux_2;
        }
    }
    (*largo)++;
}

void eliminar(int *largo){
    (*largo)--;
}

int main() {
    int largo = 10;
    int *p = &largo;

    int* arr = (int*)malloc(largo*2*sizeof(int));
    v_arreglo(arr,largo);

    imprimir_arreglo(arr,largo);

    annadir(arr,p,10);
    imprimir_arreglo(arr,*p);

    annadir(arr,p,15);
    imprimir_arreglo(arr,*p);

    eliminar(p);
    imprimir_arreglo(arr,largo);
    
    return 0;
}
