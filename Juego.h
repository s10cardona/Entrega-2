#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <vector>
#include "Mazo.h"
#include "Fila.h"
#include "Jugador.h"


using namespace std;

class Juego {
private:
    Mazo* mazo;
    vector<Fila*> filas; 
    vector<Jugador*> jugadores; 
    int numeroJugadores;
    vector<int> coloresEnJuego;
public:
    Juego();
    ~Juego();
    void iniciar(int numJugadores);
    void mostrarEstado() const;
    void turnoJugador(int idJugador);
    void jugar();
private:
    void prepararRonda(int jugadorInicial);
    void finalizarJuego();
};

#endif // JUEGO_H