#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// ��������� ��� �������� ��������� �����
struct Point {
    double x, y;
};

// ������� ��� �������� �������������� ����� ���������
bool isPointOnHyperbola(double a, double b, const Point& point) {
    double x = point.x;
    double y = point.y;
    return (x * x) / (a * a) - (y * y) / (b * b) == 1;
}

// ������� ��� ��������� ���������� ����� � ��������� [min, max]
double randomDouble(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // ��������� ���������
    double a = randomDouble(1.0, 10.0); // ����� �������������� �������
    double b = randomDouble(1.0, 10.0); // ����� ������ �������

    // ��������� �����
    Point point = {randomDouble(-20.0, 20.0), randomDouble(-20.0, 20.0)};

    std::cout << "��������� ���������: (x^2 / " << a << "^2) - (y^2 / " << b << "^2) = 1" << std::endl;
    std::cout << "��������� �����: (" << point.x << ", " << point.y << ")" << std::endl;

    // �������� �������������� ����� ���������
    bool onHyperbola = isPointOnHyperbola(a, b, point);
    std::cout << "����������� �� ����� ���������? " << (onHyperbola ? "Yes" : "No") << std::endl;

    // ���������� ������� ���������
    double c = sqrt(a * a + b * b);
    std::cout << "����� ���������: (" << c << ", 0) and (" << -c << ", 0)" << std::endl;

    // ����� �������������� � ������ ��������
    std::cout << "����� �������������� �������: " << a << std::endl;
    std::cout << "����� ������ �������: " << b << std::endl;

    // �������������� ���������
    double eccentricity = c / a;
    std::cout << "�������������� ���������: " << eccentricity << std::endl;

    // ���������� ����� ������������ ���������
    double distanceBetweenDirectrices = 2 * a / sqrt(a * a + b * b);
    std::cout << "���������� ����� ������������ ���������: " << distanceBetweenDirectrices << std::endl;

    return 0;
}
