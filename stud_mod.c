#include "student.h"

void modify_student(SLL head)
{
    SLL temp;
    int choice, roll;
    char name[50];
    float percentage;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");

    printf("Enter your choice: ");
    scanf(" %c", (char *)&choice);

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);

        temp = head;

        while (temp != NULL && temp->rollno != roll)
            temp = temp->next;
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter student name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        while (temp != NULL && strcmp(temp->name, name) != 0)
            temp = temp->next;

        if (temp != NULL)
            printf("Roll No: %d  Name: %s\n", temp->rollno, temp->name);

        if (temp != NULL)
        {
            printf("Enter roll number to modify: ");
            scanf("%d", &roll);

            temp = head;

            while (temp != NULL &&
                   (temp->rollno != roll || strcmp(temp->name, name) != 0))
                temp = temp->next;
        }
    }
    else if (choice == 'P' || choice == 'p')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);

        temp = head;

        while (temp != NULL && temp->percentage != percentage)
            temp = temp->next;
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    if (temp == NULL)
    {
        printf("Student record not found.\n");
        return;
    }

    printf("\nCurrent Student Details:\n");
    printf("Roll Number: %d\n", temp->rollno);
    printf("Name: %s\n", temp->name);
    printf("Percentage: %.2f\n", temp->percentage);

    printf("\nEnter new name: ");
    scanf(" %49[^\n]", temp->name);

    printf("Enter new percentage: ");
    scanf("%f", &temp->percentage);

    printf("Student record modified successfully.\n");
}
