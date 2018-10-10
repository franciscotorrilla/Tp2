#ifndef AHORCADO_H
#define AHORCADO_H
#include "Vector.h"
#include <string>

class Ahorcado {

    //Atributos
    private:
        std::string palabraAdivinar;
        Vector* palabraProgreso;
        unsigned erroresMaximos;
        unsigned cantidadErrores;
        Vector* letrasErroneas;

    //M�todos
    public:
        //pre: recibe una palabra a adivinar mayor a 2 caracteres, y la cantidad de errores que el
        //usuario puede cometer tambien deben ser mayor a 2.
        //post: crea el juego.
        Ahorcado(std::string palabra);

        //pre: -
        //post: mientras el jugador no pierda ni gane llama a ingresoDeDato.
        void juego();

        //pre: recibe una longitud mayor a 2.
        //post: modifica los atributos asociados a la nueva longitud.
        void nuevaPalabra(std::string palabra);

        //pre: -
        //post: destructor de los dos vectores din�micos.
        ~Ahorcado();

    private:

        //pre: -
        //post: rellena con el parametro relleno el vector palabraProgreso
        void rellenar(unsigned longitud, char relleno);

        //pre: -
        //post: pide ingreso de dificultad y devuelve la cantidad de erorres correspondiente.
        unsigned dificultad();

        //pre: -
        //post: imprime palabraProgreso.
        void mostrarProgreso();

        //pre: -
        //post: pide ingreso de dato y llama a comprobarDato.
        bool ingresoDeDato();

        //pre: recibe un caracter valido.
        //post: llama a arriesgar , a mostrarLetrasErroneas y a mostrarErroresRestantes y avisa si ganaste o perdiste.
        bool comprobarDato(char caracter);

        //pre: recibe un string valido.
        //post: llama a arriesgar y avisa si ganaste o perdiste.
        bool comprobarDato(std::string palabra);

        //pre: recibe un caracter valido.
        //post: devuelve true si la letra arriesgada esta en la palabra a adivinar, false en caso contrario.
        bool arriesgar(char letra);

        //pre: recibe un string valido.
        //post: devuelve true si el string es igual a la palabra, false en caso contrario.
        bool arriesgar(std::string palabra);

        //pre: recibe un caracter valido.
        //post: devuelve true si la letra esta en letrasErroneas, false en caso contrario.
        bool letraPerteneceErrores(char letra);

        //pret: recibe un caracter valido.
        //post: devuelve true si ya usaste y acertaste esa letra, false en caso contrario.
        bool letraYaAcertada(char letra);

        //pre:-
        //post: devuelve true si tenes menos errores q el maximo permitido, false en caso contrario.
        bool estaEnJuego();

        //pre:-
        //post: muestra palabraAdivinar.
        void mostrarPalabraAdivinar();


        //pre:-
        //post: devuelve la cantidad de errores que le quedan al usuario.
        void mostrarErroresRestantes();

        //pre:-
        //post: devuelve true si ya completo la palabraProgreso, false en caso contrario.
        bool gano();

        //pre:-
        //post: devuelve las letras que el usuario ingresa erroneamente.
        void mostrarLetrasErroneas();

};

#endif // AHORCADO_H
