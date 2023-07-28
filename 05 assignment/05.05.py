x = int(input())
numbers = list(map(int, input().split()))
numbers.sort()
orderednums = list()
flag = False
while len(numbers) != 0 :
    if flag == False :
        orderednums.append(numbers[len(numbers) - 1])
        numbers.remove(numbers[len(numbers) - 1])
        flag = True
    elif flag == True :
        orderednums.append(numbers[0])
        numbers.remove(numbers[0])
        flag = False
for i in orderednums :
    print(i , end= " ")