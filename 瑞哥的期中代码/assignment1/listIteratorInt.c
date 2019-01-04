/*
  listIteratorInt.c : list Iterator ADT implementation
  Written by Minghao Liu 
  Student ID: z5139663
  Date: 1/1/2019
  This is used to achieve a list Iterator by doubleList.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "listIteratorInt.h"

// Create a node of the iterator  which represents each element.   
typedef struct Node {
  int value;
// Self-referential structures
  struct Node *prev;
  struct Node *next; 
} Node;

// Create a cursor of the current location.
typedef struct Cursor{
  struct Node *prev;
  struct Node *next;
} Cursor;

// This represents the whole iterator.
typedef struct IteratorIntRep{
  struct Node *first;
  struct Node *last;
  struct Cursor *cursor; 
} IteratorIntRep;

// Declare a pointer to the type of iterator. 
typedef struct IteratorIntRep *IteratorInt;

// Declare a static global variable which is used to mark whether we have called next() or previous() or findNext() or findPrevious().
static Node *have = NULL;

/*
  Implements the functions 
*/

// This function is used to initialize an iterator.
IteratorInt IteratorIntNew () {
// Allocates the memory space of a iterator.
   IteratorInt a = malloc(sizeof(IteratorIntRep));
   assert(a!=NULL);
   a->first=NULL;
   a->last =NULL;
// Allocates the memory space of a cursor of the iterator.
   Cursor *cur = malloc(sizeof(Cursor)); 
   assert(cur!=NULL);
   a->cursor =cur;
   cur->prev = NULL;
   cur->next = a->last;
   have = NULL; 
   return a;  
}

// This function is used to reset the iterator's cursor to the original location. 
void reset (IteratorInt it) {
   have = NULL;
   if (it == NULL) {
      return;
   }
   it->cursor->prev = NULL;
   it->cursor->next = it->first; 
}

// This function is used to add a node to the iterator and set the cursor behind the new node. 
int add (IteratorInt it, int v) {
// If it is not NULL, return 1.
   have = NULL;
// If the pointer which is passed in is NULL, return 0. 
   if (it == NULL) {
      return 0;
   }
// Adds the new node.
   Node *n = malloc(sizeof(Node));
   assert(n != NULL);
   if (it->first == NULL && it->last == NULL) { 
      n->prev = NULL;
      n->next = NULL;
      n->value = v;
      it->first = n;
      it->last = n;
      it->cursor->prev = n;
      it->cursor->next = n->next;
   } else if (it->cursor->prev == NULL) {
      n->prev = NULL;
      n->next = it->cursor->next;
      n->value = v;
      n->next->prev = n;
      it->first = n;
      it->cursor->prev = n;
      it->cursor->next = n->next;
   } else if (it->cursor->next == NULL) {
      n->prev = it->last;
      n->prev->next = n;
      n->next = NULL;
      n->value = v;
      it->last = n;
      it->cursor ->prev = n;
      it->cursor ->next = n->next;
  }  else {
      n->prev = it->cursor->prev; 
      n->next = it->cursor->next;
      n->value = v;
      n->prev->next = n;
      n->next->prev = n;
      it->cursor->prev = n;
      it->cursor->next = n->next;
   }
   return 1;  
}

// This is used to check whether it has next node behind the cursor.
int hasNext (IteratorInt it) {
   have = NULL;
   if (it == NULL) {
      return 0;
   }
   if (it->cursor->next != NULL) {
      return 1;
   }  
   return 0;  
}

// This is used to check whether it has previous node before the cursor.
int hasPrevious (IteratorInt it) {
   have = NULL;
   if (it == NULL) {
      return 0;
   }
   if (it->cursor->prev != NULL) {
      return 1;
   }
   return 0; 
}

// This is used to show the next node and move the cursor.
int *next (IteratorInt it) {
   if (hasNext(it) == 0) {
      return NULL;
   } else {
      it->cursor->prev = it->cursor->next;
      it->cursor->next = it->cursor->next->next;
      have = it->cursor->prev;
      return &it->cursor->prev->value;
   }
}

// This is used to show the previous node and move the cursor.
int *previous (IteratorInt it) {
   if (hasPrevious(it) == 0) {
      return NULL;  
   } else {
      it->cursor->next = it->cursor->prev;
      it->cursor->prev = it->cursor->prev->prev;
      have = it->cursor->next; 
      return &it->cursor->next->value; 
   }
}

