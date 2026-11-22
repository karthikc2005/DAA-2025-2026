
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, W;
    int w[10], pr[10], p[10][20];
    int i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity: ");
    scanf("%d", &W);

    printf("Enter weights: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &pr[i]);

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                p[i][j] = 0;
            else if(w[i] <= j)
                p[i][j] = max(p[i-1][j],
                              p[i-1][j-w[i]] + pr[i]);
            else
                p[i][j] = p[i-1][j];
        }
    }

    printf("Maximum Profit = %d", p[n][W]);

    return 0;
}
