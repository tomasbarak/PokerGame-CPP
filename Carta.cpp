#include "Carta.h"

std::string palo_para_mostrar(int palo) {
    if (palo == 0){
        return "♣";
    }
    else if (palo == 1){
        return "♦";
    }
    else if (palo == 2){
        return "♥";
    }
    else {
        return "♠";
    }

}

std::string valor_para_mostrar(int valor){
    if (valor == 1){
        return "A";
    }
    else if (valor == 11){
        return "J";
    }
    else if (valor == 12){
        return "Q";
    }
    else if (valor == 13){
        return "K";
    }
    else {
        return std::to_string(valor);
    }
}

void mostrar_cartas(std::vector<carta> cartas){
    for (int i = 0; i < cartas.size(); ++i) {
        std::cout << cartas[i].visible;
        if (i < cartas.size()-1){
            std::cout << ", ";
        }
    }
}
