#include <stdio.h>
#define HASH_TABLE_IMPLEMENTATION
#include "hash_table.h"

int main(void)
{
    Hash_Table ht = {0};
    make_hash_table(&ht, 50);
    
    insert(&ht, (Set){10, 25});
    insert(&ht, (Set){114, 2665});
    insert(&ht, (Set){11, 5});
    insert(&ht, (Set){10, 11});
    insert(&ht, (Set){134, 11311});
    insert(&ht, (Set){3343, 12311});

    for (int i = 0; i < ht.size; i++){
        if(ht.items[i].key != 0) printf("%d: %d - %d\n", i, ht.items[i].key, ht.items[i].value);
    }

    remove_entry(&ht, 134);
    remove_entry(&ht, 114);
    printf("removed entries\n");
    for (int i = 0; i < ht.size; i++){
        if(ht.items[i].key != 0) printf("%d: %d - %d\n", i, ht.items[i].key, ht.items[i].value);
    }

    free_hash_table(&ht);
    return 0;
}


