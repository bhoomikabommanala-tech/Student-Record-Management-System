#include "student.h"

void add_student(SLL *head)
{
    SLL newnode, temp;
    int roll = 1;

    newnode = malloc(sizeof(struct student));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    while (1)
    {
        temp = *head;

        while (temp != NULL)
        {
            if (temp->rollno == roll)
                break;

            temp = temp->next;
        }

        if (temp == NULL)
            break;

        roll++;
    }

    newnode->rollno = roll;

    printf("Enter student name: ");
    scanf(" %[^\n]", newnode->name);

    printf("Enter percentage: ");
    scanf("%f", &newnode->percentage);

    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Student record added successfully..\n");
    printf("Assigned Roll Number: %d\n", roll);
}
