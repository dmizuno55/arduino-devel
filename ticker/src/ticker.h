#define LCD_WIDTH 16
const char BLUNK_CHAR = '_';

typedef struct {
        char *message;
        char *snapshot;
        int width;
        int position;
        int frames;
} ticker;

ticker *ticker_create(const char *message, int width);
void ticker_forward(ticker *t);
void ticker_free(ticker *t);

