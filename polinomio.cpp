#include <iostream>
#include <cmath>   // Para pow()
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
using namespace std;

class Polinomio {
private:
    int grado;        // Grado del polinomio
    double* coef;     // Arreglo dinámico para los coeficientes

public:
    // Constructor: inicializa los coeficientes del polinomio con valores aleatorios
    Polinomio(int grado) {
        this->grado = grado;
        coef = new double[grado + 1];
        srand(time(nullptr));

        // Inicializar con valores aleatorios entre -5 y 5
        for (int i = 0; i <= grado; i++)
            coef[i] = (rand() % 11) - 5; // valores entre -5 y 5
    }

    // Constructor de copia
    Polinomio(const Polinomio& p) {
        grado = p.grado;
        coef = new double[grado + 1];
        for (int i = 0; i <= grado; i++)
            coef[i] = p.coef[i];
    }

    // Método para evaluar el polinomio en un valor dado de x
    double evaluar(double x) const {
        double resultado = 0;
        for (int i = 0; i <= grado; i++)
            resultado += coef[i] * pow(x, grado - i);
        return resultado;
    }

    // Sobrecarga del operador de suma entre polinomios
    Polinomio operator+(const Polinomio& p) const {
        int maxGrado = max(grado, p.grado);
        int dif1 = maxGrado - grado;
        int dif2 = maxGrado - p.grado;

        Polinomio resultado(maxGrado);
        for (int i = 0; i <= maxGrado; i++) {
            double c1 = (i - dif1 >= 0) ? coef[i - dif1] : 0;
            double c2 = (i - dif2 >= 0) ? p.coef[i - dif2] : 0;
            resultado.coef[i] = c1 + c2;
        }
        return resultado;
    }

    // Sobrecarga del operador de multiplicación entre polinomios
    Polinomio operator*(const Polinomio& p) const {
        int nuevoGrado = grado + p.grado;
        Polinomio resultado(nuevoGrado);

        // Inicializar con ceros
        for (int i = 0; i <= nuevoGrado; i++)
            resultado.coef[i] = 0;

        for (int i = 0; i <= grado; i++)
            for (int j = 0; j <= p.grado; j++)
                resultado.coef[i + j] += coef[i] * p.coef[j];

        return resultado;
    }

    // Método para imprimir el polinomio en la forma estándar
    void imprimir() const {
        bool primero = true;
        for (int i = 0; i <= grado; i++) {
            double c = coef[i];
            int exp = grado - i;

            if (c == 0) continue;

            if (!primero) {
                cout << (c > 0 ? " + " : " - ");
            } else {
                if (c < 0) cout << "-";
                primero = false;
            }

            double valorAbs = fabs(c);
            if (valorAbs != 1 || exp == 0)
                cout << valorAbs;

            if (exp > 0) cout << "x";
            if (exp > 1) cout << "^" << exp;
        }
        cout << endl;
    }

    // Método que devuelve la derivada del polinomio
    Polinomio derivar() const {
        if (grado == 0) {
            Polinomio derivada(0);
            derivada.coef[0] = 0;
            return derivada;
        }

        Polinomio derivada(grado - 1);
        for (int i = 0; i < grado; i++)
            derivada.coef[i] = coef[i] * (grado - i);
        return derivada;
    }

    // Destructor: libera la memoria asignada dinámicamente
    ~Polinomio() {
        delete[] coef;
    }
};

// -----------------------------
// Programa principal de prueba
// -----------------------------
int main() {
    int grado = 3;
    Polinomio A(grado);
    Polinomio B(grado);

    cout << "Polinomio A: ";
    A.imprimir();
    cout << "Polinomio B: ";
    B.imprimir();

    cout << "\nA + B = ";
    (A + B).imprimir();

    cout << "A * B = ";
    (A * B).imprimir();

    cout << "\nDerivada de A: ";
    A.derivar().imprimir();

    double x = 2.0;
    cout << "\nA(" << x << ") = " << A.evaluar(x) << endl;

    return 0;
}
