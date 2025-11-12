#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 3.14159265358979323846;

class Polar; // Declaración adelantada para conversión

// ===========================================
// Clase Complex: forma binomial (a + ib)
// ===========================================
class Complex {
private:
    double real;
    double imag;

public:
    // Constructores
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Constructor flexible: a partir de un número polar
    Complex(const Polar& p);

    // Métodos de acceso
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Operadores aritméticos
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) const {
        double denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom,
                       (imag * c.real - real * c.imag) / denom);
    }

    // Conjugado
    Complex conj() const {
        return Complex(real, -imag);
    }

    // Magnitud y ángulo (para conversión a polar)
    double modulo() const { return sqrt(real * real + imag * imag); }
    double argumento() const { return atan2(imag, real); }

    // Imprimir
    void imprimir() const {
        cout << real << (imag >= 0 ? " + " : " - ") << fabs(imag) << "i";
    }
};

// ===========================================
// Clase Polar: forma polar (r e^{iθ})
// ===========================================
class Polar {
private:
    double r;  // Magnitud
    double t;  // Ángulo en radianes

public:
    // Constructores
    Polar(double r = 0, double t = 0) : r(r), t(t) {}

    // Constructor flexible: a partir de un número complejo
    Polar(const Complex& c) {
        r = c.modulo();
        t = c.argumento();
    }

    // Métodos de acceso
    double getR() const { return r; }
    double getT() const { return t; }

    // Operadores aritméticos
    Polar operator*(const Polar& p) const {
        return Polar(r * p.r, t + p.t);
    }

    Polar operator/(const Polar& p) const {
        return Polar(r / p.r, t - p.t);
    }

    Polar conj() const {
        return Polar(r, -t);
    }

    // Convertir a forma binomial
    Complex toComplex() const {
        return Complex(r * cos(t), r * sin(t));
    }

    // Imprimir
    void imprimir() const {
        cout << r << " * e^(i" << t << ")";
    }
};

// Implementación del constructor flexible de Complex
Complex::Complex(const Polar& p) {
    real = p.getR() * cos(p.getT());
    imag = p.getR() * sin(p.getT());
}

// ===========================================
// Función acumula(): suma indefinida de complejos/polares
// ===========================================
Complex acumula(const vector<Complex>& listaC, const vector<Polar>& listaP) {
    Complex suma(0, 0);

    // Suma todos los complejos
    for (auto& c : listaC)
        suma = suma + c;

    // Convierte y suma todos los polares
    for (auto& p : listaP)
        suma = suma + p.toComplex();

    return suma;
}

// ===========================================
// Programa principal de prueba
// ===========================================
int main() {
    Complex a(3, 4);     // 3 + 4i
    Polar b(5, PI / 6);  // 5∠30°

    cout << "Número complejo a = ";
    a.imprimir();
    cout << endl;

    cout << "Número polar b = ";
    b.imprimir();
    cout << endl;

    // Conversión
    Complex c(b);
    cout << "b en forma binomial = ";
    c.imprimir();
    cout << endl;

    Polar p(a);
    cout << "a en forma polar = ";
    p.imprimir();
    cout << endl;

    // Operaciones
    cout << "\na + conj(a) = ";
    (a + a.conj()).imprimir();
    cout << endl;

    cout << "a * b = ";
    (a * Complex(b)).imprimir();
    cout << endl;

    cout << "b / a = ";
    (Complex(b) / a).imprimir();
    cout << endl;

    // Acumulación de varios números
    vector<Complex> listaC = {Complex(1, 2), Complex(3, -1)};
    vector<Polar> listaP = {Polar(2, PI/4), Polar(1, PI/2)};

    Complex total = acumula(listaC, listaP);
    cout << "\nSuma total de todos los números = ";
    total.imprimir();
    cout << endl;

    return 0;
}
