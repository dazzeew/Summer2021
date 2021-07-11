import itertools

class max:
	bl = list()
	weight_bag = 0

	def algo(self,list_items,x):
		summ_weight = 0
		summ_price = 0	
		bag_items = list()
		optimal_pr = 0
		optimal_bg = 0
		optimal_name = list()
		for i in range(2**x):
			for j in range(x): 
				if self.bl[i][j] == '1':
					summ_price += list_items.get(j)[2]
					summ_weight += list_items.get(j)[1]
					bag_items.append(list_items.get(j)[0])
			if summ_weight <= self.weight_bag and optimal_pr <= summ_price and summ_price != 0:
				optimal_pr = summ_price
				optimal_bg = summ_weight
				optimal_name = bag_items
			summ_weight = 0
			summ_price = 0
			bag_items = list()
		print ('Цена вещей: ' + str(optimal_pr) + '\nВес вещей: ' + str(optimal_bg) + '\nВещи:')
		for i in optimal_name:
			print (i)

def binary(n):
		a = list()
		for i in itertools.product('01', repeat=n):
			a.append(i)
		return a


	
	

def inputs(x):
	for i in range(x):
		list_items[i] = [input('Введите название продукта: '),int(input('Введите вес продукта: ')),int(input('Введите цену продукта: '))]
	return list_items




if __name__ == '__main__':
	maximum = max()
	maximum.weight_bag = int(input('Введите вместимость рюкзака: '))
	list_items = dict()
	x = int(input('Введите количество вещей: '))
	list_items = inputs(x)
	maximum.bl = binary(x)
	maximum.algo(list_items,x)
	# print (maximum.bl[0][0])
	# for i in maximum.bl[::-1]:
	# 	print (i)



