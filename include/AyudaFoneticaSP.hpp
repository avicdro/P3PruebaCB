#ifndef AYUDAFONETICASP_H
#define AYUDAFONETICASP_H

#include <iostream>
#include <fstream>

using namespace std;

class Palabra
{
    struct Coordenada{
        int x;
        int y;
        Coordenada(){
            x = 0;
            y = 0;
        }
        Coordenada(int xx , int yy){
            x = xx;
            y = yy;
        }
    };
private:
    string fonetica;
    string palabra;
    Coordenada* encontradas;

public:
    Palabra(string palabra){
        this->palabra = palabra;
    }
    void agregarFonetica(string fon){
        fonetica = fon;
    }
    void iniciarCordenadas(int tamaño){
        entontradas = new Coordenada[tamaño];
        for(int i=0; i<tamaño ; i++ ){
            encontradas[i].Coordenada(-1,-1);
        }
    }
    void agregarEncontrada(int fila,int columna){
        int tam = sizeof(encontradas)/sizeof(*encontradas);
        for(int i; i<tam; i++){
            if(encontradas[i].x == -1){
                encontradas[i].Coordenada(fila,columna);
            }
        }
    }
    void ordenarCreciente(){

    }
};

class AyudaFoneticaSP
{
    private:
        string* conOcurrencias;
        string* sinOcurrencias;

        int filas;
        int columnas;
        char** matriz;


        int cantPalabrasABuscar;
        char* letrasDeMayorImportancia;
        char letraDeMomeno;

        // coincide con el indice de cada palabra
        string *palabrasABuscar;
        //cada palabra a buscar arreglada foneticamente
        string *palabrasABuscarArregladas;
        Palabra *palabrasABuscar1;






    public:
        /** Default constructor */
        AyudaFoneticaSP(int filas, int columnas, char** matriz, int cantPalabrasABuscar, string* palabrasABuscar){
            this->filas = filas;
            this->columnas = columnas;
            this->matriz = matriz;
            this->cantPalabrasABuscar = cantPalabrasABuscar;
            this->palabrasABuscar = palabrasABuscar;

            letrasDeMayorImportancia = new char[cantPalabrasABuscar];
            palabrasABuscarArregladas = new string[cantPalabrasABuscar];
        }


        void realizarBusqueda(){
            guardarMayorImportancia();
            palabrasAbuscarArregladas();
            int i, e;
            int cantidadDeCoord = 0;
            for(i=0; i<filas;i++){
                for(e=0; e<columnas;e++){
                    char letra = matriz[i][e];
                    if(loEncontro(letra)){

//
//                        string izquierda = "";
//                        string derecha = "";
//                        string arriba = "";
//                        string abajo = "";

//                        tomarPalabraPorIndice(i,e, izquierda, derecha, arriba, abajo);
//
//                        izquierda = palabraArreglada(izquierda);
//                        derecha = palabraArreglada(derecha);
//                        arriba = palabraArreglada(arriba);
//                        abajo = palabraArreglada(abajo);


                        coordenadas[cantidadDeCoord] = Coordenada(letra,i,e);
                        cantidadDeCoord++;


                    }
                }
            }

            conOcurrencias = new string[cantidadDeCoord-1];
            int sin =  cantPalabrasABuscar - cantidadDeCoord;
            sinOcurrencias = new string[sin];
            for(i=0; i<filas*columnas;i++){
                conOcurrencias[i] = palabrasABuscarArregladas[i] +" "+ palabrasABuscar[i];
                cout << conOcurrencias[i]<<endl;
            }
            persistencia(conOcurrencias,cantidadDeCoord,"conocurrencias.txt");
            persistencia(sinOcurrencias,sin,"sinocurrencias.txt");


        }
        int indiceP(char p){
            for(int i=0; i<cantPalabrasABuscar;i++){
                if(p == letrasDeMayorImportancia[i]){
                    return i;
                }
            }
            return 0;
        }
        int cantidadDeVecesP(string palabra){
            int cont = 0;
            for(int i=0; i<cantPalabrasABuscar; i++){
                if(palabra.compare(palabrasABuscarArregladas[i]) == 0 ){
                       cont++;
                }
            }
            return cont;
        }
        /**
        * Devuelve true si suena a algo
        */
        bool suenaAAlgo(string palabra){
            for(int i = 0; i<cantPalabrasABuscar; i++){
                if(palabra.compare(palabrasABuscarArregladas[i]) == 0){
                    return true;
                }
            }
            return false;
        }
        /**
        *  Busca la coincidencia entre sus equivalentes foneticos
        */
//        void elMismoSonidoQue(string &mismas, string palabra){
//            int i;
//            int cont=0;
//            for(i=0; i<cantPalabrasABuscar; i++){
//                if(palabra == palabrasABuscarArregladas[i]){
//                    mismas[cont] = palabrasABuscar[i];
//                    cont++;
//                }
//            }
//        }

