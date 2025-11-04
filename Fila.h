#ifndef FILA_H
#define FILA_H

#include <vector>
#include "Carta.h"


using namespace std;

class Fila {
public:
    Carta** cartas;
private:
    int capacidad;
    int numeroCartas;
public:
    Fila();
    ~Fila();
    int getNumeroCartas() const;
    bool estaLlena() const;
    void agregarCarta(Carta* c);
    vector<Carta*> tomarFila(); 
};

#endif 