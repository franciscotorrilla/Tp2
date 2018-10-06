#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Ahorcado.h"
using namespace std;

//revisa que la longitud sea mayor a 2.
unsigned corroborarLongitud(unsigned longitud);

int main() {
    unsigned longitud=0;
    cout << "Ingrese la longitud de la palabra a adivinar: ";
    cin >> longitud;
    longitud = corroborarLongitud(longitud);
    Ahorcado ahorcado(longitud);
    while (longitud!=0){
        ahorcado.juego();
        cout << "Ingrese la longitud de la palabra a adivinar (0 si quiere dejar de jugar): ";
        cin >> longitud;
        longitud = corroborarLongitud(longitud);
        ahorcado.nuevaPalabra(longitud);
    }
    return 0;
}

unsigned corroborarLongitud(unsigned longitud){
    while (longitud<3){
        cout << "Ingrese una longitud valida (debe ser mayor a 2): ";
        cin >> longitud;
    }
}

