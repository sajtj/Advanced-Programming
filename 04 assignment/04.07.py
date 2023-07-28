print(*sorted([it for i , it in enumerate(list(map(int , input().split()))) if it % 6 == 0 and i % 6 == 5 ]), sep='\n')
