#include <iostream>

void calcularSumaFilas(int** mat, int filas, int colum) {
    std::cout << "\n- Suma de cada fila -" << std::endl;
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < colum; j++) {
            suma += *(*(mat + i) + j);
        }
        std::cout << "Suma fila " << i << ": " << suma << std::endl;
    }
}

int encontrarMayor(int** mat, int filas, int colum) {
    int mayor = **mat;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colum; j++) {
            if (*(*(mat + i) + j) > mayor) {
                mayor = *(*(mat + i) + j);
            }
        }
    }
    return mayor;
}

int** transponerMatriz(int** mat, int filas, int colum) {
    int** transpuesta = new int*[colum];
    for (int i = 0; i < colum; i++) {
        transpuesta[i] = new int[filas];
    }
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colum; j++) {
            *(*(transpuesta + j) + i) = *(*(mat + i) + j);
        }
    }
    return transpuesta;
}

void imprimirMatriz(int** mat, int filas, int colum) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colum; j++) {
            std::cout << *(*(mat + i) + j);
            if (j < colum - 1) std::cout << "\t";
        }
        std::cout << std::endl;
    }
}

void liberarMatriz(int** mat, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] *(mat + i);
    }
    delete[] mat;
}

int main() {
    int n, m;

    std::cout << "- EJERCICIO 1: Matriz dinamica -" << std::endl;
    std::cout << "Ingresa el numero de filas (n): ";
    std::cin >> n;
    std::cout << "Ingresa el numero de columnas (m): ";
    std::cin >> m;

    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[m];
    }

    std::cout << "\nIngresa los " << n * m << " elementos de la matriz:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> *(*(matriz + i) + j);
        }
    }

    std::cout << "\n--- Matriz original (" << n << "x" << m << ") ---" << std::endl;
    imprimirMatriz(matriz, n, m);

    calcularSumaFilas(matriz, n, m);

    int mayor = encontrarMayor(matriz, n, m);
    std::cout << "\nMayor elemento: " << mayor << " ---" << std::endl;

    int** transpuesta = transponerMatriz(matriz, n, m);
    std::cout << "\nMatriz transpuesta (" << m << "x" << n << ") ---" << std::endl;
    imprimirMatriz(transpuesta, m, n);

    liberarMatriz(matriz, n);
    liberarMatriz(transpuesta, m);

    return 0;
}
