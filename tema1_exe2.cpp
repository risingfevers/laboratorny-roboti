#include <iostream>
#include <cmath>
#include <functional>

// Ôóíêöèÿ f(x)
double f(double x) {
    return x * exp(x) - x - 1;
}

// Ïðîèçâîäíàÿ f(x)
double df(double x) {
    return (x + 1) * exp(x) - 1;
}

// Ìåòîä äèõîòîìèè
double bisection(double a, double b, double eps) {
    double c;
    while ((b - a) / 2.0 > eps) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

// Ìåòîä õîðä (ñåêóùèõ)
double secant(double a, double b, double eps) {
    double fa = f(a), fb = f(b);
    while (fabs(b - a) > eps) {
        double c = b - fb * (b - a) / (fb - fa);
        a = b;
        fa = fb;
        b = c;
        fb = f(c);
    }
    return b;
}

// Ìåòîä ïðîñòîé èòåðàöèè
double iteration(double x0, double eps) {
    double x1;
    while (true) {
        x1 = log(x0 + 1);
        if (fabs(x1 - x0) < eps)
            break;
        x0 = x1;
    }
    return x1;
}

// Ìåòîä Íüþòîíà
double newton(double x0, double eps) {
    double x1;
    while (true) {
        x1 = x0 - f(x0) / df(x0);
        if (fabs(x1 - x0) < eps)
            break;
        x0 = x1;
    }
    return x1;
}

int main() {
    const double eps = 1e-6;

    // Ãðàíèöû äëÿ ìåòîäà äèõîòîìèè è õîðä
    double a = 0.0, b = 2.0;

    // Íà÷àëüíîå ïðèáëèæåíèå äëÿ ìåòîäà Íüþòîíà è ìåòîäà èòåðàöèé
    double x0 = 1.0;

    // Ìåòîä äèõîòîìèè
    double root_bisection = bisection(a, b, eps);
    std::cout << "Root (Bisection method): " << root_bisection << std::endl;

    // Ìåòîä õîðä (ñåêóùèõ)
    double root_secant = secant(a, b, eps);
    std::cout << "Root (Secant method): " << root_secant << std::endl;

    // Ìåòîä ïðîñòîé èòåðàöèè
    double root_iteration = iteration(x0, eps);
    std::cout << "Root (Iteration method): " << root_iteration << std::endl;

    // Ìåòîä Íüþòîíà
    double root_newton = newton(x0, eps);
    std::cout << "Root (Newton's method): " << root_newton << std::endl;

    return 0;
}
