#ifndef AYUDAFONETICASP_H
#define AYUDAFONETICASP_H


class AyudaFoneticaSP
{
    private:
        int filas;
        int columnas;
        char** matriz;

    public:
        /** Default constructor */
        AyudaFoneticaSP(int, int, char**);
        /** Default destructor */
        virtual ~AyudaFoneticaSP();

        void realizarBusqueda();
        void guardarMayorImportancia();
        void eliminarCaracteres();
        void reemplazarLetrasPorNUmeros();
        void unirValoresNumericosConLetras();
        void eliminarRepetidos();
        void letraYtresPrimerosNumeros();


};

#endif // AYUDAFONETICASP_H
