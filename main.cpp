#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Carta.h"
#include "Mensajes.h"
#include "Funciones_incompletas.h"

using namespace std;

int semilla_random = 1;

std::vector<carta> crear_mazo(){
    std::vector<carta> mazo;
    for (int palo = 0; palo < 4; palo++) {
        for (int valor = 1; valor < 14; valor++) {
            carta c;
            c.valor = valor;
            c.palo = palo;
            c.visible = valor_para_mostrar(c.valor) + palo_para_mostrar(c.palo);
            mazo.push_back(c);
        }
    }
    /*for(int i = 0; i < mazo.size(); i++){
        cout << mazo[i].visible << endl;
    }*/
    return mazo;
}

int indice_aleatorio(std::vector<carta> cartas){
    srand (semilla_random);
    semilla_random++;
    return rand() % cartas.size();
}

std::vector<carta> repartir(std::vector<carta> &mazo, int cant_cartas){
    std::vector<carta> mano;
    for (int i = 0; i < cant_cartas; i++) {
        mano.push_back(mazo[mazo.size()-1]);
        mazo.pop_back();
    }
    return mano;
}

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
                subir_apuesta(apuesta_j1, apuesta_j2, cant_fichas_j1, pozo, 1);
                responde_j1 = false;
            }
            else {
                subir_apuesta(apuesta_j2, apuesta_j1, cant_fichas_j2 , pozo, 2);
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
