#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int d[20], c[20][100];
    int n, amount, i, j;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coins: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    for(j = 0; j <= amount; j++)
        c[0][j] = 999;

    c[0][0] = 0;

    for(i = 1; i <= n; i++)
    {
        c[i][0] = 0;

        for(j = 1; j <= amount; j++)
        {
            if(d[i] > j)
                c[i][j] = c[i-1][j];
            else
                c[i][j] = min(c[i-1][j],
                              1 + c[i][j-d[i]]);
        }
    }

    printf("Minimum coins = %d", c[n][amount]);

    return 0;
}
