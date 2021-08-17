#ifndef FUNCIONES_INCOMPLETAS_H_INCLUDED
#define FUNCIONES_INCOMPLETAS_H_INCLUDED

#include <iostream>
#include <vector>
#include "Carta.h"

void ordenar_vector(std::vector<int>& v);

int revisar_jugadas(std::vector<int>& v, Jugadas j, std::vector<int>& p, std::vector<carta> mano);

void mezclar_mazo(std::vector<carta>& mazo);

int apostar(std::vector<carta> mano, int& cant_fichas, int& pozo);

int responder(std::vector<carta> mano, int apuesta_contrincante, int& cant_fichas, int& pozo);

int subir_apuesta(int& apuesta, int apuesta_contrincante, int& cant_fichas, int& pozo, int jugador);

bool comparar_cartas(std::vector<carta> mano_j1, std::vector<carta> mano_j2);

#endif // FUNCIONES_INCOMPLETAS_H_INCLUDED
