#include "Funciones_incompletas.h"

int apostar(std::vector<carta> mano, int &cant_fichas, int &pozo){
    //COMPLETAR.
    std::cout << "Tu mano es: ";
    mostrar_cartas(mano);
    std::cout << std::endl;
    cant_fichas -= 4;
    pozo +=4;
    return 4;
}
