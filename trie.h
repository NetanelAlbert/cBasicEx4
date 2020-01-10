#include <stdbool.h>
#include <stddef.h>

#ifndef NUM_LETTERS
#define NUM_LETTERS 26
#endif


#ifndef ERROR
#define ERROR -1
#endif

#ifndef NODE
#define NODE

typedef struct _node{
  char letter;
  size_t count; // how many words finished here
  struct _node* children[NUM_LETTERS];
} Node;

#endif

#ifndef TRIE
#define TRIE

typedef struct _trie{
  Node* root;
  size_t longestWord;
} Trie;

#endif

int printTrie(Trie*, bool);
int insertWord(Trie*, char*, size_t);
void destroyTrie(Trie*);
int constructTrie(Trie*);
