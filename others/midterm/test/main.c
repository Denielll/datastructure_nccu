//
//  main.c
//  test
//
//  Created by daniel.chang on 17/04/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////1
//double Factorial(n){
//    int c,  fact = 1;
//    
//    for (c = 1; c <= n; c++)
//        fact = fact * c;
//    return fact;
//}
//
//
//double f(int n){
//    double box = 0;
//    for(int i=1 ; i<n; i++){
//        box = box+ i/Factorial(i+1);
//    }
//    return box;
//}



////2
//
//int f(int n)
//{
//    
//    int  t, sum = 0, remainder;
//    
//    t = n;
//    while (t != 0)
//    {
//        remainder = t % 10;
//        sum       = sum + remainder;
//        t         = t / 10;
//    }
//    return sum;
//}



//3
#define ARRSIZE 5
int compare_array(int arr1[], int arr2[]){
    int sum_;
    sum_ = 0;
    for (int i = 0; i < 5; i++) {
        if(arr1[i] == arr2[i]){
            sum_ = sum_ + 1;
        }
    }
    return sum_;
}



void experiment(){
    
    int sum = 0;
    //srand((unsigned)time(NULL));
    
    
    for (int i=0; i<10; i++){
        
        
        srand((unsigned)time(NULL));
        
        
        int index_1;
        int index_2;
        
        
        
        // rand() is a generator ! 
        index_1 = rand() % 5;
        index_2 = rand() % 5;
        
        
        int arr1[] = { 0,0,0,0,0 };
        int arr2[] = { 0,0,0,0,0 };
        
        arr1[index_1] = 1;
        arr2[index_2] = 1;
        
        
        if (compare_array(arr1,arr2)==5){
            sum = sum+1;
        }
    }
    //printf("number of success for not switching: %d \n", sum);
    //printf("number of success for switching: %d \n", 1000-sum);
}












int main(){
    
    // printf("%f",f(4));    // test for exercise,1
    
    // printf("%d", f(999));   // test for exercise,2
    
    // experiment(); // test for exercise,3
    
    
    return 0;
    
    
}










