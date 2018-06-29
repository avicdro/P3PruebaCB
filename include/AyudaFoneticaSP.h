#ifndef AYUDAFONETICASP_H
#define AYUDAFONETICASP_H


class AyudaFoneticaSP
{
    private:
        int filas;
        int columnas;
        char** matriz;

        int cantPalabrasABuscar;
        string* palabrasABuscar;
        // coincide con el indice de cada palabra
        char* letraDeMayorImportancia;

        //cada palabra a buscar arreglada foneticamente
        string* palabrasABuscarArregladas;


        void guardarMayorImportancia();
        void eliminarCaracteres();
        void reemplazarLetrasPorNUmeros();
        void unirValoresNumericosConLetras();
        void letraYtresPrimerosNumeros();
        void eliminarRepetidos();

    public:
        /** Default constructor */
        AyudaFoneticaSP(int filas, int columnas, char** matriz, int cantPalabrasABuscar, string palabrasABuscar);
        /** Default destructor */
        virtual ~AyudaFoneticaSP();

        void realizarBusqueda();

};

#endif // AYUDAFONETICASP_H
