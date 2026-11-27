#include"student.h"

void reverse_student(SLL *head)
{
    SLL prev, current, nextnode;

    prev = NULL;
    current = *head;

    if (*head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    while (current != NULL)
    {
        nextnode = current->next;

        current->next = prev;

        prev = current;

        current = nextnode;
    }

    *head = prev;

    printf("Student records reversed successfully.\n");
}
