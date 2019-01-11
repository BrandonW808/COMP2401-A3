#ifndef _student_H
#define _student_H
 
#include "student.c"

//Define the functions to get student variables
unsigned int getGPA(struct person p);
unsigned int getNumCourses(struct person p);
float getTuitionFees(struct person p);

//Declare the print and search functions
void printStu(struct person p);
void printAllStus(struct person person[], int NUM_RECORDS);
void searchStu(char name[], int MAX_NAME_SIZE, struct person person[], int NUM_RECORDS);
 
#endif
