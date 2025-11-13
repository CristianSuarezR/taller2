# 🎲 Juego de Dominó en C++

## 📖 Descripción
Este proyecto implementa un **juego de dominó** simple en consola utilizando **C++**.  
Permite jugar entre **2 y 4 jugadores**, con reparto automático de fichas, turnos alternos y conteo de puntos por rondas ganadas.  
El objetivo es ser el primer jugador en quedarse sin fichas o tener la menor cantidad posible cuando el juego se bloquea.

---

## ⚙️ Características principales

- Generación automática del **mazo de 28 fichas** de dominó.  
- **Barajado aleatorio** de fichas usando el motor de números aleatorios de C++.  
- **Reparto automático** según el número de jugadores.  
- Colocación de fichas válida en los extremos **izquierdo o derecho** de la mesa.  
- Detección de:
  - **Jugadas inválidas.**
  - **Bloqueo del juego** cuando ningún jugador puede continuar.  
- **Contador de puntos** por jugador al ganar cada ronda.  
- Opción para **jugar múltiples rondas** en una misma sesión.  

---

## 🧩 Estructura del código

### 🧱 Clase `Ficha`
Representa una ficha de dominó con dos valores enteros (`a`, `b`).

**Método principal:**
- `imprimir()`: muestra la ficha en formato `[a|b]`.

---

### 🧍 Clase `Jugador`
Guarda el nombre, las fichas y los puntos de cada jugador.

**Métodos principales:**
- `mostrarFichas()`: muestra las fichas actuales del jugador.  
- `tieneMovimiento(int izquierda, int derecha)`: determina si el jugador puede colocar alguna ficha válida.  

---

### 🎮 Clase `JuegoDomino`
Controla toda la lógica del juego, desde la creación del mazo hasta la gestión de rondas y turnos.

**Funciones principales:**
- `crearMazo()`: genera las 28 fichas únicas del dominó.  
- `repartir()`: baraja el mazo y distribuye las fichas entre los jugadores.  
- `mostrarMesa()`: muestra el estado actual de la mesa.  
- `colocarFicha()`: intenta colocar una ficha seleccionada en el extremo válido.  
- `jugarRondas()`: ejecuta las rondas completas del juego hasta que el usuario decida salir.  

---

## 🧠 Lógica del juego

1. El usuario indica **cuántos jugadores** participarán (entre 2 y 4).  
2. Se generan las 28 fichas y se reparten de forma aleatoria.  
3. El primer jugador inicia colocando una ficha en la mesa.  
4. En cada turno, el jugador puede:
   - **Colocar una ficha válida**, o  
   - **Pasar**, si no tiene jugadas posibles.  
5. Si un jugador se queda sin fichas, **gana la ronda**.  
6. Si ningún jugador puede jugar, el juego se **bloquea**.  
7. Se muestran los **puntajes acumulados** y los jugadores deciden si continúan.  

---

## 💻 Ejecución del programa (Windows)

### 🧱 Requisitos
- Tener instalado un compilador compatible con **C++11 o superior** (por ejemplo, `MinGW` o el compilador de **Code::Blocks**, **Dev-C++** o **Visual Studio**).

### ▶️ Compilación
Si estás usando **terminal (CMD o PowerShell)** y tienes MinGW configurado, escribe:
```bash
g++ domino.cpp -o domino.exe

### Ejecucion
domino.exe 

