#include <stdio.h>

#include "employee.h"

//Code functions to get data outside of employee.c
unsigned int getYearsService(struct person p){ return p.type.emp.yearsService; }
float getSalary(struct person p){ return p.type.emp.salary; }
unsigned int getLevel(struct person p){ return p.type.emp.level; }

//Code to print a single employee
void printEmp(struct person p){
	//Start a temporary string to store first and family name in
	char buffer[33];
	//Put first name and family name in variable buffer
	sprintf(buffer, "%s %s", p.firstName, p.familyName);
	//Print the employee with proper formatting
	printf("%-33s%s%3u%s%3u%s%6.2f\n", buffer, " Years:", p.type.emp.yearsService, " Level:", p.type.emp.level, " Salary: ", p.type.emp.salary);
}

//Code to print all employees
void printAllEmps(struct person person[], int NUM_RECORDS){
	//For the amount of records there are
	for (int i=0; i<NUM_RECORDS; i++){
		//If the person is an employee
		if (person[i].emplyeeOrStudent == 0){ 
			//Print the employee
			printEmp(person[i]);
		}
	}
}
