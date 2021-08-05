#include "mazo.h"

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
    return mazo;
}

int indice_aleatorio(vector<carta> cartas){
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
