#include <stdio.h>

int largo_numero(int long long n){
    int i = 1;
    int long long multiplo_10 = 10;
    while (n>multiplo_10){
        multiplo_10*=10;
        i++;
    }
    return i;
}

void numero_cadena(int long long n,char *cad){
    int largo_n = largo_numero(n);
    int long long multiplo_10 = 10;


    //exponenciar
    int i = 0;
    while (i<=largo_n-4){
        multiplo_10*=10;
        i++;
    }
    //multiplo de n queda en n-2, obteniendo los dos primeros digitos del numero
    int k=0;
    i=(largo_n/2);
    while (i>0){
        int digitos = (int)(n/multiplo_10);
        cad[k] = (char)digitos;
        n-=digitos*multiplo_10;
        multiplo_10/=100;
        i--;
        k++;
    }
}

int main() {
    int long long i = 776983799079736779;
    int p = 72797665;
    int j = largo_numero(i);
    char cad1[20]="";
    numero_cadena(p,cad1);
    printf("%s",cad1);
    return 0;
}
