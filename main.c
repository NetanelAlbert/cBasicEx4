#include "stringFunctions.h"
#include "trie.h"
#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  char* word = NULL;
  Trie trie;

  if(constructTrie(&trie) == ERROR)
    return ERROR;

  int lent;
  do {
    lent = getUnlimitWord(&word);
    if(lent > 0){
      if(insertWord(&trie, word, lent) == ERROR){
        printf("insertWord failed\n");
        return ERROR;
      }
    }
    if(word != NULL)
      free(word);
  } while(lent != EOF);

  bool rvrs = (argc > 1 && *(argv[1]) == 'r');

  printTrie(&trie, rvrs);
  destroyTrie(&trie);

  return 0;
}
