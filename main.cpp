#include <iostream>
#include "AyudaFoneticaSP.hpp"


using namespace std;

int main()
{

    int fila, columna, cantPalabras;
    int i,e;
    cin>> fila >>columna;
    cin>> cantPalabras;
    string* palabrasABuscar = new string[cantPalabras];

    char** matriz = new char* [fila];
    for(i=0;i<fila;i++){
        matriz[i] = new char[columna];
    }

    for(i=0;i<fila;i++){
        for(e=0;e<columna;e++){
            cin >> matriz[i][e];
        }
    }

    for(i=0;i<cantPalabras;i++){
        cin >> palabrasABuscar[i];
    }

    AyudaFoneticaSP* sp = new AyudaFoneticaSP(fila, columna, matriz, cantPalabras, palabrasABuscar);

    cout<<"---------Salida--------"<<endl;
//    for(i=0;i<fila;i++){
//        for(e=0;e<columna;e++){
//            cout << matriz[i][e];
//        }
//        cout<<endl;
//    }

    for(i=0;i<cantPalabras;i++){
        cout << palabrasABuscar[i]<<endl;
    }

    cout<<endl;
    sp->realizarBusqueda();



// prueba eliminar caracteres
//    string h ,e ;
//    e = "HOLA";
//    h = p.eliminarCaracteres(e);
//    h = p.reemplazarLetrasPorNumeros(h);
//    cout << h <<endl;


// prueba de string
//    string* w = new string[fila];
//    for(i=0;i<fila;i++){
//        cin >>w[i];
//    }
//    cout<<endl;
//    w[0];
//    for(i=0;i<fila;i++){
//        cout<< w[i].at(0) <<"  ";
//    }


    return 0;
}
