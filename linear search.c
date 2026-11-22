o#include <stdio.h>

int main() {
    int a[] = {100, 200, 300, 400, 500};
    int n = 5, x = 30, i;

    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("Found at index %d", i);
            return 0;
        }
    }

    printf("Not Found");
    return 0;
}
