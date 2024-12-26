#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int h, w;
    scanf("%d %d", &h, &w);
    int** a;
    a = (int **)calloc(h, sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        a[i] = (int *)calloc(w, sizeof(int));
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int **b;
    b = (int **)calloc(h, sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        b[i] = (int *)calloc(w, sizeof(int));
    }

    int *columnSum;
    int *rowSum;
    columnSum = (int *)calloc(w, sizeof(int));
    rowSum = (int *)calloc(h, sizeof(int));

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            columnSum[i] += a[j][i];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            rowSum[i] += a[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            b[i][j] = rowSum[i] + columnSum[j] - a[i][j];
            printf("%d", b[i][j]);
            if (j != w - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
