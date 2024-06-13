import numpy as np

def gauss_elimination(A, b):
    n = len(b)
    # Прямой ход
    for i in range(n):
        # Поиск ведущего элемента
        max_el = abs(A[i][i])
        max_row = i
        for k in range(i+1, n):
            if abs(A[k][i]) > max_el:
                max_el = abs(A[k][i])
                max_row = k
        
        # Swap максимальной строки с текущей строкой
        A[[i, max_row]] = A[[max_row, i]]
        b[[i, max_row]] = b[[max_row, i]]
        
        # Приведение матрицы к верхнетреугольному виду
        for k in range(i+1, n):
            c = -A[k][i] / A[i][i]
            A[k, i:] += c * A[i, i:]
            b[k] += c * b[i]
    
    # Обратный ход
    x = np.zeros(n)
    for i in range(n-1, -1, -1):
        x[i] = b[i] / A[i][i]
        for k in range(i-1, -1, -1):
            b[k] -= A[k][i] * x[i]
    
    return x

# Исходные данные
A = np.array([
    [9, -5, -6, 3],
    [1, -7, 1, 0],
    [3, -4, 9, 0],
    [6, -1, 9, 8]
], dtype=float)

b = np.array([-8, 38, 47, -8], dtype=float)

# Копируем матрицу и вектор, чтобы не менять их при использовании матричного метода
A_copy = A.copy()
b_copy = b.copy()

# Решение методом Гаусса
x_gauss = gauss_elimination(A_copy, b_copy)

print(f"Решение системы методом Гаусса: {x_gauss}")
