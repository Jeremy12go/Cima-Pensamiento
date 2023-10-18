#include <stdio.h>
#include <malloc.h>

//todo:-------------------forma_1_definir estructuras----------------------
struct Libro{ //nombre
    //atributos
    char* titulo;
    char* autor;
    float precio;
    int anno_publicacion;
};

struct Libreria{ //nombre
    //atributos
    struct Libro libro;
    char* tematica;
};

//todo:-------------------forma_2_definir estructuras----------------------
typedef struct{
    //atributos
    float kilos;
    char *tipo;
}Producto; //nombre

typedef struct{
    //atributos
    float altura;
    float anchura;
    float largura;
    char* tipo_material;
    Producto* producto;
}Cajon; //nombre

Cajon ingreso_datos_CajonesProductos_1(float _altura, float _anchura, float _largura, char *material, char *tipo_producto, float kilos_producto){
    Cajon *_cajon = (Cajon*)malloc(sizeof(Cajon));
    Producto *_producto = (Producto*)malloc(sizeof(Producto));

    _cajon->altura = _altura;
    _cajon->anchura = _anchura;
    _cajon->largura = _largura;
    _cajon->tipo_material = material;
    _cajon->producto = _producto;
    _cajon->producto->tipo = tipo_producto;
    _cajon->producto->kilos = kilos_producto;

    return *_cajon;
}

void ingreso_datos_CajonesProductos_2(Cajon _cajon[], int indice){

    printf("Ingresar altura del cajon:");
    scanf("%f",&_cajon[indice].altura);
    getchar();

    printf("Ingresar anchura del cajon:");
    scanf("%f",&_cajon[indice].anchura);
    getchar();

    printf("Ingresar largura del cajon:");
    scanf("%f",&_cajon[indice].largura);
    getchar();

    printf("Ingresar tipo de material del cajon:");
    fgets(_cajon[indice].tipo_material, 255, stdin);

    printf("Ingresar tipo de producto:");
    fgets(_cajon[indice].producto->tipo, 255, stdin);

    printf("Ingresar peso del producto:");
    scanf("%f",&_cajon[indice].producto->kilos);
    getchar();

}

struct Libreria ingreso_datos_Librerias_1(char *_tematica, char *_titulo, char *_autor, float _precio, int _anno_publicacion){

    struct Libreria *_libreria = (struct Libreria*)malloc(sizeof(struct Libreria));
    struct Libro *_libro = (struct Libro*)malloc(sizeof(struct Libro));

    _libreria->tematica = _tematica;
    _libreria->libro = *_libro;
    _libreria->libro.titulo = _titulo;
    _libreria->libro.autor = _autor;
    _libreria->libro.precio = _precio;
    _libreria->libro.anno_publicacion = _anno_publicacion;

    return *_libreria;
}

void ingreso_datos_Librerias_2(struct Libreria _libreria[], int indice, char *_tematica, char *_titulo, char *_autor, float _precio, int _anno_publicacion){

    _libreria[indice].tematica = _tematica;
    _libreria[indice].libro.titulo = _titulo;
    _libreria[indice].libro.autor = _autor;
    _libreria[indice].libro.precio = _precio;
    _libreria[indice].libro.anno_publicacion = _anno_publicacion;

}

void Imprimir_Cajones(int cantidad, Cajon *cajones){

    for(int i=0;i<cantidad;i++){
        printf("Cajon#%d\n",i);
        printf("Tipo de material:%s\n",cajones[i].tipo_material);
        printf("Dimenciones:%0.1fx%0.1fx%0.1f cm\n",cajones[i].altura,cajones[i].anchura,cajones[i].largura);
        printf("Tipo de producto:%s -- Kilos:%f0.2\n",cajones[i].producto->tipo,cajones[i].producto->kilos);
        if(i<cantidad-1){
            printf("---------------------------------------\n");
        }
    }
}

void Imprimir_Librerias(int cantidad, struct Libreria *libreria){

    for(int i=0;i<cantidad;i++){
        printf("Libreria #%d\n",i);
        printf("Tematica de la libreria:%s\n",libreria[i].tematica);
        printf("Libro:%s\nAutor:%s (%i)\n",libreria[i].libro.titulo, libreria[i].libro.autor,libreria[i].libro.anno_publicacion);
        printf("Valor:%0.1f\n",libreria[i].libro.precio);
        if(i<cantidad-1){
            printf("---------------------------------------\n");
        }
    }
}

int main() {
    int cantidad_elementos = 3;

//todo:----------forma_1_declarar estructuras con typedef (Punteros)-------------------

    Cajon *cajones = (Cajon*)malloc(cantidad_elementos*sizeof(Cajon)); //asignar espacio para nuestro arreglo de tipo Cajon

    *(cajones+0) = ingreso_datos_CajonesProductos_1(2.5,4.5,4.5,"MADERA","TOMATE",23);
    cajones[1] = ingreso_datos_CajonesProductos_1(5,5,5,"CARTON-DURO","GUINDAS",7.5);
    *(cajones+2) = ingreso_datos_CajonesProductos_1(6.6,12,18,"MADERA","MANZANA",40);

    //Imprimir_Cajones(cantidad_elementos,cajones);
//todo:----------forma_2_declarar estructuras con typedef(Parametro por referencia)------
    /*
    Cajon cajones_2[cantidad_elementos];

    ingreso_datos_CajonesProductos_2(cajones_2,0);
    ingreso_datos_CajonesProductos_2(cajones_2,1);
    ingreso_datos_CajonesProductos_2(cajones_2,2);

    Imprimir_Cajones(cantidad_elementos,cajones_2);
    */

//todo:----------forma_1_declarar estructuras sin typedef (Punteros)-------------------

    struct Libreria *libreria = (struct Libreria*) malloc(cantidad_elementos*sizeof(struct Libreria));

    *(libreria+0) = ingreso_datos_Librerias_1("PERRO","El perro","Miguel B",5500,2019);
    libreria[1] = ingreso_datos_Librerias_1("GATO","El gato","NotMiguel B",5500,2018);

    //Imprimir_Librerias(cantidad_elementos-1,libreria);

//todo:----------forma_2_declarar estructuras sin typedef(Parametro por referencia)------

    struct Libreria libreria_2[cantidad_elementos];

    ingreso_datos_Librerias_2( libreria_2,0,"PERRO", "El perro","Miguel B",5500,2019);
    ingreso_datos_Librerias_2(libreria_2, 1, "GATO", "El gato", "NotMiguel B", 5500, 2018);

    Imprimir_Librerias(cantidad_elementos-1,libreria_2);
    return 0;
}
