#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const float C_INF = 2000000000.0;
    int n;
    cin >> n;

    cout.precision(2);

    int tower[n];
    float gradient[n][n];

    for (int i = 0; i < n; i++)
    {
        cin >> tower[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            gradient[i][j] = (float)(tower[j]-tower[i]) / (float)(j-i);
        }
    }

    
    int maxNum = 0;
    int towerNum;
    float slopeFront, slopeBack;

    for (int i = 0; i < n; i++)
    {
        towerNum = 0;
        slopeBack = C_INF;
        slopeFront = -C_INF;

        for (int j = i-1; j >= 0; j--)
        {
            float grad = gradient[j][i];
            if ((grad < slopeBack))
            {
                slopeBack = gradient[j][i];
                towerNum++;
            }
        }

        for (int j = i+1; j < n; j++)
        {
            float grad = gradient[i][j];
            if (gradient[i][j] > slopeFront)
            {
                slopeFront = gradient[i][j];
                towerNum++;
            }
        }
        
        maxNum = max(maxNum, towerNum);
    }

    cout << maxNum;
    
    return 0;
}