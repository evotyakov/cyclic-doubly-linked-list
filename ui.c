#include "ui.h"

void cdll_print (const cdll *l)
{
    if (l == NULL)
    {
        printf("No list\n");
        return;
    }

    if (l->current == NULL)
    {
        printf("No nodes\n");
        return;
    }

    const node *start = l->current;
    const node *current = start;
    int count = 0;

    printf("List of elements:\n");

    do
    {
        printf("%d", current->data);
        current = current->next;
        count++;

        if (current != start) printf(" <-> ");
    }
    while (current != start);

    printf("\n^");
    printf("\nTotal elements: %d\n", count);
}

void cdll_commands()
{
    printf("\nCircular Doubly Linked List commands:\n"
           "  1. Create empty list\n"
           "  2. Create list copy\n"
           "  3. Insert after current\n"
           "  4. Insert before current\n"
           "  5. Delete current element\n"
           "  6. Move to next element\n"
           "  7. Move to previous element\n"
           "  8. Display list contents\n"
           "  9. Destroy list\n"
           " 10. Switch active list\n"
           "  0. Exit\n\n");
}
