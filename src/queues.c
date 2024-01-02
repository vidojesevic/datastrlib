#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/queues.h"

Queue *create_queue(void) {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Malloc fails when allocating memory for Queue!\n");
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int queue_size(Queue *queue) {
    return queue->size;
}

bool is_empty_queue(Queue *queue) {
    return queue->size == 0 ? true : false;
}

int queue_peek(Queue *queue, bool *status) {
    if (is_empty_queue(queue)) {
        *status = false;
        return -1;
    }

    *status = true;
    return queue->head->value;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (is_empty_queue(queue)) {
        queue->tail = newNode;
        queue->head = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

int dequeue(Queue *queue, bool *status) {
    if (is_empty_queue(queue)) {
        *status = false;
        return -1;
    }

    *status = true;

    Node *oldNode = queue->head;
    int value = oldNode->value;

    if (queue->size == 0) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = oldNode->next;
    }

    free(oldNode);
    queue->size--;

    return value;
}

void destroy_queue(Queue *queue) {
    Node *currentNode = queue->head;
    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(queue);
}

void queue_queue(Queue *queue) {
    if (is_empty_queue(queue)) {
        printf("Queue is empty, Queue size: %d\n", queue->size);
    } else {
        Node *currentNode = queue->head;
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("NULL | Queue size: %d\n", queue->size);
        free(currentNode);
    }
}
