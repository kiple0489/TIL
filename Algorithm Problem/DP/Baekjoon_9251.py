
a = input()
b = input()

dp = [[0 for _ in range(len(b)+1)] for _ in range(len(a)+1)]

for i in range(len(a)):

    for j in range(len(b)):

        match = 0

        if a[i] == b[j]:
            match += 1
        
        dp[i+1][j+1] = min(i+1, j+1, max(dp[i][j]+match, dp[i][j+1], dp[i+1][j]))

print(dp[len(a)][len(b)])

