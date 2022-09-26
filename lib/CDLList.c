#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "CDLListNode.h"
#include "CDLList.h"

/******************************************************************************
 * Construct an empty CDL list whose head is uninitialised.
 *
 * @return Pointer to newly allocated memory.
 *****************************************************************************/
struct CDLList *CDLList_new(void)
{
    struct CDLList *list = malloc(sizeof *list);
    list->length = 0;
    return list;
}

/******************************************************************************
 * Check whether a CDL list is empty.
 *
 * @param list CDL list.
 *
 * @return `true` if `list` is empty, else `false`.
 *****************************************************************************/
bool CDLList_empty(struct CDLList *list)
{
    return list->length == 0;
}

/******************************************************************************
 * Obtain the number of items in a CDL list.
 *
 * @param list CDL list.
 *
 * @return Length of `list`.
 *****************************************************************************/
int CDLList_length(struct CDLList *list)
{
    return list->length;
}

/******************************************************************************
 * Insert into a CDL list. The head of the list is updated only if it is
 * initially empty.
 *
 * @param list CDL list.
 * @param item Item to append.
 *****************************************************************************/
void CDLList_insert(struct CDLList *list, int item)
{
    struct CDLListNode *node = CDLListNode_new(item);
    if(CDLList_empty(list))
    {
        list->head = node;
        node->prev = node;
        node->next = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->head->prev;
        list->head->prev = node;
        node->prev->next = node;
    }
    ++list->length;
}

/******************************************************************************
 * Erase from a CDL list.
 *
 * @param list CDL list.
 * @param node Node to erase. Must be a pointer to a node of `list`.
 *****************************************************************************/
void CDLList_erase(struct CDLList *list, struct CDLListNode *node)
{
    if(node == list->head)
    {
        list->head = list->head->next;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    CDLListNode_delete(node);
    --list->length;
}

/******************************************************************************
 * Destroy a CDL list. (Erase all elements from it and deallocate all memory,
 * including that of the list itself.)
 *
 * @param list CDL list. This pointer will point to an invalid location after
 *     this function has returned.
 *****************************************************************************/
void CDLList_delete(struct CDLList *list)
{
    while(!CDLList_empty(list))
    {
        CDLList_erase(list, list->head);
    }
    free(list);
}
