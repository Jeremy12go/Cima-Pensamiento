#include <stdio.h>

struct Datos_1{
    int v_int;
    float v_float;
    char v_char;
    char* v_string;
};

typedef struct Datos_2{
    int v_int;
    float v_float;
    char v_char;
    char* v_string;
}datos_2 ;

typedef struct Caja{
    int valor;
    datos_2 *datos;
    struct Caja *siguiente;
}Caja_call;

int main() {

    return 0;
}
