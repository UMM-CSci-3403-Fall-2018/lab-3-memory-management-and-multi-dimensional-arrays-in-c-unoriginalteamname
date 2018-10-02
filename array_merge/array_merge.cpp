#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_merge.h"

//check if value is in array
bool checkValue(int num, int* arr, int size){
	int i;
	for(i = 0; i < size; i++){
		if(arr[i] == num)
			return true;
	}
	return false;
}

int* array_merge(int num_arrays, int* sizes, int** values){
	int i,j;
	int n = 0;
	for(i = 0; i <= num_arrays; i++){
		n = n + sizes[i];
	}

	int arr[n];
	int uniqueElements = 0;
	int count = 0;

	//fill an array with unique values, count the number of unique values
	for(i = 0; i < num_arrays; i++){
		int x = sizes[i];
		for(j = 0; j <= x; j++){
			if(checkValue(values[x][j], arr, n) == false){
				uniqueElements = uniqueElements + 1;
				arr[count] = values[x][j];
				count++;
			}
		}
	}

	//create array of exact size, set first element to # of elements
	int x = uniqueElements + 1;
	int* returnArr;
	returnArr = (int*) calloc(x,sizeof(int));
	returnArr[0] = uniqueElements;

	for(i = 1; i <= x; i++){
		returnArr[i] = arr[i - 1];
	}

	return returnArr;
}
