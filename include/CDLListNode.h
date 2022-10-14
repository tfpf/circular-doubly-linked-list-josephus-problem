#ifndef CIRCULAR_DOUBLY_LINKED_LIST_JOSEPHUS_PROBLEM_INCLUDE_CDLLISTNODE_H_
#define CIRCULAR_DOUBLY_LINKED_LIST_JOSEPHUS_PROBLEM_INCLUDE_CDLLISTNODE_H_

// Circular doubly-linked list node.
struct CDLListNode
{
    // Read-write.
    int long item;

    // Read-only.
    struct CDLListNode *prev;
    struct CDLListNode *next;
};

struct CDLListNode *CDLListNode_new(int long item);
void CDLListNode_delete(struct CDLListNode *node);

#endif  // CIRCULAR_DOUBLY_LINKED_LIST_JOSEPHUS_PROBLEM_INCLUDE_CDLLISTNODE_H_
