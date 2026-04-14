#include <iostream>

double valorExtra = 20.0;

double cuadrado(double x)  { return x * x; }
double triple(double x)    { return x * 3.0; }
double doble(double x)     { return x * 2.0; }
double sumaExtra(double x) { return x + valorExtra; }
double sumaTres(double x)  { return x + 3.0; }

double suma(double acumulador, double valor)     { return acumulador + valor; }
double producto(double acumulador, double valor) { return acumulador * valor; }
double maximo(double acumulador, double valor) {
    if (valor > acumulador) return valor;
    else                    return acumulador;
}

double aplicarCadena(double entrada, double (*cadena[])(double), int cantidadTransformaciones) {
    double resultadoParcial = entrada;
    for (int indice = 0; indice < cantidadTransformaciones; indice++) {
        resultadoParcial = cadena[indice](resultadoParcial);
    }
    return resultadoParcial;
}

double reducirConCadena(
    double* arreglo,
    int tamano,
    double (*cadena[])(double),
    int cantidadTransformaciones,
    double (*acumular)(double, double)
) {
    double resultadoFinal = aplicarCadena(*(arreglo + 0), cadena, cantidadTransformaciones);
    for (int indice = 1; indice < tamano; indice++) {
        double valorTransformado = aplicarCadena(*(arreglo + indice), cadena, cantidadTransformaciones);
        resultadoFinal = acumular(resultadoFinal, valorTransformado);
    }
    return resultadoFinal;
}

void imprimirArreglo(double* arreglo, int tamano) {
    std::cout << "[ ";
    for (int indice = 0; indice < tamano; indice++) {
        std::cout << *(arreglo + indice);
        if (indice < tamano - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

void imprimirMenuTransformaciones() {
    std::cout << "  1. Cuadrado  (x -> x^2)" << std::endl;
    std::cout << "  2. Triple    (x -> x*3)" << std::endl;
    std::cout << "  3. Doble     (x -> x*2)" << std::endl;
    std::cout << "  4. Suma " << valorExtra << "  (x -> x+" << valorExtra << ")" << std::endl;
    std::cout << "  5. Suma 3    (x -> x+3)" << std::endl;
    std::cout << "  0. Terminar cadena" << std::endl;
}

int main() {
    std::cout << "- EJERCICIO 4: Transformaciones encadenadas -" << std::endl;

    int cantidadElementos;
    std::cout << "Cuantos elementos? ";
    std::cin >> cantidadElementos;

    double* arreglo = new double[cantidadElementos];

    std::cout << "Ingresa los " << cantidadElementos << " valores:" << std::endl;
    for (int indice = 0; indice < cantidadElementos; indice++) {
        std::cout << "Elemento [" << indice << "]: ";
        std::cin >> *(arreglo + indice);
    }

    std::cout << "\nArreglo original: ";
    imprimirArreglo(arreglo, cantidadElementos);

    const int MAX_TRANSFORMACIONES = 10;
    double (*cadenaTransformaciones[MAX_TRANSFORMACIONES])(double);
    int cantidadTransformaciones = 0;

    std::cout << "\n- Elige las transformaciones en orden (0 para terminar) -" << std::endl;

    int opcionTransformacion = -1;
    while (opcionTransformacion != 0 && cantidadTransformaciones < MAX_TRANSFORMACIONES) {
        imprimirMenuTransformaciones();
        std::cout << "Transformacion " << (cantidadTransformaciones + 1) << ": ";
        std::cin >> opcionTransformacion;

        if      (opcionTransformacion == 1) cadenaTransformaciones[cantidadTransformaciones++] = cuadrado;
        else if (opcionTransformacion == 2) cadenaTransformaciones[cantidadTransformaciones++] = triple;
        else if (opcionTransformacion == 3) cadenaTransformaciones[cantidadTransformaciones++] = doble;
        else if (opcionTransformacion == 4) cadenaTransformaciones[cantidadTransformaciones++] = sumaExtra;
        else if (opcionTransformacion == 5) cadenaTransformaciones[cantidadTransformaciones++] = sumaTres;
        else if (opcionTransformacion != 0) std::cout << "Opcion invalida, intenta de nuevo." << std::endl;
    }

    if (cantidadTransformaciones == 0) {
        std::cout << "No elegiste ninguna transformacion." << std::endl;
        delete[] arreglo;
        return 0;
    }

    std::cout << "\n- Elige el acumulador -" << std::endl;
    std::cout << "  1. Suma total" << std::endl;
    std::cout << "  2. Producto total" << std::endl;
    std::cout << "  3. Maximo" << std::endl;
    std::cout << "Acumulador: ";
    int opcionAcumulador;
    std::cin >> opcionAcumulador;

    double (*funcionAcumuladora)(double, double) = nullptr;

    if      (opcionAcumulador == 1) funcionAcumuladora = suma;
    else if (opcionAcumulador == 2) funcionAcumuladora = producto;
    else                            funcionAcumuladora = maximo;

    double resultadoFinal = reducirConCadena(arreglo, cantidadElementos, cadenaTransformaciones, cantidadTransformaciones, funcionAcumuladora);

    std::cout << "\nResultado: " << resultadoFinal << std::endl;

    delete[] arreglo;
    return 0;
}
