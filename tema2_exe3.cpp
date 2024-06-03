#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Структура для хранения координат точки
struct Point {
    double x, y;
};

// Функция для проверки принадлежности точки гиперболе
bool isPointOnHyperbola(double a, double b, const Point& point) {
    double x = point.x;
    double y = point.y;
    return (x * x) / (a * a) - (y * y) / (b * b) == 1;
}

// Функция для генерации случайного числа в диапазоне [min, max]
double randomDouble(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Параметры гиперболы
    double a = randomDouble(1.0, 10.0); // Длина действительной полуоси
    double b = randomDouble(1.0, 10.0); // Длина мнимой полуоси

    // Случайная точка
    Point point = {randomDouble(-20.0, 20.0), randomDouble(-20.0, 20.0)};

    std::cout << "Уравнение гиперболы: (x^2 / " << a << "^2) - (y^2 / " << b << "^2) = 1" << std::endl;
    std::cout << "Случайная точка: (" << point.x << ", " << point.y << ")" << std::endl;

    // Проверка принадлежности точки гиперболе
    bool onHyperbola = isPointOnHyperbola(a, b, point);
    std::cout << "Принадлежит ли точка параболле? " << (onHyperbola ? "Yes" : "No") << std::endl;

    // Координаты фокусов гиперболы
    double c = sqrt(a * a + b * b);
    std::cout << "Фокус гиперболы: (" << c << ", 0) and (" << -c << ", 0)" << std::endl;

    // Длины действительной и мнимой полуосей
    std::cout << "Длина действительной полуоси: " << a << std::endl;
    std::cout << "Длина мнимой полуоси: " << b << std::endl;

    // Эксцентриситет гиперболы
    double eccentricity = c / a;
    std::cout << "Эксцентриситет гиперболы: " << eccentricity << std::endl;

    // Расстояние между директрисами гиперболы
    double distanceBetweenDirectrices = 2 * a / sqrt(a * a + b * b);
    std::cout << "Расстояние между директрисами гиперболы: " << distanceBetweenDirectrices << std::endl;

    return 0;
}
