def create_subset(i, n, sol, res, cur):
    if i == n:
        res.append(cur.copy())
        return res
    create_subset(i + 1, n, sol, res, cur)
    cur.append(sol[i])
    create_subset(i + 1, n, sol, res, cur)
    cur.pop()
    return res

sol = []
res = []
n = int(input("Enter the number of elements: "))
for i in range(n):
    sol.append(int(input("Enter element {}: ".format(i + 1))))

create_subset(0, n, sol, res, [])
print(res)
