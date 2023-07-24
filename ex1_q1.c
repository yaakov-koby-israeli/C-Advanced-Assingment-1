// Course: Advanced C programming
// exercise 1, question 1
// file name: ex1_q1.c
#define _CRT_SECURE_NO_WARNINGS
// --------------------------- //
// include package section:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------- //
//
//	Assigned by:
//		Student1_Full_Name Bar Brener #ID 207703026
//		Student2_Full_Name Yaakov Israeli #ID 208196816
//
// --------------------------- //

// function declarations section:
int* scanArray(int*);
void printArray(int*, int);
int arrangeArray(int**, int);

// --------------------------- //

// main section:
// DO NOT CHANGE the following function:
int main()
{
	int* arr, n, k;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	arr = scanArray(&n);
	k = arrangeArray(&arr, n);

	// write output:
	printf("Output:\n");
	printf("Size of k: %d\n", k);
	printf("Sorted array:\n");
	printArray(arr, n);
	free(arr);

	return 0;
}
// --------------------------- //


// DO NOT CHANGE the following function:
int* scanArray(int* n)
{
	int i;
	int* arr;

	printf("Enter array size: ");
	scanf("%d", n);

	arr = (int*)malloc(sizeof(int) * (*n));
	for (i = 0; i < *n; ++i)
	{
		printf("Enter value #%d: ", i + 1);
		scanf("%d", arr + i);
	}

	return arr;
}
// --------------------------- //


// DO NOT CHANGE the following function:
void printArray(int* arr, int n)
{
	int i;
	printf("{");
	for (i = 0; i < n; ++i)
		printf("%d%s", arr[i], i == n - 1 ? "" : ", ");
	printf("}\n");
}
// --------------------------- //

/// <summary>
/// Combine the two groups using realloc and memcpy only. 
/// </summary>
/// <param>int **arr - Address of the array pointer</param>
/// <param>int n - Size of the array</param>
/// <returns>Size of the first group</returns>
int arrangeArray(int** arr, int n)
{
	// your code:
	int i, k = 0;
	for (i = 0; i < n - 1; i++) {
		if ((*arr)[i] > (*arr)[i + 1]) {
			k = i + 1;
			break;
		}
	}

	int* newArr = (int*)realloc((*arr), (n + k) * sizeof(int));
	if (!newArr) return 0;
	memcpy(newArr + n, newArr, sizeof(int) * k);
	memcpy(newArr, newArr + k, sizeof(int) * n);
	(*arr) = (int*)realloc(newArr, n * sizeof(int));
	if (!(*arr)) return 0;
	newArr = NULL;
	return k;
	
}
// --------------------------- //