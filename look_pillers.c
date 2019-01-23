#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	A given number of men (say, 100) stand in a circle. Exactly one of them has a gun.
	This gunner shoots the next man, and gives the gun to the third man.
	Repeat until there's only one man standing.
	The gun never runs out of ammunition.
	(I say 'man' only because women are far too sensible to indulge in this animal-like behaviour.)
	Will try to solve this problem using a circular linked list.
*/

// structure to identify men individually
typedef struct node
{
	int index;
	struct node *next;
}
Node;

// linked list to emulate men standing
typedef struct list
{
	Node *head; // pointer to the first item
	Node *tail; // pointer to the last item
}
List;

// initialize a node with a given value
Node *Node_init(void)
{
	// declare and allocate space
	Node *N;
	N = malloc(sizeof(Node));

	// explicitly set pointer to null
	// in case they were not automatically
	N->next = NULL;

	// return it
	return N;
}

// initialize a linked list and return the pointer
// I know it is just two lines, but in case it needs to be used elsewhere,
// it should be easily changeable.
List *List_init(void)
{
	// declare and allocate space
	List *L;
	L = malloc(sizeof(List));

	// explicitly set pointers to null
	// in case they were not automatically
	L->head = NULL;
	L->tail = NULL;

	// return the pointer
	return L;
}

// check if the linked list is empty
// if head is null, tail will also be null
// so no need to check both
_Bool List_empty(List *L)
{
	return L->head == NULL;
}

// add item to linked list
void List_add(List *L, int I)
{
	// obtain a node pointer
	Node *N;
	N = Node_init();

	// set Node values
	N->index = I;
	N->next = NULL;

	// linked list was empty
	if(List_empty(L))
	{
		L->head = L->tail = N;
		return;
	}

	// linked list was not empty
	L->tail->next = N;
	L->tail = N;
	return;
}

int main(int argc, char **argv)
{
	// check arguments
	if(argc != 2)
	{
		printf("usage:\n");
		printf("\t./killers.out <number of people>\n");
		return 1;
	}

	// obtain the number of people
	int last;
	last = atoi(argv[1]);
	if(last <= 0)
	{
		printf("Could not convert %s to a positive integer.\n", argv[1]);
		return 2;
	}

	// initialize a linked list
	List *circle; // because stupid men are standing in a circle
	circle = List_init();

	// add elements to the list
	int count;
	for(count = 1; count <= last; count++)
	{
		List_add(circle, count);
	}

	// make it a circular list
	circle->tail->next = circle->head;

	// action begins
	Node *iterator; // the man who kills
	Node *killed; // the man who dies
	iterator = circle->head; // gun is given to the first person
	while(iterator->next != iterator)
	{
		// find out who is going to be killed
		killed = iterator->next;

		// kill and give the gun to the next living person
		printf("%*d deleting %*d\n", (int)strlen(argv[1]), iterator->index, (int)strlen(argv[1]), killed->index);
		iterator->next = killed->next;

		// free the soul of the dead and continue the game
		free(killed);
		iterator = iterator->next;
	}
	printf("\n");

	// and the winner is
	int winner = iterator->index;
	printf("last man standing: %d\n", winner);

	// in case you want to run this program multiple times using a Bash script, uncomment this line
	// return winner;
}
