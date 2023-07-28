class BankAccount:

    def __init__(self, AccNum, AccBalnc, AccHoldr):
        self.AccNum = AccNum
        self.AccBalnc = AccBalnc
        self.AccHoldr = AccHoldr

    def Deposit(self, value):
        self.AccBalnc = self.AccBalnc + value

    def Withdrawal(self, value):
        self.AccBalnc = self.AccBalnc - value

    def showingAccBalnc(self):
        return self.AccBalnc


data = input().split()
obj = BankAccount(int(data[0]), int(data[1]), data[2])
while True:
    flag = input().split()
    if flag[0] == "exit":
        break
    elif flag[0] == '1':
        obj.Deposit(int(flag[1]))
    elif flag[0] == '2':
        if obj.showingAccBalnc() < int(flag[1]):
            print('Insufficient balance')
        else:
            obj.Withdrawal(int(flag[1]))
            print(
            f'{int(flag[1])} has been withdrawn from your account')
    elif flag[0] == '3':
        print(obj.showingAccBalnc())