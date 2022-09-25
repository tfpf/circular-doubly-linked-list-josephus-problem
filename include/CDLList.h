#ifndef LOOP_KILLERS_INCLUDE_CDLLIST_H_
#define LOOP_KILLERS_INCLUDE_CDLLIST_H_

#include <stdbool.h>

// Circular doubly-linked list.
struct CDLList
{
    struct CDLListNode *head;
    int length;
};

struct CDLList *CDLList_new(void);
bool CDLList_empty(struct CDLList *list);
int CDLList_length(struct CDLList *list);
void CDLList_insert(struct CDLList *list, int item);
void CDLList_erase(struct CDLList *list, struct CDLListNode *node);
void CDLList_clear(struct CDLList *list);

#endif  // LOOP_KILLERS_INCLUDE_CDLLIST_H_
