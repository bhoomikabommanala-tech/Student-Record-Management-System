#include "student.h"

void show_student(SLL head)
{
    SLL temp;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    temp = head;

    printf("\nRoll No.\tName\t\tPercentage\n");

    while (temp != NULL)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }
}
