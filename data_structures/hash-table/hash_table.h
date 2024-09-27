#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdlib.h>
typedef struct {
    int key;
    int value;
} Set;

typedef struct {
    int size;
    int count;
    Set *items;
} Hash_Table;


void make_hash_table(Hash_Table* ht, int size);
void free_hash_table(Hash_Table* ht);
static int hash_function(Hash_Table* ht, int key);
static int get_next_hash(Hash_Table* ht, int idx, int key);
int insert(Hash_Table* ht, Set s);
int remove_entry(Hash_Table* ht, int key);

#ifdef HASH_TABLE_IMPLEMENTATION

void make_hash_table(Hash_Table* ht, int size)
{
    ht->size = size;
    ht->count = 0;
    ht->items = malloc(ht->size*sizeof(Set));
    for (int i = 0; i < size; i++)
    {
        ht->items[i].key = 0;
        ht->items[i].value = 0;
    }
}

void free_hash_table(Hash_Table* ht)
{
    free(ht->items);
    ht->items = NULL;
}

static int hash_function(Hash_Table* ht, int key)
{
    return key % ht->size;
}

static int get_next_hash(Hash_Table *ht, int idx, int key)
{
    
    for (size_t i = 1; i <= ht->size; i++) {
        size_t next_idx = (idx+i)%ht->size;
        int ht_key = ht->items[next_idx].key;
        if (ht_key == 0 || ht_key == key) return next_idx;
    }
    return -1;
}

int insert(Hash_Table* ht, Set s)
{
    const int idx = hash_function(ht, s.key);
    if (ht->items[idx].key = 0) {
        ht->items[idx] = s;
        ht->count++;
        return 0;
    }

    if (ht->items[idx].key == s.key) {
        ht->items[idx].value = s.value;
        return 0;
    }
    
    const int next_idx = get_next_hash(ht, idx, s.key);
    if (next_idx == -1) return -1; 
    
    if (ht->items[next_idx].key == 0) {
        ht->items[next_idx] = s;
        ht->count++;
        return 0;
    }
    ht->items[idx].value = s.value;
    return 0;
}

int remove_entry(Hash_Table* ht, int key)
{
    const int idx = hash_function(ht, key);
    if(ht->items[idx].key == key) {
        ht->items[idx].key = 0;
        ht->items[idx].value = 0;
        return 0;
    }
    const int next_idx = get_next_hash(ht, idx, key);
    if (next_idx == -1) return -1;

    ht->items[next_idx].key = 0;
    ht->items[next_idx].value = 0;
    return 0;
}


#endif // HASH_TABLE_IMPLEMENTATION
#endif // HASH_TABLE_H
