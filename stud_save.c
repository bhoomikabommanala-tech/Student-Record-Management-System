#include "student.h"

void save_student(SLL head)
{
    FILE *fp;
    SLL temp;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("File opening failed!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fprintf(fp, "%d %s %f\n",
                temp->rollno,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("Student records saved successfully.\n");
}


void load_student(SLL *head)
{
    FILE *fp;
    SLL newnode, temp;

    int roll;
    char name[50];
    float percentage;

    fp = fopen("student.dat", "r");

    if (fp == NULL)
        return;

    while (fscanf(fp, "%d %49s %f",
                  &roll, name, &percentage) == 3)
    {
        newnode = malloc(sizeof(struct student));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            break;
        }

        newnode->rollno = roll;
        strcpy(newnode->name, name);
        newnode->percentage = percentage;
        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            temp = *head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fclose(fp);
}
