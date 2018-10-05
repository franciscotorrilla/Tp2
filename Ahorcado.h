#ifndef AHORCADO_H
#define AHORCADO_H
#include "Vector.h"
#include <string>

class Ahorcado {

    private:
        std::string palabraAdivinar;
        Vector* palabraProgreso;
        unsigned erroresMaximos;
        unsigned cantidadErrores;
        Vector* letrasErroneas;

    public:
        /* pre: recibe una palabra a adivinar mayor a 2 caracteres, y la cantidad de errores que el
        usuario puede cometer tambien deben ser mayor a 2.
        pos: crea el juego */
        Ahorcado(unsigned longitud);

        void mostrarPalabraAdivinar();

        //pos: suma un error cuando el usuario arriesga una letra y no acierta
        void sumarError();

        //pos: devuelve la cantidad de erores que el usuario puede cometer
        unsigned obtenerErroresMaximos();

        void mostrarErroresRestantes();

        //pos: imprime palabraProgreso
        void mostrarProgreso();

        //pre: recibe un string por parametro y lo compara con la palabra a adivinar
        //pos: devuelve true si el string es igual a la palabra, false caso contrario
        bool arriesgar(std::string palabra);

        //pre: recibe una letra por parametro y la coloca en las posiciones correspondientes
        // de la palabra a adivinar.
        //pos: devuelve true si la letra arriesgada esta en la palabra a adivinar, false caso contrario
        bool arriesgar(char letra);

        bool gano();

        void buscarPalabrasArchivo();

        bool estaEnJuego();
        //pos: devuelve las letras que el usuario ingresa erroneamente
        void mostrarLetrasErroneas();

        bool seguirJugando();

        void nuevaPalabra(unsigned longitud);

        bool ingresoDeDato();

        void juego();

        ~Ahorcado();

    private:

        // Funcion privada que rellena con el parametro relleno el vector palabraProgreso
        // pos: palabraProgreso -> relleno en cada posicion
        void rellenar(unsigned longitud, char relleno);

        bool letraPerteneceErrores(char letra);

        bool letraYaAcertada(char letra);

        std::string buscadorPalabra(unsigned longitud);

        unsigned dificultad();

};

#endif // AHORCADO_H
