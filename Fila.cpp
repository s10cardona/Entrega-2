#ifndef FILA_H
#define FILA_H

#include <vector>
#include "Carta.h"

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
    std::vector<Carta*> tomarFila();
};

#endif
