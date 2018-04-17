#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
//#include <conio.h> // for getting user input, _getch
//for MAC user, go to https://stackoverflow.com/questions/7469139/what-is-equivalent-to-getch-getche-in-linux
// google keyword: clear terminal C

void PrintArr(int arr[], int n);

void BubbleSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				//Swap(arr, j+1, j);

			}
			//PrintArr(arr, n);
			//getchar();
		}
	}
}









int FindMaxPos(int arr[], int n) {
	int max = arr[0];
	int maxPos = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxPos = i;
		}
	}

	return maxPos;
}

void Swap(int arr[], int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void MySort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int maxPos = FindMaxPos(arr, n - i);
		/* find the position of the max number between arr[0] and arr[n-i-1]*/
		Swap(arr, maxPos, n-i-1);
		/* swap arr[maxPos] and arr[n-i-1]*/
	}
}














void InsertionSort(int arr[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j]>temp; j--) {
			arr[j + 1] = arr[j];
			//printf("    ");PrintArr(arr, n);
			//getchar();
		}
		arr[j + 1] = temp;
		//PrintArr(arr, n);
		//getchar();
	}
}




void PrintArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr1[SIZE], arr2[SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		arr1[i] = rand() % 100;
		arr2[i] = arr1[i];
	}
	//PrintArr(arr1, SIZE);
	//InsertionSort(arr1, SIZE);




	clock_t start1 = clock();
	InsertionSort(arr1, SIZE);
	clock_t end1 = clock();
	printf("bubble sort: %f sec\n", (float)(end1 - start1) / CLOCKS_PER_SEC );

	clock_t start2 = clock();
	MySort(arr2, SIZE);
	clock_t end2 = clock();
	printf("MySort: %f sec\n", (float)(end2 - start2) / CLOCKS_PER_SEC);

	getchar();
	/*
	clock_t start = clock();
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;*/


	/*PrintArr(arr, SIZE);
	MySort(arr, SIZE);
	PrintArr(arr, SIZE);*/





	/*printf("please press any key\n");
	char c = _getch();

	printf("you just pressed %c\n", c);*/

	getchar();
}