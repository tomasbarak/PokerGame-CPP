#include "Funciones_incompletas.h"

using namespace std;

bool comparar_cartas(vector<carta> mano_j1, vector<carta> mano_j2) {
    vector<vector<int>> jugadas = { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } };

    vector<int> valores_j1(5, 0);
    vector<int> valores_j2(5, 0);

    for (int i = 0; i < mano_j1.size(); i++)
    {
        valores_j1[i] = mano_j1[i].valor;
        valores_j2[i] = mano_j2[i].valor;
    }

    ordenar_vector(valores_j1);
    ordenar_vector(valores_j2);

    vector<int> pu_j1 = {};
    vector<int> pu_j2 = {};

    // Jugadas Jugador 1
    jugadas[0][5] = revisar_jugadas(valores_j1, Jugadas::EscColor, pu_j1, mano_j1);
    jugadas[0][4] = revisar_jugadas(valores_j1, Jugadas::Poker, pu_j1, mano_j1);
    jugadas[0][3] = revisar_jugadas(valores_j1, Jugadas::Color, pu_j1, mano_j1);
    jugadas[0][2] = revisar_jugadas(valores_j1, Jugadas::Escalera, pu_j1, mano_j1);
    jugadas[0][1] = revisar_jugadas(valores_j1, Jugadas::Trio, pu_j1, mano_j1);
    jugadas[0][0] = revisar_jugadas(valores_j1, Jugadas::Par, pu_j1, mano_j1);

    jugadas[1][5] = revisar_jugadas(valores_j2, Jugadas::EscColor, pu_j2, mano_j2);
    jugadas[1][4] = revisar_jugadas(valores_j2, Jugadas::Poker, pu_j2, mano_j2);
    jugadas[1][3] = revisar_jugadas(valores_j2, Jugadas::Color, pu_j2, mano_j2);
    jugadas[1][2] = revisar_jugadas(valores_j2, Jugadas::Escalera, pu_j2, mano_j2);
    jugadas[1][1] = revisar_jugadas(valores_j2, Jugadas::Trio, pu_j2, mano_j2);
    jugadas[1][0] = revisar_jugadas(valores_j2, Jugadas::Par, pu_j2, mano_j2);

    for (int i = 0; i < jugadas.size(); i++)
    {
        cout << "Jugador " << i+1 << ":" << endl;
        for (int j = 0; j < jugadas[0].size(); j++)
        {
            cout << jugadas[i][j] << " ";
        }
        cout << endl << endl;
    }

    // Pasa por todos los valores del ultimo al primero
    for (int i = jugadas[0].size()-1; i >= 0; i--)
    {
        // Si el jugador 1 tiene una jugada de ese valor, pero no el jugador 2
        if (jugadas[0][i] > jugadas[1][i])
            return true;

        // Si el jugador 2 tiene una jugada de ese valor, pero no el jugador 1
        else if (jugadas[0][i] < jugadas[1][i])
            return false;

        // Si ambos jugadores tienen el mismo valor en este campo
        else if (jugadas[0][i] == jugadas[1][i]) {
            // Sabemos que ambos valores son iguales, solo tenemos que comparar uno
            if (jugadas[0][i] == 0)
                continue;   // No hay nada que comparar

            // Revisar si el valor de alguno es mayor
            if (mano_j1[i].valor > mano_j2[i].valor)
                return true;

            else if (mano_j1[i].valor < mano_j2[i].valor)
                return false;

            // Revisar cual palo es mejor
            if (mano_j1[i].palo < mano_j2[i].palo)
                return true;

            else if (mano_j1[i].palo > mano_j2[i].palo)
                return false;
        }
    }

    // Ya que ninguno de los dos jugadores tiene una jugada, se elige un ganador aleatorio
    int semilla_secundaria = time(NULL);

    srand(semilla_secundaria);

    bool ganador_aleatorio = rand() % 2;

    return ganador_aleatorio;
}

