# 🧮 Programa de Manejo de Polinomios en C++

## 📖 Descripción
Este programa implementa operaciones básicas con **polinomios** utilizando el lenguaje **C++**.  
Permite al usuario **ingresar dos polinomios** y calcular su **suma** y **producto**, mostrando los resultados en una forma algebraica legible.  

El código está diseñado usando **clases y programación orientada a objetos**, aprovechando conceptos como **encapsulamiento, arreglos dinámicos y métodos de acceso**.

---

## ⚙️ Características principales

- Permite crear polinomios a partir de los términos ingresados por el usuario.  
- Cada término tiene un **coeficiente** y un **exponente**.  
- Soporta las operaciones:
  - ➕ **Suma de polinomios**
  - ✖️ **Multiplicación de polinomios**
- Evita mostrar **términos nulos (coeficiente = 0)**.  
- Muestra los polinomios con formato matemático:  
  Ejemplo → `3x^2 + 5x + 1`

---

## 🧩 Estructura del código

### 📘 Clase `CTermino`
Representa un **término individual** del polinomio (de la forma `a*x^n`).

**Atributos:**
- `coeficiente` (float): valor numérico del término.  
- `exponente` (int): potencia de la variable `x`.  

**Métodos principales:**
- `getCoeficiente()` y `getExponente()` — devuelven los valores del término.  
- `toString()` — devuelve una representación en texto como `+3x^2` o `-2x`.  

---

### 📗 Clase `CPolinomio`
Representa un **polinomio completo**, es decir, un conjunto dinámico de términos.

**Atributos:**
- `CTermino* terminos`: arreglo dinámico de términos.  
- `int n`: cantidad de términos actuales.  

**Métodos principales:**
- `asignarTermino(const CTermino&)`: agrega o combina términos.  
- `sumar(const CPolinomio&)`: retorna la suma de dos polinomios.  
- `multiplicar(const CPolinomio&)`: retorna el producto de dos polinomios.  
- `toString()`: genera una cadena con el polinomio formateado.  

---

## 🧠 Lógica del programa

1. El usuario ingresa cuántos términos tiene el **primer polinomio** y sus respectivos **coeficientes y exponentes**.  
2. Luego repite el proceso para el **segundo polinomio**.  
3. El programa muestra:
   - `P(x)` y `Q(x)` formateados.
   - La **suma** `P(x) + Q(x)`.
   - El **producto** `P(x) * Q(x)`.

---

## 💻 Ejecución del programa (Windows)

### 🧱 Requisitos
- Compilador de C++ compatible con **C++11 o superior**, como:
  - **MinGW**
  - **Dev-C++**
  - **Code::Blocks**
  - **Visual Studio**

### ▶️ Compilación
Si usas **terminal (CMD o PowerShell)** con MinGW configurado, escribe:
```bash
g++ polinomio.cpp -o polinomio.exe

###Ejecución
polinomio.exe
