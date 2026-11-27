#include"student.h"

void delete_all(SLL *head)
{
    SLL temp;

    if (*head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;

        free(temp);
    }

    printf("All student records deleted successfully.\n");
}
