#include "Funciones_incompletas.h"

int responder(std::vector<carta> mano, int apuesta_contrincante, int &cant_fichas, int &pozo){
    //COMPLETAR.
    std::cout << "Tu mano es: ";
    mostrar_cartas(mano);
    std::cout << std::endl;
    cant_fichas -= 4;
    pozo +=4;
    return 4;
}
