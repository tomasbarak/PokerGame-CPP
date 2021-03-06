#include "Funciones_incompletas.h"

using namespace std;
int subir_apuesta(int &apuesta, int apuesta_contrincante, int &cant_fichas, int &pozo, int jugador){
    bool valor_aceptado = false;
    int fichas_a_apostar;
    cout << "\nApuesta J1: " << ((jugador == 1) ? apuesta : apuesta_contrincante) << " Apuesta J2: " << ((jugador == 2) ? apuesta : apuesta_contrincante) << endl;
    while (!valor_aceptado)
    {
        cout << "Fichas a apostar (min: " << apuesta_contrincante << "): ";
        cin >> fichas_a_apostar;

        if (apuesta_contrincante > cant_fichas) {
            cout << "\nFuiste ALL IN (no tienes suficientes fichas para satisfacer la apuesta)." << endl;

            fichas_a_apostar = apuesta_contrincante;
            valor_aceptado = true;

        }

        else if (fichas_a_apostar > cant_fichas)
            cout << "\nNo tienes suficientes fichas para apostar ese monto." << endl;

        else if (fichas_a_apostar < apuesta_contrincante)
            cout << "\nDebes apostar por lo menos " << apuesta_contrincante << " fichas." << endl;

        else
            valor_aceptado = true;
    }

    apuesta = fichas_a_apostar;

    cant_fichas -= apuesta;

    pozo += apuesta;

    return fichas_a_apostar;
}
