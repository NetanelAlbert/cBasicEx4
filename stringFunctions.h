#ifndef LINE
#define LINE 256
#endif

#ifndef PREV
#define PREV -1
#endif

#ifndef WORD
#define WORD 30
#endif

int getLine(char s[]);

int getword(char w[]);

int substring(char * str1, char * str2);

void copyLessOne(char *src, char* trgt, int drop);

int similar(char *s, char *t, int n);

void printLines(char* str);

void printSimilarWords(char* str);
