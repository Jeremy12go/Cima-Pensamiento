#include <stdio.h>
#include <malloc.h>

typedef struct{
    int dia;
    int mes;
    int anno;
}Fecha;

typedef struct{
    char *nombre;
    char *codigo;
    int precio;
    int peso;
}Producto;

typedef struct{
    Fecha *fecha;
    Producto *Producto;
    int valor_total;
    int peso_total;
}Compra;

Fecha in_fecha(int dia, int mes, int anno){
    Fecha *fecha = (Fecha*)malloc(sizeof(Fecha));
    fecha->dia = dia;
    fecha->mes = mes;
    fecha->anno = anno;
    return *fecha;
}

void print_fecha(Fecha fecha){
    printf("Fecha:%d/%d/%d\n",fecha.dia,fecha.anno,fecha.mes);
}

Producto in_producto(int precio, int peso, char *codigo, char *nombre){
    Producto *producto = (Producto*)malloc(sizeof(Producto));
    producto->precio = precio;
    producto->peso = peso;
    producto->codigo = codigo;
    producto->nombre = nombre;
    return *producto;
}
void print_producto(Producto producto){
    printf("Nombre:%s\n",producto.nombre);
    printf("Precio:%d\n",producto.precio);
    printf("Peso:%d\n",producto.peso);
    printf("Codigo:%s\n",producto.codigo);
}

int v_max(Compra compra, int cont_productos){
    int aux = 0;
    for(int i = 0; i < cont_productos; i++){
        aux += compra.Producto[i].precio;
    }
    return aux;
}

int p_max(Compra compra, int cont_productos){
    int aux = 0;
    for(int i = 0; i < cont_productos; i++){
        aux += compra.Producto[i].peso;
    }
    return aux;
}

Compra in_compra(Fecha fecha, Producto *producto, int *registro, int cantidad_productos){
    Compra *compra = (Compra*)malloc(sizeof(Compra));

    compra->fecha->dia = fecha.dia;
    compra->fecha->mes = fecha.mes;
    compra->fecha->anno = fecha.anno;

    for(int i = 0; i < cantidad_productos; i++){
        compra->Producto[i].nombre = producto[i].nombre;
        compra->Producto[i].codigo = producto[i].codigo;
        compra->Producto[i].peso = producto[i].peso;
        compra->Producto[i].precio = producto[i].precio;
    }

    compra->peso_total = p_max(*compra,cantidad_productos);
    compra->valor_total = v_max(*compra,cantidad_productos);

    *(registro)++;
    return *compra;
}

void print_compras(Compra compra,int *registro, int cantidad_productos){

    printf("Compra: #%i\n",*registro);
    print_fecha(*compra.fecha);

    for(int i = 0; i < cantidad_productos; i++){
        print_producto(compra.Producto[i]);
        if(i<cantidad_productos-1){
            printf("---------------------------------\n");
        }
    }

    printf("Precio total:%d\n",compra.valor_total);
    printf("Peso total:%d\n",compra.peso_total);
}

int main() {
    int registro_compras = 1;
    int *p_Rcompras = &registro_compras;

    int cantidad_productos=3;
    Producto *productos = (Producto*)malloc(cantidad_productos*sizeof(Producto));

    Fecha fecha_1 = in_fecha(10,2,199);

    productos[0] = in_producto(2000, 12, "p001", "Palta");
    productos[1] = in_producto(3000, 23, "p002", "Tomate");
    productos[2] = in_producto(1500, 10, "p002", "Mayo");
    //Compra *compras = (Compra*)malloc(12*sizeof(Compra));

    Compra compras = in_compra(fecha_1,productos,p_Rcompras,3);
    print_compras(compras,p_Rcompras,3);

    return 0;
}
