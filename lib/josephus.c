#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "CDLListNode.h"
#include "CDLList.h"

/******************************************************************************
 * Convert a string into a number.
 *
 * @param str String.
 * @param minimum Minimum permitted number.
 *
 * @return Integer greater than or equal to `minimum`, or -1 if that is not
 *     possible.
 *****************************************************************************/
int long strtol_wrapper(char const *str, int long minimum)
{
    char *endptr;
    int long val = strtol(str, &endptr, 10);
    if(*endptr != '\0' || errno == ERANGE || val < minimum)
    {
        fprintf(stderr, "Could not parse %s as an integer ≥ %ld.\n", str, minimum);
        return -1;
    }
    return val;
}

/******************************************************************************
 * Find the winner in an instance of the Josephus problem.
 *
 * @param number_of_people Number of people. Must be at least 2.
 * @param step_size Number of people to people to step over. (Specifically:
 *     'Every `step_size`th person is eliminated.') Must be at least 2.
 *****************************************************************************/
void josephus(int long number_of_people, int long step_size)
{
    printf("%ld people, numbered from 1 to %ld, are standing in a circle. ", number_of_people, number_of_people);
    printf("Every %ld", step_size);
    switch(step_size % 10)
    {
        case 1:  printf("st"); break;
        case 2:  printf("nd"); break;
        case 3:  printf("rd"); break;
        default: printf("th"); break;
    }
    printf(" person is eliminated.\n");
    struct CDLList *list = CDLList_new();
    for(int long i = 1; i <= number_of_people; ++i)
    {
        CDLList_insert(list, i);
    }

    struct CDLListNode *curr = list->head->prev;
    while(CDLList_length(list) > 1)
    {
        for(int long i = 0; i < step_size - 1; ++i)
        {
            curr = curr->next;
        }
        CDLList_erase(list, curr->next);
    }
    int long winner = curr->item;
    printf("%ld is the winner.\n", winner);
    CDLList_delete(list);
}

/******************************************************************************
 * Main function.
 *****************************************************************************/
int main(int const argc, char const *argv[])
{
    int long number_of_people = 100;
    if(argc >= 2 && (number_of_people = strtol_wrapper(argv[1], 2)) == -1)
    {
        return EXIT_FAILURE;
    }
    int long step_size = 3;
    if(argc >= 3 && (step_size = strtol_wrapper(argv[2], 2)) == -1)
    {
        return EXIT_FAILURE;
    }

    josephus(number_of_people, step_size);
    return EXIT_SUCCESS;
}
