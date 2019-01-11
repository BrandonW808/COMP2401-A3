#ifndef _struct_H
#define _struct_H

#define NAME_SIZE 16
#define TELEPHONE_SIZE 11

//Pack the student structure
struct student{    
	unsigned int gpa:4;
	unsigned int numCourses:6;
	float tuitionFees;
};
//Pack the employee structure
struct employee{ 
	unsigned int yearsService:7;
	float salary;
	unsigned int level:4;
};
//Pack the union that dictates whether a person is an employee or student
union role{
	struct student stu;
	struct employee emp;
};
//Pack the person structure
struct person{
	char firstName[NAME_SIZE];
    	char familyName[NAME_SIZE];
    	char telephone[TELEPHONE_SIZE];
	int emplyeeOrStudent:1;
	union role type;
};

#endif
 

