#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

list *hashtable;
int tableCapacity;
void *values;

void init(int capacity) {
        hashtable = malloc(sizeof(list) * capacity);
        tableCapacity = capacity;
}

int hash(char *key) {
        int hashval = 0;
        while(*key != '\0') {
                hashval += *key++;
        }
        return (hashval % tableCapacity);
}

void *get(char *key) {
        list *p;
        for (p = hashtable[hash(key)]; p != NULL; p = p->next) {
                if (strcmp(key, (*p).keyword)) {
                        return (*p).value;
                }
        }
        return NULL;
}

void set(char *key, void *value) {
        list *n, *p, *swap;
        int hashval = hash(key);
        int overwrite = 0;
        n = newNode(key, value);
        if (hashtable[hashval] == NULL) {
                hashtable[hashval] = n;
        } else {
                p = hashtable[hashval];
                if (strcmp((*p).keyword, key)) {
                        hashtable[hashval] = n;
                        n->next = p->next;
                } else {
                        swap(p, n);
                }
        }
}

void swap(list *head, list node) {
        if (strcmp((*head).keyword, (*node).keyword)) {
                node->next = head->next;
                head = node;
        } else if (head->next != NULL) {
                swap(head->next, node);
        } else {
                head->next = node;
        }
}

list *newNode(char *key, void *value) {
        list *node = malloc(sizeof(list));
        strcpy((*node).keyword, key);
        node->value = value;
        node->next = NULL;
        return node;
}
