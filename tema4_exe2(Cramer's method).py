import numpy as np

# Матрица коэффициентов
A = np.array([
    [2, 0, 2],
    [5, -2, 5],
    [2, 2, 5]
])

# Вектор правых частей
b = np.array([-1, 2, 0])

# Функция для вычисления определителя
def determinant(matrix):
    return np.linalg.det(matrix)

# Вычисление решения системы методом Крамера
def cramer(A, b):
    n = len(b)
    det_A = determinant(A)
    if det_A == 0:
        raise ValueError("Система не имеет единственного решения")
    
    x = np.zeros(n)
    for i in range(n):
        Ai = A.copy()
        Ai[:, i] = b
        x[i] = determinant(Ai) / det_A
    
    return x

x_cramer = cramer(A, b)

print(f"Решение системы методом Крамера: {x_cramer}")
