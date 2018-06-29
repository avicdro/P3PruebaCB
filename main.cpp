#include <iostream>
#include "AyudaFoneticaSP.h"


using namespace std;

int main()
{
    int fila, columna;
    int i;
    cout>> fila >>columna;

    char** matriz = new char[fila];
    for(i=0;i<fila;i++){
        matriz[i] = new char[columna];
    }

    AyudaFoneticaSP SP = new AyudaFoneticaSP(filam, columna, matriz);




    return 0;
}
