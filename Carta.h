#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

enum ColorID {
    ROJO = 1, AZUL, AMARILLO, VERDE, NARANJA, CAFE, VIOLETA
};

class Carta {
private:
    int color;
public:
    Carta(int c);
    ~Carta();
    int getColor() const;
    void mostrar() const;
};

#endif