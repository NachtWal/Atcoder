#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int* x;
    int *y;
    int *t;

    scanf("%d", &n);
    x = (int *)malloc(sizeof(int) * (n + 1));
    y = (int *)malloc(sizeof(int) * (n + 1));
    t = (int *)malloc(sizeof(int) * (n + 1));
    x[0] = 0;
    y[0] = 0;
    t[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d %d %d", &t[i], &x[i], &y[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int dt = t[i + 1] - t[i];
        int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        if (dt < dist || dt % 2 != dist % 2)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}
