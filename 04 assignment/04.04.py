qnumber = int(input())
answer = input()
answershitnumber = int(input())
answershit = list()
t = j = 0
for i in range(0, answershitnumber*qnumber):
    x = input()
    answershit.append(x)   
def checkanswer(strans , correctans) :
    if strans == "OOOO" :
        return 0    
    elif correctans == 'A' and strans == "#OOO" :
        return 3
    elif correctans == 'B' and strans == "O#OO" :
        return 3
    elif correctans == 'C' and strans == "OO#O" :
        return 3
    elif correctans == 'D' and strans == "OOO#" :
        return 3       
    else :
        return -1              
for r in range(0 , answershitnumber) :
    wholescore = 0
    j = 0
    for i in range(t, qnumber + t):
        str = answershit[i]
        score = checkanswer(str , answer[j])
        wholescore = wholescore + score
        j += 1 
    t = t + qnumber
    print(wholescore)