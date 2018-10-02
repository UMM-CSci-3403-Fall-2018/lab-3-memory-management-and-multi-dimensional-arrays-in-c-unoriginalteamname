#include <stdio.h>
#include <stdlib.h>
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){

        int* concatArrs(){
                int i;
                int n = 0;
                for(i = 0; i <= num_arrays; i++){
                        n = n + sizes[i];
                }

                int arr[n];

                int j;
                for(i = 0; i < num_arrays; i++){
                        int x = sizes[i];
                        int count = 0;
                        for(j = 0; j < x; j++){
                                arr[count] = values[x][j];
                                count++;
                        }
                }

