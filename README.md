# Puntos taller de punteros

**Taller:** Taller de punteros
**Estudiante:** Paula Noguera - Julian Rojas
**Lenguaje:** C++  
**Tipo:** Aplicación de consola

## Descripción

Cuatro programas que tienen por función principal la variable especial "Puntero":

## Matriz dinámica + operaciones por punteros
1. El programa que crea una matriz dinámica de tamaño n x m
2. Llena la matriz con valores ingresados por el usuario
3. Implementa funciones para:
• Calcula la suma de cada fila
• Encuentra el mayor elemento de toda la matriz
• Crea una nueva matriz transpuesta

## Funciones como parámetros (punteros a función)
1. Declara un arreglo dinámico de un double
2. Crea una función que:
• Recibe el arreglo
• Recibe un puntero a función
• Aplica esa función a cada elemento del arreglo
3. Implementa 3 funciones:
•  Cuadrado (x * x)
•  Doble (x * 2)
•  Inverso (1/x)
4. El usuario elige qué función aplicar

## Lambdas + composición de operaciones
1. Se declara un arreglo dinámico de double
2. Se definen dos lambdas:
• Uno que transforme un valor
• Otro que combine dos valores (tipo acumulador)
3. Se crea una función que:
• Reciba el arreglo
• Reciba ambas lambdas
• Retorne un resultado final (ej: suma transformada)

## BONUS

Se modifica el ejercicio 3 para:
• Permitir múltiples transformaciones encadenadas
• Ejemplo: (x → x*2) → (x → x+3) → (x → x²)
