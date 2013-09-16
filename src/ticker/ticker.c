#include <stdio.h>
#include <string.h>

#define LCD_WIDTH 16
const char BLUNK_CHAR = '_';

struct ticker {
        char *message;
        int padding;
        char *messagePos;
        char snapshot[LCD_WIDTH + 1];
};

void init(struct ticker *t);
void next(struct ticker *t);
int hasNext(struct ticker *);

int main() {
        struct ticker t = {.message = "apple"};
        init(&t);
        for (; hasNext(&t); next(&t)) {
                printf("%s\n", t.snapshot);
        }
}

void init(struct ticker *t) {
        t->padding = LCD_WIDTH;
        t->messagePos = t->message;
        memset(t->snapshot, 0x00, sizeof(t->snapshot));
}

void next(struct ticker *t) {
        printf("padding=%i,messagePos=%s\n", t->padding, t->messagePos);
        memset(t->snapshot, 0x00, sizeof(t->snapshot));
        if (t->padding > 0) {
                int i;
                for (i = 0; i < t->padding; i++) {
                        t->snapshot[i] = BLUNK_CHAR;
                }
        }

        if (t->padding < LCD_WIDTH) {
                strncat(t->snapshot, t->messagePos, (LCD_WIDTH - t->padding));
        }
        
        if (t->padding > 0) {
                t->padding--;
        } else if (t->padding == 0 && *(t->messagePos) != '\0') {
                t->messagePos++;
        }
}

int hasNext(struct ticker *t) {
        return *(t->messagePos) != '\0';
}
