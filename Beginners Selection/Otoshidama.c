#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum;
    scanf("%d %d", &n, &sum);

    int x, y;
    for ( x = 0; x < n + 1; x++)
    {
        for (y = 0; y < n + 1; y++)
        {
            if (10000 * x + 5000 * y + 1000 * (n - x - y) == sum && n - x - y >= 0)
            {
                printf("%d %d %d", x, y, n - x - y);
                return 0;
            }
            
        }
    }
    printf("-1 -1 -1");
}
