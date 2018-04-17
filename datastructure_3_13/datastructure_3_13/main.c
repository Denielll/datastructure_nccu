//
//  main.c
//  datastructure_3_13
//
//  Created by daniel.chang on 13/03/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.
//
//
//
//
////1,array
////  array只會傳第一個 element 的位置 ( C的特性 )
//#include <stdio.h>
//
//double AVG(int score[5]){
//    
//    double sum = 0;
//    
//    for (int i=0; i<5; i++){
//        sum += score[i];  // double + int 是可以的. 最後會變成 double
//    }
//    
//    return sum/5.0;
//}
//
//
//// 解決  overflow的問題 ( 全部相加/個數 ) 之方法
//double AVG2(int score[5]){
//    
//    double currentAVG = 0;
//    
//    for (int i=0; i<5; i++){
//        currentAVG = currentAVG*(i/(i+1))+ (double)(score[i])/(i+1);
//    }
//    
//    return currentAVG;
//}
//
//int main(){
//    int score[5] = {60,70,80,90,100};
//    //score[0] == 60
//    
//    for (int i=0; i<5;i++){
//        printf("score[%d] = %d\n",i, score[i]);
//    }
//    printf("AVF = %f\n", AVG(score));
//    
//    getchar();
//    return 0;
//}
//
//
//
//// 2,2048棋盤
//#include <stdio.h>
//
//void PrintBoard(int board[][4], int n){
//    for (int i=0; i<n; i++){
//        for(int j=0; j<4; j++){
//            printf("%d ", board[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//
//
//int main(){
//    int M[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16}};
//    PrintBoard(M,4);
//    return 0;
//}
//
//
//
////3, 對 M[i][j] 來說，先i再j 會比 先j再i快！ ( 跟 排序 有關 )
////   換句話說, 比較 先row再column ＆ 先column再row 哪個快
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//#define SIZEX 100
//#define SIZEY 100
//
//
//void Sum1(int M[SIZEX][SIZEY]) {
//    double sum = 0;
//    
//    for (int i = 0; i < SIZEX; i++) {
//        for (int j = 0; j < SIZEY; j++) {
//            sum += M[i][j];
//        }
//    }
//    return; // not necessary
//}
//
//
//void Sum2(int M[SIZEX][SIZEY]) {
//    double sum = 0;
//    
//    for (int j = 0; j < SIZEY; j++) {
//        for (int i = 0; i < SIZEX; i++) {
//            sum += M[i][j];
//        }
//    }
//    return; // not necessary
//
//}
//
//int main(){
//    
//    // just to randomly produce values for M2 for the example below
//    int M2[SIZEX][SIZEY];
//    for (int i = 0; i < SIZEX; i++) {
//        for (int j = 0; j < SIZEY; j++) {
//            M2[i][j] = i + j;
//        }
//    }
//    
//    clock_t start1, start2, end1, end2, totalTime1 = 0, totalTime2 = 0;
//    for (int i = 0; i < 10; i++) {
//        start1 = clock();
//        Sum1(M2);
//        end1 = clock();
//        totalTime1 += end1 - start1;
//        
//        start2 = clock();
//        Sum2(M2);
//        end2 = clock();
//        totalTime2 += end2 - start2;
//    }
//    printf("sum1: %f, sum2: %f\n", (float)totalTime1 / CLOCKS_PER_SEC,
//           (float)totalTime2 / CLOCKS_PER_SEC);
//    
//    return 0;
//}
//
//
//
////4, modify array
//#include <stdio.h>
//#include <math.h>
//
//void Modify(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        arr[i] = 10.0 * sqrt(arr[i]);
//    }
//}
//
//
//int main(){
//    int s[5] = { 36, 36, 36, 36, 60 };
//    printf("Before: ");
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", s[i]);
//    }
//    printf("\n");
//    
//    Modify(s, 5);
//    printf("After: ");
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", s[i]);
//    }
//    printf("\n");
//    getchar();
//    
//    return 0;
//}
//
//
//
////5, struct 是使用者自訂的型態
//#include <stdio.h>
//#define SIZEX 10000
//#define SIZEY 10000
//
//
//struct student {
//    int id;
//    double score;
//};
//
//
//typedef struct student S;
//typedef double D;
//
//
//void PrintStudent(S s) { //int i
//    printf("id: %d, score: %f\n", s.id, s.score);
//}
//
//
//int main(){
//    //D d = 3.0;
//    S Peter;
//    // S Jane;
////    S studentList[100];
////    struct student SL[100];
////    
////    for (int i = 0; i < 100; i++) {
////        studentList[i].id = i;
////        SL[i].id = i;
////    }
//    Peter.id = 100;
//    Peter.score = 90;
//    PrintStudent(Peter);
//    //PrintStudent(Jane);
//    
//}
//
//
//
////6, 比較 array和non-array 在丟到function執行時的速度差
////   原因： array丟給function時，實際上給的是第一個element的記憶體位置，而不是全部東西！所以 會比較快。（不用等到丟完全部東西，function才開始執行
//#include <stdio.h>
//#include <time.h>
//#define SIZEX 100
//#define SIZEY 100
//
//
//struct t {
//    int M[SIZEX][SIZEY];
//};
//typedef struct t T;
//
//
//void f1(T t) {
//    return;
//}
//void f2(int M[SIZEX][SIZEY]) {
//    return;
//}
//
//
//int main() {
//    
//    clock_t start1, start2, end1, end2, totalTime1 = 0, totalTime2 = 0;
//    
//    int M2[SIZEX][SIZEY];
//    T t;  // declare t
//    
//    for (int i = 0; i < 1000; i++) {
//        start1 = clock();
//        f1(t);
//        end1 = clock();
//        totalTime1 += end1 - start1;
//        
//        start2 = clock();
//        f2(M2);
//        end2 = clock();
//        totalTime2 += end2 - start2;
//    }
//    printf("f1: %f, f2: %f\n", (float)totalTime1 / CLOCKS_PER_SEC,
//           (float)totalTime2 / CLOCKS_PER_SEC);
//
//}
//
//
