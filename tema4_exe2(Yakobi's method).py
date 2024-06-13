import numpy as np

def jacobi(A, b, x0, tol, max_iterations):
    n = len(A)
    x = x0.copy()
    for k in range(max_iterations):
        x_new = np.zeros_like(x)
        for i in range(n):
            s1 = sum(A[i][j] * x[j] for j in range(n) if j != i)
            x_new[i] = (b[i] - s1) / A[i][i]
        if np.linalg.norm(x_new - x, ord=np.inf) < tol:
            return x_new
        x = x_new
    return x

# Исходные данные
A = np.array([
    [2, 2, 3],
    [5, -2, 5],
    [2, 2, 5]
], dtype=float)

b = np.array([-1, 2, 0], dtype=float)

# Начальное приближение
x0 = np.zeros(len(b))

# Решение системы уравнений методом Якоби
tol = 1e-6
max_iterations = 1000
x_jacobi = jacobi(A, b, x0, tol, max_iterations)

print(f"Решение системы методом Якоби: {x_jacobi}")
