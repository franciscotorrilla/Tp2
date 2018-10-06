#include "Ahorcado.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "Vector.h"
using namespace std;


Ahorcado::Ahorcado(unsigned longitud) {

    palabraAdivinar = buscadorPalabra(longitud) ;
    palabraProgreso = new Vector(longitud);
    rellenar(longitud,'-');
    erroresMaximos= dificultad();
    letrasErroneas = new Vector(erroresMaximos);
    cantidadErrores = 0;
}

string Ahorcado::buscadorPalabra(unsigned longitud){

    ifstream archivo;
    unsigned pos=0, random;
    string linea, listado[2000];
    archivo.open("palabras.txt");
    while (archivo>>linea){
        if (linea.length()==longitud){
            listado[pos]=linea;
            pos++;
        }
    }
    random = rand() % pos+1;
    archivo.close();
    return listado[random];
}

void Ahorcado::rellenar(unsigned longitud, char relleno){

    for(unsigned i = 0; i < longitud; i++ ) {
        palabraProgreso->asignarDato(i,relleno);
    }
}

unsigned Ahorcado::dificultad() {

    char x=0;
    cout << "Ingrese 1 para jugar en facil." <<endl;
    cout << "Ingrese 2 para jugar en normal." <<endl;
    cout << "Ingrese 3 para jugar en dificil." <<endl;
    cin >> x;
    switch(x) {
        case '1' : cout << "Tenes 7 errores." <<endl;
            return 7;
        case '2' : cout << "Tenes 5 errores." <<endl;
            return 5;
        case '3' : cout << "Tenes 3 errores." <<endl;
            return 3;
        default:  cout << "Dato invalido." <<endl;
            dificultad();
    }
    return 0;
}

void Ahorcado::juego(){
    bool estaEnJuego = true;
    while(estaEnJuego) {
        cout <<endl;
        mostrarProgreso();
        estaEnJuego=ingresoDeDato();
    }
}

void Ahorcado::mostrarProgreso() {

    for(unsigned i = 0; i < palabraAdivinar.length(); i++){
        cout << palabraProgreso->obtenerDato(i);
    }
    cout <<endl;
}

bool Ahorcado::ingresoDeDato(){

    string datoIngresado;
    cout << "Ingrese palabra/letra: ";
    cin >> datoIngresado;
    if(datoIngresado.length() == 1)
         return comprobarDato(datoIngresado[0]);

    else
        return comprobarDato(datoIngresado);
}

bool Ahorcado::comprobarDato(char caracter) {

        caracter = toupper(caracter);
        if(!arriesgar(caracter) && !estaEnJuego()) {
            cout <<"Perdiste"<<endl;
            mostrarPalabraAdivinar();
            return false;
        }
        if (gano()){
           cout <<"Ganaste"<<endl;
           return false;
        }
        mostrarLetrasErroneas();
        mostrarErroresRestantes();
        return true;
}

bool Ahorcado::comprobarDato(string palabra) {

        if(palabra.length()!=palabraAdivinar.length()){
            cout << "El tamanio no corresponde con el de la palabra a adivinar." <<endl;
            return ingresoDeDato();
        }
        //IngresaPalabra
        for (unsigned i=0 ; i < palabra.length() ; i++){
            palabra[i]=toupper(palabra[i]);
        }
        if(arriesgar(palabra)) {
            cout <<"Ganaste"<<endl;
        }
        else {
            cout <<"Perdiste"<<endl;
            mostrarPalabraAdivinar();
        }
        return false;
}


bool Ahorcado::arriesgar(string palabra) {

    if(palabra == palabraAdivinar) {
        return true;
    }
    return false;
}

bool Ahorcado::arriesgar(char letra){

    bool acierto = false;
    // Chequeo si la letra ya fue ingresada con anterioridad
    if(letraPerteneceErrores(letra) || letraYaAcertada(letra)) {
        cout <<"La letra ya fue ingresada anteriormente."<<endl;
        return true;
    }
    for ( unsigned i = 0; i < palabraAdivinar.length(); i++) {
        if ( letra == palabraAdivinar[i]) {
            palabraProgreso->asignarDato(i,letra);
            acierto = true;
        }
    }
    if (!acierto){
        letrasErroneas->asignarDato(cantidadErrores,letra);
        sumarError();
    }
    return acierto;
}

void Ahorcado::sumarError() {

    cantidadErrores++;
}

bool Ahorcado::letraPerteneceErrores(char letra) {

    for(unsigned i = 0; i < letrasErroneas->obtenerLongitud(); i++) {
        if(letra == letrasErroneas->obtenerDato(i)) {
            return true;
        }
    }
    return false;
}

bool Ahorcado::letraYaAcertada(char letra) {

    for(unsigned i = 0; i < palabraProgreso->obtenerLongitud(); i++) {
        if(letra == palabraProgreso->obtenerDato(i)) {
            return true;
        }
    }
    return false;
}

bool Ahorcado::estaEnJuego() {

    if(cantidadErrores < erroresMaximos){
        return true;
    }
    return false;
}

void Ahorcado::mostrarPalabraAdivinar() {

    cout<< "La palabra a adivinar era: " << palabraAdivinar << endl;
}

unsigned Ahorcado::obtenerErroresMaximos(){

    return erroresMaximos;
}

void Ahorcado::mostrarErroresRestantes() {

    if ((erroresMaximos - cantidadErrores)!=1)
        cout<< "Te quedan " << erroresMaximos - cantidadErrores << " errores restantes"<< endl;
    else{
        cout<< "Te queda 1 error restante" << endl;
    }
}

bool Ahorcado::gano(){

    for(unsigned i = 0; i < palabraAdivinar.length(); i ++){
        if(palabraProgreso->obtenerDato(i) == '-'){
            return false;
        }
    }
    return true;
}

void Ahorcado::mostrarLetrasErroneas() {

    if(cantidadErrores > 0 ) {
        cout << "Las letras erroneas son: ";
        for(unsigned i = 0; i < cantidadErrores-1; i ++) {
            cout << letrasErroneas->obtenerDato(i) << "-";
        }
        cout << letrasErroneas->obtenerDato(cantidadErrores-1) << endl;
    }
}

void Ahorcado::nuevaPalabra(unsigned longitud){

    if(!longitud) return;
    palabraAdivinar = buscadorPalabra(longitud);
    palabraProgreso->cambiarLongitud(longitud);
    rellenar(longitud,'-');
    erroresMaximos= dificultad();
    letrasErroneas->cambiarLongitud(erroresMaximos);
    cantidadErrores = 0;
}

Ahorcado::~Ahorcado() {
    delete palabraProgreso;
    delete letrasErroneas;
}
