#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ticker.h"

ticker *ticker_create(const char *message, int width) {
        ticker *t = (ticker *)malloc(sizeof(ticker));
        t->message = strdup(message);
        t->width = width;
        t->head = 0;
        t->cursor = 0;
        t->message_length = strlen(t->message);
        return t;
}

char ticker_sequence(ticker *t) {
        char c;
        int position = t->head + t->cursor;

        // 表示の終端に達した場合、NUL文字を返却する
        if (t->cursor >= t->width) {
                return '\0';
        }

        c = BLUNK_CHAR;
        if (t->width <= position && t->width + t->message_length > position) {
                c = *(t->message + (position - t->width));
        }
        t->cursor++;
        return c;
}

int ticker_forward(ticker *t) {
        if (t->head + 1 > t->message_length + t->width) {
                return 0;
        }
        t->head++;
        t->cursor = 0;
        return 1;
}

void ticker_rewind(ticker *t) {
        t->head = 0;
        t->cursor = 0;
}

void ticker_destroy(ticker *t) {
        free(t->message);
        free(t);
}
