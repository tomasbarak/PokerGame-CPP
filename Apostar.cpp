#include "Funciones_incompletas.h"

using namespace std;

int apostar(vector<carta> mano, int &cant_fichas, int &pozo){
    //COMPLETAR.
    cout << "Tu mano es: ";
    mostrar_cartas(mano);
    cout << endl;

    bool valor_aceptado = false;
    int fichas_a_apostar;
    while (!valor_aceptado)
    {
        cout << "Fichas a apostar: ";
        cin >> fichas_a_apostar;

        if (fichas_a_apostar > cant_fichas)
            cout << "\nNo tienes suficientes fichas para apostar ese monto." << endl;

        else
            valor_aceptado = true;
    }

    cant_fichas -= fichas_a_apostar;
    pozo += fichas_a_apostar;

    return fichas_a_apostar;
}
