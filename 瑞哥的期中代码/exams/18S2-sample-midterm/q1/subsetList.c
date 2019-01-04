// subsetList.c 
// Written by Ashesh Mahidadia, Jan 2018

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"


/* 
    You will submit only this one file.

    Implement the function "subsetList" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/
// merge two sorted list to one
DLListNode *merge(DLListNode *head1, DLListNode *head2) {
    if (head1 == NULL)return head2;
    if (head2 == NULL)return head1;
    DLListNode *res, *p;
    if (head1->value < head2->value) {
        res = head1;
        head1 = head1->next;
    } else {
        res = head2;
        head2 = head2->next;
    }
    p = res;

    while (head1 != NULL && head2 != NULL) {
        if (head1->value < head2->value) {
            p->next = head1;
            head1 = head1->next;
        } else {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if (head1 == NULL) {
        p->next = head2;
    } else {
        p->next = head1;
    }
    return res;
}


DLListNode *mergeSortList(DLListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //链表归并排序
    if (head == NULL || head->next == NULL)return head;
    else {
        //快慢指针找到中间节点
        DLListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = mergeSortList(head);//
        slow = mergeSortList(slow);//
        return merge(fast, slow);
    }

}

/**
 * 主要是使用归并排序，先排序，然后check 是否存在 complexity is n*lgn
 * @param L1 list1
 * @param L2 list2
 * @return return 1: exist 0: not exist
 */
int method_01(DLList L1, DLList L2) {
    int result = 0;

    // check L1 empty
    if (!DLListIsEmpty(L1)) {
        // if L2 is empty, return 1;
        if (DLListIsEmpty(L2)) {
            result = 1;
        } else {
            // order list 1
            DLListNode *head1 = mergeSortList(L1->first);
            // order list 2
            DLListNode *head2 = mergeSortList(L2->first);
            //  match and check L2 existence in L1
            while (head1 != NULL && head2 != NULL) {
                // if not exist,move head1
                if (head2->value != head1->value) {
                    head1 = head1->next;
                } else {
                    // exist move head2
                    head2 = head2->next;
                }
            }
            // head2 is the last one ,in this case ,head2 is null;
            if (head2 == NULL) {
                result = 1;
            }
        }
    }
    // return result;
    return result;
}

/**
 * loop method, complexity is n^2
 * @param L1 list1
 * @param L2 list2
 * @return return 1: exist 0: not exist
 */
int method_02(DLList L1, DLList L2) {
    int result = 0;
    // check L1 empty
    if (!DLListIsEmpty(L1)) {
        // if L2 is empty, return 1;
        if (DLListIsEmpty(L2)) {
            result = 1;
        } else {

            // local variables
            DLListNode *head1, *head2 = L2->first;
            while (head2 != NULL) {
                // get the first element of list 1
                head1 = L1->first;
                while (head1 != NULL) {
                    // exist
                    if (head2->value == head1->value) {
                        break;
                    } else {
                        // next value
                        head1 = head1->next;
                    }
                }

                // head1 == null not found
                if (head1 == NULL) {
                    break;
                }

                // move to next
                head2 = head2->next;
            }

            // head2 search finish
            if (head2 == NULL) {
                result = 1;
            }

        }
    }

    return result;
}


/**
 * check current node
 * @param head1 list 1 head
 * @param currentNode current node
 * @return 1 exist 0 not exist
 */
int method_03_node_search(DLListNode *head1, DLListNode *currentNode) {
    int result = 0;

    while (head1 != NULL && currentNode != NULL) {
        // check the value
        if (head1->value == currentNode->value) {
            result = 1;
            break;
        }
        head1 = head1->next;
    }

    return result;
}

/**
 * loop method, complexity is n^2
 * 方法2的另外一种写法
 * @param L1 list1
 * @param L2 list2
 * @return return 1: exist 0: not exist
 */
int method_03(DLList L1, DLList L2) {
    int result = 0;
    // check L1 empty
    if (!DLListIsEmpty(L1)) {
        // if L2 is empty, return 1;
        if (DLListIsEmpty(L2)) {
            result = 1;
        } else {

            // local variables
            DLListNode *head1, *head2 = L2->first;
            while (head2 != NULL) {
                head1 = L1->first;
                // search the node
                result = method_03_node_search(head1, head2);
                // not found
                if (!result) {
                    break;
                }
                // move to next
                head2 = head2->next;
            }
        }
    }

    return result;
}


int subsetList(DLList L1, DLList L2) {
    // second method
    // return method_01(L1, L2);
    // return method_02(L1, L2);
    return method_03(L1, L2);
}



