#include <stdio.h>
#include <stdbool.h>

bool bs_list(int haystack[], int size, int needle);

int main() {
    int real_haystack[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(real_haystack) / sizeof(real_haystack[0]);
    printf("%s", bs_list(real_haystack, size, 7) ? "true" : "false");
    return 0;
}

bool bs_list(int haystack[], int size, int needle) {
    // IMPORTANT!! lo is INCLUSIVE, hi is EXCLUSIVE
    int lo = 0;
    int hi = size;
    
    while(lo < hi) {
        const int m = lo + (hi - lo) / 2;
        const int v = haystack[m];

        if (v == needle) { return true; }
        else if (v > needle) { hi = m; }
        else { lo = m + 1; }
    }

    return false;
}
