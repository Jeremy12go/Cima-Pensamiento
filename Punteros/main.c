#include <stdio.h>
#include <malloc.h>
#include <time.h>

int largo_cad(char *cad){
    int i = 0;
    while (cad[i]!='\0'){i++;}
    return i;
}

void add_v_arr(int *arr, int n){
    for(int i=0;i<n;i++){
        *(arr+i)=i+1; //Ingreso de datos por aritmetica de punteros
        //arregloPuntero[i]=i+1; //Ingreso de datos de forma comun
    }
}


void imprimir_arr(int *arr, int n){
    printf("\n|");
    for (int i = 0; i < n; ++i) {
        printf("%d|",*(arr+i));
    }
}

void funcion(int *arr){
    int *puntero;
    puntero = &arr[3];
    *puntero = 14;
}

void funcion_2(int *arr, int largo){
    int temp;
    int j = largo-1;
    for (int i = 0; i < largo/2; ++i) {
        temp = *(arr+i);
        *(arr+i) = *(arr+j);
        *(arr+j) = temp;
        j--;
    }
}

void funcion_3(){

    int largo = 12;

    int *arreglo = (int*)calloc(largo,sizeof (int));

    int *arregloPuntero = (int*)malloc( largo * sizeof (int));

    add_v_arr(arreglo,largo);
    imprimir_arr(arreglo,largo);

    //printf("\n%d",arregloPuntero[0]);//imprimira basura
    //printf("\n%d",arreglo[0]);//imprimira 0

}

void ejercicio_cad_random(char *cad, int largo){


}

int main() {
    srand(time(NULL));
    int arr[] = {1,2,3,4,5};
    int largo_arr = sizeof(arr)/sizeof(arr[0]);

    imprimir_arr(arr,largo_arr);
    funcion(arr);
    imprimir_arr(arr,largo_arr);
    funcion_2(arr,largo_arr);
    imprimir_arr(arr,largo_arr);

    funcion_3();


    return 0;
}
