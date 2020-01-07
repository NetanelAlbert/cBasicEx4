#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "trie.h"




int constructTrie(Trie *t){
  t->root = (Node*)calloc(1, sizeof(Node));
  if (t->root == NULL)
    return ERROR;

  t->root->letter = '\0';
  return 0;

}

int addChilde(Node* n, size_t i){
  if(n == NULL || i < 0 || NUM_LETTERS <= i || n->children[i] != NULL)
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
      if(addChilde(father, index) == ERROR){
        printf("ass chiled failed\n");
        return ERROR;
      }

    father = father->children[index];

  }
  if(father->letter != '\0')
    father->count++;

  if(t->longestWord < size)
    t->longestWord = size;

  return 0;
}

void printNode(Node* node, char* word, size_t size){
  if(size >= 0)
    word[size] = node->letter;
  word[size+1] = '\0';
  if(node->count > 0)
    printf("%s\t%d\n", word, (int)node->count);
  for (size_t i = 0; i < NUM_LETTERS; i++) {
    if(node->children[i] != NULL){
      printNode(node->children[i], word, size+1);
      word[size+1] = '\0';
    }
  }
}

void printNodeRvrs(Node* node, char* word, size_t size){
  if(size >= 0)
    word[size] = node->letter;

  for (size_t i = 0; i < NUM_LETTERS; i++) {
    if(node->children[NUM_LETTERS-i-1] != NULL){
      word[size+1] = '\0';
      printNodeRvrs(node->children[NUM_LETTERS-i-1], word, size+1);
    }
  }
  word[size+1] = '\0';
  if(node->count > 0)
    printf("%s\t%d\n", word, (int)node->count);
}

int printTrie(Trie* t, bool rvrs){
  if(t == NULL){
    printf("Can't print NULL trie\n");
    return ERROR;
  }

  char* word = calloc(sizeof(char), t->longestWord);
  if(word == NULL)
    return ERROR;

  if(rvrs)
    printNodeRvrs(t->root, word, -1);
  else
    printNode(t->root, word, -1);

  if(word != NULL)
    free(word);
  return 0;
}
