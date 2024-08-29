/**
 * @file main.c 
 * @brief Main entry point for the  >>>    Student Management System
 *
 * This file contains the main function, which provides a menu-driven interface
 * for interacting with the student management system. The user can add, display,
 * search, modify, calculate average GPA, find the maximum GPA, check the student's
 * pass/fail status, and delete student records.
 *
 * @author [Youssef Adel]
 * @date [29/8/2024]
 */

#include<stdio.h>
#include<string.h>
#include"functions.h"

/**
 * @brief main function to display the menu and handle user input.
 * 
 * The main loop presents the user with a menu of options. The user can 
 * choose different actions related to student management.
 *
 * @return int Returns 0 upon successful execution.
 */
int main(){
    int choice=1;
    printf("\t\t\t\t\t--------------Student Managment System-------------- \n");
    while (choice)   
    {
        printf(
         "\n 1 - Add Student \n"
         "---------------------------"
         "\n 2 - Display Students_list\n"
         "---------------------------"
         "\n 3 - Search By_Id\n"
         "---------------------------"
         "\n 4 - Modify Student Data\n"
         "---------------------------"
         "\n 5 - Calc Avg_GPA \n"
         "---------------------------"
         "\n 6 - MAX GPA \n"
         "---------------------------"
         "\n 7 - Show Student_State\n"
         "---------------------------"
         "\n 8 - delete Student_By_Id\n"
         "---------------------------"
         "\n 0 - Exit\n"
         "------------------------------------------------------"
        );
        printf("\nPlease ,Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            printf("\n\t\t\tThank You!\n");
            return 0;
        case 1:
            {
            student std;
            std.GPA=-1;
            std.age=-1;
            printf("ID : ");
            scanf("%d",&std.id);
            printf("Name : ");
            scanf("%s",std.name);
            while((std.age<=0)){
                printf("Age  : ");
                scanf("%d",&std.age);
            }

            while((std.GPA<0||std.GPA>4)){
                printf("GPA [0,4] : ");
                scanf("%f",&std.GPA);
            }
            Add_std(std);
            }
            break;
        case 2:    
            Display(); 
            break;
        case 3:
            {
            int id;
            printf("Plz Enter Student_ID to Fetch its data : ");
            scanf("%d",&id);
            SearchById(id);
            }
            break;
        case 4:
            {
            int id;
            printf("Plz Enter Student_ID to Modify data : ");
            scanf("%d",&id);
            Modify(id);
            }
            break;
        case 5:
            Avg_GPA();
            break;
        case 6:
            Max_GPA();
            break;
        case 7:
            {
            int id;
            printf("Plz Enter Student_ID to Fetch its State : ");
            scanf("%d",&id);
            State(id); 
            }
            break;
        case 8:
            {
            int id;
            printf("Plz Enter id to be Deleted : ");
            scanf("%d",&id);
            Delete(id);
            }
            break;
        default:
            printf("Invalid Input !! Plz try Again...\n");
                break;
        }                
    }
    return 0;
}