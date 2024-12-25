#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
int main()
{
    char S[100000] = {0x00};
    scanf("%s", S);

    const char a[] = "maerd";
    const char b[] = "remaerd";
    const char c[] = "esare";
    const char d[] = "resare";

    int index = 0;
    const int n = strlen(S);
    char tmp;
    for (int i = 0; i < n / 2; i++)
    {
        tmp = S[i];
        S[i] = S[n - 1 - i];
        S[n - 1 - i] = tmp;
    }

    while (true)
    {
        
        if (strncmp(&S[index], b, 7) == 0)
        {
            index += 7;
        }
        else if (strncmp(&S[index], d, 6) == 0)
        {
            index += 6;
        }
        else if (strncmp(&S[index], a, 5) == 0 || strncmp(&S[index], c, 5) == 0)
        {
            index += 5;
        }
        else 
        {
            printf("NO");
            return 0;
        }
        if (S[index] == 0)
        {
            printf("YES");
            return 0;
        }
    }
}
