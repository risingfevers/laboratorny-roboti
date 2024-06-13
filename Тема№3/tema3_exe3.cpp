#include <iostream>
#include <cmath>

double sumSeries(double epsilon) {
    double sum = 0.0;
    double term;
    int k = 1;
    
    do {
        term = 17.0 / (2*k - 1) + pow(-1, k-1) / (2 * pow(3, k-1));
        sum += term;
        k++;
    } while (std::abs(term) > epsilon);
    
    return sum;
}

int main() {
    double epsilon = 1e-6;
    double result = sumSeries(epsilon);
    std::cout << "Численное значение суммы ряда: " << result << std::endl;
    return 0;
}
