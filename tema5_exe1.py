import numpy as np

# Данные
x = np.array([-1.0, 0.0, 1.0, 2.0, 3.0])
y = np.array([-0.5, 0.0, 0.5, 0.86603, 1.0])

def finite_difference(x, y):
    n = len(x)
    dy = np.zeros((n, n))
    dy[:, 0] = y

    for j in range(1, n):
        for i in range(n - j):
            dy[i, j] = (dy[i + 1, j - 1] - dy[i, j - 1]) / (x[i + j] - x[i])
    
    return dy

def first_derivative(dy, x, x0):
    n = len(x)
    result = 0
    for i in range(1, n):
        term = dy[0, i]
        for j in range(i):
            term *= (x0 - x[j])
        result += term
    return result

def second_derivative(dy, x, x0):
    n = len(x)
    result = 0
    for i in range(2, n):
        term = dy[0, i]
        for j in range(i):
            term *= (x0 - x[j])
        result += term
    return result

dy = finite_difference(x, y)
x0 = 1.0
first_deriv = first_derivative(dy, x, x0)
second_deriv = second_derivative(dy, x, x0)

print(f"Первая производная в точке x = {x0}: {first_deriv}")
print(f"Вторая производная в точке x = {x0}: {second_deriv}")
