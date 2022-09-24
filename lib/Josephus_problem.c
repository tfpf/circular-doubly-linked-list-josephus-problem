#include <stdio.h>
#include <stdlib.h>

#include "CDLListNode.h"
#include "CDLList.h"

/******************************************************************************
 * Find the winner in an instance of the Josephus problem.
 *
 * @param number_of_people Number of people. Must be positive.
 *****************************************************************************/
void Josephus_problem(int number_of_people)
{
    struct CDLList *list = CDLList_new();
    for(int i = 1; i <= number_of_people; ++i)
    {
        CDLList_insert(list, i);
    }

    struct CDLListNode *curr = list->head;
    while(CDLList_length(list) > 1)
    {
        printf("%d shot %d.\n", curr->item, curr->next->item);
        CDLList_erase(list, curr->next);
        curr = curr->next;
    }
    int winner = curr->item;
    printf("%d is the winner.\n", winner);

    // No memory leaks!
    CDLList_erase(list, curr);
    free(list);

    // Check the answer: clear the most significant set bit, double the result,
    // and increment it.
    int MSB_position = -1;
    int number_of_people_ = number_of_people;
    while(number_of_people_ != 0)
    {
        ++MSB_position;
        number_of_people_ >>= 1;
    }
    int MSB_removed = number_of_people & ~(1 << MSB_position);
    int actual_winner = (MSB_removed << 1) | 1;
    if(winner != actual_winner)
    {
        fprintf(stderr, "Wait! Something's wrong. That's not the winner.\n");
    }
}

/******************************************************************************
 * Main function.
 *****************************************************************************/
int main(int const argc, char const *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  %s <number of people>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *endptr;
    int number_of_people = strtol(argv[1], &endptr, 10);
    if(*endptr != '\0' || number_of_people <= 0)
    {
        fprintf(stderr, "Could not parse %s as a positive integer.\n", argv[1]);
        return EXIT_FAILURE;
    }

    Josephus_problem(number_of_people);
    return EXIT_SUCCESS;
}
