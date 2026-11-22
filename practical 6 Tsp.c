#include <stdio.h>
int a[10][10], n, best, found;

void tsp(int city, int count, int cost, int mask) {
    int i, total;

    if(count == n) {
        if(a[city][0] > 0) {
            total = cost + a[city][0];
            if(!found || total < best) {
                best = total;
                found = 1;
            }
        }
        return;
    }

    for(i = 1; i < n; i++) {
        if(!(mask & (1 << i)) && a[city][i] > 0)
            tsp(i, count + 1, cost + a[city][i],
                mask | (1 << i));
    }
}

int main() {
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    tsp(0, 1, 0, 1);

    if(found)
        printf("Minimum cost = %d\n", best);
    else
        printf("No tour possible\n");

    return 0;
}
