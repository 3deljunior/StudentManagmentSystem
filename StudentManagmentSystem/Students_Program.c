    /**  
     @brief Implements student management functions.
    * This file contains the implementations of the functions declared in
    * functions.h. These functions perform various operations on the student
    * linked list, such as adding, displaying, searching, modifying, calculating
    * GPA, and deleting students.
    *   *   *   *   *   *   *   *   *   *   *
    * @author [Youssef Adel]
    * @date [29/8/2024]
    */
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include"functions.h"
    node* Head=NULL;

    /**
     * @brief Adds a new student to the linked list.
     *
     * This function checks for duplicate IDs before adding a new student to the
     * linked list. If the ID already exists, the student is not added.
     *
     * @param std A student structure containing the ID, name, age, and GPA.
     */
    void Add_std(student std){
        node* new_node=NULL,*last=Head;
        while (last!=NULL)
        {
            if(std.id==last->std.id){
                printf("\nID Already Exists!\n");
                return;
            }
            last=last->next;
        }
        last=Head;
        new_node=(node*)malloc(sizeof(node));
        new_node->std.id=std.id;
        new_node->std.age=std.age;
        new_node->std.GPA=std.GPA;
        strcpy(new_node->std.name,std.name);
        if(Head==NULL){     // 1st Add
            Head=new_node;
            new_node->next=NULL;
            printf("\nSuccessfully Added!\n");
        }
        else{
            while (last->next!=NULL)
            {
                last=last->next;
            }
            last->next=new_node;
            new_node->next=NULL;
            printf("\nSuccessfully Added!\n");
        }   
    }

    /**
     * @brief Displays all students in the linked list.
     *
     * This function traverses the linked list and prints out the details of each
     * student, including ID, name, age, and GPA.
     */
    void Display(){
        node* current=NULL;
        current=Head;
        if(Head==NULL){
            printf("\nList is empty! \n");
            return;
        }
        while (current!=NULL)
        {
            printf("\nStudent_id is : %d",current->std.id);
            printf("\nStudent_Name is : %s",current->std.name);
            printf("\nStudent_Age is : %d",current->std.age);
            printf("\nStudent_GPA is : %0.3f\n",current->std.GPA);
            current=current->next;
        }
    } 

    /**
     * @brief Searches for a student by their ID.
     *
     * This function searches the linked list for a student with the specified ID
     * and prints their details if found.
     *
     * @param id The ID of the student to search for.
     */
    void SearchById(int id){
        node* current=NULL;
        current=Head;
        if(Head==NULL){
            printf("\nNot found ,list is empty! \n");
            return;
        }
        while (current->std.id!=id&&current->next!=NULL)
        {
            current=current->next;
        }
        if(current->std.id==id){
            printf("\nStudent_id is : %d",current->std.id);
            printf("\nStudent_Name is : %s",current->std.name);
            printf("\nStudent_Age is : %d",current->std.age);
            printf("\nStudent_GPA is : %0.3f\n",current->std.GPA);
        }
        else printf("\nID not Found! \n");
    }

    /**
     * @brief Modifies the details of a student with the specified ID.
     *
     * This function allows the user to update the ID, name, age, or GPA of a
     * student with the given ID. The user can choose which fields to update.
     *
     * @param id The ID of the student to modify.
     */
    void Modify(int id){
        node* current=Head;
        if(Head==NULL){
            printf("Not found ,list is empty! \n");
            return;
        }
        while(current->std.id!=id&&current->next!=NULL){
            current=current->next;
        }
        if(current->std.id==id){
            student std;
            int choice=0;
            printf("to update name enter 1 otherwise 0 : ");
            scanf("%d",&choice);
            if(choice==1){    
                printf("Name : ");
                while(getchar() != '\n'); // Clear the input buffer
                fgets(std.name, 50, stdin);
                std.name[strcspn(std.name, "\n")] = 0; // Remove newline character
                strcpy(current->std.name, std.name);
            }
            printf("to update Age enter 1 otherwise 0 : ");
            scanf("%d",&choice);
            if(choice==1){
                std.age=-1;
                while((std.age<=0)){
                printf("Age  : ");
                scanf("%d",&std.age);
            }
            }
            printf("to update GPA enter 1 otherwise 0 : ");
            scanf("%d",&choice);
            if(choice==1){
                std.GPA=-1;
                while((std.GPA<0||std.GPA>4)){
                printf("GPA [0,4] : ");
                scanf("%f",&std.GPA);
            }
            }
            printf("Successfully Updated!");
        }
        else 
            printf("\nThe Entered ID is not found . . .\n");
    }

    /**
     * @brief Calculates and displays the average GPA of all students.
     *
     * This function traverses the linked list to calculate the average GPA of
     * all students and prints the result.
     */
    void Avg_GPA(){
        node* current=NULL;
        current=Head;
        if(Head==NULL){
            printf("\nlist is empty! \n");
            return;
        }
        float sum=0;
        int cnt=0;
        while (current!=NULL)
        {
            sum+=current->std.GPA;
            cnt++;
            current=current->next;
        }
        printf("\nAverage GPA : %0.3f \n",sum/cnt);
    }

    /**
     * @brief Finds and displays the student with the highest GPA.
     *
     * This function searches the linked list to find the student with the maximum
     * GPA and prints their details.
     */
    void Max_GPA(){
        node* current=NULL;
        current=Head;
        if(Head==NULL){
            printf("\nlist is empty! \n");
            return;
        }
        float max=0.0;
        while (current!=NULL){
            if(max<current->std.GPA) max=current->std.GPA;
            current=current->next;
        }
        current=Head;
        while (current->std.GPA!=max&&current->next!=NULL)
        {
            current=current->next;
        }
        if(current->std.GPA==max){
        printf("\n Max GPA : %0.3f ",max);
        printf("\nStudent_id is : %d",current->std.id);
        printf("\nStudent_Name is : %s",current->std.name);
        printf("\nStudent_Age is : %d",current->std.age);
        printf("\nStudent_GPA is : %0.3f\n",current->std.GPA);
        }
    }

    /**
     * @brief Displays the pass/fail status of a student.
     *
     * This function checks the GPA of the student with the given ID and prints
     * whether the student has passed or failed.
     *
     * @param id The ID of the student to check.
     */
    void State(int id){
        node* current=NULL;
        current=Head;
        if(Head==NULL){
            printf("\nNot found ,list is empty! \n");
            return;
        }
        while (current->std.id!=id&&current->next!=NULL)
        {
            current=current->next;
        }
        if(current->std.id==id){
            printf(current->std.GPA>=2?"\nPassed\n":"\nFailed\n"); 
        }
        else printf("\nID not Found! \n");
    }


    /**
     * @brief Deletes a student from the linked list.
     *
     * This function removes the student with the specified ID from the linked list
     * and frees the allocated memory.
     *
     * @param id The ID of the student to delete.
     */
    void Delete(int id){
        node* previuos=NULL,*current=NULL;
        previuos=Head;
        current=Head;
        if(Head==NULL) printf("\nNot found ,list is empty!\n");
        else{
            if(Head->std.id==id){  // 1st element
                Head=Head->next;
                free(current);
                printf("\nSuccessfully Deleted\n");
                return;
                }
            while(current->std.id!=id&&current->next!=NULL){ //&&current!=NULL
                previuos=current;
                current=current->next;
            }
            if(current->std.id==id){
                previuos->next=current->next;
                free(current);
                printf("\nSuccessfully Deleted\n");
            }
            else
                printf("\nThe Entered ID is not found . . .\n");
        }
    }