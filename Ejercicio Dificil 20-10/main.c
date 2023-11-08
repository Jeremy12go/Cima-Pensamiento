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

    (*registro)++;
    return *compra;
}

void print_compra(Compra compra, int registro){

    printf("Compra: #%i\n",registro);
    print_fecha(*compra.fecha);

    int i = 0;
    while (compra.Producto != NULL){
        print_producto(compra.Producto[i]);
        printf("---------------------------------\n");
        i++;
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

    compras[0] = in_compra(fechas[0],productos,registro_compras,1);
    compras[1] = in_compra(fechas[1],productos,registro_compras,2);
    compras[2] = in_compra(fechas[2],productos,registro_compras,3);
    return compras;
}

void annadir(Compra *arr, int *largo, Compra *c_ingresada){
    Compra *aux_1 = (Compra*)malloc(sizeof(Compra));
    Producto *producto = (Producto*)malloc(sizeof(Producto));
    Fecha *fecha = (Fecha*) malloc(sizeof (Fecha));
    aux_1->Producto = producto;
    aux_1->fecha = fecha;
    Compra *aux_2 = aux_1;
    aux_2->Producto = producto;
    aux_2->fecha = fecha;

    for (int i = 0; i < (*largo+1); ++i) {
        if(i==0){
            //guardar los valores de arr[i] en un aux
            aux_1->fecha = (arr+i)->fecha;
            aux_1->Producto->precio = (arr+i)->Producto->precio;
            aux_1->Producto->peso = (arr+i)->Producto->peso;
            aux_1->Producto->nombre = (arr+i)->Producto->nombre;
            aux_1->Producto->codigo = (arr+i)->Producto->codigo;
            aux_1->peso_total = (arr+i)->peso_total;
            aux_1->valor_total = (arr+i)->valor_total;

            //reemplazar el nuevo valor en arr[i]
            arr->fecha = c_ingresada->fecha;
            arr->Producto->precio = c_ingresada->Producto->precio;
            arr->Producto->peso = c_ingresada->Producto->peso;
            arr->Producto->nombre = c_ingresada->Producto->nombre;
            arr->Producto->codigo = c_ingresada->Producto->codigo;
            arr->peso_total = c_ingresada->peso_total;
            arr->valor_total = c_ingresada->valor_total;
        }else{
            //guardar el siguiente valor en un aux
            aux_2->fecha = (arr+i)->fecha;
            aux_2->Producto->precio = (arr+i)->Producto->precio;
            aux_2->Producto->peso = (arr+i)->Producto->peso;
            aux_2->Producto->nombre = (arr+i)->Producto->nombre;
            aux_2->Producto->codigo = (arr+i)->Producto->codigo;
            aux_2->peso_total = (arr+i)->peso_total;
            aux_2->valor_total = (arr+i)->valor_total;

            //reemplar el valor anterios
            (arr+i)->fecha = aux_1->fecha;
            (arr+i)->Producto->precio = aux_1->Producto->precio;
            (arr+i)->Producto->peso = aux_1->Producto->peso;
            (arr+i)->Producto->nombre = aux_1->Producto->nombre;
            (arr+i)->Producto->codigo = aux_1->Producto->codigo;
            (arr+i)->peso_total = aux_1->peso_total;
            (arr+i)->valor_total = aux_1->valor_total;

            //guardar la siguiente compra a ingresar
            aux_1->fecha = aux_2->fecha;
            aux_1->Producto->precio = aux_2->Producto->precio;
            aux_1->Producto->peso = aux_2->Producto->peso;
            aux_1->Producto->nombre = aux_2->Producto->nombre;
            aux_1->Producto->codigo = aux_2->Producto->codigo;
            aux_1->peso_total = aux_2->peso_total;
            aux_1->valor_total = aux_2->valor_total;
            aux_1 = aux_2;
        }
    }
    (*largo)++;
}

void eliminar(int *largo){
    (*largo)--;
}

void imprimir_cola_compras(Compra *compras, int  cantidad_compras){
    for(int i = 1; i <= cantidad_compras; i++){
        print_compra(*(compras+i-1),i);
    }
}

int main() {
    //todo:---------------------Variables de registro-----------------------------
    int registro_compras = 0;
    int *p_Rcompras = &registro_compras;
    int cantidad_compras = 12;

    //todo:---------------------------Fechas-----------------------------------
    Fecha *fechas = asignacion_v_Fecha(cantidad_compras);

    //todo:---------------------------Productos-----------------------------------
    int cantidad_productos=30;
    Producto *productos = asignacion_v_Productos(cantidad_productos);

    //todo:---------------------------Compras-----------------------------------
    Compra *compras = asignacion_v_Compras(cantidad_compras,fechas,productos,p_Rcompras);
    imprimir_cola_compras(compras,2);






    return 0;
}
