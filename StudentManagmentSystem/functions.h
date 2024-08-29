/**
 * @file functions.h
 * @brief Header file for student management functions.
 *
 * This file contains the declarations of the student management functions
 * and data structures used in the program.
 *
 * @author [Youssef Adel]
 * @date [29/8/2024]
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h> 
typedef struct student {
    int id;
    char name[50];
    int age;
    float GPA;
} student;

typedef struct node {
    student std;
    struct node* next;
} node;

void Add_std(student std);
void Display();
void SearchById(int id);
void Modify(int id);
void Avg_GPA();
void Max_GPA();
void State(int id);
void Delete(int id);

#endif // FUNCTIONS_H