
#include <stdio.h>

int main()
{
    int n, i, j, k;
    int cost[10][10], visited[10] = {0};
    int min, total = 0, start = 0, city;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[start] = 1;
    city = start;

    printf("\nPath: %d", city + 1);

    for(k = 1; k < n; k++)
    {
        min = 9999;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && cost[city][j] < min)
            {
                min = cost[city][j];
                start = j;
            }
        }

        total = total + min;
        visited[start] = 1;
        city = start;

        printf(" -> %d", city + 1);
    }

    total = total + cost[city][0];

    printf(" -> 1");
    printf("\nMinimum cost: %d\n", total);

    return 0;
}
