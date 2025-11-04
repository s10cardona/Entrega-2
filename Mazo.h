#ifndef MAZO_H
#define MAZO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "Carta.h"


using namespace std;

class Mazo {
private:
    vector<Carta*> cartas; 
    float totalCartas;
public:
    Mazo();
    ~Mazo();
    void inicializar(int numColoresUsar);
    void barajar();
    Carta* robar();
    float getTotalCartas() const;
};

#endif