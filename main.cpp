#include <iostream>
#include "AyudaFoneticaSP.h"


using namespace std;

int main()
{
    int fila, columna;
    int i;
    cin>> fila >>columna;

    char** matriz = new char* [fila];
    for(i=0;i<fila;i++){
        matriz[i] = new char[columna];
    }

//    string* h = new string[fila];
//    for(i=0;i<fila;i++){
//        cin >>h[i];
//    }
//    cout<<endl;
//    for(i=0;i<fila;i++){
//        cout<< h[i] <<"  ";
//    }


    //AyudaFoneticaSP SP = new AyudaFoneticaSP(fila, columna, matriz);

    return 0;
}
