#ifndef HASH_TABLE_H
#define HASH_TABLE_H

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
int hash_function(Hash_Table* ht, int key);
int insert(Hash_Table* ht, Set s);

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

int hash_function(Hash_Table* ht, int key)
{
    return key % ht->size;
}

int insert(Hash_Table* ht, Set s)
{
    int idx = hash_function(ht, s.key);
    if (ht->items[idx].key = 0) {
        ht->items[idx] = s;
        ht->count++;
        return 0;
    }

    if (ht->items[idx].key == s.key) {
        ht->items[idx].value = s.value;
        return 0;
    }
    
    
    for (int i = 1; i <= ht->size; i++) {
        int next_idx = (idx+i)%ht->size;
        if (ht->items[next_idx] == 0) {
            ht->items[next_idx] = set;
            ht->count++;
            return 0;
        }
        else if (ht->items[next_idx].key == s.key) {
            ht->items[idx].value = s.value;
            return 0;
        }
    }
    return -1;
    
}

#endif // HASH_TABLE_IMPLEMENTATION
#endif // HASH_TABLE_H
