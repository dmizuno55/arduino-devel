#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ticker.h"

int main() {
        ticker *t = ticker_create("hello Tokyo Adachi Hanahata 7 - 14 - 7", LCD_WIDTH);
        int i;
        for (i = 0; i < t->frames; i++) {
                printf("%s\n", t->snapshot);
                ticker_forward(t);
        }
        ticker_free(t);
}

ticker *ticker_create(const char *message, int width) {
        ticker *t = (ticker *)malloc(sizeof(ticker));
        t->message = strdup(message);
        t->width = width;
        char *snapshot = (char *)malloc(sizeof(char) * (width + 1));
        memset(snapshot, (int)BLUNK_CHAR, sizeof(char) * width);
        snapshot[width + 1] = '\0';
        t->snapshot = snapshot;
        t->position = 0;
        t-> frames = width + strlen(message) + 1;
        return t;
}

void ticker_forward(ticker *t) {
        int msglen = strlen(t->message);
        char snapshot[t->width + 1];
        sprintf(snapshot, "%s", t->snapshot + 1);
        if (msglen > t->position) {
                sprintf(snapshot, "%s%c", snapshot, *(t->message + t->position));
                t->position++;
        } else {
                sprintf(snapshot, "%s%c", snapshot, BLUNK_CHAR);
        }
        strcpy(t->snapshot, snapshot);
}

void ticker_free(ticker *t) {
        free(t->message);
        free(t->snapshot);
        free(t);
}
