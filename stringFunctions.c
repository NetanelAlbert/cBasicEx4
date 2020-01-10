#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>




#ifndef PREV
#define PREV -1
#endif

#ifndef NEXT
#define NEXT +1
#endif

#ifndef WORD
#define WORD 30
#endif

#ifndef SMALL_WORD
#define SMALL_WORD 10
#endif

bool isEOF(bool b){
  static bool eof = false;
  if(b)
    eof = true;
  return eof;
}

int getUnlimitWord(char** word){
  if(isEOF(false))
    return EOF;

  char* w = (char*) calloc(SMALL_WORD, sizeof(char));
  if(w == NULL)
    return PREV;

  int cap = SMALL_WORD;

  char c=' ';
  while(c == ' ' || c == '\t' || c == '\n' || c == '\0') {
    c = getchar();
    if(isEOF(c == '\0'))  //set+get eof
      return EOF;
  }
  int i = 0;
  while(c != ' ' && c != '\t' && c != '\n' && c != '\0' && c != EOF) {
    if(i == cap PREV){
      char* t = realloc(w, (cap+SMALL_WORD)*sizeof(char));
      if(t == NULL){
        if(w != NULL)
          free(w);
        return PREV;
      }
      w = t;
      cap += SMALL_WORD;
    }


    w[i++] = c;
    c = getchar();
  }
  w[i] = '\0';

  *word = w;

  if(isEOF(c == EOF))
    return EOF;

  return i;
}
