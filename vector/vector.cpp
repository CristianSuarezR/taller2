#include <iostream>
#include <cmath>   // Para sqrt()

using namespace std;

class Vector3D {
private:
    double x, y, z;

public:
    // Constructor
    Vector3D(double x_ = 0, double y_ = 0, double z_ = 0)
        : x(x_), y(y_), z(z_) {}

    // Método para calcular la magnitud del vector
    double magnitud() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Método para normalizar el vector
    Vector3D normalizar() const {
        double mag = magnitud();
        if (mag == 0) {
            cout << "No se puede normalizar un vector nulo." << endl;
            return Vector3D(0, 0, 0);
        }
        return Vector3D(x / mag, y / mag, z / mag);
    }

    // Sobrecarga del operador suma (+)
    Vector3D operator+(const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    // Sobrecarga del operador resta (-)
    Vector3D operator-(const Vector3D& v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    // Sobrecarga del operador producto escalar (*)
    double operator*(const Vector3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Método para imprimir el vector
    void imprimir() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

// Ejemplo de uso
int main() {
    Vector3D v1(3, 4, 0);
    Vector3D v2(1, 2, 3);

    cout << "v1 = "; v1.imprimir();
    cout << "v2 = "; v2.imprimir();

    cout << "Magnitud de v1: " << v1.magnitud() << endl;

    Vector3D v3 = v1 + v2;
    cout << "v1 + v2 = "; v3.imprimir();

    Vector3D v4 = v1 - v2;
    cout << "v1 - v2 = "; v4.imprimir();

    cout << "Producto escalar (v1 · v2): " << (v1 * v2) << endl;

    cout << "Vector normalizado de v1: ";
    v1.normalizar().imprimir();

    return 0;
}
