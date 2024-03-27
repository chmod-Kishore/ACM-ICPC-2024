#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct entry {
    int data;
    int key;
    struct entry* next;
} entry;

typedef struct {
    entry* bucket[SIZE];
} Hashtable;

Hashtable* hashtable;

void create_hash() {
    hashtable = (Hashtable*)malloc(sizeof(Hashtable));
    for (int i = 0; i < SIZE; ++i) {
        hashtable->bucket[i] = NULL;
    }
}

int hash(int key) {
    return key % SIZE;
}

entry* set_entry(int data, int key) {
    entry* new_entry = (entry*)malloc(sizeof(entry));
    new_entry->data = data;
    new_entry->key = key;
    new_entry->next = NULL;
    return new_entry;
}

void insert(int key, int value) {
    int hashed_key = hash(key);
    entry* new_entry = set_entry(value, key);
    if (!hashtable->bucket[hashed_key]) {
        hashtable->bucket[hashed_key] = new_entry;
    } else {
        entry* temp = hashtable->bucket[hashed_key];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_entry;
    }
}

int get(int key) {
    int hashed_key = hash(key);
    entry* temp = hashtable->bucket[hashed_key];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->data;
        }
        temp = temp->next;
    }
    return -1;
}

void print() {
    printf("Hashtable:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("[%d]", i);
        entry* curr = hashtable->bucket[i];
        while (curr) {
            printf("(%d, %d)", curr->key, curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

void free_memory() {
    for (int i = 0; i < SIZE; ++i) {
        entry* curr = hashtable->bucket[i];
        while (curr) {
            entry* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashtable);
}

int main() {
    create_hash();
    insert(16, 100);
    insert(30, 200);
    insert(33, 250);
    insert(83, 300);
    insert(84, 300);
    printf("Value for key 20 is: %d\n", get(20));
    printf("Value for key 30 is: %d\n", get(30));
    print();
    free_memory();
    return 0;
}
