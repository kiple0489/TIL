
def game(x, y):
    if x < 0 or y < 0:
        return 0
    
    if x < b[0] and y < b[0]:
        return 1
    
    if dp[x][y] >= 0:
        return (dp[x][y]+1) % 2

    wins = []

    for i in b:
        wins.append(game(x-i, y))
        wins.append(game(x, y-i))

    dp[x][y] = max(wins)

    return (dp[x][y]+1) % 2

b = list(map(int, input().split()))

for _ in range(5):
    k = list(map(int, input().split()))

    dp = [[-1 for _ in range(k[1]+1)] for _ in range(k[0]+1)]

    winner = game(k[0], k[1])

    if winner == 0:
        print("A")
    else:
        print("B")
