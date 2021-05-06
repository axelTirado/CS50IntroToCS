// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"



unsigned int num_words = 0;
bool loaded = false;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash(const char *word)
{
   int n;
   int h = 0;
   for (int i = 0; word[i] != '\0'; i++){

       if (isalpha(word[i])){
           n = word[i] - 'a' + 1;
       }

       else{
           n = 27;
       }

       h = ((h << 3) + n) % N;
   }

   return h;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char check_word[strlen(word)];
    strcpy(check_word, word);

    for (int i = 0; check_word[i] != '\0'; i++){

        check_word[i] = tolower(check_word[i]);

    }

    int index = hash(check_word);

    if (table[index] != NULL){
        for (node* Pnode = table[index]; Pnode != NULL; Pnode = Pnode -> next) {
            if (strcmp(Pnode -> word, check_word) == 0){
                return true;
            }
        }
    }

    return false;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

node* new_node;

    FILE *f = fopen(dictionary,"r");

    if (f == NULL){
        printf("File not found\n");
        return false;
    }
  for (int i = 0; i < N; i++){
      table[i] = NULL;
      char word[LENGTH + 1];
      while(fscanf(f, "%s", word) != EOF){
          num_words++;
        do {
            new_node = malloc(sizeof(node));
            if (new_node == NULL){
                free(new_node);
            }

        } while (new_node == NULL);
        strcpy(new_node -> word, word);
       int index = hash(word);
       new_node -> next = table[index];
       table[index] = new_node;
      }
     fclose(f);
     loaded = true;
     return true;
  }
return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return num_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!loaded){
        return false;
    }

    for (int i = 0; i < N; i++){
        if (table[i] != NULL){
            node* point = table[i];
            while (point != NULL){
                node* rpoint = point;
                point = point -> next;
                free(rpoint);
            }

        }

    }
    return true;
}
