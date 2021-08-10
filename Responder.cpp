#include "Funciones_incompletas.h"

using namespace std;

int responder(std::vector<carta> mano, int apuesta_contrincante, int &cant_fichas, int &pozo){
    //COMPLETAR.
    cout << "Tu mano es: ";
    mostrar_cartas(mano);
    cout << endl;

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

    cant_fichas -= fichas_a_apostar;
    pozo += fichas_a_apostar;

    return fichas_a_apostar;
}
