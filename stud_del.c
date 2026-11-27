#include "student.h"

void delete_student(SLL *head)
{
    SLL temp, prev;
    int choice, roll;
    char name[50];

    if (*head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter your choice: ");
    scanf(" %c", (char *)&choice);

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter student name: ");
        scanf(" %[^\n]", name);

        temp = *head;

        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
                printf("Roll No: %d  Name: %s\n", temp->rollno, temp->name);

            temp = temp->next;
        }

        printf("Enter roll number to delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    temp = *head;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->rollno == roll)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Student record deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Student record not found.\n");
}
