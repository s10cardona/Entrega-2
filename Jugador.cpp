#include "Jugador.h"
using namespace std;

Jugador::Jugador(int id) : puntaje(0), yaTomoFila(false) {
    nombre = "Jugador " + to_string(id);
    cartas = new int[NUM_COLORES + 1];
    for (int i = 0; i <= NUM_COLORES; ++i) cartas[i] = 0;
}

Jugador::~Jugador() {
    delete[] cartas;
    cartas = nullptr;
}

string Jugador::getNombre() const { return nombre; }
int Jugador::getPuntaje() const { return puntaje; }
void Jugador::setTomoFila(bool estado) { yaTomoFila = estado; }
bool Jugador::getTomoFila() const { return yaTomoFila; }

void Jugador::tomarCarta(Carta* c) {
    if (c) cartas[c->getColor()]++;
}

void Jugador::tomarCartas(const vector<Carta*>& cartasRecibidas) {
    for (Carta* c : cartasRecibidas) tomarCarta(c);
    yaTomoFila = true;
}

int Jugador::puntosPorCantidad(int cantidad) {
    if (cantidad <= 0) return 0;
    if (cantidad == 1) return 1;
    if (cantidad == 2) return 3;
    if (cantidad == 3) return 6;
    if (cantidad == 4) return 10;
    if (cantidad == 5) return 15;
    return 21;
}

void Jugador::calcularPuntuacion(const vector<int>& coloresEnJuego) {
    vector<pair<int,int>> conteoOrdenado;
    for (int colorId : coloresEnJuego)
        conteoOrdenado.push_back({cartas[colorId], colorId});
    sort(conteoOrdenado.rbegin(), conteoOrdenado.rend());
    int puntosTotales = 0;
    cout << "\n[Puntuación de " << nombre << "]" << endl;
    for (size_t i = 0; i < conteoOrdenado.size(); ++i) {
        int cantidad = conteoOrdenado[i].first;
        if (cantidad == 0) continue;
        int puntos = puntosPorCantidad(cantidad);
        if (i < 3) {
            puntosTotales += puntos;
            cout << "  -> POSITIVO Color " << conteoOrdenado[i].second
                 << " (" << cantidad << " cartas): +" << puntos << endl;
        } else {
            puntosTotales -= puntos;
            cout << "  -> NEGATIVO Color " << conteoOrdenado[i].second
                 << " (" << cantidad << " cartas): -" << puntos << endl;
        }
    }
    puntaje = puntosTotales;
}
