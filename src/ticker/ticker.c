#include <stdio.h>
#include <string.h>

#define LCD_WIDTH 16
const char BLUNK_CHAR = '_';

void ticker(char *message);
char* padding(char word, int count);

int main() {
  ticker("Hello World!");
  ticker("apple");
}

void ticker(char *message) {
  int msgLength = (int)strlen(message);
  int i;
  for (i = 0; i < LCD_WIDTH + msgLength; i++) {
    char content[LCD_WIDTH + 1];
    int paddingLeft = LCD_WIDTH  - i;
    int paddingRight =i -  msgLength;
    // padding left
    if (paddingLeft > 0) {
      strcat(content, padding(BLUNK_CHAR, paddingLeft));
    }
    // message
    if (paddingLeft < LCD_WIDTH) {
      int messageLeftPosition = i < LCD_WIDTH ? 0 : i - LCD_WIDTH;
      int messageRightPosition = msgLength - i > 0 ? msgLength - i : msgLength; 
      strncpy(content, message + messageLeftPosition, messageRightPosition);
    }
    // padding rigth
    if (paddingRight > 0) {
      strcat(content, padding(BLUNK_CHAR, paddingRight));
    }
    printf("%i %s\n", i, content);
  }
}

char* padding(char word, int count) {
  char result[count];
  int i;
  for (i = 0; i < count; i++) {
    result[i] = word;
  }
  return result;
}
