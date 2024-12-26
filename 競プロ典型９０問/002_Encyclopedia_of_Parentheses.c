#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(const char* s)
{
    int score = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            ++score;
        }
        else
        {
            --score;
        }

        if (score < 0)
        {
            return false;
        }
    }
    return (score == 0);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    char* s;
    s = (char *)malloc(sizeof(char) * (n + 1));

    for (int bit = 0; bit < (1 << n); bit++)
    {
        memset(s, 0x00, n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            if (!(bit & (1<<i)))
            {
                s[n - i - 1] = '(';
            }
            else
            {
                s[n - i - 1] = ')';
            }
        }
        if(isValid(s))
        {
            printf("%s\n", s);
        }
    }
}
