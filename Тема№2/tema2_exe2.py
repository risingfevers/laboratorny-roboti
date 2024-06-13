import numpy as np
import math

# Генерация случайных векторов
np.random.seed(42)  # Для воспроизводимости
v1 = np.random.rand(3)
v2 = np.random.rand(3)
v3 = np.random.rand(3)

print(f"Вектор v1: {v1}")
print(f"Вектор v2: {v2}")
print(f"Вектор v3: {v3}")

# Функция для вычисления длины вектора
def vector_length(v):
    return np.linalg.norm(v)

# Вычисление длин векторов
length_v1 = vector_length(v1)
length_v2 = vector_length(v2)
length_v3 = vector_length(v3)

print(f"Длина вектора v1: {length_v1}")
print(f"Длина вектора v2: {length_v2}")
print(f"Длина вектора v3: {length_v3}")

# Функция для вычисления угла между векторами
def angle_between_vectors(v1, v2):
    dot_product = np.dot(v1, v2)
    length_v1 = vector_length(v1)
    length_v2 = vector_length(v2)
    cosine_angle = dot_product / (length_v1 * length_v2)
    angle = np.arccos(np.clip(cosine_angle, -1.0, 1.0))
    return math.degrees(angle)

# Вычисление углов между векторами
angle_v1_v2 = angle_between_vectors(v1, v2)
angle_v1_v3 = angle_between_vectors(v1, v3)
angle_v2_v3 = angle_between_vectors(v2, v3)

print(f"Угол между v1 и v2: {angle_v1_v2:.2f} градусов")
print(f"Угол между v1 и v3: {angle_v1_v3:.2f} градусов")
print(f"Угол между v2 и v3: {angle_v2_v3:.2f} градусов")

# Функция для сложения и вычитания векторов
def vector_addition(v1, v2):
    return v1 + v2

def vector_subtraction(v1, v2):
    return v1 - v2

# Попарные суммы и разности векторов
sum_v1_v2 = vector_addition(v1, v2)
sum_v1_v3 = vector_addition(v1, v3)
sum_v2_v3 = vector_addition(v2, v3)

diff_v1_v2 = vector_subtraction(v1, v2)
diff_v1_v3 = vector_subtraction(v1, v3)
diff_v2_v3 = vector_subtraction(v2, v3)

print(f"Сумма v1 и v2: {sum_v1_v2}")
print(f"Сумма v1 и v3: {sum_v1_v3}")
print(f"Сумма v2 и v3: {sum_v2_v3}")

print(f"Разность v1 и v2: {diff_v1_v2}")
print(f"Разность v1 и v3: {diff_v1_v3}")
print(f"Разность v2 и v3: {diff_v2_v3}")

# Проверка на параллельность векторов
def are_parallel(v1, v2):
    return np.allclose(np.cross(v1, v2), 0)

parallel_v1_v2 = are_parallel(v1, v2)
parallel_v1_v3 = are_parallel(v1, v3)
parallel_v2_v3 = are_parallel(v2, v3)

print(f"Параллельны ли v1 и v2? {'Да' if parallel_v1_v2 else 'Нет'}")
print(f"Параллельны ли v1 и v3? {'Да' if parallel_v1_v3 else 'Нет'}")
print(f"Параллельны ли v2 и v3? {'Да' if parallel_v2_v3 else 'Нет'}")

# Проверка на соосность (лежат ли в одной плоскости)
def are_coplanar(v1, v2, v3):
    volume = np.dot(v1, np.cross(v2, v3))
    return np.isclose(volume, 0)

coplanar = are_coplanar(v1, v2, v3)

print(f"Соосны ли v1, v2 и v3? {'Да' if coplanar else 'Нет'}")
