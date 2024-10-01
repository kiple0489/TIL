#include <iostream>

using namespace std;

int main()
{
    int mod = 10007;
    int n;
    cin >> n;

    int dp[1001][10] = {0,};

    for (int j = 0; j < 10; j++)
    {
        dp[0][j] = j+1;
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][9];

        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = mod + dp[i][j-1] + dp[i][0] - dp[i-1][j-1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n-1][9] % mod;
    
    return 0;
}