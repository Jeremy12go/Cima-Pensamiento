#include <stdio.h>
#include <malloc.h>


void print_arr(int n, int *arr){
    printf("|");
    for (int i = 0; i < n; ++i) {
        printf("%d|",arr[i]);
    }
    printf("\n");
}

void swap(int idx_before, int idx_after, int* arr){
    int temp = arr[idx_before];
    arr[idx_before] = arr[idx_after];
    arr[idx_after] = temp;
}

void swap_p(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int n, int *arreglo){
    for(int i = 0; i < n-1 ; i++){
        for(int j=0 ; j<n-1-i ; j++){
            if(arreglo[j] > arreglo[j+1]){
                swap(j,j+1,arreglo);
            }
        }
    }
}

void insertion_sort(int n, int* arreglo){
    int i,j;
    int actual;
    for (i = 1; i < n; i++) {
        actual = arreglo[i]; //actual toma el segundo elemento
        for (j = i; j > 0 && arreglo[j-1] > actual; j--){ // compara si el primer elemento es mayor que el segundo(actual)
            arreglo[j] = arreglo[j - 1]; //intercambia (mueve hacia la izquierda) todos elementos hasta i
        }
        arreglo[j] = actual; //cuando termina el ciclo actual se posiciona, ya que no es menor que el siguiente numero
    }
}

void selection_sort(int n, int* arreglo){
    int actual, menor, j;
    for (actual=0; actual<n-1; actual++) {
        menor = actual;
        for (j = actual; j < n; j++) {
            if (arreglo[j] < arreglo[menor]) {
                menor = j;
            }
        }
        swap(actual,menor,arreglo);
    }
}

int partition(int menor, int mayor, int* arreglo){

    int pivote = arreglo[mayor];
    int i = (menor-1);

    for (int j = menor; j <= mayor-1; j++) {
       if(arreglo[j] < pivote){
           i++;
           swap(i,j,arreglo);
       }

    }
    swap(i+1,mayor,arreglo);
    return (i+1);
}

void quick_sort(int menor, int mayor, int* arreglo){
    if(menor < mayor){
        int part = partition(menor, mayor, arreglo);
        quick_sort(menor ,part-1,arreglo);
        quick_sort(part+1 ,mayor ,arreglo);
    }
}

int main() {
    //todo: ordenamientos~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int arr[] = {7,5,1,3,9,4,8};
    int largo = sizeof (arr)/sizeof(arr[0]);

    print_arr(largo,arr);
    //bubble_sort(largo,arr);
    //insertion_sort(largo,arr);
    //selection_sort(largo,arr);
    quick_sort(0,largo-1,arr);
    print_arr(largo,arr);

    /*todo: punteros basico~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int valor = 9;
    int* puntero = &valor; //el puntero(*) apunta(&) a la variable valor

    *puntero = *puntero * 13; //el puntero(*) multiplica su propio valor en 13
    //los cambios se han realizado en la variable, pese a no trabajar con la variable directamente
    printf("%d\n",valor);
    //podemos imprimir el valor que tiene la direccion de memoria a la que apunta, recuperando la informacion con (*)
    printf("%d\n",*puntero);
    printf("%p",puntero); //podemos imprimir la direccion de memoria a la que apunta
    *///todo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    return 0;
}
