#include "stringFunctions.h"
#include "trie.h"
#include "stdbool.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  char word[WORD]; // TODO chech if cane limit lenght
  Trie trie;

  if(constructTrie(&trie) == ERROR)
    return ERROR;

  int lent;
  do {
    lent = getword(word);
    if(lent > 0){
      if(insertWord(&trie, word, lent) == ERROR){
        printf("insertWord failed\n");
        return ERROR;
      }
    }

  } while(lent != EOF);

  bool rvrs = (argc > 1 && *(argv[1]) == 'r');
  
  printTrie(&trie, rvrs);
  destroyTrie(&trie);

  return 0;
}
