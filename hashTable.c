/* !!!!!!!!!!  DO NOT DELETE  !!!!!!!!!!!
   Author: Checo Sergio Ponce De Leon, checopdleon@gmail.com
   Edits/Additions: n/a
   Course: Computer Architecture
   Project: #1 "Personnel Management System"
   Last Edit: Mar. 1, 2018
   !!!!!!!!!!  DO NOT DELETE  !!!!!!!!!!!
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"llist.h"
#include"llist.c"

/** Array of lists, which make up the hashTable. Dynamically 
    resizing hashTable. */
struct LList* hashTable;

/** Atores the number of elements in the entire hash table. */
int totalElements;

/** Max Llists the hashTable can store. */
int maxLists = 31339;

/** Hashes the given int passed in. */
int hashedString (int key)  {
  return key % maxLists;
}

/** */
struct node* get_elements(struct node *list, int find_index);

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

int main() {

  hashTable = (struct LList*) malloc(31339 * sizeof(struct LList*) );

  printf("HashTable struct was created correctly\n");
  return 0;
}
