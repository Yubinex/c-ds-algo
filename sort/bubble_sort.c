#include <stdio.h>

void bubble_sort(int arr[], int size);

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, size);

    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                const int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
