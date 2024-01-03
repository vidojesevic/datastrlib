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
