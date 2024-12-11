#include <iostream>

using namespace std;

int main()
{
    int d, k;
    cin >> d >> k;

    int fib[30] = {0, };

    fib[1] = 1;
    fib[2] = 1;

    for(int i = 3; i < d; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    int a = 1;
    int b = 1;
    
    while(fib[d-1]*b < k)
    {
        if((k - fib[d-1]*b) % fib[d-2] == 0)
        {
            if (b >= (k - fib[d-1]*b) / fib[d-2])
            {
                a = (k - fib[d-1]*b) / fib[d-2];
                break;
            }
        }

        b++;
    }

    cout << a << endl << b << endl;

    return 0;
}