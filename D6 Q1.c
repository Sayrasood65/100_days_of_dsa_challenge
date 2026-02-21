//Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print first element
    printf("%d ", arr[0]);

    // Print only when element is different from previous
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
