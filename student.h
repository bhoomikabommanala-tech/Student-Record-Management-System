#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;

} *SLL;



void add_student(SLL *head);
void delete_student(SLL *head);
void show_student(SLL head);
void modify_student(SLL head);
void save_student(SLL head);
void load_student(SLL *head);
void sort_student(SLL *head);
void delete_all(SLL *head);
void reverse_student(SLL *head);

#endif
