#include "Funciones_incompletas.h"
#include <algorithm>
#include <ctime>

using namespace std;
int randomNumber (int n){
    return rand()%n;
}

void mezclar_mazo(vector<carta> &mazo){
    srand (unsigned(time(0)));
    random_shuffle(mazo.begin(), mazo.end(), randomNumber);
}
