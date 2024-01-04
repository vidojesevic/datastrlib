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

LinkedList *create_single_linked_list(void);
int linked_list_size(LinkedList *list);
bool is_empty_list(LinkedList *list);
void linked_list_append(LinkedList *list, int value);
void linked_list_prepend(LinkedList *list, int value);
void linked_list_insert(LinkedList *list, int value, int position);
void destroy_linked_list(LinkedList *list);
void linked_list_print(LinkedList *list);

#endif
