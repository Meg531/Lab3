#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char* argv[]){
	
	int length = 0;
	 scanf("%d", &length);
	
	MyStruct* array = createArray(length);

	printArray(array, length);
	printf("average: %.2lf\n", average(array, length));
	free(array);
	return 0;
}