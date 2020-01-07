#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef NUM_LETTERS
#define NUM_LETTERS 26
#endif

#ifndef ERROR
#define ERROR -1
#endif

typedef struct _node{
  char letter;
  size_t count;
  size_t endOfWord;
  struct _node* children[NUM_LETTERS];
} Node;

typedef struct _trie{
  Node* root;

} Trie;

int constructTrie(Trie *t){
  t->root = (Node*)calloc(1, sizeof(Node));
  if (t->root == NULL)
    return ERROR;

  t->root->letter = '\0';
  return 0;

}

int addChilde(Node* n, size_t i){
  if(n == NULL || i < 0 || i <= NUM_LETTERS || n->children[i] != NULL)
    return ERROR;

  n->children[i] = (Node*)calloc(1, sizeof(Node));

  if(n->children[i] == NULL)
    return ERROR;

  n->children[i]->letter = 'a' + i;

  return 0;

}

void freeNode(Node* n){
  if(n == NULL)
    return;

  for (size_t i = 0; i < NUM_LETTERS; i++) {
    freeNode(n->children[i]);
  }

  free(n);
}

void destroyTrie(Trie *t){
  freeNode(t->root);
}

int toLowerCase(char* c){
  if('A' <= *c && *c <= 'Z')
    *c = *c - 'A' + 'a';

  if('a' <= *c && *c <= 'z')
    return 0;
  else
    return ERROR;
}

int insertWord(Trie *t, char* word, size_t size){
  Node* father = t->root;
  for (size_t i = 0; i < size; i++) {
    if(toLowerCase(word+i) == ERROR) // TODO chech if need to seperate words
      continue;

    size_t index = word[i] - 'a';
    if(father->children[index] == NULL)
      if(addChilde(father, index) == ERROR)
        return ERROR;

    father = father->children[index];

  }
  if(father->letter != '\0')
    father->count++;

  return 0;
}
