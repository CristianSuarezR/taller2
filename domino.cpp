#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// ================================
// Clase Ficha
// ================================
class Ficha {
public:
    int a, b;
    Ficha(int x = 0, int y = 0) : a(x), b(y) {}

    void imprimir() const {
        cout << "[" << a << "|" << b << "]";
    }
};

// ================================
// Clase Jugador
// ================================
class Jugador {
public:
    string nombre;
    vector<Ficha> fichas;
    int puntos = 0;

    Jugador(string n = "") : nombre(n) {}

    void mostrarFichas() const {
        cout << "Fichas de " << nombre << ": ";
        for (int i = 0; i < fichas.size(); i++) {
            cout << "(" << i << ")";
            fichas[i].imprimir();
            cout << " ";
        }
        cout << endl;
    }

    bool tieneMovimiento(int izquierda, int derecha) {
        for (auto &f : fichas)
            if (f.a == izquierda || f.b == izquierda ||
                f.a == derecha || f.b == derecha)
                return true;
        return false;
    }
};

// ================================
// Clase JuegoDomino
// ================================
class JuegoDomino {
private:
    vector<Ficha> mazo;
    vector<Jugador> jugadores;
    vector<Ficha> mesa;

public:
    void iniciar() {
        int n;
        cout << "Cantidad de jugadores (2 - 4): ";
        cin >> n;

        jugadores.clear();
        for (int i = 0; i < n; i++) {
            cout << "Nombre del jugador " << i+1 << ": ";
            string nombre;
            cin >> nombre;
            jugadores.push_back(Jugador(nombre));
        }

        jugarRondas();
    }

    // -------------------
    // Crear las 28 fichas
    // -------------------
    void crearMazo() {
        mazo.clear();
        for (int i = 0; i <= 6; i++)
            for (int j = i; j <= 6; j++)
                mazo.push_back(Ficha(i, j));
    }

    // -------------------------
    // Barajar y repartir fichas
    // -------------------------
    void repartir() {
        shuffle(mazo.begin(), mazo.end(), default_random_engine(time(NULL)));

        int porJugador = (mazo.size() / jugadores.size());
        for (int i = 0; i < jugadores.size(); i++) {
            jugadores[i].fichas.clear();
            for (int j = 0; j < porJugador; j++)
                jugadores[i].fichas.push_back(mazo.back()), mazo.pop_back();
        }
    }

    // -------------------------
    // Mostrar el estado de mesa
    // -------------------------
    void mostrarMesa() {
        cout << "\nMesa: ";
        for (auto &f : mesa) {
            f.imprimir();
            cout << " ";
        }
        cout << "\nIzquierda: " << mesa.front().a
             << " | Derecha: " << mesa.back().b << "\n";
    }

    // -------------------------
    // Intentar colocar una ficha
    // -------------------------
    bool colocarFicha(Jugador &jug, int idx) {
        if (idx < 0 || idx >= jug.fichas.size()) return false;

        Ficha f = jug.fichas[idx];
        int izq = mesa.front().a;
        int der = mesa.back().b;

        // Colocar por izquierda
        if (f.b == izq) {
            mesa.insert(mesa.begin(), f);
            jug.fichas.erase(jug.fichas.begin() + idx);
            return true;
        }
        if (f.a == izq) {
            mesa.insert(mesa.begin(), Ficha(f.b, f.a));
            jug.fichas.erase(jug.fichas.begin() + idx);
            return true;
        }

        // Colocar por derecha
        if (f.a == der) {
            mesa.push_back(f);
            jug.fichas.erase(jug.fichas.begin() + idx);
            return true;
        }
        if (f.b == der) {
            mesa.push_back(Ficha(f.b, f.a));
            jug.fichas.erase(jug.fichas.begin() + idx);
            return true;
        }

        return false;
    }

    // -------------------------
    // Ronda completa del juego
    // -------------------------
    void jugarRondas() {
        bool continuar = true;

        while (continuar) {
            crearMazo();
            repartir();
            mesa.clear();

            // Colocar primera ficha del jugador 0
            mesa.push_back(jugadores[0].fichas.back());
            jugadores[0].fichas.pop_back();

            bool bloqueado = false;
            int turno = 0;

            while (true) {
                Jugador &j = jugadores[turno];

                cout << "\n-------------------------------------------\n";
                cout << "Turno de " << j.nombre << endl;
                mostrarMesa();
                j.mostrarFichas();

                if (!j.tieneMovimiento(mesa.front().a, mesa.back().b)) {
                    cout << j.nombre << " NO puede jugar.\n";

                    // Si todos pasan → bloqueo
                    bool todosBloqueados = true;
                    for (auto &x : jugadores) {
                        if (x.tieneMovimiento(mesa.front().a, mesa.back().b))
                            todosBloqueados = false;
                    }

                    if (todosBloqueados) {
                        cout << "Juego bloqueado!\n";
                        bloqueado = true;
                        break;
                    }

                } else {
                    int sel;
                    cout << "Elige ficha (indice): ";
                    cin >> sel;

                    if (!colocarFicha(j, sel))
                        cout << "Movimiento invalido, intenta otra ficha.\n";
                    else if (j.fichas.empty()) {
                        cout << "\n" << j.nombre << " HA GANADO LA RONDA!\n";
                        j.puntos++;
                        break;
                    }
                }

                turno = (turno + 1) % jugadores.size();
            }

            // Mostrar puntaje
            cout << "\nPUNTAJE GENERAL\n";
            for (auto &j : jugadores)
                cout << j.nombre << ": " << j.puntos << endl;

            cout << "\n¿Jugar otra ronda? (1=si, 0=no): ";
            cin >> continuar;
        }

        cout << "\nFIN DEL JUEGO\n";
    }
};

// ================================
// MAIN
// ================================
int main() {
    JuegoDomino domino;
    domino.iniciar();
    return 0;
}
