#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"
#include "populateRecords.h"
#include "student.h"
#include "employee.h"

#define NUM_RECORDS 20
#define MAX_NAME_SIZE 33
#define QUIT_SIZE 2

//Initialize the menu function
int menu(){
	//Print the menu
	printf("\n");
	printf("MENU\n");
	printf("1 | Print all employees.\n");
	printf("2 | Print all students.\n");		
	printf("3 | Search students using family name.\n");
	printf("4 | Summary of data.\n");
	printf("0 | Quit.\n");
	printf("Choose an Option: ");
	//Scan for input and ensure it's an integer
	char *p, s[100];
	int option;
	while (fgets(s, sizeof(s), stdin)){
		option = strtol(s, &p, 10);
		if (p == s || *p != '\n'){
			//If its not, ask them to enter a valid integer
			printf("Please enter a valid integer: ");
		}else break; 
	}
	//Print a space
	printf("\n");
	//Return the choice
	return option;
}

//Initialize a function to print all records
void printRecords(struct person person[]){
	//Start variables to save & print data
	float stuCount = 0;
	float empCount = 0;
	float gpaAvrg = 0;
	float feeAvrg = 0;
	float courseAvrg = 0;
	float salaryAvrg = 0;
	int minLvl;
	int maxLvl = 0;
	float yearsAvrg = 0;
	printf("Printing records... \n");
	//Print the number of records
	printf("%s%d\n", "Total number of records: ", NUM_RECORDS);
	printf("\n");
	//For all records
	for (int i=0; i<NUM_RECORDS; i++){
		//If the person is an employee
		if (person[i].emplyeeOrStudent == 0){
			//Add one employee to out employee count and add the salary and years spent to the average variables
			empCount += 1;
			salaryAvrg += getSalary(person[i]);
			//If this employee's level is the smallest we've seen, save it to minLvl
			if (minLvl > getLevel(person[i])) { minLvl = getLevel(person[i]); }
			//If this employee's level is the largest we've seen, save it to maxLvl
			if (maxLvl < getLevel(person[i])) { maxLvl = getLevel(person[i]); }
			yearsAvrg += getYearsService(person[i]);
		//If the person is a student
		}else { 
			//add to stuCount, add the gpa, course number, and tuition fees to their respective avrg variables
			stuCount += 1; 
			gpaAvrg += getGPA(person[i]);
			courseAvrg += getNumCourses(person[i]);
			feeAvrg += getTuitionFees(person[i]);
		}
	}
	//Divide the averages by the stuCount or empCount
	gpaAvrg = gpaAvrg / stuCount;
	courseAvrg = courseAvrg / stuCount;
	feeAvrg = feeAvrg / stuCount;
	yearsAvrg = yearsAvrg / empCount;
	salaryAvrg = salaryAvrg / empCount;

	//Print the data we collected with proper formatting
	printf("Student Stats:\n");
	printf("%s%2.0f\n", "Number of students: ", stuCount);
	printf("%s%2.2f%s%2.2f%s%4.2f\n", "Average GPA: ", gpaAvrg, " Average Number of courses: ", courseAvrg, " Average Tuition Fees: ", feeAvrg);
	printf("\n");
	printf("Employee Stats:\n");
	printf("%s%2.0f%s%2d%s%d\n", "Number of employees: ", empCount, " Min Level: ", minLvl, " Max Level: ", maxLvl);
	printf("%s%2.2f%s%5.2f\n", "Average Years of Service: ", yearsAvrg, " Average Salary: ", salaryAvrg);
}

int main()
{
    	struct person person[NUM_RECORDS];

    	populateRecords(person, NUM_RECORDS);

	//Start some variables for the case statement
	int done = 0;
	int option;
	char quit[QUIT_SIZE];
	char name[MAX_NAME_SIZE];
	//While we aren't done
	while (done == 0){
		//Save the option choosen into variable option
		option = menu();
		//Error trap to ensure option is a integer in the proper range, if not ask for a new choice
		while (option > 4 || option < 0){  
			printf("%d%s\n", option, " is not a valid menu option. Please choose again: ");
			option = menu();
			if (option <= 4 && option >= 0) break;
		}

		switch(option){
			case 0:
				//Quit the application if option is 0 and the user follows up with 'y'
				printf("Quit Application?(y/n): ");
				scanf("%s", quit);
				if (strcmp(quit, "y") == 0) { done = 1; }
				break;
			case 1:
				//Print all the employees
				printAllEmps(person, NUM_RECORDS);
				break;
			case 2:
				//Print all the students
				printAllStus(person, NUM_RECORDS);
				break;
			case 3: 
				//Ask for a family name to search
				printf("Enter a family name to search: ");
				scanf("%s", name);
				//Search students for the right name
				searchStu(name, MAX_NAME_SIZE, person, NUM_RECORDS);
				break;
			case 4:
				//Print all the records
				printRecords(person);
		
		}
			
	};

    	return 0;
}

