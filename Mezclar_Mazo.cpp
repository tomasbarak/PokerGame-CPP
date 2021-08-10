#include "Funciones_incompletas.h"
#include <algorithm>
#include <ctime>
int myrandom (int i){
    return std::rand()%i;
}

void mezclar_mazo(std::vector<carta> &mazo){
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(mazo.begin(), mazo.end(), myrandom);
}
