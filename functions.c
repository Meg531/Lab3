#include <stdio.h>
#include <stdlib.h>

#include "functions.h"


double average(MyStruct array[], int length){
	double sum = 0.0;
	double avg = 0.0;
	 for(int i=0; i< length; ++i){
		 sum += array[i].value;
		
	 }
	 avg = sum/length;
	 return avg;
}

MyStruct* createArray(int length){
	
	
	 MyStruct* array = (MyStruct*)malloc(length * sizeof(MyStruct));
	 
	for(int i=0; i<length; ++i){
		array[i].zero =0;
		array[i].value = i;
	}
	return array;
}

void printArray(MyStruct array[], int length){
	for(int i = 0; i < length; ++i){
		printf("%d %d\n", array[i].zero, array[i].value);
	}
}


tyoedef struct Point 

{
int x;
int y;
}
Point1;
Point2;

point1 = x1, y2;
if(

point2 = x2, y1;

solveEquation((x1*y2)+-sqrt(x2+y1));

sqrt

if(result<0)
x =0;
y=0
else(*y
scanf("%s, 

