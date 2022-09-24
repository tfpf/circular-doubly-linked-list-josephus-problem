#include <stddef.h>
#include <stdlib.h>

#include "CDLListNode.h"

/******************************************************************************
 * Construct a CDL list node.
 *
 * @param item Value to store in the node.
 *
 * @return Pointer to newly allocated memory.
 *****************************************************************************/
struct CDLListNode *CDLListNode_new(int item)
{
    struct CDLListNode *node = malloc(sizeof *node);
    node->item = item;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
