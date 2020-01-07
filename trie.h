#include <stdbool.h>
#include <stddef.h>

#ifndef NUM_LETTERS
#define NUM_LETTERS 26
#endif


#ifndef ERROR
#define ERROR -1
#endif

typedef struct _node{
  char letter;
  size_t count; // how many words finished here
  //size_t endOfWord;
  struct _node* children[NUM_LETTERS];
} Node;

typedef struct _trie{
  Node* root;
  size_t longestWord;
} Trie;

int printTrie(Trie*, bool );
int insertWord(Trie*, char*, size_t);
void destroyTrie(Trie*);
int constructTrie(Trie*);
