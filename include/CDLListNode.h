#ifndef LOOP_KILLERS_INCLUDE_CDLLISTNODE_H_
#define LOOP_KILLERS_INCLUDE_CDLLISTNODE_H_

// Circular doubly-linked list node.
struct CDLListNode
{
    int item;
    struct CDLListNode *prev;
    struct CDLListNode *next;
};

struct CDLListNode *CDLListNode_new(int item);

#endif  // LOOP_KILLERS_INCLUDE_CDLLISTNODE_H_
