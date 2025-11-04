#include "Juego.h"
using namespace std;

Juego::Juego() : numeroJugadores(0) { mazo = new Mazo(); }
Juego::~Juego() {
    delete mazo;
    for (Fila* f : filas) delete f;
    for (Jugador* j : jugadores) delete j;
    cout << "\n--- Memoria dinámica liberada correctamente. ---" << endl;
}

void Juego::iniciar(int numJugadores) {
    numeroJugadores = numJugadores;
    int numColoresUsar = (numJugadores == 3) ? 6 : 7;
    for (int i = 1; i <= numColoresUsar; ++i) coloresEnJuego.push_back(i);
    mazo->inicializar(numColoresUsar);
    for (int i = 1; i <= numJugadores; ++i) jugadores.push_back(new Jugador(i));
    for (int i = 0; i < numJugadores; ++i) filas.push_back(new Fila());
}

void Juego::mostrarEstado() const {
    cout << "\n--- ESTADO DE LA MESA ---" << endl;
    cout << "Cartas restantes en el mazo: " << mazo->getTotalCartas() << endl;
    for (size_t i = 0; i < filas.size(); ++i) {
        cout << "Fila " << i+1 << " (" << filas[i]->getNumeroCartas() << "/3): ";
        for (int j = 0; j < filas[i]->getNumeroCartas(); ++j) {
            filas[i]->cartas[j]->mostrar(); cout << " ";
        }
        cout << endl;
    }
}

void Juego::turnoJugador(int idxJugador) {
    Jugador* actual = jugadores[idxJugador];
    if (actual->getTomoFila()) return;
    cout << "\n===== TURNO de " << actual->getNombre() << " =====" << endl;
    bool puedeRobar = mazo->getTotalCartas() > 0;
    bool todasLlenas = true;
    for (Fila* f : filas) if (!f->estaLlena()) { todasLlenas = false; break; }
    int opcion;
    if (!puedeRobar || todasLlenas) opcion = 2;
    else {
        cout << "¿Qué desea hacer? (1: Robar y colocar, 2: Tomar una fila): ";
        if (!(cin >> opcion)) { opcion = 1; cin.clear(); cin.ignore(10000, '\n'); }
    }
    if (opcion == 1) {
        if (!puedeRobar && todasLlenas) return;
        Carta* cartaRobada = mazo->robar();
        if (cartaRobada) {
            cout << "Robaste "; cartaRobada->mostrar(); cout << endl;
            int filaElegida;
            do {
                cout << "Elige la fila (1 a " << filas.size() << ") para colocarla: ";
                cin >> filaElegida; filaElegida--;
                if (filaElegida >= 0 && filaElegida < filas.size() && !filas[filaElegida]->estaLlena()) {
                    filas[filaElegida]->agregarCarta(cartaRobada);
                    break;
                } else cout << "Fila inválida o llena. Intente de nuevo." << endl;
            } while (true);
        }
    } else {
        int filaElegida;
        do {
            cout << "Elige la fila (1 a " << filas.size() << ") que deseas tomar: ";
            cin >> filaElegida; filaElegida--;
            if (filaElegida >= 0 && filaElegida < filas.size() && filas[filaElegida]->getNumeroCartas() > 0) {
                vector<Carta*> cartasTomadas = filas[filaElegida]->tomarFila();
                actual->tomarCartas(cartasTomadas);
                cout << actual->getNombre() << " ha tomado la Fila " << filaElegida+1 << "." << endl;
                break;
            } else cout << "Fila inválida o vacía. Intente de nuevo." << endl;
        } while (true);
    }
}

void Juego::prepararRonda(int jugadorInicial) {
    for (Jugador* j : jugadores) j->setTomoFila(false);
    int jugadoresActivos = jugadores.size();
    int filasTomadas = 0;
    int turnoActual = jugadorInicial;
    while (filasTomadas < jugadoresActivos) {
        if (!jugadores[turnoActual]->getTomoFila()) {
            turnoJugador(turnoActual);
            if (jugadores[turnoActual]->getTomoFila()) filasTomadas++;
            if (mazo->getTotalCartas() == 0 && filasTomadas < jugadoresActivos) {
                cout << "\n¡MAZO VACÍO! Los jugadores restantes deben tomar filas obligatoriamente." << endl;
                for (int i = 0; i < jugadores.size(); ++i)
                    if (!jugadores[i]->getTomoFila()) { turnoJugador(i); filasTomadas++; }
                break;
            }
        }
        turnoActual = (turnoActual + 1) % jugadoresActivos;
    }
    cout << "\n--- FIN DE RONDA ---" << endl;
}

void Juego::finalizarJuego() {
    cout << "\n=====================================" << endl;
    cout << "========== FIN DEL JUEGO ==========" << endl;
    cout << "=====================================" << endl;
    for (Jugador* j : jugadores) j->calcularPuntuacion(coloresEnJuego);
    Jugador* ganador = nullptr; int maxPuntos = -1000;
    for (Jugador* j : jugadores)
        if (j->getPuntaje() > maxPuntos) { maxPuntos = j->getPuntaje(); ganador = j; }
    if (ganador)
        cout << "\n🎉 ¡EL GANADOR ES " << ganador->getNombre() << " con "
             << ganador->getPuntaje() << " puntos! 🎉" << endl;
}

void Juego::jugar() {
    const int NUM_RONDAS = 2; int jugadorInicial = 0;
    for (int ronda = 1; ronda <= NUM_RONDAS; ++ronda) {
        cout << "\n*************** RONDA " << ronda << " ***************" << endl;
        prepararRonda(jugadorInicial);
        jugadorInicial = (jugadorInicial + 1) % jugadores.size();
        if (mazo->getTotalCartas() == 0) {
            cout << "\n[El mazo está completamente vacío. El juego terminará.]" << endl;
            break;
        }
    }
    finalizarJuego();
}
