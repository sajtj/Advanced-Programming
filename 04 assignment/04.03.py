str = input()
zero = 0
one = 0
s = ""
sz = ""
so = ""
ls = []
for i in range(0 , len(str)) :
    s = ""
    if int(str[i]) == 0 :
        zero = zero + 1
        sz = sz + str[i]
    elif int(str[i]) == 1 :
        one = one + 1
        so = so + str[i]
    if zero == one :
        s = sz + so
        sz = ""
        so = ""
        zero = 0
        one = 0
        ls.append(s)
sumstr = ""
for i in ls :
    sumstr = sumstr + i
if str == sumstr :
    print('True')
else :
    print('False')