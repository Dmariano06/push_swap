
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }
    int size = argc - 1;
    int *a = malloc(size * sizeof(int));
    if (a == NULL) {
        perror("Malloc failed");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    push_swap(a, size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }

    free(a);
    return 0;
}

void push_swap(int *a, int size) {
    if (size <= 5) {
        insertion_sort(a, size);
    } else {
        selection_sort(a, size);
    }
}

void insertion_sort(int *a, int size) {
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

void selection_sort(int *a, int size) {
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

void sa(int *a, int size) {
    if (size >= 2) {
        int temp = a[0];
        a[0] = a[1];
        a[1] = temp;
    }
}

void sb(int *b, int size) {
    if (size >= 2) {
        int temp = b[0];
        b[0] = b[1];
        b[1] = temp;
    }
}

void ss(int *a, int *b, int size_a, int size_b) {
    sa(a, size_a);
    sb(b, size_b);
}

void pa(int *a, int *b, int *top_a, int *top_b) {
    if (*top_b >= 0) {
        (*top_a)++;
        a[*top_a] = b[*top_b];
        (*top_b)--;
    }
}

void pb(int *a, int *b, int *top_a, int *top_b) {
    if (*top_a >= 0) {
        (*top_b)++;
        b[*top_b] = a[*top_a];
        (*top_a)--;
    }
}

void ra(int *a, int size) {
    if (size > 1) {
        int first = a[0];
        int i = 0;
        while (i < size - 1) {
            a[i] = a[i + 1];
            i++;
        }
        a[size - 1] = first;
    }
}

void rb(int *b, int size) {
    if (size > 1) {
        int first = b[0];
        int i = 0;
        while (i < size - 1) {
            b[i] = b[i + 1];
            i++;
        }
        b[size - 1] = first;
    }
}

void rr(int *a, int *b, int size_a, int size_b) {
    ra(a, size_a);
    rb(b, size_b);
}

void rra(int *a, int size) {
    if (size > 1) {
        int last = a[size - 1];
        int i = size - 1;
        while (i > 0) {
            a[i] = a[i - 1];
            i--;
        }
        a[0] = last;
    }
}

void rrb(int *b, int size) {
    if (size > 1) {
        int last = b[size - 1];
        int i = size - 1;
        while (i > 0) {
            b[i] = b[i - 1];
            i--;
        }
        b[0] = last;
    }
}

void rrr(int *a, int *b, int size_a, int size_b) {
    rra(a, size_a);
    rrb(b, size_b);
}