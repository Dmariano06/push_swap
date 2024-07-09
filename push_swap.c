typedef struct s_stack {
    int *array;
    int top;
} t_stack;

void push(t_stack *stack, int value) {
    stack->array[++stack->top] = value;
}

int pop(t_stack *stack) {
    return stack->array[stack->top--];
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0;
    int L[n1], R[n2];
    int j = 0;

   while (i < n1)
        L[i] = a[l + i];
        i++;
    while( j < n2)
        R[j] = a[m + 1 + j];
        j++;

    int i = 0;
     int j = 0;
      int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) {
        a[k++] = L[i++];
    }

    while (j < n2) {
        a[k++] = R[j++];
    }
}

void mergeSort(t_stack *a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a->array, l, m, r);
    }
}

void push_swap_merge(t_stack *a) {
    mergeSort(a, 0, a->top);
}