int revisar_jugadas(vector<int>& v, Jugadas j, vector<int>& p, vector<carta> mano)
{
    switch (j)
    {
    case Jugadas::EscColor:
        {
            int contador = 0, inicio = 0;
            bool vuelta = false;
            while (true)
            {
                if (vuelta && contador == 0)
                    return 0;

                for (int i = 0; i < v.size()-1; i++)
                {
                    if (contador != 0 && i == inicio)
                        return 0;

                    if (v[i + 1] == v[i] + 1 && mano[i].palo == mano[i+1].palo) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4) {
                            for (int j = 0; j < v.size(); j++)
                            {
                                p.push_back(j);
                            }
                            return 1;

                        }

                    } else if (v[i] == 13 && v[i+1] == 1 && mano[i].palo == mano[i+1].palo) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4) {
                            for (int j = 0; j < v.size(); j++)
                            {
                                p.push_back(j);
                            }
                            return 1;

                        }

                    }
                }
                vuelta = true;
            }

            return 1;
        }

    case Jugadas::Poker:
        {
            int valor_contado = 0;
            for (int i = 0; i < v.size(); i++)
            {
                valor_contado = v[i];

                if (v[i+1] == valor_contado && v[i+2] == valor_contado && v[i+3] == valor_contado) {
                    // Las cuatro cartas utilizadas
                    p.push_back(i);
                    p.push_back(i+1);
                    p.push_back(i+2);
                    p.push_back(i+3);

                    return 1;   // Solo puede haber un poker por mano

                }
            }

            return 0;
        }

    case Jugadas::Color:
        {
            vector<int> cantidades_palos = { 0, 0, 0, 0 };
            vector<vector<int>> posiciones_utilizadas = { {}, {}, {}, {} };;
            for (int i = 0; i < mano.size(); i++)
            {
                switch (mano[i].palo)
                {
                case 0:
                    cantidades_palos[0]++;
                    posiciones_utilizadas[0].push_back(i);
                    break;

                case 1:
                    cantidades_palos[1]++;
                    posiciones_utilizadas[1].push_back(i);
                    break;

                case 2:
                    cantidades_palos[2]++;
                    posiciones_utilizadas[2].push_back(i);
                    break;

                case 3:
                    cantidades_palos[3]++;
                    posiciones_utilizadas[3].push_back(i);
                    break;

                default:
                    cout << "Hubo un error al encontrar el palo de la carta " << i << endl;
                }
            }

            for (int j = 0; j < cantidades_palos.size(); j++)
            {
                if (cantidades_palos[j] == 5) {
                    for (int g = 0; g < posiciones_utilizadas[j].size(); g++)
                    {
                        p.push_back(posiciones_utilizadas[j][g]);
                    }

                    return 1;

                }


            }

            return 0;
        }

    case Jugadas::Escalera:
        {
            if (p.size() != 0)
                return 0;

            int contador = 0, inicio = 0;
            bool vuelta = false;
            while (true)
            {
                if (vuelta && contador == 0)
                    return 0;

                for (int i = 0; i < v.size()-1; i++)
                {
                    if (contador != 0 && i == inicio)
                        return 0;

                    if (v[i + 1] == v[i] + 1) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4) {
                            for (int j = 0; j < v.size(); j++)
                            {
                                p.push_back(j);
                            }
                            return 1;

                        }

                    }
                    else if (v[i] == 13 && v[i+1] == 1) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4) {
                            for (int j = 0; j < v.size(); j++)
                            {
                                p.push_back(j);
                            }
                            return 1;

                        }

                    }
                }
                vuelta = true;
            }

            return 1;
        }

    case Jugadas::Trio:
        {
            int valor_contado = 0;
            bool utilizado;
            for (int i = 0; i < v.size()-2; i++)
            {
                utilizado = false;
                valor_contado = v[i];

                if (v[i+1] == valor_contado && v[i+2] == valor_contado) {
                    if (p.size() != 0) {
                        for (int j = 0; j < p.size(); j++)
                        {
                            if (p[j] == i || p[j] == i+1 || p[j] == i+2) {
                                utilizado = true;
                                break;

                            }
                        }

                    }


                    if (!utilizado) {
                        p.push_back(i);
                        p.push_back(i + 1);
                        p.push_back(i + 2);

                        return 1;

                    }
                }
            }

            return 0;
        }

    case Jugadas::Par:
        {
            int cantidad_pares = 0;
            int valor_contado = 0;
            bool utilizado;
            for (int i = 0; i < v.size()-1; i++)
            {
                utilizado = false;
                valor_contado = v[i];

                if (v[i+1] == valor_contado) {
                    if (p.size() != 0) {
                        for (int j = 0; j < p.size(); j++)
                        {

                            if (p[j] == i || p[j] == i+1) {
                                utilizado = true;;
                                break;
                            }
                        }
                    }



                    if (!utilizado) {
                        p.push_back(i);
                        p.push_back(i+1);

                        cantidad_pares++;

                    }
                }
            }

            return cantidad_pares;
        }
    }
}

void ordenar_vector(vector<int>& v)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[i - 1]) {
                sorted = false;
                v[i] = v[i] + v[i - 1];
                v[i - 1] = v[i] - v[i - 1];
                v[i] = v[i] - v[i - 1];

            }
        }
    }
}
