#include <iostream>
#include <ctime>
#include "Juego.h"
using namespace std;

int main() {
    srand(time(0));
    int numJugadores;
    do {
        cout << "Ingrese el número de jugadores (3-5): ";
        if (!(cin >> numJugadores) || numJugadores < 3 || numJugadores > 5) {
            cin.clear();
            cin.ignore(10000, '\n');
            numJugadores = 0;
            cout << "Entrada inválida. Intente de nuevo." << endl;
        }
    } while (numJugadores == 0);
    Juego coloretto;
    coloretto.iniciar(numJugadores);
    coloretto.jugar();
    return 0;
}
