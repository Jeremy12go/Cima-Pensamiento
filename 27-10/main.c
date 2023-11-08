#include <stdio.h>
#include <malloc.h>

typedef struct{
    int dia;
    int mes;
    int anno;
}Fecha;

typedef struct {
    char *nombre;
    char nombrae[20];
    Fecha fecha;
}Sec_A, Sec_B;


int main() {
    printf("Hello, World!\n");
    int cantidad = 12;
    Amigo *amigos = (Amigo*)malloc(cantidad*sizeof(Amigo));
    Familiar *familiares = (Familiar*)malloc(cantidad*sizeof(Familiar));


    return 0;
}
