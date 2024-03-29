#ifndef CIRCULAR_DOUBLY_LINKED_LIST_JOSEPHUS_PROBLEM_INCLUDE_CDLLIST_H_
#define CIRCULAR_DOUBLY_LINKED_LIST_JOSEPHUS_PROBLEM_INCLUDE_CDLLIST_H_

#include <stdbool.h>

#include "CDLListNode.h"

// Circular doubly-linked list.
struct CDLList
{
    // Read-only.
    struct CDLListNode *head;

    // No access.
    int long length;
};

struct CDLList *CDLList_new(void);
bool CDLList_empty(struct CDLList *list);
int long CDLList_length(struct CDLList *list);
void CDLList_insert(struct CDLList *list, int long item);
void CDLList_erase(struct CDLList *list, struct CDLListNode *node);
void CDLList_delete(struct CDLList *list);

#endif  // CIRCULAR_DOUBLY_LINKED_LIST_JOSEPHUS_PROBLEM_INCLUDE_CDLLIST_H_
