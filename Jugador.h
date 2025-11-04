#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Carta.h"

using namespace std;

class Jugador {
private:
    string nombre; 
    int* cartas;
    int puntaje;
    bool yaTomoFila;
    static const int NUM_COLORES = 7;
public:
    Jugador(int id);
    ~Jugador();
    string getNombre() const;
    int getPuntaje() const;
    void setTomoFila(bool estado);
    bool getTomoFila() const;
    void tomarCarta(Carta* c);
    void tomarCartas(const vector<Carta*>& cartasRecibidas); 
    void calcularPuntuacion(const vector<int>& coloresEnJuego);
private:
    int puntosPorCantidad(int cantidad);
};

#endif 