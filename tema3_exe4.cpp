#include <iostream>
#include <cmath>

double sumFunctionalSeries(double x, double epsilon) {
    double sum = 0.0;
    double term;
    int k = 1;
    
    do {
        term = pow(-1, k) / (sin(k * x) + 17 + k * k);
        sum += term;
        k++;
    } while (std::abs(term) > epsilon);
    
    return sum;
}

int main() {
    double x = 1.0;  // Пример значения x
    double epsilon = 1e-6;
    double result = sumFunctionalSeries(x, epsilon);
    std::cout << "Численное значение суммы функционального ряда: " << result << std::endl;
    return 0;
}
