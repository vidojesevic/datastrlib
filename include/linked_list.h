#define LINKED_LIST_IMPLEMENTATION
#ifdef LINKED_LIST_IMPLEMENTATION

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// single linked list
typedef struct NodeSL {
    int value;
    struct NodeSL *next;
} NodeSL;

typedef struct {
    int size;
    NodeSL *head;
    NodeSL *tail;
} LinkedList;

// Create and Destroy
LinkedList *create_single_linked_list(void);
void destroy_linked_list(LinkedList *list);

int linked_list_size(LinkedList *list);
bool is_empty_list(LinkedList *list);

// Insertion
void linked_list_append(LinkedList *list, int value);
void linked_list_prepend(LinkedList *list, int value);
void linked_list_insert(LinkedList *list, int value, int position);

// Reverse List
void linked_list_reverse(LinkedList *list);

// Remove node
void linked_list_remove_by_value(LinkedList *list, int value);
void linked_list_remove_by_index(LinkedList *list, int index);

// Searching
int linked_list_search_by_value(LinkedList *list, int value);
int linked_list_search_by_index(LinkedList *list, int index);

// Printing
void linked_list_print(LinkedList *list);

#endif
