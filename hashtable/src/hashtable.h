typedef struct {
        char* keyword;
        void* value;
        list* next;
} list;

void init(int capacity);
void *get(char *key);
void set(char *key, void *node);
