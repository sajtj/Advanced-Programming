import math
x = int(input())
a = math.ceil((x**(5/3)) + math.tan(math.radians(x)))
b = math.floor(math.pi**(2+math.atan(math.sin(math.radians(x))**2)))
print(math.gcd(a , b))