#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include "Vector.h"
#include "Ahorcado.h"
using namespace std;

//revisa que la longitud sea mayor a 2.
unsigned corroborarLongitud(unsigned longitud);
string buscadorPalabra(unsigned longitud);

int main() {
    //randomiza la seed del random.
    srand(time(NULL));
    unsigned longitud=0;
    string palabra;
    cout << "Ingrese la longitud de la palabra a adivinar: ";
    cin >> longitud;
    longitud = corroborarLongitud(longitud);
    palabra = buscadorPalabra(longitud);
    Ahorcado ahorcado(palabra);
    while (longitud!=0){
        ahorcado.juego();
        cout << "Ingrese la longitud de la palabra a adivinar (0 si quiere dejar de jugar): ";
        cin >> longitud;
        longitud = corroborarLongitud(longitud);
        if (longitud !=0){
            palabra = buscadorPalabra(longitud);
            ahorcado.nuevaPalabra(palabra);
        }
    }
    cout << "Final del juego." << endl;
    return 0;
}

unsigned corroborarLongitud(unsigned longitud){
    while ((0<longitud) && (longitud < 3)){
        cout << "Ingrese una longitud valida (debe ser mayor a 2): ";
        cin >> longitud;
    }
    return longitud;
}

string buscadorPalabra(unsigned longitud){

    ifstream archivo;
    unsigned pos=0, random=0;
    string linea, listado[2000];
    while (pos==0){
        archivo.open("palabras.txt");
        while (archivo>>linea){
            if (linea.length()==longitud){
                listado[pos]=linea;
                pos++;
            }
        }
        archivo.close();
        if (pos==0){
            cout << "No tenemos palabras con esa longitud." << endl;
            cout << "Ingrese la longitud de la palabra a adivinar: ";
            cin >> longitud;
            longitud = corroborarLongitud(longitud);
        }
    }
    random = rand() % pos;
    return listado[random];
}
