#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct MyStruct {
	
	int zero;
	int value; 
} MyStruct;



//Three function prototypes
double average(MyStruct array[], int length);



MyStruct* createArray (int length);


void printArray(MyStruct array[], int length);

#endif