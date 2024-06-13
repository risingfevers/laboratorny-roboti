import numpy as np
from scipy.integrate import quad

# Определение подынтегральной функции
def integrand(x):
    return x**4 / (17 + x**2)

# Численное интегрирование
result, error = quad(integrand, 1, 2)

print(f"Численное значение определенного интеграла: {result:.6f}")
