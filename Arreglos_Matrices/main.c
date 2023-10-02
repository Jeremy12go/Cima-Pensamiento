#include <stdio.h>

void imprimir_arr(int largo, int arr[]){
    printf("|");
    for(int i = 0 ; i < largo ; i++){
        printf("%d|",arr[i]);
    }
    printf("\n\n");
}

int* arreglo(int largo, int arr[largo]){
    for(int i = 0; i < largo ; i++){
        arr[i] = 0;
    }
    return arr;
}

void imprimir_mat(int filas ,int columnas, int matriz[filas][columnas]){
    for (int i = 0; i < filas; ++i) {
        printf("|");
        for (int j = 0; j < columnas; ++j) {
            printf("%d |",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrizz(int filas, int columnas){
    int matriz[filas][columnas];

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = 1;
        }
    }
    imprimir_mat(filas, columnas, matriz);
}

void contenido(int m, int n, int matriz[m][n], int Arr[n]){

    int condicion_falsa = 0;
    for (int i = 0; i < m; i++) {
        int contador = 0;
        for (int j = 0;  j < n; j++) {
            for (int k = 0; k < n; k++) {
                if(matriz[i][j]==Arr[k]){
                   contador++;
                }
            }
        }
        if(contador == n){
            printf("Esta contenido en M[%d]",i);
            condicion_falsa = 1;
            break;
        }
    }
    if(condicion_falsa == 0){
        printf("No esta contenida en M");
    }
}

void Rcont(int m, int matriz[m][m], int Arr[m], int t){


    for(int i=0;i<m;i++){
        int cont=0;
        for(int j=0;j<m;j++){
            for(int k=0;k < t;k++){
                if (matriz[i][j]==Arr[k]){
                    cont++;
                }
            }
        }
        if(cont==m){
            printf("Esta contenido en a[%i]",i);
            break;
        }
    }

}

int main() {
    //todo:Arreglos~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    int largo = 5;
    int arr_indefinido[largo];
    int* retorno_A = arreglo(largo,arr_indefinido);

    //imprimir_arr(largo,retorno_A);

    int arr_definido[] = {1,2,3,4,5};
    int largo_def = sizeof(arr_definido)/sizeof(arr_definido[0]);
    //imprimir_arr(largo_def,arr_definido);


    //todo:Matrices~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int filas = 4;
    int columnas = 4;

    matrizz(filas,columnas);

    int matriz[][3] = {{1,2,3},{3,2,1},{1,2,3}};
    int f = sizeof(matriz)/sizeof(matriz[0]);
    int c = sizeof(matriz[0])/sizeof(matriz[0][0]);



    int ma[][3] = {{8,3,3},{2,2,1},{3,1,3}};
    imprimir_mat(f,c,ma);
    int tupla[] = {1,2,3};
    Rcont(3,ma,tupla,3);

    return 0;
}
