#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[5000], str2[5000];
    cin >> str1 >> str2;

    int lcs = 0;
    int stack = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int x1, x2, y;

    for (int i = 0; i < len1+len2-1; i++)
    {
        stack = 0;
        x1 = max(0, i - len2 + 1);
        x2 = max(0, len2 - i - 1);

        while (x1 < len1 && x2 < len2)
        {
            if (str1[x1] == str2[x2])
            {
                stack++;
                lcs = max(lcs, stack);
            }
            else
            {
                stack = 0;
            }

            x1++;
            x2++;
        }
    }

    cout << lcs;

    return 0;
}