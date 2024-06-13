import numpy as np
from scipy.integrate import quad

# Определение подынтегральной функции
def integrand(x):
    return np.exp(-2*x) * np.sin(17*x)

# Численное интегрирование
result, error = quad(integrand, 0, np.inf)

print(f"Численное значение неопределенного интеграла: {result:.6f}")
