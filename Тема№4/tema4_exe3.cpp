#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printSolution(const vector<double>& x) {
    for (double xi : x) {
        cout << xi << " ";
    }
    cout << endl;
}

vector<double> seidel(const vector<vector<double>>& A, const vector<double>& b, double tol, int max_iterations) {
    int n = A.size();
    vector<double> x(n, 0.0);
    for (int k = 0; k < max_iterations; ++k) {
        vector<double> x_new = x;
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += A[i][j] * x_new[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }
        double norm = 0.0;
        for (int i = 0; i < n; ++i) {
            norm += pow(x_new[i] - x[i], 2);
        }
        if (sqrt(norm) < tol) {
            return x_new;
        }
        x = x_new;
    }
    return x;
}

int main() {
    vector<vector<double>> A = {
        {-23, -7, 5, 2},
        {-7, -11, 9, 3},
        {9, 5, -31, -8},
        {0, 1, -2, 10}
    };
    vector<double> b = {-26, -55, -58, -24};
    double tol = 0.01;
    int max_iterations = 1000;

    vector<double> x = seidel(A, b, tol, max_iterations);

    cout << "Решение системы методом Зейделя: ";
    printSolution(x);

    return 0;
}
