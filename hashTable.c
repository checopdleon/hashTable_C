/* !!!!!!!!!!  DO NOT DELETE  !!!!!!!!!!!
   Author: Checo Sergio Ponce De Leon, checopdleon@gmail.com
   Edits/Additions: n/a
   Course: Computer Architecture
   Project: #1 "Personnel Management System"
   Last Edit: Mar. 12, 2018
   !!!!!!!!!!  DO NOT DELETE  !!!!!!!!!!!
 */

// !!!!!!!!!!!!!!!!!!  ADD '#ifndef' INCLUDE GUARD  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"llist.h"
#include"llist.c"

/* First build the base struct that the LLists will be composed of, this
 * struct is called LLItem and is within the 'llist.h' included file. Next
 * is to create the struct of LLists, this is also in the 'llist.h' file.*/

/** Array of lists, which make up the hashTable. Dynamically 
    resizing hashTable. */
struct LList *hashTable;

/** Atores the number of elements in the entire hash table. */
int totalElements;

/** Max Llists the hashTable can store. */
int maxLists = 31339;

/** Return maxLists */
int getMax() {
  return maxLists;
}

/** Hashes the given int passed in to figure out which list corresponds
    to the passed in string.
    source: http://research.cs.vt.edu/AVresearch/hashing/strings.php*/
int hashedString (char *string)  {
  int i, sum = 0;
  for (i = 0; i < strlen( string); i++)
    {
      sum += string[i];
    }
  
  return sum % maxLists;
}

/** */
struct node* get_elements(LList *list, int find_index);

/** */
void remove_element(int key);

/** */
void rehash();

/** */
void init_array();

/** */
void insert (int key, char* str[]) {
  float loadFactor = 0.0; // check if rehashing is needed

  int hashIndex = hashcode(key);

  // copy the list at the given slot in the hashTable
  struct node *list = (struct node*) hashTable[hashIndex]->first;

  // make the LLItem to add
  struct node *newLLItem = (struct node*) malloc(sizeof(struct node) );
  newLLItem->key = key;
  newLLItem-> 
}

int main() {

  hashTable = (struct LList*) malloc(31339 * sizeof(struct LList*) );

  printf("HashTable struct was created correctly\n");
  
  return 0;
}
