x = int(input())
data = list()
deteil = list()
for i in range(0, x) :
    str = input()
    deteil = str.split()
    if len(deteil) == 5 :
        deteil[0] = deteil[0] + " " + deteil[1]
        deteil.remove(deteil[1])
    deteil[1] = int(deteil[1])
    deteil[2] = int(deteil[2])
    data.append(deteil)
result = dict()
for i in data :
    if i[1] < 100 and i[2] < 50 and i[3] == "YES":
        if i[0] in result :
            result[i[0]] += 1
        else :
            result[i[0]] = 1
result = sorted(result.items() , key=lambda x:x[1] , reverse=True)
result = dict(result)
print(result) 