
#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5, x = 30;
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == x) {
            printf("Found at index %d", mid);
            return 0;
        }
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not Found");
    return 0;
}
