import math

a1 = 2
b1 = 1
a2 = 2
b2 = -2

sign1 = '+'
sign2 = '-'

summa = str(a1 + a2) + str(b1 + b2) + '*i'
if (b1 + b2) < 0:
    summa = str(a1 + a2) + str(b1 + b2) + '*i'
else:
    summa = str(a1 + a2) + sign1 + str(b1 + b2) + '*i'

diff = str(a1 - a2) + str(b1 - b2) + '*i'
if (b1 - b2) < 0:
    diff = str(a1 - a2) + str(b1 - b2) + '*i'
else:
    diff = str(a1 - a2) + sign1 + str(b1 - b2) + '*i'

mult = str((a1 * a2) - (b1 * b2)) + str((a1 * b2) + (a2 * b1)) + '*i'

div = str(((a1 * a2) + (b1 * b2)) / ((a2**2) + (b2**2))) + '+' + str(((b1 * a2) - (a1 * b2)) / ((a2**2) + (b2**2))) + '*i'

#=======================================================================

a3 = -1
b3 = 2

r = round(((a3**2 + b3**2)**(1/2)), 2) 
y = round((math.atan(2/(-1))), 2)

stepen = str(round((r**4),2)) + '*' + '(' + str(round((math.cos(y)),2)) + str(round((math.sin(y)),2)) + '*i' + ')'
koren = str(round((r**(1/3)),2))+'*'+'('+str(round((math.cos((y+2*math.pi)/3)),2))+'+'+str(round((math.sin((y+2*math.pi)/3)),2))+'*i)'

#=======================================================================

print('Ответ: \n Операции с комплексными числами z1=2+i и z2=2-2i: \n Сумма: {0} \n Разность: {1} \n Произведение: {2} \n Частное: {3} \n Теперь  комплексное число z3=-1+2i: \n Четвертая степень: {4} \n Корень третьей степени: {5}'.format(summa, diff, mult, div, stepen, koren))
