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
    printf("Fecha:%d/%d/%d\n",fecha.dia,fecha.mes,fecha.anno);
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
    //asignacion de memoria, para estructura dentro de la estructura
    compra->fecha = (Fecha*)malloc(sizeof(Fecha));
    compra->Producto = (Producto*) malloc(cantidad_productos*sizeof(Producto));

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

void print_compra(Compra compra, int *registro, int cantidad_productos){

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

Fecha* asignacion_v_Fecha(int n){
    Fecha *fechas = (Fecha*)malloc(n*sizeof(Fecha));
    fechas[0] = in_fecha(10,02,2023);
    fechas[1] = in_fecha(22,03,2023);
    fechas[2] = in_fecha(10,02,2023);
    fechas[3] = in_fecha(22,03,2023);
    fechas[4] = in_fecha(22,03,2023);
    return fechas;
}

Producto* asignacion_v_Productos(int n){
    Producto *productos = (Producto*)malloc(n*sizeof(Producto));
    productos[0] = in_producto(2000, 12, "p001", "Palta");
    productos[1] = in_producto(3000, 23, "p002", "Tomate");
    productos[2] = in_producto(1500, 10, "p003", "Mayo");
    productos[3] = in_producto(2450, 11, "p004", "Pan");
    productos[4] = in_producto(3100, 9, "p005", "Vianesas");
    productos[5] = in_producto(1510, 10, "p006", "Aceite");
    productos[6] = in_producto(2080, 12, "p007", "Coca-Cola");
    productos[7] = in_producto(3420, 18, "p008", "Queso");
    productos[8] = in_producto(1590, 11, "p009", "Leche");
    return productos;
}

Compra* asignacion_v_Compras(int n, Fecha *fechas, Producto* productos, int *registro_compras){
    Compra *compras = (Compra*)malloc(n*sizeof(Compra)); //Cola de 12 elementos

    compras[0] = in_compra(fechas[0],productos,registro_compras,3);

    return compras;
}

int main() {
    //todo:---------------------Variables de registro-----------------------------
    int registro_compras = 1;
    int *p_Rcompras = &registro_compras;
    int cantidad_compras = 12;

    //todo:---------------------------Fechas-----------------------------------
    Fecha *fechas = asignacion_v_Fecha(cantidad_compras);

    //todo:---------------------------Productos-----------------------------------
    int cantidad_productos=30;
    Producto *productos = asignacion_v_Productos(cantidad_productos);

    //todo:---------------------------Compras-----------------------------------
    Compra *compras = asignacion_v_Compras(cantidad_compras,fechas,productos,p_Rcompras);
    print_compra(*(compras+0),p_Rcompras,3);

    return 0;
}
