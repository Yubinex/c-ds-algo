#include <stdio.h>
#include <stdbool.h>

bool linear_search(int haystack[], int size, int needle);

int main() {
    int real_haystack[] = { 9, 8, 4, 2, 6, 3, 7, 1, 5 };
    int size = sizeof(real_haystack) / sizeof(real_haystack[0]);
    printf("%s", linear_search(real_haystack, size, 2) ? "true" : "false");
    return 0;
}

bool linear_search(int haystack[], int size, int needle) {
    for (int i = 0; i < size; i++) {
        if (haystack[i] == needle) { return true; }
    }
    return false;
}
