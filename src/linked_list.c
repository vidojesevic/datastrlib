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
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->head = newNode;
    }
    list->size++;
}

void linked_list_insert(LinkedList *list, int value, int position) {
    if (position < 0 || position > linked_list_size(list)) {
        printf("Position cannot be less that 0 or greater that list size!\n");
        return;
    } else {
        NodeSL *newNode = malloc(sizeof(NodeSL));
        newNode->value = value;
        newNode->next = NULL;

        if (position == 0) {
            newNode->next = list->head;
            list->head = newNode;
        } else if (position == linked_list_size(list)) {
            list->tail->next = newNode;
            list->tail = newNode;
        } else {
            NodeSL *current = list->head;

            for (int i = 0; i <= position; ++i) {
                if (i == position - 1) {
                    newNode->next = current->next;
                    current->next = newNode;
                }
                current = current->next;
            }
        }

    }
    list->size++;
}

void linked_list_print(LinkedList *list) {
    if (is_empty_list(list)) {
        printf("Cannot print empty list!\n");
    } else {
        NodeSL *current = list->head;
        while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void linked_list_reverse(LinkedList *list) {
    if (is_empty_list(list)) {
        printf("List is empty!\n");
        return;
    }
    NodeSL *current = list->head;
    NodeSL *prev = NULL;
    NodeSL *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    list->head = prev;
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