// This function is used to delete the value which returned by next() or previous() or findNext() or findPrevious(). 
int deleteElm (IteratorInt it) {
// Checks whether the pointer is null or the one of four functions is not called.   
   if (have == NULL || it == NULL) {
      return 0;  
   } else {
// If there is only one node
      if (have == it->first && it->first == it->last ) {
         it->first = NULL;
         it->last = NULL;
         it->cursor->prev= NULL;
         it->cursor->next=it->last;
         free(have);
         have = NULL;
         return 1;
      } else if (have == it->first) {
// If the node is also the first node 
         it->first = it->first->next;
         it->first->prev = NULL;
         it->cursor->prev=NULL;
         it->cursor->next = it->first;
         free(have);
         have = NULL;
         return 1; 
      } else if (have == it->last) {
// If the node is also the last node
         it->last = it->last->prev;
         it->last->next = NULL;
         it->cursor->next=NULL;
         it->cursor->prev = it->last;
         free(have);
         have=NULL;
         return 1;
      } else {
// The normal situation.
         have->prev->next = have->next;
         have->next->prev = have->prev;
         it->cursor->prev = have->prev;
         it->cursor->next = have->next;
         free(have);
         have=NULL;
         return 1;
      }
   }
}

// The function is used to set the element returned by next() or previous() or findNext() or findPrevious() to a new value.
int set (IteratorInt it, int v) {
// Checks whether the pointer is null or the one of four functions is not called. 
   if (have == NULL || it == NULL) {
      return 0;
   } else {
// Sets a new value.
      have->value = v;
      have = NULL;
      return 1;
   }
}

// The function is used to find the next node with the given value , return the pointer of its previous node's value and advance the cursor. The time complexity of this function is O(n).
int *findNext (IteratorInt it, int v) {
   if (it ==NULL) {
      return NULL;
   }
   if (hasNext(it) == 0) {
      return NULL;
   } else {
//The original position of the cursor.
      Node *onext =it->cursor->next;
      Node *oprev = it->cursor->prev;
//Advances the cursor and searches the node with the given value.
      while (it->cursor->next != NULL) {
         if (it->cursor->next->value == v) {
            it->cursor->prev=it->cursor->next;
            it->cursor->next=it->cursor->next->next;
            have = it->cursor->prev;
            return &it->cursor->prev->value;
         }
         it->cursor->prev=it->cursor->next;
         it->cursor->next=it->cursor->next->next; 
      } 
// Returns NULL if there is no such next value and the cursor backs to the original position.
      it->cursor->next = onext;
      it->cursor->prev = oprev;
      return NULL; 
  }
}

// The function is used to find the previous node with the given value, return the pointer of its next node's value and move the cursor backwards. The time complexity of this function is O(n).
int *findPrevious (IteratorInt it, int v) {
   if (it == NULL) {
      return NULL;
   }
   if (hasPrevious(it) == 0) {
      return NULL;
   } else {
//The original position of the cursor.
      Node *pnext =it->cursor->next;
      Node *pprev = it->cursor->prev;
//Moves the cursor backwards and searches the node with the given value.
      while (it->cursor->prev != NULL) {
         if (it->cursor->prev->value == v) {
            it->cursor->next = it->cursor->prev;
            it->cursor->prev = it->cursor->prev->prev;
            have=it->cursor->next;
            return &it->cursor->next->value;
         }
         it->cursor->next = it->cursor->prev;
         it->cursor->prev = it->cursor->prev->prev;
      }
//Returns NULL if there is no such previous value and the cursor backs to the original posotion.
      it->cursor->next = pnext;
      it->cursor->prev = pprev;
      return NULL;
   }
}

//This function is used to free the all nodes. The time complexity of this function is O(n).
void freeIt (IteratorInt it) {
   have = NULL;
   if (it == NULL) {
      return;
   }
   Node *a = it->last; 
   it->cursor->next=NULL;
   it->cursor->prev = it->last;
   while (it->cursor->prev != NULL) {
      a = it->cursor->prev;
      it->cursor->next = it->cursor->prev;
      it->cursor->prev=it->cursor->prev->prev;
      free(a);
   } 
   free(it->cursor);
   free(it);
   return;
}


