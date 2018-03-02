/* !!!!!!!  DO NOT DELETE  !!!!!!!
   Author: Eric Freudenthal Ph.D, UTEP
   Edits/addtions: Sergio Ponce De Leon, srosales4@miners.utep.edu
   Course: Computer Architecture
   Project: #1, "Personnel Management System"
   Last edit: Feb 28, 2018
   COPYRIGHT 2018
   !!!!!!  DO NOT DELETE  !!!!!!!!
*/

#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

//Why have a linked list struct AND a list of LLItems in the same file?  ******************************
/* a linked-list item */
typedef struct LLItem_s {
  struct LLItem_s *next;                                            //pointer to next LLItem_s instance
  char *str;                                                             //pointer to an array of chars
  int key;
} LLItem; // Why does the struct finish with 'LLItem'? ************************************************

/* a list of LLItems */
typedef struct {
  LLItem *first, *last;  //pointers to the first and last LLItem? Refresh on lists *******************
} LList;

extern int llDoCheck;	/* set true for paranoid consistency checking ????????????????????????????? */ 

/*  !!!!!!!!!!!!  INTERFACE SECTION  !!!!!!!!!!!!! */
/* create a new list */
LList *llAlloc() ;

/* free memory associated with a list, discarding all items it contains */
void llFree(LList *lp);

/* append a copy of str to end of list */
void llPut(LList *lp, char *s);

/* Delete all elements off of the list */
void llMakeEmpty(LList *lp);

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(LList *lp, char *msg);

// Not sure what prof means by 'llist consistency' ?????????????????????????????????????????????
/* check llist consistency, always returns zero */
int llCheck(LList *lp);

#endif	/* included */
