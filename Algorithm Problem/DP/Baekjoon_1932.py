
n = int(input())

dp = [[0 for _ in range(i)] for i in range(1, n+1)]
numList = []

for _ in range(n):
    nums = list(map(int, input().split()))
    numList.append(nums)

for i in range(n):
    for j in range(i+1):
        x = max(0, i-1)
        y = max(0, j-1)
        z = min(x, j)

        dp[i][j] = numList[i][j] + max(dp[x][y], dp[x][z])

print(max(dp[n-1]))