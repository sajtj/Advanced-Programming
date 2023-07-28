n , m = map(int , input().split())
index = 0
num = m
max = 9
x = 0
numstr = ""
for i in range(n):
    if num >= max :
        num = num - max
        numstr = numstr + str(max)
    elif index == 0 :
        numstr = numstr + str(num)
        index += 1
    elif len(numstr) != n and index == 1:
        numstr = numstr + '0'
for i in numstr :
    x = x + int(i)        
if x == m and m != 0 and n != 0 : 
    print(int(numstr) , end =" ")
    for i in range(10**(n-1) , 10**(n)) :
        numstr = str(i)
        sumnum = 0
        for j in numstr :
            sumnum = sumnum + int(j)
        if sumnum == m :
            print(int(i))
            break
else :
    print(-1 , -1)
   
