#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

double func(vector<double> x) {
    return pow(x[0], 2) + exp(pow(x[0], 2) + pow(x[1], 2)) + 4 * x[0] + 3 * x[1];
}

vector<double> gradient(function<double(vector<double>)> func, vector<double> x, double h = 1e-5) {
    vector<double> grad(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        vector<double> x_h = x;
        x_h[i] += h;
        grad[i] = (func(x_h) - func(x)) / h;
    }
    return grad;
}

vector<double> gradient_descent(function<double(vector<double>)> func, vector<double> x0, double learning_rate = 0.01, int max_iter = 1000, double tol = 1e-6) {
    vector<double> x = x0;
    for (int iter = 0; iter < max_iter; ++iter) {
        vector<double> x_old = x;
        vector<double> grad = gradient(func, x);
        for (size_t i = 0; i < x.size(); ++i) {
            x[i] -= learning_rate * grad[i];
        }
        double norm = 0;
        for (size_t i = 0; i < x.size(); ++i) {
            norm += pow(x[i] - x_old[i], 2);
        }
        if (sqrt(norm) < tol) {
            break;
        }
    }
    return x;
}

int main() {
    vector<double> x0 = {1.0, 1.0};
    vector<double> opt_x = gradient_descent(func, x0);
    
    cout << "Найденный минимум: (" << opt_x[0] << ", " << opt_x[1] << ")" << endl;
    cout << "Значение функции в найденной точке: " << func(opt_x) << endl;

    return 0;
}
