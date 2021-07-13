class fibo:
	a = []
	def fibonacci(self,number):
		if number == self.a[0]:
			return 0
		if number == self.a[1]:
			return 1
		while (len(self.a) <= number):
			self.a.append(self.a[len(self.a) - 2] + self.a[len(self.a) - 1])
		return self.a[number]
		
if __name__ == '__main__': 
	fib = fibo()
	number = int(input("Input: "))
	fib.a = [0,1,1]
	print (fib.fibonacci(number))