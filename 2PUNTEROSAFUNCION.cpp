#include <iostream>

double cuadrado(double x) {
    return x * x;
}

double doble(double x) {
    return x * 2.0;
}

double inverso(double x) {
    if (x == 0.0) {
        std::cout << "Advertencia: inverso de 0 indefinido. Se devuelve 0." << std::endl;
        return 0.0;
    }
    return 1.0 / x;
}

void aplicarFuncion(double* arreglo, int n, double (*transformar)(double)) {
    for (int i = 0; i < n; i++) {
        *(arreglo + i) = transformar(*(arreglo + i));
    }
}

void imprimirArreglo(double* arreglo, int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << *(arreglo + i);
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

int main() {
    std::cout << "- EJERCICIO 2: Punteros a funcion -" << std::endl;

    int n;
    std::cout << "Cuantos elementos tendra el arreglo? ";
    std::cin >> n;

    double* arreglo = new double[n];

    std::cout << "Ingresa los " << n << " valores:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento [" << i << "]: ";
        std::cin >> *(arreglo + i);
    }

    std::cout << "\nArreglo original: ";
    imprimirArreglo(arreglo, n);

    std::cout << "\nQue funcion deseas aplicar?" << std::endl;
    std::cout << "  1. Cuadrado  (x -> x*x)" << std::endl;
    std::cout << "  2. Doble     (x -> x*2)" << std::endl;
    std::cout << "  3. Inverso   (x -> 1/x)" << std::endl;
    std::cout << "Opcion: ";

    int opcion;
    std::cin >> opcion;

    double (*pf)(double) = nullptr;

    if (opcion == 1) {
        pf = cuadrado;
        std::cout << "Funcion elegida: cuadrado" << std::endl;
    } else if (opcion == 2) {
        pf = doble;
        std::cout << "Funcion elegida: doble" << std::endl;
    } else if (opcion == 3) {
        pf = inverso;
        std::cout << "Funcion elegida: inverso" << std::endl;
    } else {
        std::cout << "Opcion invalida." << std::endl;
        delete[] arreglo;
        return 1;
    }

    aplicarFuncion(arreglo, n, pf);

    std::cout << "Arreglo transformado: ";
    imprimirArreglo(arreglo, n);

    delete[] arreglo;

    return 0;
}
