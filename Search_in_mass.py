from array import *
x = int(input('Введите число которое хотели бы найти: '))
my_array = array('i', [1,32,525,363,142,2,313,8,543]) #Условимся что интовые значения
for i in my_array:
	if i == x:
		print('Индекс числа = ' + str(my_array.index(x)))
		break