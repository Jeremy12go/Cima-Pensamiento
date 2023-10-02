#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir_matriz(int m, int n, int matriz[m][n]){

    for(int i = 0; i < m;i++){
        printf("|");
        for(int j = 0; j < n; j++){
            printf("%d|",matriz[i][j]);
        }
        printf("\n");
    }
}

//todo: ejercicio 1 semana pasada
float Centigrados_to_Fahrenheit(float grado_C){
    return 32+((9*grado_C)/5);
}

//todo: ejercicio 2 semana pasada
void matriz(int m, int n){

    int matriz_q[m][n];
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if(i==j || i==(m-j-1) || j==(n-i-1)){
                matriz_q[i][j]=1;
            }else{
                matriz_q[i][j]=0;
            }
        }
    }
    imprimir_matriz(m,n,matriz_q);
}

void arreglos(){
    char arreglo_A[]= {'H','o','l','a',' ','M','u','n','d','o','!'};
    int largo_arr_A=sizeof(arreglo_A)/sizeof(arreglo_A[0]);

    int arreglo_B[largo_arr_A];

    //recorrer un arreglo
    for(int i=0;i<largo_arr_A;i++){
        arreglo_B[i]=(int)arreglo_A[i];
    }

    //imprimir
    printf("[");
    for(int i=0;i<largo_arr_A;i++){
        printf("%c",arreglo_A[i]);
    }
    printf("]\n[");
    for(int i=0;i<largo_arr_A;i++){
        printf("%i ",arreglo_B[i]);
    }
    printf("]");
}

void numero_random(){

    int numero_max = 3;
    int numero_min = 0;

    int n = rand() % (numero_max)+numero_min;

    printf("\nNumero random:%d",n);
}

int largo_cadena(char cadena[]){
    int largo = 0;
    while (cadena[largo] != '\0') {
        largo += 1;
    }
    return largo;
}

int largo_cadena_2(char cad[]){
    int i=0;
    while (cad[i]!='\0'){i++;}
    return i;
}

void cadenas_1(char cadena_A[]){

    //concatenar cadenas
    int largo_A = largo_cadena(cadena_A);
    char cadena_B[]="Mundo!";
    int largo_B = largo_cadena(cadena_A);
    char cadena_D[255];

    int indice = 0;
    int i = 0;
    while (cadena_A[i] != '\0') {
        cadena_D[indice]=cadena_A[i];
        indice++;
        i++;
    }
    i=largo_B-1;
    while (i>=0) {
        cadena_D[indice]=cadena_B[i];
        indice++;
        i--;
    }

    printf("\nCadena D: %s",cadena_D);
}

void cadenas_2(){

    char cad_1[]="hola\0";
    char cad_2[]={"hola\0"};
    largo_cadena_2(cad_2);
    cad_1[0]='b';

    printf("\n1:%s --- 2:%s",cad_1,cad_2);
}

//todo: ejercicio 1 esta semana
void ejercicio(char cadena_A[],char cadena_B[]){
    char cadena_C[]="";

    int largo_A = largo_cadena(cadena_A);
    int largo_B = largo_cadena(cadena_B);
    int indice_A = 0;
    int indice_B = largo_B-1;
    int indice_C = 0;


    while (cadena_A[indice_A] != '\0' || cadena_B[indice_B]!= '\0'){
        if(indice_C%2==0){
            if(indice_A<=largo_A-1){
                cadena_C[indice_C]=cadena_A[indice_A];
                indice_A++;
            }
        }else{
            if(indice_B>=0){
                cadena_C[indice_C]=cadena_B[indice_B];
                indice_B--;
            }
        }
        indice_C++;
    }
    printf("\nCadenaA: %s +++ CadenaB: %s   ->>  resultado: %s",cadena_A,cadena_B,cadena_C);

}

//todo: ejercicio PALINDROMO esta semana

void palindromo(char cadena[]){
    int largo = 0;
    for(; cadena[largo] != '\0' ;largo++){
    }

    bool condicion = true;

    for(int i = 0; i<largo ; i++){
        if(cadena[i] != cadena[largo-1]){
            condicion=false;
        }
        largo--;
    }
    if(condicion){
        printf("Es palindromo");
    }else{
        printf("No es palindromo");
    }
}


int main() {
    /*
    //todo:ejercicio 1------------------------------------
    float F = Centigrados_to_Fahrenheit(-17.7778);
    printf("%.2f\n",F);

    //todo:ejercicio 2------------------------------------
    matriz(7,7);

    //todo:arreglos---------------------------------------
    arreglos();

    //todo:numeros random---------------------------------
    srand (time(NULL));//semilla, siempre debe existir srand en el main, para que en cada ejecucion, cambien la semilla
    numero_random();

    //todo:cadenas----------------------------------------
    cadenas_1("Holaa");
    cadenas_2();

    //todo:ejercicio de cadenas---------------------------
    ejercicio("Mar\0","Pez\0");
    return 0;*/
    //palindromo("reconocer\0");

}
