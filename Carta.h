#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

struct carta{
    int valor;
    int palo;
    std::string visible;
};

std::string palo_para_mostrar(int palo);

std::string valor_para_mostrar(int valor);

void mostrar_cartas(std::vector<carta> cartas);

#endif // CARTA_H_INCLUDED
