#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Carta.h"
#include "Mensajes.h"
#include "mazo.h"
#include "Funciones_incompletas.h"

using namespace std;

int semilla_random = 1;


int main() {
    int cant_fichas_j1 = 15;
    int cant_fichas_j2 = 15;

    mostrar_mensaje_bienvenida();

    while (cant_fichas_j1 > 0 && cant_fichas_j2 > 0){
        vector<carta> mazo = crear_mazo();
        int pozo = 2;
        cant_fichas_j1--;
        cant_fichas_j2--;

        mostrar_principio_mano(cant_fichas_j1, cant_fichas_j2);

        mezclar_mazo(mazo);
        vector<carta> mano_j1 = repartir(mazo, 5);
        vector<carta> mano_j2 = repartir(mazo, 5);

        int apuesta_j1 = apostar(mano_j1, cant_fichas_j1, pozo);
        int apuesta_j2 = responder(mano_j2, apuesta_j1, cant_fichas_j2 , pozo);

        bool responde_j1 = true;

        while (apuesta_j1 != apuesta_j2){
            if (responde_j1){
                subir_apuesta(apuesta_j1, apuesta_j2, cant_fichas_j1, pozo);
                responde_j1 = false;
            }
            else {
                subir_apuesta(apuesta_j2, apuesta_j1, cant_fichas_j2 , pozo);
                responde_j1 = true;
            }
        }

        bool gana_j1 = comparar_cartas(mano_j1, mano_j2);
        if (gana_j1){
            cant_fichas_j1 += pozo;
            mostrar_mensaje_ganador_mano(1, cant_fichas_j1);
        }
        else{
            cant_fichas_j2 += pozo;
            mostrar_mensaje_ganador_mano(2, cant_fichas_j1);
        }
    }
    mostrar_ganador_partida(cant_fichas_j1, cant_fichas_j2);
    return 0;
}
