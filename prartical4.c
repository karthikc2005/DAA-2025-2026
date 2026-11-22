#include <stdio.h>

int main()
{
    int n, amount, i, j;
    int d[10], c[10][100];

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coin values: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    // Step 1
    for(i = 0; i <= n; i++)
        c[i][0] = 0;

    // Step 2, 3 and 4
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= amount; j++)
        {
            if(i == 1)
                c[i][j] = 1 + c[i][j-d[i]];

            else if(j < d[i])
                c[i][j] = c[i-1][j];

            else
            {
                c[i][j] = c[i-1][j];

                if(1 + c[i][j-d[i]] < c[i][j])
                    c[i][j] = 1 + c[i][j-d[i]];
            }
        }
    }

    printf("Minimum coins = %d", c[n][amount]);

    return 0;
}
