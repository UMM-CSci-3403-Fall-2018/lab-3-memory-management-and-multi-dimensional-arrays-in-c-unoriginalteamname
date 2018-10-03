#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_merge.h"
#include "mergesort.cpp"

//check if value is in array
bool checkValue(int num, int* arr, int size){
	int i;
	for(i = 0; i < size; i++){
		if(arr[i] == num)
			return true;
	}
	return false;
}

void printArray(int size, int* arr) {
	for (int i=0; i<size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int* array_merge(int num_arrays, int* sizes, int** values){
	int i;
	int j;
	int n = 0;
	for(i = 0; i < num_arrays; i++){
		n = n + sizes[i];
	}

	int arr[n];
	int uniqueElements = 0;
	int count = 0;

	//fill an array with unique values, count the number of unique values
	for(i = 0; i < num_arrays; i++){
		int x = sizes[i];
		for(j = 0; j < x; j++){
			int check = values[i][j];
			bool boolean = checkValue(check, arr, count);
			if(boolean == false){
				uniqueElements++;
				arr[count] = check;
				count++;
			}
		}
	}

	//create array of exact size, set first element to # of elements
	int finalsize = uniqueElements + 1;
	int *returnArr = (int *)malloc(finalsize * sizeof(int));
	//int* returnArr;
	//returnArr = (int*) calloc(x,sizeof(int));
	returnArr[0] = uniqueElements;
	//printf("array:");
	//printArray(finalsize, returnArr);

	for(i = 1; i < finalsize; i++){
		returnArr[i] = arr[i - 1];
	}


  mergesortRange(returnArr, 1, finalsize);
	return returnArr;
}
