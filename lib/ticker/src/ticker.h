#define LCD_WIDTH 16
static const char BLUNK_CHAR = ' ';

typedef struct {
        char *message;
        int width;
        int head;
        int message_length;
        int cursor;
 } ticker;

ticker *ticker_create(const char *message, int width);
char ticker_sequence(ticker *t);
int ticker_forward(ticker *t);
void ticker_destroy(ticker *t);

