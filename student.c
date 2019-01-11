#include <stdio.h>
#include "student.h"

#define RESPONSE_SIZE 2

//Code functions to get data outside of student.c
unsigned int getGPA(struct person p){ return p.type.stu.gpa; }
unsigned int getNumCourses(struct person p){ return p.type.stu.numCourses; }
float getTuitionFees(struct person p){ return p.type.stu.tuitionFees; }

//Code to print a single student
void printStu(struct person p){
	//Start a temporary string to store first and family name in
	char buffer[33];
	//Put first name and family name in variable buffer
	sprintf(buffer, "%s %s", p.firstName, p.familyName);
	//Print the student with proper formatting
	printf("%-33s%s%3u%s%3u%s%5.2f\n", buffer, " GPA: ", p.type.stu.gpa, " Courses: ", p.type.stu.numCourses, " Tuition Fees: ", p.type.stu.tuitionFees);
}

//Code to print all students
void printAllStus(struct person person[], int NUM_RECORDS){
	//For the amount of records there are
	for (int i=0; i<NUM_RECORDS; i++){
		//If the person is a student
		if (person[i].emplyeeOrStudent != 0){ 
			//Print the student
			printStu(person[i]);
		}
	}
}

//Code to search students by family name
void searchStu(char name[], int MAX_NAME_SIZE, struct person person[], int NUM_RECORDS){
	//Declare a variable to determine if we've found a student or not
	int found = 0;
	//For all records
	for (int i=0; i<NUM_RECORDS; i++){
		//If the person is a student
		if (person[i].emplyeeOrStudent != 0){
			//If the family name matches
			if (strcmp(name, person[i].familyName) == 0){
				//Print the student with the matching name
				printStu(person[i]);
				found = 1;
			}
		}
	}
	//If we didn't find anyone, let the user know
	if (found == 0){
		printf("Couldn't find a student with the entered family name, try again?(y/n): ");
		char response[RESPONSE_SIZE];
		scanf("%s", response);
		if (strcmp(response, "y") == 0) { 
			//Ask for a family name to search
			printf("\nEnter a family name to search: ");
			scanf("%s", name);
			//Search students for the right name
			searchStu(name, MAX_NAME_SIZE, person, NUM_RECORDS);
		}
	}
}
