#define HASHTABLE_IMPLEMENTATION
#ifdef HASHTABLE_IMPLEMENTATION
#include <stdlib.h>

typedef struct NodeH {
    char *value;
    int key;
    struct NodeH *next;
} NodeH;

typedef struct {
    struct NodeH **bucket;
    size_t size;
} HashMap;

void seed_random_number();
int hashing(int value, int size);
HashMap *create_hash_map(size_t initial);
void hash_insert(HashMap *map, int key, const char *value);
void hash_print(HashMap *map);
void destroy_hash_map(HashMap *map);

#endif
