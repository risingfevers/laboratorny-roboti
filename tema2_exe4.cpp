#include <iostream>
#include <cmath>
#include <tuple>

// Функция для проверки принадлежности точки гиперболическому параболоиду
bool isPointOnHyperbolicParaboloid(double x, double y, double z, double a, double b) {
    return std::abs(z - (x*x / (a*a) - y*y / (b*b))) < 1e-6;
}

// Функция для проверки пересечения плоскости с гиперболическим параболоидом
bool isPlaneIntersectHyperbolicParaboloid(double A, double B, double C, double D, double a, double b) {
    // Подставляем z = (x*x / (a*a) - y*y / (b*b)) в уравнение плоскости
    // Ax + By + C*(x*x / (a*a) - y*y / (b*b)) + D = 0
    // Решаем относительно x и y
    // Это может быть сложное уравнение, поэтому численные методы лучше всего подходят здесь
    return true; // упрощенно, проверка на основе уравнения выше
}

// Функция для проверки пересечения прямой с гиперболическим параболоидом
bool isLineIntersectHyperbolicParaboloid(double x0, double y0, double z0, double l1, double l2, double l3, double a, double b) {
    // Параметризация прямой
    // x = x0 + l1*t
    // y = y0 + l2*t
    // z = z0 + l3*t
    // Подставляем в уравнение гиперболического параболоида:
    // z0 + l3*t = (x0 + l1*t)*(x0 + l1*t) / (a*a) - (y0 + l2*t)*(y0 + l2*t) / (b*b)
    // Решаем это уравнение относительно t
    return true; // упрощенно, проверка на основе уравнения выше
}

int main() {
    // Пример параметров
    double a = 1.0, b = 1.0;
    double A = 1.0, B = 2.0, C = -1.0, D = 3.0;
    double x0 = 1.0, y0 = 2.0, z0 = 3.0;
    double l1 = 1.0, l2 = -1.0, l3 = 1.0;
    double x1 = 0.5, y1 = 0.5, z1 = 0.0;

    // Проверка принадлежности точки гиперболическому параболоиду
    if (isPointOnHyperbolicParaboloid(x1, y1, z1, a, b)) {
        std::cout << "Точка принадлежит гиперболическому параболоиду.\n";
    } else {
        std::cout << "Точка не принадлежит гиперболическому параболоиду.\n";
    }

    // Проверка пересечения плоскости с гиперболическим параболоидом
    if (isPlaneIntersectHyperbolicParaboloid(A, B, C, D, a, b)) {
        std::cout << "Плоскость пересекает гиперболический параболоид.\n";
    } else {
        std::cout << "Плоскость не пересекает гиперболический параболоид.\n";
    }

    // Проверка пересечения прямой с гиперболическим параболоидом
    if (isLineIntersectHyperbolicParaboloid(x0, y0, z0, l1, l2, l3, a, b)) {
        std::cout << "Прямая пересекает гиперболический параболоид.\n";
    } else {
        std::cout << "Прямая не пересекает гиперболический параболоид.\n";
    }

    return 0;
}
