#include <stdio.h>
#include "../src/ticker.h"

void print_debug(ticker *t);
void print_sequence(ticker *t);

int main() {
        ticker *t = ticker_create("The microcontroller on the board is programmed using the Arduino programming language (based on Wiring) and the Arduino development environment (based on Processing)", 16);

        do {
                print_sequence(t);
        } while(ticker_forward(t));

        printf("\nrewind\n");
        ticker_rewind(t);

        do {
                print_sequence(t);
        } while(ticker_forward(t));
        
        ticker_destroy(t);
}

void print_debug(ticker *t) {
        printf("----------\n");
        printf("head=%d\n", t->head);
        printf("cursor=%d\n", t->cursor);
}

void print_sequence(ticker *t) {
        char c;
        while ((c = ticker_sequence(t)) != '\0') {
                printf("%c", c);
        }
        printf("\n");
}
