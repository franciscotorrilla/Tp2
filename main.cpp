#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Ahorcado.h"
using namespace std;

int main() {
    unsigned longitud;
    cout << "Ingrese la longitud de la palabra a adivinar: ";
    cin >> longitud;
    Ahorcado ahorcado(longitud);
    while (longitud!=0){
        ahorcado.juego();
        cout << "Ingrese la longitud de la palabra a adivinar (0 si quiere dejar de jugar): ";
        cin >> longitud;
        ahorcado.nuevaPalabra(longitud);
    }
    return 0;
}

