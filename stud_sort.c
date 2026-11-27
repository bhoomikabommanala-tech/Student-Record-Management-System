#include "student.h"

void sort_student(SLL *head)
{
    SLL temp, nextnode;

    int roll;
    char name[50];
    float percentage;

    if (*head == NULL)
    {
        printf("No student records available to sort.\n");
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        nextnode = temp->next;

        while (nextnode != NULL)
        {
            if (temp->rollno > nextnode->rollno)
            {
                roll = temp->rollno;
                temp->rollno = nextnode->rollno;
                nextnode->rollno = roll;

                strcpy(name, temp->name);
                strcpy(temp->name, nextnode->name);
                strcpy(nextnode->name, name);

                percentage = temp->percentage;
                temp->percentage = nextnode->percentage;
                nextnode->percentage = percentage;
            }

            nextnode = nextnode->next;
        }

        temp = temp->next;
    }

    printf("Student records sorted successfully.\n");
}
