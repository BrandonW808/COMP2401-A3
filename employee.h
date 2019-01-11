#ifndef _employee_H
#define _employee_H

#include "employee.c"
     
//Declare the functions to get employee variables
unsigned int getYearsService(struct person p);
float getSalary(struct person p);
unsigned int getLevel(struct person p);

//Declare the functions to print employees
void printEmp(struct person p);
void printAllEmps(struct person person[], int NUM_RECORDS);
 
#endif
