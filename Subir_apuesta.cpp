#include "Funciones_incompletas.h"

using namespace std;
int subir_apuesta(int &apuesta, int apuesta_contrincante, int &cant_fichas, int &pozo, int jugador){
    bool valor_aceptado = false;
    int fichas_a_apostar;
    while (!valor_aceptado)
    {
        cout << "Fichas a apostar (min: " << apuesta_contrincante << "): ";
        cin >> fichas_a_apostar;

        if (fichas_a_apostar > cant_fichas)
            cout << "\nNo tienes suficientes fichas para apostar ese monto." << endl;

        else if (fichas_a_apostar < apuesta_contrincante)
            cout << "\nDebes apostar por lo menos " << apuesta_contrincante << " fichas." << endl;

        else
            valor_aceptado = true;
    }

    apuesta = fichas_a_apostar;

    cant_fichas -= apuesta;

    pozo += apuesta;

    cout << "Apuesta J1: " << ((jugador == 1) ? apuesta : apuesta_contrincante) << " Apuesta J2: " << ((jugador == 2) ? apuesta : apuesta_contrincante) << endl;
    return fichas_a_apostar;
}
