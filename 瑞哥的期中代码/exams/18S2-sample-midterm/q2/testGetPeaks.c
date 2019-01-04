// testGetPeaks.h - testing DLList data type
// Written by Ashesh Mahidadia, December 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"
#include "getPeaks.h"

void print_list(DLList L) {
    //forth
    DLListNode *node = L->first;
    if (L->first != NULL) {
        printf("header value: %d", L->first->value);
    }
    if (L->curr != NULL) {
        printf("curr value: %d", L->curr->value);
    }
    if (L->last != NULL) {
        printf("last value: %d", L->last->value);
    }
    printf("nitems value: %d \n", L->nitems);

    while (node != NULL) {
        printf("node value:%d \n", node->value);
        node = node->next;
    }

    node = L->last;

    while (node != NULL) {
        printf("prev node value:%d \n", node->value);
        node = node->prev;
    }
}

int main(int argc, char *argv[]) {
    DLList L = getDLList(stdin);
    fprintf(stdout, "Input sequence: ");
    putDLList(stdout, L);

    DLList AnsL = getPeaks(L);
    int validList = validDLList(L);
    if( ! validList ) {
    fprintf(stderr, ">>> Error: Invalid list returned from the function getPeaks! \n");
     	return 1;
    }

    fprintf(stdout, "Peaks: ");
    putDLList(stdout, AnsL);


    return 0;
}
