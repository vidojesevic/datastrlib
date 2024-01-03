#include "../include/linked_list.h"

LinkedList *create_single_linked_list(void) {
    LinkedList *linked_list = malloc(sizeof(LinkedList));
    if (linked_list == NULL) {
        printf("Malloc fails while allocating memory for list!");
        return NULL;
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

int linked_list_size(LinkedList *list) {
    return list->size;
}

bool is_empty_list(LinkedList *list) {
    return list->size == 0 ? true : false;
}

void linked_list_append(LinkedList *list, int value) {
    NodeSL *newNode = malloc(sizeof(NodeSL));
    newNode->next = NULL;
    newNode->value = value;

    if (is_empty_list(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void linked_list_prepend(LinkedList *list, int value) {
    NodeSL *newNode = malloc(sizeof(NodeSL));
    newNode->next = list->head;
    newNode->value = value;

    if (is_empty_list(list)) {
        linked_list_append(list, value);
    } else {
        list->head = newNode;
    }
    list->size++;
}

void linked_list_print(LinkedList *list) {
    if (is_empty_list(list)) {
        printf("Cannot print empty list!\n");
    } else {
        NodeSL *current = list->head;
        printf("Linked List:\n");
        while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void destroy_linked_list(LinkedList *list) {
    NodeSL *current = list->head;
    while (current != NULL) {
        NodeSL *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
