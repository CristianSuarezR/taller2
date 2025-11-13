# Vector3D - Operaciones con Vectores en C++

## 🧩 Descripción del programa

El programa **Vector3D** implementa una clase en C++ que permite realizar operaciones matemáticas fundamentales con vectores tridimensionales, aplicando los principios de **Programación Orientada a Objetos (POO)**.  

Cada vector tiene tres componentes (`x`, `y`, `z`), y la clase proporciona métodos y operadores sobrecargados para facilitar cálculos comunes en álgebra vectorial.

---

### 🔹 Características principales

**Atributos:**
- `x`, `y`, `z`: componentes del vector.

**Métodos:**
- `magnitud()`: calcula la magnitud del vector.  
- `normalizar()`: devuelve un vector unitario (magnitud 1).  
- `operator+`: suma dos vectores.  
- `operator-`: resta dos vectores.  
- `operator*`: calcula el producto escalar entre dos vectores.  
- `imprimir()`: muestra el vector en formato `(x, y, z)`.

---

## ⚙️ Compilación y ejecución (Windows)

### 🔧 Requisitos previos
- Sistema operativo **Windows**
- Compilador **g++** (instalado con [MinGW](https://www.mingw-w64.org/))
- Editor recomendado: **Visual Studio Code**

---

### 🖥️ Pasos para ejecutar el programa

1. Guarda el código en un archivo llamado `vector3D.cpp`.

2. Abre una terminal **CMD** o **PowerShell** en la carpeta donde se encuentra el archivo.

3. Compila el programa con el siguiente comando:
g++ vector3D.cpp -o vector3D.exe

5. Ejecuta el programa:
vector3D.exe
