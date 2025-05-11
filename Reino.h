#pragma once
#include <iostream>

class Reino {
private:
    int id;
    char nombre[50];
    char evento[20];

public:
    Reino(int _id, const char* _nombre, const char* _evento) {
        id = _id;

        int i = 0;
        while (_nombre[i] != '\0') {
            nombre[i] = _nombre[i];
            i++;
        }
        nombre[i] = '\0';

        i = 0;
        while (_evento[i] != '\0') {
            evento[i] = _evento[i];
            i++;
        }
        evento[i] = '\0';
    }

    void mostrar() {
        std::cout << id << " - " << nombre << " - " << evento << std::endl;
    }
};
