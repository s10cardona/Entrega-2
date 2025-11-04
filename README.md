# Coloretto (C++)

## Descripción general
Coloretto es un juego de cartas donde los jugadores intentan conseguir la mejor combinación de colores posible.  
El objetivo es sumar puntos coleccionando cartas del mismo color, pero solo **tres colores** otorgan puntos positivos.  
Los demás colores restan, así que hay que equilibrar bien el riesgo y la estrategia durante la partida.

Esta versión del juego fue desarrollada en **C++** y se ejecuta completamente por consola.  
Incluye todas las funciones principales: creación del mazo, barajado, robos, turnos, cálculo de puntajes y determinación del ganador.

---

## Características
- Interfaz completamente **interactiva en consola**.  
- Implementación **orientada a objetos**: clases separadas para cada componente del juego.  
- **Barajado aleatorio** con generador `mt19937` para mayor realismo.  
- **Validación de entradas** para evitar errores del usuario.  
- **Cálculo automático de puntuaciones** al finalizar la partida.  
- Administración correcta de **memoria dinámica**.

---

## Estructura del proyecto
Coloretto/
├── Carta.h → Define la clase Carta (representa una carta con color)
├── Carta.cpp → Implementación de la clase Carta
├── Fila.h → Clase que representa una fila de cartas en la mesa
├── Fila.cpp → Maneja la lógica de agregar y tomar cartas en una fila
├── Mazo.h → Crea, mezcla y administra las cartas del mazo
├── Mazo.cpp → Implementación del mazo y sus métodos
├── Jugador.h → Define los atributos y acciones de un jugador
├── Jugador.cpp → Implementa el sistema de puntuación y turnos del jugador
├── Juego.h → Control general del flujo del juego
├── Juego.cpp → Implementación de rondas, turnos y cálculo del ganador

## Compilación y ejecución

### Requisitos:
- Compilador compatible con **C++11 o superior** (`g++`, `clang++`, MinGW o Visual Studio).  

### Compilación:
En la terminal, dentro de la carpeta del proyecto:
```bash
g++ *.cpp -o coloretto


## Fujo básico del juego:
┌───────────────┐
│   Inicia juego│
└──────┬────────┘
       │
       ▼
┌───────────────┐
│ Jugador roba  │
│ o toma fila   │
└──────┬────────┘
       │
       ▼
┌───────────────┐
│ Fila llena?   │───Sí──▶ Jugador siguiente
└──────┬────────┘
       │ No
       ▼
┌───────────────┐
│ Mazo vacío?   │───Sí──▶ Fin del juego
└──────┬────────┘
       │ No
       ▼
    Repite turno

