# 🧮 Programa de Manejo de Matrices en C++

## 📖 Descripción
Este programa implementa una **clase `Matriz`** en **C++** que permite crear, imprimir, transponer y multiplicar matrices cuadradas de tamaño `n x n`.  
Los elementos se inicializan de forma **aleatoria** con valores enteros entre 0 y 9.

El código utiliza **programación orientada a objetos**, asignación dinámica de memoria y sobrecarga de operadores para acceder a los elementos de la matriz.

---

## ⚙️ Características principales

- Creación dinámica de matrices cuadradas de tamaño `n x n`.  
- Inicialización con **valores aleatorios** entre 0 y 9.  
- Métodos para:
  - 📤 **Imprimir** la matriz.
  - 🔁 **Calcular la transpuesta**.
  - ✖️ **Multiplicar dos matrices del mismo tamaño**.
- Liberación automática de memoria mediante el **destructor**.  
- Uso de **punteros dobles (`double**`)** para almacenar los datos.  
- **Sobrecarga del operador `()`** para acceder a elementos como `A(i, j)`.

---

## 🧩 Estructura del código

### 📘 Clase `Matriz`

**Atributos privados:**
- `int n` → tamaño de la matriz (número de filas y columnas).  
- `double** datos` → puntero doble que almacena los valores.  

**Métodos principales:**

| Método | Descripción |
|--------|--------------|
| `Matriz(int n)` | Constructor: crea una matriz de tamaño `n x n` e inicializa sus elementos aleatoriamente. |
| `void imprimir() const` | Muestra la matriz en consola. |
| `Matriz transpuesta() const` | Retorna una nueva matriz con la transpuesta de la actual. |
| `Matriz multiplicar(const Matriz& B) const` | Retorna una nueva matriz resultante del producto `A * B`. |
| `double& operator()(int i, int j)` | Permite acceder o modificar un elemento como `A(i,j)`. |
| `~Matriz()` | Destructor: libera la memoria asignada dinámicamente. |

---

## 🧠 Lógica del programa principal

1. Se define el tamaño `n` de las matrices (por defecto, 3).  
2. Se crean dos matrices `A` y `B` con valores aleatorios.  
3. Se imprimen ambas matrices.  
4. Se calcula y muestra:
   - La **multiplicación** `A * B`.  
   - La **transpuesta** de `A`.  

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
g++ normamatriz.cpp -o normamatriz.exe

### Ejecución
normamatriz.exe
