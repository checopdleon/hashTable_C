/* !!!!!!!  DO NOT DELETE  !!!!!!!
   Author: Eric Freudenthal Ph.D, UTEP
   Edits/addtions: Sergio Ponce De Leon, checopdleon@gmail.com
   Course: Computer Architecture
   Project: #1, "Personnel Management System"
   Last edit: Mar 1, 2018
   COPYRIGHT 2018
   !!!!!!  DO NOT DELETE  !!!!!!!!
*/

#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		/* for llists */
#include <string.h>             /* for strings */

int llDoCheck = 1;		/* set true for paranoid consistency checking */

/*  Some listpointer is passed in.
    if 'LLDoCheck' in list.h is true AND
    'llCheck' passing in the list-pointer returns 0, ie, false
    'doCheck' is set to true.

    The only way this is false with the lazy AND
    is if 'llDoCheck' in list.h is set to false. */
#define doCheck(_lp) (llDoCheck && llCheck(_lp))

/* create a new list */
LList *llAlloc()
{
  // Make a pointer to a new LList by:
  // 1. "allocating 'size' byte of memory returned by sizeOf(LLIst)
  // malloc returns a pointer to the frist byte
  // from c-language.com/c-tutorial/c-dma/c-malloc/
  // 2. then casting the memory that has the value of size
  LList *lp = (LList *)malloc(sizeof(LList));
  // set point first and last LLItem pointers to 0
  // so then first and last are just inices ??????????????????????????????????????????????
  lp->first = lp->last = 0;
  // check list for consistency
  doCheck(lp);
  // return the list-pointer
  return lp;
}

/* recycle a list, discarding all items it contains */
void llFree(LList *lp)
{
  //  Check list consistency
  doCheck(lp);
  // empty the list
  llMakeEmpty(lp);
  // free up the space that was allocated, built in func
  free(lp);
}

/* Delete all elements off of the list */
void llMakeEmpty(LList *lp)
{
  // initialize an LLItem pointer current and point it to the head
  // declare  another LLItem pointer called next
  LLItem *current = lp->first, *next;
  // check list for consistency
  doCheck(lp);
  // free up the space taken by str, current, and current->next
  while (current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  // reset the first and list indices to 0
  lp->first = lp->last = 0;	/* list is empty */
  // recheck list for consistency
  doCheck(lp);
}

/* finds the given string in the llist and returns its index
   within the llist or returns -1 when the string is not found */
int llFind (LList *lp, char *s)
{
  int index = 0;
  LLItem *iter = lp;
  while (iter != NULL)
    {
      // if the strings are the same when compared
      if (strcmp( s, (*iter).str) == 0) {return index;}

      iter = (*iter).next;
      index++;
    }
  // the string wasn't in the list
  return -1;
}
  
/* append a copy of str to end of list */
void llPut(LList *lp, char *s)
{
  int len;
  char *scopy;
  LLItem *i;

  doCheck(lp);
  /* w = freshly allocated copy of putWord */
  for (len = 0; s[len]; len++) /* compute length */
    ;
  scopy = (char *)malloc(len+1);
  for (len = 0; s[len]; len++) /* copy chars */
    scopy[len] = s[len];
  scopy[len] = 0;			/* terminate copy */


  /* i = new item containing s */
  i = (LLItem *)malloc(sizeof(LLItem));
  i->str = scopy;
  i->next = 0;

  /* append to end of list */
  if (lp->last) {			/* list not empty */
    lp->last->next = i;
  } else {			/* list empty */
    lp->first = i;
  }

  /* new item is last on list */
  lp->last = i;
  doCheck(lp);
}

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(LList *lp, char *msg)
{
  LLItem *ip;
  int count = 1;
  doCheck(lp);
  puts(msg ? msg :" List contents:");
  for (ip = lp->first; ip; ip = ip->next) {
    printf("  %d: <%s>\n", count, ip->str);
    count++;
  }
}

/*  I read up on assert in:
    https://www.tutorialspoint.com/c_standard_library/c_macro_assert.htm
    Still don't know what this this method does.
    Why do we check for consistency? ?????????????????????????????????????????????????????? */
/* check llist consistency */
int llCheck(LList *lp)
{
  LLItem *ip;
  ip = lp->first;
  if (!ip) 
    assert(lp->last == 0);
  else {
    for (; ip->next; ip = ip->next);
    assert(ip == lp->last);
  }
  return 0;
}
