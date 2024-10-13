#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    int a, b;

    while(1)
    {
        cin >> n1 >> n2;

        if (n1 < 1 or n2 < 1)
        {
            break;
        }

        if (n1 < n2)
        {
            a = n2;
            b = n1;
        }
        else
        {
            a = n1;
            b = n2;
        }

        int turn = 1;
        bool gameEnd = false;

        while (a > 0 && b > 0)
        {
            int quot = a/b;

            if (quot > 1)
            {
                if (turn%2)
                {
                    cout << "A wins" << endl;
                }
                else
                {
                    cout << "B wins" << endl;
                }

                gameEnd = true;
                break;
            }

            int temp = b;
            b = a%b;
            a = temp;
            turn++;
        }

        if (gameEnd == false)
        {
            if (turn%2)
            {
                cout << "B wins" << endl;
            }
            else
            {
                cout << "A wins" << endl;
            }
        }

    } 
}