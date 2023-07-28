import collections
x = int(input())
data = collections.defaultdict(dict)
for i in range(x) :
    titel = input()
    data[titel]['name'] = input()
    data[titel]['age'] = int(input())
    data[titel]['major'] = input()
    
    name = data[titel]['name'] 
    name = name.split()
    newname = ""
    for n in name :
        newname = newname + n.capitalize() + " "
    newname = newname.strip()
    data[titel]['name'] = newname
print(dict(sorted(list(data.items()), key=lambda x: x[1]['major'][1])))