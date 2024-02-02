class py_sol:
	def pow(self,num,i,res):
		for j in range(i):
			res=res*num
		return res
num=int(input("Enter number: "))
n=int(input("Enter power: "))
print(py_sol().pow(num,n,1))


