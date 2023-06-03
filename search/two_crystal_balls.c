#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int two_crystal_balls(bool breaks[], int size);

int main() {
    bool breaks[] = {false, false, false, true, false, true, false, false, false};
    int size = sizeof(breaks) / sizeof(breaks[0]);

    int result = two_crystal_balls(breaks, size);

    if (result != -1) {
        printf("The first breaking point is at index %d\n", result);
    } else {
        printf("No breaking point found.\n");
    }

    return 0;
}

int two_crystal_balls(bool breaks[], int size) {
    const double square_root = sqrt(size);
    const int jmp_amount = (int)floor(square_root);

    int i = jmp_amount;
    for (; i < size; i += jmp_amount) {
        if (breaks[i]) { break; }
    }

    i -= jmp_amount;

    for (int j = 0; j <= jmp_amount && i < size; j++, i++) {
        if (breaks[i]) { return i; }
    }

    return -1;
}
