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

    vector<int> pu_j1(5, 0);

    jugadas[0][5] = revisar_jugadas(valores_j1, Jugadas::EscColor, pu_j1, mano_j1);
    jugadas[0][4] = revisar_jugadas(valores_j1, Jugadas::Poker, pu_j1, mano_j1);

    cout << jugadas[0][4] << endl;

    return true;
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
                        if (contador == 4)
                            return 1;

                    } else if (v[i] == 13 && v[i+1] == 1 && mano[i].palo == mano[i+1].palo) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4)
                            return 1;

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

    case Jugadas::Escalera:
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

                    if (v[i + 1] == v[i] + 1) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4)
                            return 1;

                    }
                    else if (v[i] == 13 && v[i+1] == 1) {
                        if (contador == 0)
                            inicio = i;
                        contador++;
                        if (contador == 4)
                            return 1;

                    }
                }
                vuelta = true;
            }

            return 1;
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
