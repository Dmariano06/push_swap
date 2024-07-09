int main() {
    t_stack a;
    a.top = -1;
    a.array = malloc(5 * sizeof(int));
    
    push(&a, 3);
    push(&a, 1);
    push(&a, 4);
    push(&a, 2);
    push(&a, 5);

    push_swap_merge_sort(&a);
    int i = 0;

    while(i <= a.top) {
        printf("%d ", a.array[i]);
        i++;
    }

    return 0;
}