#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/hashmap.h"

char *strdup(const char *s); // needs for compiler

HashMap *create_hash_map(size_t initial) {
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));
    if (map == NULL) {
        printf("Malloc fails when allocating memory for hash amp!\n");
        free(map);
        return NULL;
    }

    map->bucket = (struct NodeH**)malloc(sizeof(struct NodeH*) * initial);
    if (map->bucket == NULL) {
        printf("Malloc fails when allocating memory for bucket!\n");
        return NULL;
    }

    memset(map->bucket, 0, sizeof(struct NodeH*) * initial);

    map->size = initial;

    return map;
}


void hash_insert(HashMap *map, int key, const char *value) {
    size_t index = key % map->size;

    NodeH *newNode = (NodeH*)malloc(sizeof(NodeH));
    if (newNode == NULL) {
        printf("Malloc fails on alocating newNode!\n");
        return;
    }

    newNode->key = key;
    newNode->value = strdup(value); // makes copy of string
    newNode->next = NULL;

    if (map->bucket[index] == NULL) {
        map->bucket[index] = newNode;
    } else {
        newNode->next = map->bucket[index];
        map->bucket[index] = newNode;
    }
}

void destroy_hash_map(HashMap *map) {
    for (size_t i = 0; i < map->size; ++i) {
        NodeH *current = map->bucket[i];
        while (current != NULL) {
            NodeH *temp = current->next;
            free(current->value);
            free(current);
            current = temp;
        }
    }
    free(map->bucket);
    free(map);
}

void hash_print(HashMap *map) {
    if (map == NULL || map->bucket == NULL) {
        printf("Invalid hash map!\n");
        return;
    }

    printf("Hash Map content:\n");
    for (size_t i = 0; i < map->size; ++i) {
        NodeH *current = map->bucket[i];
        while (current != NULL) {
            printf("[%zu] Key: %d, Value: %s\n", i, current->key, current->value);
            current = current->next;
        }
    }
    printf("End of Hash Map!\n");
}
