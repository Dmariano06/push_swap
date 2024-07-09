typedef struct s_stack {
    int content;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

typedef struct s_push_swap {
    t_stack *a;
    t_stack *b;
} t_push_swap;