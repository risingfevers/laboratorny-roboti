import numpy as np

def func(x):
    return np.exp(x[0]**2 + x[1]**2) + np.log(4 + x[1]**2 + 2*x[0]**2)

def coordinate_descent(func, x0, learning_rate=0.01, max_iter=1000, tol=1e-6):
    x = np.array(x0)
    for _ in range(max_iter):
        x_old = np.copy(x)
        for i in range(len(x)):
            x[i] -= learning_rate * derivative(func, x, i)
        if np.linalg.norm(x - x_old) < tol:
            break
    return x

def derivative(func, x, i, h=1e-5):
    x_h = np.copy(x)
    x_h[i] += h
    return (func(x_h) - func(x)) / h

# Начальная точка
x0 = [1.0, 1.0]

# Применение метода покоординатного спуска
opt_x = coordinate_descent(func, x0)

print("Найденный минимум:", opt_x)
print("Значение функции в найденной точке:", func(opt_x))
