#include "Carta.h"
using namespace std;

Carta::Carta(int c) : color(c) {}
Carta::~Carta() {}

int Carta::getColor() const { return color; }

void Carta::mostrar() const {
    map<int, string> nombres = {
        {ROJO, "ROJO"}, {AZUL, "AZUL"}, {AMARILLO, "AMARILLO"},
        {VERDE, "VERDE"}, {NARANJA, "NARANJA"}, {CAFE, "CAFÉ"},
        {VIOLETA, "VIOLETA"}
    };
    cout << "[" << nombres.at(color) << "]";
}

