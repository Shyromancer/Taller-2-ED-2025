#include <iostream>
#include "Reino.h"
#include "Funciones.h"

int main() {
    Reino* reinos[MAX_REINOS];
    int cantidad = 0;
    int matriz[MAX][MAX];
    int dimension = 0;

    cargarReinos(reinos, cantidad);
    std::cout << "\n🔹 Reinos cargados:\n";
    for (int i = 0; i < cantidad; i++) {
        reinos[i]->mostrar();
    }

    cargarMatriz(matriz, dimension);
    std::cout << "\n🔹 Matriz de adyacencia:\n";
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (matriz[i][j] == INF)
                std::cout << "i ";
            else
                std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Liberar memoria
    for (int i = 0; i < cantidad; i++) {
        delete reinos[i];
    }

    return 0;
}
