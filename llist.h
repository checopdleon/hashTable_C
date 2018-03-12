/* !!!!!!!  DO NOT DELETE  !!!!!!!
   Author: Eric Freudenthal Ph.D, UTEP
   Edits/addtions: Sergio Ponce De Leon, srosales4@miners.utep.edu
   Course: Computer Architecture
   Project: #1, "Personnel Management System"
   Last edit: Mar. 12, 2018
   COPYRIGHT 2018
   !!!!!!  DO NOT DELETE  !!!!!!!!
*/

// READ UP ON 'ifndef' and 'define' multiple inclusion ????????????????????????????????????????????????
#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

//Why have a linked list struct AND a list of LLItems in the same file? -SPDL
//They are both structs; llist is composed of LLItems. - SPDL
/* a linked-list item */
typedef struct LLItem_s {
  struct LLItem_s *next;                                            //pointer to next LLItem_s instance
  char *str;                                                             //pointer to an array of chars
} LLItem; // Why does the struct finish with 'LLItem'? - SPDL
// Because of the 'typedef' keyword. it's used to give any data-type, even user-defined ones, a new
// name, e.g., instead of typing out "unsigned char 'someName' " just define BYTE to be the name for
// unsigned char. Now we can type "BYTE b1, b2" and the compiler will know b1 and b2 are unsigned chars.
// from https://wwww.tutorialspoint.com/cprogramming/c_typedef.htm

/* a list of LLItems */
typedef struct {
  LLItem *first, *last;  //pointers to the first and last LLItem? Refresh on lists *******************
} LList;

extern int llDoCheck;	/* set true for paranoid consistency checking ????????????????????????????? */ 

/*  !!!!!!!!!!!!  INTERFACE SECTION  !!!!!!!!!!!!! */
/* create a new list */
LList *llAlloc();

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
