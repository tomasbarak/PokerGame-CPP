#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#include <vector>
#include <stdlib.h>
#include "Carta.h"

std::vector<carta> crear_mazo();

int indice_aleatorio(std::vector<carta> cartas);

std::vector<carta> repartir(std::vector<carta>& mazo, int cant_cartas);

#endif // MAZO_H_INCLUDED
