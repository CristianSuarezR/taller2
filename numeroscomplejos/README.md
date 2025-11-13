# 🔢 Números Complejos y Polares en C++

## 📖 Descripción
Este programa implementa dos clases en **C++** para el manejo de **números complejos** en forma **binomial** y **polar**.  
Permite realizar operaciones aritméticas, conversiones entre representaciones, cálculo del conjugado, magnitud y fase, y acumulación de múltiples números.

El código aplica **programación orientada a objetos (POO)**, **sobrecarga de operadores**, y **constructores flexibles** para la conversión automática entre las clases `Complex` y `Polar`.

---

## ⚙️ Características principales

- Representación de números complejos en:
  - 🧮 **Forma binomial:** `a + bi`
  - 📈 **Forma polar:** `r * e^(iθ)`
- Operaciones soportadas:
  - Suma (`+`)
  - Resta (`-`)
  - Multiplicación (`*`)
  - División (`/`)
  - Conjugado (`conj()`)
- Conversión entre **formas binomial y polar**.
- Cálculo de:
  - **Módulo** (magnitud)
  - **Ángulo** (fase en radianes)
- Función `acumula()` que suma una lista de números complejos y polares.

---

## 🧩 Clases implementadas

### 📘 Clase `Complex` (forma binomial)
**Atributos:**
- `real`: parte real del número.
- `imag`: parte imaginaria.

**Métodos principales:**
| Método | Descripción |
|--------|--------------|
| `Complex(double r, double i)` | Constructor principal. |
| `Complex(const Polar& p)` | Convierte un número polar a binomial. |
| `modulo()` | Devuelve la magnitud del número complejo. |
| `argumento()` | Devuelve el ángulo en radianes. |
| `conj()` | Devuelve el número conjugado. |
| `imprimir()` | Muestra el número en formato `a + bi`. |

**Operadores sobrecargados:** `+`, `-`, `*`, `/`

---

### 📗 Clase `Polar` (forma polar)
**Atributos:**
- `r`: magnitud.
- `t`: ángulo en radianes.

**Métodos principales:**
| Método | Descripción |
|--------|--------------|
| `Polar(double r, double t)` | Constructor principal. |
| `Polar(const Complex& c)` | Convierte un número complejo a polar. |
| `toComplex()` | Convierte la forma polar a binomial. |
| `conj()` | Retorna el conjugado (inversión del ángulo). |
| `imprimir()` | Muestra el número en formato `r * e^(iθ)`. |

**Operadores sobrecargados:** `*`, `/`

---

## 🔁 Conversión entre formas
- De **polar → binomial**:
  ```cpp
  Complex c(b); // b es un objeto Polar
🧮 Función acumula()
Complex acumula(const vector<Complex>& listaC, const vector<Polar>& listaP);


Suma todos los números complejos y polares (convertidos a binomial) en un solo resultado.

💻 Ejecución del programa (Windows)
🧱 Requisitos

Compilador C++11 o superior (por ejemplo: MinGW, Dev-C++, Code::Blocks, Visual Studio).

▶️ Compilación

Si usas terminal (CMD o PowerShell) con MinGW:

g++ numeroscomplejos.cpp -o numeroscomplejos.exe

▶️ Ejecución
numeroscomplejos.exe
