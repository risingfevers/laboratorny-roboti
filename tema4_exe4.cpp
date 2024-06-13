#include <iostream>
#include <vector>

using namespace std;

vector<double> tridiagonalSolver(const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d) {
    int n = d.size();
    vector<double> p(n), q(n), x(n);

    p[0] = -c[0] / b[0];
    q[0] = d[0] / b[0];

    for (int i = 1; i < n; ++i) {
        double denominator = b[i] + a[i] * p[i - 1];
        p[i] = -c[i] / denominator;
        q[i] = (d[i] - a[i] * q[i - 1]) / denominator;
    }

    x[n - 1] = q[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = p[i] * x[i + 1] + q[i];
    }

    return x;
}

int main() {
    vector<double> a = {0, -4, -1, 6, 4};  // Нижняя диагональ
    vector<double> b = {13, 9, -12, 20, 5}; // Главная диагональ
    vector<double> c = {5, -5, 6, -5, 0};  // Верхняя диагональ
    vector<double> d = {-66, -47, -40, -74, 14}; // Правая часть

    vector<double> x = tridiagonalSolver(a, b, c, d);

    cout << "Решение системы методом прогонки: ";
    for (double xi : x) {
        cout << xi << " ";
    }
    cout << endl;

    return 0;
}
