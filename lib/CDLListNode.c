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
struct CDLListNode *CDLListNode_new(int long item)
{
    struct CDLListNode *node = malloc(sizeof *node);
    node->item = item;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/******************************************************************************
 * Destroy a CDL list node.
 *
 * @param node CDL list node. This pointer will point to an invalid location
 *     after this function has returned.
 *****************************************************************************/
void CDLListNode_delete(struct CDLListNode *node)
{
    free(node);
}
