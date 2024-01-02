#define STACKS_IMPLEMENTATION
#ifdef STACKS_IMPLEMENTATION

#include <stdbool.h>
#include <stdlib.h>

typedef struct NodeS {
    int value;
    struct Node *next;
} NodeS;

typedef struct {
    int size;
    Node *head;
    Node *tail;
} Stack;

Stack *create_stack(void);
int stack_size(Stack *stack);
bool is_empty_stack(Stack *stack);
int stack_peek(Stack *stack, bool *status);
void stack_push(Stack *stack, int value);
void stack_print(Stack *stack);
int stack_pop(Stack *stack, bool *status);
void destroy_stack(Stack *stack);

#endif
