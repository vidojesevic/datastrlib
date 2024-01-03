#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/stacks.h"

Test(test_create_stack, basic_test) {
    Stack *stack = create_stack();

    cr_assert_not_null(stack, "Stack creation failed");

    cr_assert_null(stack->head, "Head should be null");
    cr_assert_null(stack->tail, "Tail should be null");
    cr_assert_eq(stack->size, 0, "Size should be 0");

    destroy_stack(stack);
}

Test(test_stack_size, test) {
    Stack *stack = create_stack();

    cr_assert_eq(stack_size(stack), 0, "Size should be 0");

    stack_push(stack, 4);
    stack_push(stack, 7);

    cr_assert_eq(stack_size(stack), 2, "Size should be 0");

    destroy_stack(stack);
}

Test(test_stack_peek, test) {
    Stack *stack = create_stack();
    bool status = false;

    cr_assert_eq(stack_peek(stack, &status), -1, "Stack peek should return -1 (NULL)");

    for (int i = 0; i < 5; ++i) {
        stack_push(stack, i);
        cr_assert_eq(stack_peek(stack, &status), i, "Stack peek should return %d", i);
    }

    destroy_stack(stack);
}

Test(test_stack_push, test) {
    Stack *stack = create_stack();

    stack_push(stack, 2);
    cr_assert_eq(stack_size(stack), 1, "Should be 1");
    stack_push(stack, 6);
    cr_assert_eq(stack_size(stack), 2, "Should be 2");

    destroy_stack(stack);
}

Test(test_stack_pop, test) {
    Stack *stack = create_stack();
    bool status = false;

    cr_assert_eq(stack_pop(stack, &status), -1, "Stack pop should return -1 (NULL)");
    int test_val = 5;
    stack_push(stack, test_val);
    cr_assert_eq(stack_size(stack), 1, "Stack size should be 1");
    cr_assert_eq(stack_pop(stack, &status), test_val, "Stack pop should return last pushed value");
    cr_assert_eq(stack_size(stack), 0, "Stack size should be 0");

    destroy_stack(stack);
}
