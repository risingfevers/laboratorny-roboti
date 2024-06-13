#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления интерполяционного многочлена Лагранжа
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Данные
    std::vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    std::vector<double> y;

    for (double xi : x) {
        y.push_back(sin(xi));
    }

    // Точка для интерполяции
    double xi = 0.25 * M_PI;
    double yi = sin(xi);

    // Интерполяция
    double yi_interp = lagrangeInterpolation(x, y, xi);

    // Вычисление погрешности
    double error = fabs(yi - yi_interp);

    std::cout << "Значение интерполяции в точке x = " << xi << ": " << yi_interp << std::endl;
    std::cout << "Погрешность интерполяции: " << error << std::endl;

    return 0;
}
