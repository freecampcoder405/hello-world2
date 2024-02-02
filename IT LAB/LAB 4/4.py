class my_class:
    def get_string(self):
        res=input("Enter a string: ")
        return res

    def print_string(self,str):
        return str.upper()
        
res=my_class().get_string()
print(my_class().print_string(res))
    




