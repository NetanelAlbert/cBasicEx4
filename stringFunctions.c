#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef LINE
#define LINE 256
#endif

#ifndef PREV
#define PREV -1
#endif

#ifndef NEXT
#define NEXT +1
#endif

#ifndef WORD
#define WORD 30
#endif

bool isEOF(bool b){
  static bool eof = false;
  if(b)
    eof = true;
  return eof;
}

int getLine(char s[]){
  if(isEOF(false))
    return EOF;

  int i = 0;
  char c;
  do{
    c = getchar();
    *(s+i++) = c;
  }while(c != '\n' && c != '\0' && i < LINE PREV);

  *(s+i) = '\0';

  if(isEOF(c == EOF))
    return EOF;

  return i PREV;
}

int getword(char w[]){
  if(isEOF(false))
    return EOF;

  int i = 0;
  char c=' ';
  while(c == ' ' || c == '\t' || c == '\n' || c == '\0') {
    c = getchar();
    if(isEOF(c == '\0'))  //set+get eof
      return PREV;
  }
  while(c != ' ' && c != '\t' && c != '\n' && c != '\0' && i < WORD PREV) {

    *(w+(i++)) = c;
    c = getchar();
  }
  *(w+i) = '\0';

  if(isEOF(c == EOF))
    return EOF;

  return i PREV;
}

int substring(char* str1, char* str2){
  int str1Len = strlen(str1);
  int str2Len = strlen(str2);
  for (size_t i = 0; i < str1Len - str2Len; i++) {
    bool found = true;
    for (size_t j = 0; j < str2Len && found; j++) {
      found = found && (*(str1+i+j) == *(str2+j));
    }
    if(found)
      return true;
  }
  return false;
}

void copyLessOne(char *src, char* trgt, int drop){

  for (size_t i = 0; i < drop ; i++) {
    *(trgt+i) = *(src+i);
  }

  for (size_t i = drop; *(src+i) != '\0'; i++) {
    *(trgt+i) = *(src+i NEXT);
  }
}

int similar(char *s, char *t, int n){
  int sLen = strlen(s);
  int tLen = strlen(t);
  if(n == 0){
    if(sLen != tLen)
      return false;
    for (size_t i = 0; i < sLen; i++) {
      if(*(s+i) != *(t+i))
        return false;
    }
    return true;
  }

  if(sLen <= tLen || n < 0)
    return false;

  for (size_t i = 0; i < sLen; i++) {

    char sLess[WORD] = {0};
    copyLessOne(s, sLess, i);
    if(similar(sLess, t, n PREV))
      return true;
  }
  return false;
}

void printLines(char* str){
  int lent = 0;
  char line[LINE];
  do {
    lent = getLine(line);
    if(lent > 0 && substring(line, str) == true)
      printf("%s", line);

  } while(lent != EOF);
}

void printSimilarWords(char* str){
  int lent;
  do {
    char word[WORD];
    lent = getword(word);
    if(lent > 0 && (similar(word, str, 0) || similar(word, str, 1)))
      printf("%s\n", word);

  } while(lent != EOF);
}
