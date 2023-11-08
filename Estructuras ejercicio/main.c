#include <stdio.h>
#include <malloc.h>

/*Realizar una estructura para manejar los productos y compras de un negocio pequeño,
 *almacenando los datos de productos y compras realizadas en ficheros*/

typedef struct{
    char *codigo;
    int valor_total;
}Compra;

void Obtener_registros(char *nombre, Compra *compras) {
    FILE *p_archivo;

    //se verifica la existencia del archivo
    if ((p_archivo = fopen(nombre, "r+")) == NULL) {
        printf("Archivo no existente\nGenarando archivo...\n");
        p_archivo = fopen(nombre, "w");
    }

    int i = 0;
    //se lee la informacion

    int valor=0;
    while(!feof(p_archivo)){ //!feof(archivo) determina el final del archivo, por lo que sera true si es 0, aun no ha llegado al final
        char *codigo = (char*)malloc(12*sizeof(char));
        fscanf(p_archivo, "CODIGO:%s\n", codigo);
        fscanf(p_archivo, "VALOR:%d\n", &valor);
        compras[i].codigo = codigo;
        compras[i].valor_total = valor;
        i++;
    }

    //se cierra el archivo
    fclose(p_archivo);
}

void Realizar_registros(char *nombre, Compra *compras, int registro_compras){
    FILE *p_archivo;

    //se verifica la existencia del archivo
    if((p_archivo = fopen(nombre,"r+"))==NULL){
        printf("Archivo no existente\nGenarando archivo...\n");
        p_archivo = fopen(nombre,"w");
    }

    //se le añade informacion
    //todo: el formato de escritura debe ser el mismo que el de lectura
    for(int i = 0; i < registro_compras; i++){
        fprintf(p_archivo,"CODIGO:%s VALOR:%d\n", compras[i].codigo, compras[i].valor_total);
        if(i == registro_compras-1){
            printf("El archivo guardo la informacion\n");
        }
    }
    //se cierra el archivo
    fclose(p_archivo);
}


int main() {
    char *nombre_archivo="Compras.txt";
    int registro_compra = 4;
    Compra *compras = (Compra*)malloc(10*sizeof(Compra));

    compras[0].valor_total=10120;
    compras[0].codigo = "A9120";
    compras[1].valor_total=3890;
    compras[1].codigo = "A9121";
    compras[2].valor_total=47190;
    compras[2].codigo = "A9122";
    compras[3].valor_total=1010;
    compras[3].codigo = "A9123";
    Realizar_registros(nombre_archivo,compras,registro_compra);

    Obtener_registros(nombre_archivo,compras);
    printf("CODIGO:%s -- VALOR:%d\n",compras[0].codigo,compras[0].valor_total);
    printf("CODIGO:%s -- VALOR:%d\n",compras[1].codigo,compras[1].valor_total);
    printf("CODIGO:%s -- VALOR:%d\n",compras[2].codigo,compras[2].valor_total);
    printf("CODIGO:%s -- VALOR:%d\n",compras[3].codigo,compras[3].valor_total);
    return 0;
}
