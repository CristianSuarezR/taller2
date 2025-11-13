#include <iostream>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
using namespace std;

class Matriz {
private:
    int n;           // Tamaño de la matriz (n x n)
    double** datos;  // Puntero doble para almacenar los valores de la matriz

public:
    // Constructor: crea una matriz de tamaño n x n con valores aleatorios
    Matriz(int n) {
        this->n = n;

        // Asignación dinámica de memoria
        datos = new double*[n];
        for (int i = 0; i < n; i++)
            datos[i] = new double[n];

        // Inicializar con valores aleatorios entre 0 y 9
        srand(time(nullptr));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                datos[i][j] = rand() % 10;
    }

    // Método para imprimir la matriz
    void imprimir() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << datos[i][j] << "\t";
            cout << endl;
        }
    }

    // Método para calcular y devolver la transpuesta
    Matriz transpuesta() const {
        Matriz T(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                T.datos[i][j] = datos[j][i];
        return T;
    }

    // Método para multiplicar por otra matriz del mismo tamaño
    Matriz multiplicar(const Matriz& B) const {
        Matriz C(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C.datos[i][j] = 0;
                for (int k = 0; k < n; k++)
                    C.datos[i][j] += datos[i][k] * B.datos[k][j];
            }
        }
        return C;
    }

    // Sobrecarga del operador () para acceder a los elementos
    double& operator()(int i, int j) {
        return datos[i][j];
    }

    // Destructor: libera la memoria asignada dinámicamente
    ~Matriz() {
        for (int i = 0; i < n; i++)
            delete[] datos[i];
        delete[] datos;
    }
};

// Programa principal para probar la clase
int main() {
    int n = 3;
    cout << "Matriz A:" << endl;
    Matriz A(n);
    A.imprimir();

    cout << "\nMatriz B:" << endl;
    Matriz B(n);
    B.imprimir();

    cout << "\nA * B:" << endl;
    Matriz C = A.multiplicar(B);
    C.imprimir();

    cout << "\nTranspuesta de A:" << endl;
    Matriz T = A.transpuesta();
    T.imprimir();

    return 0;
}
