//
//  main.c
//  datastructure_4_3
//
//  Created by daniel.chang on 10/04/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.
//

#include <stdio.h> //for printf and getchar
#include <time.h> // for time
#include <stdlib.h> // for rand and srand
#define ARRSIZE 3433
#include <math.h>



void PrintArr(int arr[], int n); // 為了讓以下可以用到
void InsertionSort(int arr[], int n);  // 為了讓以下可以用到



void Merge(int arr1[], int arr2[], int arr1Size, int arr2Size, int result[]) {
    int writePos = 0, readPos1 = 0, readPos2 = 0; // Key idea 1
    
    for (writePos = 0; writePos < arr1Size + arr2Size; writePos++ /*key idea 4*/) { // Key idea *
        if (arr1[readPos1] <= arr2[readPos2]) { // key idea 2
            result[writePos] = arr1[readPos1]; // key idea 3
            readPos1++; // key idea 4
            if (readPos1 == arr1Size) { //key idea 5
                /*another choice
                 for(writePos++;writePos < arr1Size + arr2Size; writePos++){
                 */
                
                writePos++;
                for (; writePos < arr1Size + arr2Size; writePos++) {
                    result[writePos] = arr2[readPos2];
                    readPos2++;
                }
            }
        }
        else {
            result[writePos] = arr2[readPos2]; // key idea 3
            readPos2++; // key idea 4
            if (readPos2 == arr2Size) { //key idea 5
                /*another choice
                 for(writePos++;writePos < arr1Size + arr2Size; writePos++){
                 */
                
                writePos++;
                for (; writePos < arr1Size + arr2Size; writePos++) {
                    result[writePos] = arr1[readPos1];
                    readPos1++;
                }
            }
        }
    }
    
}



void TestMerge() {
    int arr1[] = { 2,4,6,8,10 };
    int arr2[] = { 1,3,5,7,9 };
    int result[10];
    Merge(arr1, arr2, 5, 5, result);
    PrintArr(result, 10);
}

void TestDivideArray() {
    int arr[] = { 10,20,30,40,50,60,70,80 };
    PrintArr(arr, 3); // should print 10 20 30. arr stores the address of 10
    PrintArr(arr + 2, 4); // arr+2 is the address of 30
}


// -------





void MergeSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }
    
    
    
    MergeSort(arr, n / 2);
    MergeSort(arr + n / 2, n - n / 2);
    
    static int result[ARRSIZE];
    
    Merge(arr,     arr + n / 2,      n / 2,      n - n / 2, result);
    
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    
    
}

void TestMergeSort() {
    int arr[] = { 3,2,1 };
    MergeSort(arr, 3);
    PrintArr(arr, 3);
}



void CompareSorting() {
    int arr1[ARRSIZE];
    int arr2[ARRSIZE];
    
    srand((unsigned)time(NULL)); // use the current time as the starting point in the random table
    for (int i = 0; i < ARRSIZE; i++) {
        arr1[i] = rand() % 100; // generate a random integer from 0 to 99
        arr2[i] = arr1[i];
    }
    
    clock_t start1, end1, start2, end2;
    start1 = clock();  // current clock time
    InsertionSort(arr1, ARRSIZE);
    end1 = clock();
    
    printf("Insertion sort: %f sec\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
    //CLOCKS_PER_SEC number of clocks per second
    
    start2 = clock();
    MergeSort(arr2, ARRSIZE);
    end2 = clock();
    
    printf("Merge sort: %f sec\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
}







// MergeSortPlus 這個算是mergesort+insertionsort的版本
// 這樣做的好處是... 可以顧慮到.. 當n不大時， insertionsort會比較有利！
void MergeSortPlus(int arr[], int n) {
    if (n <= 16) {
        InsertionSort(arr, n); // insertion sort is better than merge sort when n is small
        return;
    }
    
    MergeSort(arr, n / 2); // key ideas 1 and 2
    MergeSort(arr + n / 2, n - n / 2); // key ideas 1 and 2
    
    static int result[ARRSIZE]; //int result[n] is not valid in most C complilers
    //assume n <= ARRSIZE
    //if a variable is static, this variable is created when the process
    //starts, this variable will be reused in the future
    Merge(arr, arr + n / 2, n / 2, n - n / 2, result); //key idea 3
    
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

void CompareSorting2() {
    int arr1[ARRSIZE];
    int arr2[ARRSIZE];
    
    srand((unsigned)time(NULL)); // use the current time as the starting point in the random table
    for (int i = 0; i < ARRSIZE; i++) {
        arr1[i] = rand() % 100; // generate a random integer from 0 to 99
        arr2[i] = arr1[i];
    }
    
    clock_t start1, end1, start2, end2;
    start1 = clock();  // current clock time
    MergeSortPlus(arr1, ARRSIZE);
    end1 = clock();
    
    printf("Merge sort plus: %f sec\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
    //CLOCKS_PER_SEC number of clocks per second
    
    start2 = clock();
    MergeSort(arr2, ARRSIZE);
    end2 = clock();
    
    printf("Merge sort: %f sec\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
}




int main() {
    CompareSorting2();
    //CompareSorting();
    //TestMergeSort();
    //TestDivideArray();
    //TestMerge();
    return 0;
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


