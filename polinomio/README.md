# 🧮 Polinomios en C++

## 📖 Descripción
Este programa implementa una clase **`Polinomio`** en **C++**, que permite crear, operar y analizar polinomios de forma dinámica.  
Los coeficientes se generan aleatoriamente y el código demuestra operaciones algebraicas básicas, derivación y evaluación de polinomios.  
El objetivo es aplicar **programación orientada a objetos (POO)**, manejo de **memoria dinámica**, **sobrecarga de operadores** y **métodos matemáticos**.

## ⚙️ Características principales
- Creación automática de polinomios con coeficientes aleatorios entre **-5 y 5**.  
- Operaciones algebraicas entre polinomios:
  - ➕ **Suma**
  - ✖️ **Multiplicación**
  - 🔻 **Derivación**
- Evaluación de un polinomio en un valor dado de `x`.
- Impresión en formato legible (forma estándar: `ax^n + bx^(n-1) + ... + c`).
- Uso de memoria dinámica (`new` y `delete`).
- Control automático de signos y términos nulos.

## 🧩 Clase `Polinomio`

### 🔹 Atributos privados
| Atributo | Tipo | Descripción |
|-----------|------|-------------|
| `grado` | `int` | Grado del polinomio |
| `coef` | `double*` | Puntero dinámico a los coeficientes |

### 🔹 Métodos públicos
| Método | Descripción |
|---------|--------------|
| `Polinomio(int grado)` | Constructor: crea un polinomio aleatorio. |
| `Polinomio(const Polinomio& p)` | Constructor de copia. |
| `double evaluar(double x)` | Evalúa el polinomio en un valor de `x`. |
| `Polinomio operator+(const Polinomio& p)` | Suma dos polinomios. |
| `Polinomio operator*(const Polinomio& p)` | Multiplica dos polinomios. |
| `Polinomio derivar()` | Devuelve la derivada del polinomio. |
| `void imprimir()` | Muestra el polinomio en formato legible. |
| `~Polinomio()` | Destructor que libera la memoria dinámica. |

## 🧮 Operaciones demostradas en `main()`
cpp
Polinomio A(grado);
Polinomio B(grado);

A.imprimir();          // Muestra el polinomio A
B.imprimir();          // Muestra el polinomio B
(A + B).imprimir();    // Suma de A y B
(A * B).imprimir();    // Multiplicación de A y B
A.derivar().imprimir();// Derivada de A
A.evaluar(2.0);        // Evalúa A en x = 2


## 💻 Compilación y ejecución (Windows)
🧱 Requisitos

Compilador C++11 o superior
(por ejemplo: MinGW, Code::Blocks, Dev-C++, o Visual Studio)

▶️ Compilar

Abre una terminal (CMD o PowerShell) en la carpeta donde está tu archivo polinomio.cpp y ejecuta:
g++ polinomio.cpp -o polinomio.exe

▶️ Ejecutar
polinomio.exe


