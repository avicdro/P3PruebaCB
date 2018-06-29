#ifndef AYUDAFONETICASP_H
#define AYUDAFONETICASP_H

#include <iostream>
using namespace std;

class AyudaFoneticaSP
{
    private:
        int filas;
        int columnas;
        char** matriz;

        int cantPalabrasABuscar;
        string *palabrasABuscar;
        // coincide con el indice de cada palabra
        char* letraDeMayorImportancia;

        //cada palabra a buscar arreglada foneticamente
        string *palabrasABuscarArregladas;


        void guardarMayorImportancia()
        {
            int i;
            for(i=0;i<cantPalabrasABuscar;i++){
                letraDeMayorImportancia[i] = palabrasABuscar[i].at(0);
            }
        }
//        void eliminarCaracteres(string palabra)
//        {
//            int i;
//            for(i=0; i< palabra.length() ; i++){
//                if(palabra.at(i) == 'A' ){
//
//                }
//            }
//        }
        void reemplazarLetrasPorNumeros();
        void unirValoresNumericosConLetras();
        void letraYtresPrimerosNumeros();
        void eliminarRepetidos();

    public:
        /** Default constructor */
        AyudaFoneticaSP(int filas, int columnas, char** matriz, int cantPalabrasABuscar, string* palabrasABuscar){
            this->filas = filas;
            this->columnas = columnas;
            this->matriz = matriz;
            this->cantPalabrasABuscar = cantPalabrasABuscar;
            this->palabrasABuscar = palabrasABuscar;
        }
        /** Default destructor */
        virtual ~AyudaFoneticaSP();

        void realizarBusqueda();

};



#endif // AYUDAFONETICASP_H
