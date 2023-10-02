#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//constantes
const float pi = 3.1415;
const int maximo_user = 10;

//variables globales
int contador = 0;

void imprimir(int entero, short entero_pequeno, long long entero_grande, double decimal_grande, float decimal, char _string[]){

    printf("short:%i    \nentero:%d    \ngrande:%lli    \n",entero_pequeno,entero,entero_grande);
    printf("decimal_grande:%f  \ndecimal_aproximado:%.2f    \n",decimal_grande,decimal);
    printf("String:%s   \n",_string);
    printf("const:%f    \nconst2:%i \n",pi,maximo_user);

    //datos interesantes de las impresiones en C
    printf("%30s\n", "Hello, world!");  //Imprime una cadena de 30 caracteres agragando espacios a la izquierda para que "Hello, world" los tenga
    printf("%.9s\n", "Hello, world!");  //Imprime una cadena con los primeros 9 caracteres
}

void tamanos_Datos(short entero_pequeno,int entero , double decimal_grande,long long entero_grande ,float decimal, char caracter,char _string[]){
    printf("char: %zu\n",sizeof(caracter)*8);
    printf("short: %zu\n",sizeof(entero_pequeno)*8);
    printf("int: %zu\n",sizeof(entero)*8);
    printf("float: %zu\n",sizeof(decimal)*8);
    printf("double: %zu\n",sizeof(decimal_grande)*8);
    printf("long long: %zu\n",sizeof(entero_grande)*8);
    printf("string: %zu\n",sizeof(_string)*8);
    long _long = 123911231241231;
    printf("long: %zu",sizeof(_long));

}

void declaracion_variables(){

    //Numeros
    short entero_pequeno = 10;
    int entero = 1012301293;
    long long entero_grande = 1919825123125138120;
    double decimal_grande = 192.3812812371293;
    float decimal = 12.2191293912;

    //caracteres
    char caracter = 'a';
    char _string[] = "Hola Mundo!";

    imprimir(entero,entero_pequeno,entero_grande,decimal_grande,decimal,_string);
    printf("___________________________________________\n\n");
    tamanos_Datos(entero_pequeno,entero ,decimal_grande, entero_grande, decimal, caracter, _string);

}

int entrada_numero(){

    int entrada;
    printf("Ingresar un numero:\n");
    scanf("%d",&entrada);

    getchar();//evitar el salto de linea en el búfer

    return entrada;
}

void entrada_cadena(){

    char entrada[] = "";
    printf("Ingresar una cadena:\n");
    fgets(entrada,255,stdin);

    printf("%s",entrada);
}

void condcionales (){

    if(true){
        //bloque de codigo
    }else{
        //bloque de codigo
    }

}

//todo: el retorno de cadenas es solo posible mediante PUNTEROS*
char* entrada_return_cadena(){

    char *entrada = (char*)malloc(sizeof (char*));
    printf("Ingresar una frase:\n");
    fgets(entrada,255,stdin);

    return entrada;
}

void ciclos(){

    int condicion = 10;
    for(int i = 0; i < condicion; i++){
        //bloque de codigo
    }

    bool condicion_1 = true;
    while(condicion_1){
        //bloque de codigo
    }

    bool condicion_2 = false;
    do {
        //bloque de codigo
    } while (!condicion_2);

}

//todo: matriz para el segundo ejercicio, tarea realizar las condicionales para diagonal y anti-diagonal con 1s
void matriz(int m, int n){

    int cantidad_filas = m;
    int cantidad_columnas = n;

    int matriz_q[m][n];
    for(int i = 0; i < cantidad_filas;i++){
        for(int j = 0; j < cantidad_columnas; j++){
            matriz_q[m][n]=0;
        }
    }

    //imprime matriz_q
    for(int i = 0; i < cantidad_filas;i++){
        printf("|");
        for(int j = 0; j < cantidad_columnas; j++){
            printf("%d|",matriz_q[m][n]);
        }
        printf("\n");
    }

}

int main() {
    //todo: llamar a las funciones que quieres ver como funcionan
    matriz(3,3);

    return 0;
}


