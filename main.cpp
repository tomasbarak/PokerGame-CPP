#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct carta{
    int valor;
    int palo;
    string visible;
};

int semilla_random = 1;

void delay(int secs) {
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

string palo_para_mostrar(int palo) {
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

string valor_para_mostrar(int valor){
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
        return to_string(valor);
    }
}

vector<carta> crear_mazo(){
    vector<carta> mazo;
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

void mostrar_cartas(vector<carta> cartas){
    for (int i = 0; i < cartas.size(); ++i) {
        cout << cartas[i].visible;
        if (i < cartas.size()-1){
            cout << ", ";
        }
    }
}

int indice_aleatorio(vector<carta> cartas){
    srand (semilla_random);
    semilla_random++;
    return rand() % cartas.size();
}

void mostrar_mensaje_bienvenida(){
    cout << "Bienvenidos al poquer tapado de 2°CSTC" << endl;
    cout << "Cada jugador cuenta con 15 fichas para jugar, el juego se termina cuando uno se queda sin fichas" << endl;
    cout << "Buena suerte y que gane el mejor!" << endl;
    delay(5);
    //system("clear");
}

void mostrar_principio_mano(int cant_fichas_j1, int cant_fichas_j2){
    cout << "Comienza una nueva mano" << endl;
    cout << "El jugador 1 posee " << cant_fichas_j1 << " fichas" << endl;
    cout << "El jugador 2 posee " << cant_fichas_j2 << " fichas" << endl;
    delay(3);
    //system("clear");
}

void mezclar_mazo(vector<carta> &mazo){
    //COMPLETAR.
}

vector<carta> repartir(vector<carta> &mazo, int cant_cartas){
    vector<carta> mano;
    for (int i = 0; i < cant_cartas; i++) {
        mano.push_back(mazo[mazo.size()-1]);
        mazo.pop_back();
    }
    return mano;
}

int apostar(vector<carta> mano, int &cant_fichas, int &pozo){
    //COMPLETAR.
    cout << "Tu mano es: ";
    mostrar_cartas(mano);
    cout << endl;
    cant_fichas -= 4;
    pozo +=4;
    return 4;
}

int responder(vector<carta> mano, int apuesta_contrincante, int &cant_fichas, int &pozo){
    //COMPLETAR.
    cout << "Tu mano es: ";
    mostrar_cartas(mano);
    cout << endl;
    cant_fichas -= 4;
    pozo +=4;
    return 4;
}

int subir_apuesta(int &apuesta, int apuesta_contrincante, int &cant_fichas, int &pozo){
    //COMPLETAR.
    cant_fichas -= 2;
    pozo +=2;
    return 2;
}

bool comparar_cartas(vector<carta> mano_j1, vector<carta> mano_j2) {
    //COMPLETAR.
    return true;
}

void mostrar_mensaje_ganador_mano(int ganador, int cant_fichas){
    cout << "Gana esta mano el jugador " << ganador << " y queda con " << cant_fichas << " fichas" << endl;
}

void mostrar_ganador_partida(int cant_fichas_j1, int cant_fichas_j2){
    if (cant_fichas_j1 == 0){
        cout << "Gana la partida el jugador 2!" << endl;
    }
    else {
        cout << "Gana la partida el jugador 1!" << endl;
    }
}

int main() {
    int cant_fichas_j1 = 15;
    int cant_fichas_j2 = 15;

    mostrar_mensaje_bienvenida();

    while (cant_fichas_j1 > 0 && cant_fichas_j2 > 0){
        vector<carta> mazo = crear_mazo();
        int pozo = 2;
        cant_fichas_j1--;
        cant_fichas_j2--;

        mostrar_principio_mano(cant_fichas_j1, cant_fichas_j2);

        mezclar_mazo(mazo);
        vector<carta> mano_j1 = repartir(mazo, 5);
        vector<carta> mano_j2 = repartir(mazo, 5);

        int apuesta_j1 = apostar(mano_j1, cant_fichas_j1, pozo);
        int apuesta_j2 = responder(mano_j2, apuesta_j1, cant_fichas_j2 , pozo);

        bool responde_j1 = true;

        while (apuesta_j1 != apuesta_j2){
            if (responde_j1){
                subir_apuesta(apuesta_j1, apuesta_j2, cant_fichas_j1, pozo);
                responde_j1 = false;
            }
            else {
                subir_apuesta(apuesta_j2, apuesta_j1, cant_fichas_j2 , pozo);
                responde_j1 = true;
            }
        }

        bool gana_j1 = comparar_cartas(mano_j1, mano_j2);
        if (gana_j1){
            cant_fichas_j1 += pozo;
            mostrar_mensaje_ganador_mano(1, cant_fichas_j1);
        }
        else{
            cant_fichas_j2 += pozo;
            mostrar_mensaje_ganador_mano(2, cant_fichas_j1);
        }
    }
    mostrar_ganador_partida(cant_fichas_j1, cant_fichas_j2);
    return 0;
}
