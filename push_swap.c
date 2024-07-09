
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf(stderr, "%s", argv[0]);
        return 1;
    }
    int size = argc - 1;
    int *a = malloc(size * sizeof(int));
    if (a == NULL) {
        return 0;
    }
    int i = 0;
    while ( i < size) {
        a[i] = atoi(argv[i + 1]);
        i++;
    }
    push_swap(a, size);
    i = 0;
    while (i < size) {
        printf("%d\n", a[i]);
        i++;
    }
    return 0;
}

void push_swap(int *a, int size) {
    if (size <= 5) {
        first_sort(a, size);
    } else {
        second_sort(a, size);
    }
}

void first_sort(int *a, int size) {
    int i = 1;
    while (i < size) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            sa(a + j, 2);
            j--;
        }
        i++;
    }
}

void second_sort(int *a, int size) {
    int b[size];
    int top1 = size - 1;
    int top2 = -1;

    int i = 0;
    while (i < size) {
        int min = 0;
        int j = 1;
        while (j < size - i) {
            if (a[j] < a[min]) {
                min = j;
            }
            j++;
        }

        int min_pos = min;
        while (min_pos > 0) {
            if (min_pos <= (size - i) / 2) {
                ra(a, size - i);
            } else {
                rra(a, size - i);
            }
            min_pos--;
        }

        pb(a, b, &top1, &top2);
        i++;
    }

    while (top2 >= 0) {
        pa(a, b, &top1, &top2);
    }
}