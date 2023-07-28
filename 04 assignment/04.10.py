import math
vx , vy , y0 , h = map(float , input().split())
# h = -5t^2 + vy t + y0
delta = vy**(2) - 4*-5*(y0 - h)
if delta < 0 or vx < 0:
    print("impossible")
else :
    t1 = (-vy + math.sqrt(vy**(2) - 4*-5*(y0 - h))) / -10
    t2 = (-vy - math.sqrt(vy**(2) - 4*-5*(y0 - h))) / -10
    if t1 > 0 and t2 < 0 :
        result = "{:.2f}".format(t1 * vx)
        print(result)
    elif t2 > 0 and t1 < 0 :
        result = "{:.2f}".format(t2 * vx)
        print(result)
    elif t1 == t2 :
        result = "{:.2f}".format(t1 * vx)
        print(result)
    elif t2 > t1 and t1 > 0 and t2 > 0:
        result = "{:.2f}".format(t1 * vx)
        print(result)
        result = "{:.2f}".format(t2 * vx)
        print(result)
    elif t1 > t2 and t1 > 0 and t2 > 0:
        result = "{:.2f}".format(t2 * vx)
        print(result)
        result = "{:.2f}".format(t1 * vx)
        print(result)