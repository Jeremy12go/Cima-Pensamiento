#include <stdio.h>
#include <malloc.h>

typedef struct{
    char *nombre;
    char *apellido;
    char *numero;
    char *correo;
}Persona;

Persona constructor_persona(char* nombre, char* apellido, char* numero, char* correo){
    Persona *persona = (Persona*)malloc(sizeof(Persona));
    persona->nombre=nombre;
    persona->apellido=apellido;
    persona->numero=numero;
    persona->correo=correo;
    return *persona;
}

void imprimir_persona(Persona persona){
    printf("%s\n%s\n%s\n%s\n",persona.nombre, persona.apellido,persona.numero,persona.correo);
}

void Realizar_escritura(char *nombre,Persona *personas, int registro_personas){
    FILE *p_archivo;

    //se verifica la existencia del archivo
    if((p_archivo = fopen(nombre,"r+"))==NULL){
        printf("Archivo no existente\nGenarando archivo...\n");
        p_archivo = fopen(nombre,"w");
    }

    //se le añade informacion
    //todo: el formato de escritura debe ser el mismo que el de lectura
    for(int i = 0; i < registro_personas; i++){
        fprintf(p_archivo,"Nombre:%s Apellido:%s Numero:%s Correo:%s\n", personas[i].nombre, personas[i].apellido, personas[i].numero, personas->correo);
        if(i == registro_personas-1){
            printf("El archivo guardo la informacion\n");
        }
    }
    //se cierra el archivo
    fclose(p_archivo);
}

void Obtener_registros(char *nombre_arch, Persona *personas) {
    FILE *p_archivo;

    //se verifica la existencia del archivo
    if ((p_archivo = fopen(nombre_arch, "r+")) == NULL) {
        printf("Archivo no existente\nGenarando archivo...\n");
        p_archivo = fopen(nombre_arch, "w");
    }

    int i = 0;
    //se lee la informacion

    while(!feof(p_archivo)){ //!feof(archivo) determina el final del archivo, por lo que sera true si es 0, aun no ha llegado al final
        char *nombre = (char*)malloc(50*sizeof(char));
        char *apellido = (char*)malloc(50*sizeof(char));
        char *numero = (char*)malloc(50*sizeof(char));
        char *correo = (char*)malloc(50*sizeof(char));
        fscanf(p_archivo, "Nombre:%s\n", nombre);
        fscanf(p_archivo, "Apellido:%s\n", apellido);
        fscanf(p_archivo, "Numero:%s\n", numero);
        fscanf(p_archivo, "Correo:%s\n", correo);
        personas[i].nombre = nombre;
        personas[i].nombre = apellido;
        personas[i].nombre = numero;
        personas[i].nombre = correo;
        i++;
    }

    //se cierra el archivo
    fclose(p_archivo);
}

int main() {
    char* nombre = "Agenda.txt";
    Persona *personas = (Persona*)malloc(12*sizeof(Persona));
    /*
    personas[0] = constructor_persona("Juan","Perez","+56912122412","quweidja@mgial.com");
    personas[1] = constructor_persona("Agustin","Becerra","+56912121231","kkkkkkkk@mgial.com");
    personas[2] = constructor_persona("Tomas","Corabalan","+56912990012","qqqqqqqqqqqqq@mgial.com");
    */
    imprimir_persona(personas[0]);
    Realizar_escritura(nombre,personas,3);
    //Persona *personas_1 = (Persona*)malloc(12*sizeof(Persona));
    Obtener_registros(nombre,personas);

    //imprimir_persona(personas);
    return 0;
}
