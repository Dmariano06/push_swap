#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int content;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

typedef struct s_push_swap {
    t_stack *a;
    t_stack *b;
} t_push_swap;

t_stack *ft_new_stack(int content) {
    t_stack *new_element = (t_stack *)malloc(sizeof(t_stack));
    if (!new_element)
        return NULL;
    new_element->content = content;
    new_element->prev = NULL;
    new_element->next = NULL;
    return new_element;
}
void push(t_stack **src, t_stack **dest) {
    if (*src == NULL)
        return;
    t_stack *temp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    temp->next = *dest;
    if (*dest)
        (*dest)->prev = temp;
    *dest = temp;
}

void swap(t_stack *stack) {
    if (stack == NULL || stack->next == NULL)
        return;
    int temp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = temp;
}

void rotate(t_stack **stack) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_stack *temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    t_stack *last = *stack;
    while (last->next)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
}

void change(t_stack **stack) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_stack *last = *stack;
    while (last->next)
        last = last->next;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}
int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }

    t_push_swap pushswap;
    pushswap.a = NULL;
    pushswap.b = NULL;
    int i = 1;

    while(i < argc) {
        int res = ft_atoi(argv[i]);
        t_stack *new_elem = ft_new_stack(res);
        if (!new_elem) {
            write(stderr, "Error\n", 6);
            return 1;
        }
        new_elem->next = pushswap.a;
        if (pushswap.a)
            pushswap.a->prev = new_elem;
        pushswap.a = new_elem;
        i++;
    }

    sort(&pushswap);

    while (pushswap.a) {
        t_stack *temp = pushswap.a;
        pushswap.a = pushswap.a->next;
        free(temp);
    }
    while (pushswap.b) {
        t_stack *temp = pushswap.b;
        pushswap.b = pushswap.b->next;
        free(temp);
    }

    return 0;
}