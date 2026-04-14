#include <iostream>

double valorExtra = 20.0;

double cuadrado(double x)   { return x * x; }
double triple(double x)     { return x * 3.0; }
double sumaExtra(double x)  { return x + valorExtra; }

double suma(double acum, double x)     { return acum + x; }
double producto(double acum, double x) { return acum * x; }
double maximo(double acum, double x)   { return (x > acum) ? x : acum; }

double reducirConFunciones(
    double* arreglo,
    int n,
    double (*transformar)(double),
    double (*acumular)(double, double)
) {
    double resultado = transformar(*(arreglo + 0));
    for (int i = 1; i < n; i++) {
        double valorTransformado = transformar(*(arreglo + i));
        resultado = acumular(resultado, valorTransformado);
    }
    return resultado;
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
    std::cout << "- EJERCICIO 3: Lambdas y composicion -" << std::endl;

    int n;
    std::cout << "Cuantos elementos? ";
    std::cin >> n;

    double* arreglo = new double[n];

    std::cout << "Ingresa los " << n << " valores:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento [" << i << "]: ";
        std::cin >> *(arreglo + i);
    }

    std::cout << "\nArreglo: ";
    imprimirArreglo(arreglo, n);

    std::cout << "\n- Elige la transformacion -" << std::endl;
    std::cout << "  1. Cuadrado (x -> x^2)" << std::endl;
    std::cout << "  2. Triple   (x -> x*3)" << std::endl;
    std::cout << "  3. Suma " << valorExtra << " (x -> x+" << valorExtra << ")" << std::endl;
    std::cout << "Transformacion: ";
    int opT;
    std::cin >> opT;

    std::cout << "\n- Elige el acumulador -" << std::endl;
    std::cout << "  1. Suma total" << std::endl;
    std::cout << "  2. Producto total" << std::endl;
    std::cout << "  3. Maximo" << std::endl;
    std::cout << "Acumulador: ";
    int opA;
    std::cin >> opA;

    double (*transformSelec)(double)    = nullptr;
    double (*acumSelec)(double, double) = nullptr;

    if      (opT == 1) transformSelec = cuadrado;
    else if (opT == 2) transformSelec = triple;
    else               transformSelec = sumaExtra;

    if      (opA == 1) acumSelec = suma;
    else if (opA == 2) acumSelec = producto;
    else               acumSelec = maximo;

    double resultado = reducirConFunciones(arreglo, n, transformSelec, acumSelec);

    std::cout << "\nResultado: " << resultado << std::endl;

    delete[] arreglo;
    return 0;
}
