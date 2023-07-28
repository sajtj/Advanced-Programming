import math
n, m = map(int, input().split())
pnum = []

def isprime(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

for i in range(n, m + 1):
    if isprime(i):
        pnum.append(i)
        
h = 0
check = False
for i in range(0, len(pnum)):
    snum = str(pnum[h])
    if pnum[h] > 100:
        t = 1
        check = False
        for j in range(0, len(snum) - 1):
            s = snum[j] + snum[t]
            n = int(s)
            t = t + 1
            if isprime(n) == False:
                pnum.remove(pnum[h])
                check = True
                break
        if check == False:
            h = h + 1
    else:
        h = h + 1

for i in pnum:
    print(i)
