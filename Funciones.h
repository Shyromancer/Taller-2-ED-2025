#pragma once
#include <iostream>
#include <fstream>
#include "Reino.h"

const int MAX_REINOS = 100;
const int MAX = 100;
const int INF = 999999; // Representa “infinito”

void cargarReinos(Reino* reinos[], int& cantidad) {
    std::ifstream archivo("reinos.csv");
    char linea[100];
    cantidad = 0;

    if (!archivo.is_open()) {
        std::cout << "❌ Error al abrir reinos.csv" << std::endl;
        return;
    }

    while (archivo.getline(linea, 100)) {
        char idStr[10], nombre[50], evento[20];
        int i = 0, j = 0;

        while (linea[i] != ',' && linea[i] != '\0') {
            idStr[j++] = linea[i++];
        }
        idStr[j] = '\0';
        int id = 0;
        for (int k = 0; idStr[k] != '\0'; k++) {
            id = id * 10 + (idStr[k] - '0');
        }

        i++; j = 0;
        while (linea[i] != ',' && linea[i] != '\0') {
            nombre[j++] = linea[i++];
        }
        nombre[j] = '\0';

        i++; j = 0;
        while (linea[i] != '\0') {
            evento[j++] = linea[i++];
        }
        evento[j] = '\0';

        reinos[cantidad] = new Reino(id, nombre, evento);
        cantidad++;
    }

    archivo.close();
}

void cargarMatriz(int matriz[MAX][MAX], int& dimension) {
    std::ifstream archivo("matriz_reinos.txt");
    if (!archivo.is_open()) {
        std::cout << "❌ Error al abrir matriz_reinos.txt" << std::endl;
        return;
    }

    char linea[200];
    dimension = 0;

    while (archivo.getline(linea, 200)) {
        int columna = 0, i = 0;
        char valor[10];
        int j = 0;

        while (linea[i] != '\0') {
            j = 0;

            while (linea[i] != ',' && linea[i] != '\0' && linea[i] != '\n') {
                valor[j++] = linea[i++];
            }
            valor[j] = '\0';

            if (valor[0] == 'i') {
                matriz[dimension][columna++] = INF;
            }
            else {
                int numero = 0;
                for (int k = 0; valor[k] != '\0'; k++) {
                    numero = numero * 10 + (valor[k] - '0');
                }
                matriz[dimension][columna++] = numero;
            }

            if (linea[i] == ',') i++;
        }

        dimension++;
    }

    archivo.close();
}