        /**
        * Busca la palabra que se le pase retorna true si la encuentra
        */
        bool loEncontro(char letra){
            int i;
            for(i=0 ; i<cantPalabrasABuscar;i++){
                if(letra == letrasDeMayorImportancia[i]){
                    return true;
                }
            }
            return false;
        }
        /**
        * llenar arreglo de palabras arregladas
        */
        void palabrasAbuscarArregladas(){
            int i;
            for(i=0; i<cantPalabrasABuscar; i++){
                obtenerLetraDeMomento(palabrasABuscar[i].at(0));
                palabrasABuscarArregladas[i] = palabraArreglada(palabrasABuscar[i]);
            }

        }
        /**
        * Le pasa una palabra, y retorna su forma fonetica.
        */
        string palabraArreglada(string palabra){
                obtenerLetraDeMomento(palabra.at(0));
                palabra = eliminarCaracteres(palabra);
                palabra = reemplazarLetrasPorNumeros(palabra);
                palabra = unirValoresNumericosConLetras(palabra);
                palabra = unirNumerosConsecutivos(palabra);
                palabra = letraYPrimerosNumeros(palabra);
                return palabra;
        }
        /**
        *   Guarda la letra de momento para luego revisar si esta
        */
        void obtenerLetraDeMomento(char letra){
            letraDeMomeno = letra;
        }
        /**
        * Tomar palabra por indice
        */
        void tomarPalabraPorIndice(int posX,int posY,string &izquierda, string &derecha, string &arriba, string &abajo){
            int i;

            //horizontal izquierda
            for(i=posX;i>=0;i--){
                izquierda = izquierda + matriz[posY][i];
            }
            //horizontal derecha
            for(i=posX;i<filas;i++){
                derecha = derecha + matriz[posY][i];
            }
            //vertical arriba
            for(i=posY;i>=0;i--){
                arriba = arriba + matriz[i][posX];
            }
            //vertical abajo
            for(i=posY;i<columnas;i++){
                abajo = abajo + matriz[i][posX];
            }
        }
         /**
        *  Insertar en archivo
        */
        void persistencia(string *arr,int length,string nombreArch){
            ofstream archivo(nombreArch.c_str());  // objeto de la clase ofstream

            int i;
            for(i=0;i<length;i++){
                archivo << arr[i] << endl;
            }
            archivo.close();
        }
        /**
        *  Primer paso
        */
        void guardarMayorImportancia(){
            int i;
            for(i=0;i<cantPalabrasABuscar;i++){
                letrasDeMayorImportancia[i] = palabrasABuscar[i].at(0);
            }
        }
        /**
        *  Segundo paso
        */
        string eliminarCaracteres(string palabra){
            int i;
            string nvpalabra;
            int len = palabra.length();
            for(i=0; i< len ; i++){
                if(   palabra.at(i) == 'A' || palabra.at(i) == 'E' || palabra.at(i) == 'I'|| palabra.at(i) == 'O'
                   || palabra.at(i) == 'U' || palabra.at(i) == 'H' || palabra.at(i) == 'W'|| palabra.at(i) == 'Y'  ){

                }else{
                        nvpalabra.push_back(palabra.at(i));
                }
            }
            return nvpalabra;
        }
        /**
        *  Tercer paso
        */
        string reemplazarLetrasPorNumeros(string palabra){
            int i;
            int len = palabra.length();
            for(i=0; i< len; i++){
                if( palabra.at(i) == 'B' || palabra.at(i) == 'P' || palabra.at(i) == 'F' || palabra.at(i) == 'V' ){
                    palabra.replace(i,1,"1");

                }else if( palabra.at(i) == 'C' || palabra.at(i) == 'G' || palabra.at(i) == 'K' || palabra.at(i) == 'S' ||
                          palabra.at(i) == 'X' || palabra.at(i) == 'Z'){
                    palabra.replace(i,1,"2");

                }else if( palabra.at(i) == 'D' || palabra.at(i) == 'T'){
                    palabra.replace(i,1,"3");

                }else if( palabra.at(i) == 'L'){
                    palabra.replace(i,1,"4");

                }else if( palabra.at(i) == 'M' || palabra.at(i) == 'N'){
                    palabra.replace(i,1,"5");

                }else if( palabra.at(i) == 'R'){
                    palabra.replace(i,1,"6");

                }else if( palabra.at(i) == 'Q' || palabra.at(i) == 'J'){
                    palabra.replace(i,1,"7");
                }
            }
            return palabra;
        }
        /**
        * Cuarto paso
        */
        string unirValoresNumericosConLetras(string palabra){
                return letraDeMomeno + palabra;;
        }
        /**
        * Quinto paso
        */
        string unirNumerosConsecutivos(string palabra){
            string apuntador;
            string salida = "";
            string aux;
            apuntador = palabra.at(0);
            salida= salida + (string) apuntador;
            int i;
            int len = palabra.length();
            for(i=1; i< len; i++){
                aux = palabra.at(i);
                if(apuntador != aux ){
                    apuntador = palabra.at(i);
                    salida.insert(salida.end(), palabra.at(i));
                }
            }
            return salida;
        }
        /**
        * Sexto paso
        */
        string letraYPrimerosNumeros(string palabra){
            int len =palabra.length();
            if(len >=4){
                palabra = palabra.substr(0,4);
            }else{
                int dif = 4 - len;
                int i;
                for(i=0;i<dif;i++){
                    palabra = palabra + "0";
                }
            }
            return palabra;
        }
};



#endif // AYUDAFONETICASP_H
