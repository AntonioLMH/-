// getPeaks.c 
// Written by Ashesh Mahidadia, December 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"


/* 
    You will submit only this one file.

    Implement the function "getPeaks" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/

DLList getPeaks(DLList L) {

    DLList peaksL = newDLList();

    // your solution here ...
    if (!DLListIsEmpty(L)) {
        // local variables
        DLListNode *peakTemp, *newNode, *temp = L->first->next;

        // find the peak node
        while (temp != NULL && temp->next != NULL) {
            if (temp->value > temp->next->value
                && temp->value > temp->prev->value) {

                // create new node
                newNode = malloc(sizeof(*newNode));
                newNode->value = temp->value;
                newNode->next = NULL;
                newNode->prev = NULL;

                if (DLListIsEmpty(peaksL)) {
                    // init the first element of list
                    peakTemp = peaksL->last = peaksL->first = newNode;
                } else {
                    // new node
                    peakTemp->next = newNode;
                    // move last node and prev node
                    peakTemp->next->prev = peakTemp;
                    // move the next node
                    peaksL->last = peakTemp = peakTemp->next;
                }
                // add number of node;
                peaksL->nitems++;
            }
            // move to next node
            temp = temp->next;
        }
    }
    return peaksL;
}



