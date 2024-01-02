#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/stacks.h"

Stack *create_stack(void) {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;

    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;

    return stack;
}

int stack_size(Stack *stack) {
    return stack->size;
}

bool is_empty_stack(Stack *stack) {
    return stack->size == 0 ? true : false;
}

int stack_peek(Stack *stack, bool *status) {
    if (is_empty_stack(stack)) {
        *status = false;
        return -1;
    }

    *status = true;
    return stack->tail->value;
}

void stack_push(Stack *stack, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) perror("Unsuccessfull malloc for new node!\n");
    newNode->value = value;
    newNode->next = NULL;

    if (is_empty_stack(stack)) {
        stack->head = newNode;
        stack->tail = newNode;
    } else {
        stack->tail->next = newNode;
        stack->tail = newNode;
    }
    stack->size++;
}

int stack_pop(Stack *stack, bool *status) {
    if (is_empty_stack(stack)) {
        *status = false;
        return -1;
    }

    *status = true;

    Node *oldNode = stack->tail;
    int value = oldNode->value;

    if (stack->size == 1) {
        stack->head = NULL;
        stack->tail = NULL;
    } else {
        Node *newTail = stack->head;
        while (newTail->next != oldNode) {
            newTail = newTail->next;
        }

        stack->tail = newTail;
        stack->tail->next = NULL;
    }

    stack->size--;
    free(oldNode);

    return value;
}

void destroy_stack(Stack *stack) {
    Node *currentNode = stack->head;
    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(stack);
}

void stack_print(Stack *stack) {
    if (is_empty_stack(stack)) {
        printf("Print stack: Stack is empty\n");
    } else {
        Node *currentNode = stack->head;
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("NULL | Stack size: %d\n", stack->size);
        free(currentNode);
    }
}
