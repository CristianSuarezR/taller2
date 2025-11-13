#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

// ------------------------------------------------------------
// Clase que representa un término: a*x^n
// ------------------------------------------------------------
class CTermino {
private:
    float coeficiente;
    int exponente;

public:
    // Constructor por omisión (coeficiente = 0, exponente = 0)
    CTermino(float c = 0, int e = 0) {
        coeficiente = c;
        exponente = e;
    }

    // Métodos de acceso (getters)
    float getCoeficiente() const { return coeficiente; }
    int getExponente() const { return exponente; }

    // Método para convertir el término en cadena legible
    string toString() const {
        ostringstream salida;
        if (coeficiente == 0) return ""; // No mostrar términos nulos

        // Mostrar signo positivo o negativo según el caso
        if (coeficiente > 0) salida << "+";
        salida << coeficiente;

        // Mostrar variable y exponente si corresponde
        if (exponente == 1)
            salida << "x";
        else if (exponente > 1)
            salida << "x^" << exponente;

        return salida.str();
    }
};

// ------------------------------------------------------------
// Clase que representa un polinomio (colección de términos)
// ------------------------------------------------------------
class CPolinomio {
private:
    CTermino* terminos;  // arreglo dinámico de términos
    int n;               // número de términos actuales

public:
    // Constructor por omisión
    CPolinomio() {
        n = 0;
        terminos = nullptr;
    }

    // Destructor: libera memoria dinámica
    ~CPolinomio() {
        delete[] terminos;
    }

    // Obtener número de términos
    int getNumTerminos() const { return n; }

    // Asignar un término al polinomio (en orden de exponente)
    void asignarTermino(const CTermino& t) {
        if (t.getCoeficiente() == 0) return; // no agregar términos nulos

        // Verificar si ya existe un término con ese exponente
        for (int i = 0; i < n; i++) {
            if (terminos[i].getExponente() == t.getExponente()) {
                // Sumar coeficientes
                float nuevoCoef = terminos[i].getCoeficiente() + t.getCoeficiente();
                terminos[i] = CTermino(nuevoCoef, t.getExponente());
                return;
            }
        }

        // Crear nuevo arreglo con un término más
        CTermino* nuevo = new CTermino[n + 1];

        // Insertar el nuevo término en orden creciente de exponente
        int j = 0, insertado = 0;
        for (int i = 0; i < n; i++) {
            if (!insertado && t.getExponente() < terminos[i].getExponente()) {
                nuevo[j++] = t;
                insertado = 1;
            }
            nuevo[j++] = terminos[i];
        }
        if (!insertado) nuevo[j++] = t;

        // Reemplazar el arreglo antiguo
        delete[] terminos;
        terminos = nuevo;
        n++;
    }

    // Sumar dos polinomios
    CPolinomio sumar(const CPolinomio& p) const {
        CPolinomio resultado;
        for (int i = 0; i < n; i++)
            resultado.asignarTermino(terminos[i]);
        for (int i = 0; i < p.n; i++)
            resultado.asignarTermino(p.terminos[i]);
        return resultado;
    }

    // Multiplicar dos polinomios
    CPolinomio multiplicar(const CPolinomio& p) const {
        CPolinomio resultado;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p.n; j++) {
                float c = terminos[i].getCoeficiente() * p.terminos[j].getCoeficiente();
                int e = terminos[i].getExponente() + p.terminos[j].getExponente();
                resultado.asignarTermino(CTermino(c, e));
            }
        }
        return resultado;
    }

    // Convertir a cadena legible
    string toString() const {
        if (n == 0) return "0";
        ostringstream salida;
        for (int i = 0; i < n; i++) {
            string term = terminos[i].toString();
            if (!term.empty()) salida << term;
        }
        string res = salida.str();
        if (res[0] == '+') res.erase(0, 1); // quitar signo inicial +
        return res;
    }
};

// ------------------------------------------------------------
// Función principal
// ------------------------------------------------------------
int main() {
    cout << "=== MANEJO DE POLINOMIOS ===" << endl;

    int n1, n2;
    float coef;
    int exp;

    // --- Ingreso del primer polinomio ---
    cout << "\nCuantos terminos tiene el primer polinomio? ";
    cin >> n1;
    CPolinomio P;
    for (int i = 0; i < n1; i++) {
        cout << "Coeficiente del termino " << i + 1 << ": ";
        cin >> coef;
        cout << "Exponente del termino " << i + 1 << ": ";
        cin >> exp;
        P.asignarTermino(CTermino(coef, exp));
    }

    // --- Ingreso del segundo polinomio ---
    cout << "\nCuantos terminos tiene el segundo polinomio? ";
    cin >> n2;
    CPolinomio Q;
    for (int i = 0; i < n2; i++) {
        cout << "Coeficiente del termino " << i + 1 << ": ";
        cin >> coef;
        cout << "Exponente del termino " << i + 1 << ": ";
        cin >> exp;
        Q.asignarTermino(CTermino(coef, exp));
    }

    // --- Mostrar resultados ---
    cout << "\nP(x) = " << P.toString() << endl;
    cout << "Q(x) = " << Q.toString() << endl;

    CPolinomio Rsum = P.sumar(Q);
    CPolinomio Rmul = P.multiplicar(Q);

    cout << "\nP(x) + Q(x) = " << Rsum.toString() << endl;
    cout << "P(x) * Q(x) = " << Rmul.toString() << endl;

    return 0;
}
