#include "Mensajes.h"
#include "delay.h"

void mostrar_mensaje_bienvenida(){
    std::cout << "Bienvenidos al poker tapado de 2°CSTC" << std::endl;
    std::cout << "Cada jugador cuenta con 15 fichas para jugar, el juego se termina cuando uno se queda sin fichas" << std::endl;
    std::cout << "Buena suerte y que gane el mejor!" << std::endl;
    //delay(5);
    //system("clear");
}

void mostrar_principio_mano(int cant_fichas_j1, int cant_fichas_j2){
    std::cout << "Comienza una nueva mano" << std::endl;
    std::cout << "El jugador 1 posee " << cant_fichas_j1 << " fichas" << std::endl;
    std::cout << "El jugador 2 posee " << cant_fichas_j2 << " fichas" << std::endl;
    //delay(3);
    //system("clear");
}

void mostrar_mensaje_ganador_mano(int ganador, int cant_fichas){
    std::cout << "Gana esta mano el jugador " << ganador << " y queda con " << cant_fichas << " fichas" << std::endl;
}


void mostrar_ganador_partida(int cant_fichas_j1, int cant_fichas_j2){
    if (cant_fichas_j1 == 0){
        std::cout << "Gana la partida el jugador 2!" << std::endl;
    }
    else {
        std::cout << "Gana la partida el jugador 1!" << std::endl;
    }
}
