//
//  main.c
//  datastructure_3_27
//
//  Created by daniel.chang on 27/03/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.
//






//// 1, 講一下下一次作業，讓HW1的棋盤可以用上,下,左,右 去更新棋盤
//#include <stdio.h>
////#include <conio.h>  // windows專用，讓程式可以接受鍵盤輸入，mac專用要另外找
//// 除此之外，要找一下 clear terminal C
//
//
//int main() {
//    
//    
//    printf("Hello, World!\n");
//    char c = _getch();
//    return 0;
//    
//    printf("u just pressed %c \n", c);
//    getchar();
//    
//}





//// 2-1, array sorting。有很多種不同的sorting方式。可以比較這些分別用的時間
////    但這些的時間複雜度都是O(n^2)
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define SIZE 10
//
//void PrintArr(int arr[], int n); // 為了讓 bubbleSort裡的PrintArr找得到位置
//
//
//
//// logic:
//// 5,4,3,2,1
//// 4,5,3,2,1
//// 4,3,5,2,1
//// 4,3,2,5,1
//// 4,3,2,1,5
//void bublleSort(int arr[], int n ){
//    int i,j,temp;
//    for(i=0; i<n-1;i++){
//        for (j=0;j<n-1-i; j++){
//            if (arr[j] >arr[j+1]){
//                temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//                
//            }
//            //PrintArr(arr,n);
//            //getchar();
//            
//        }
//    }
//}
//
//
//void PrintArr(int arr[], int n){
//    for (int i =0; i<n ; i++){
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//}
//
//
//int main(){
//    
//    int arr[SIZE];
//
//    for (int i=0; i<SIZE; i++){
//
//        //srand(time(NULL));  // 每次執行時，重新找一個亂數起始值。讓每次執行時時間都不同
//        arr[i] = rand() %100 ; // 確保出來的數字是0~99
//    }
//    PrintArr(arr, SIZE);
//    bublleSort(arr, SIZE);
//    PrintArr(arr, SIZE);
//    
//    return 0;
//
//}







//// 2-2, array sorting。有很多種不同的sorting方式。可以比較這些分別用的時間
////    但這些的時間複雜度都是O(n^2)
//
//// logic:
//// 找到最大，然後跟 盡量是最後一個位置交換
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define SIZE 10
//
//int FindMaxPos(int arr[], int n){
//    int max = arr[0];
//    int maxPos = 0;
//
//    for (int i=1 ; i<n; i++){
//        if(arr[i]>max){
//            max = arr[i];
//            maxPos = i;
//        }
//    }
//    return maxPos;
//}
//
//
//void Swap(int arr[], int pos1, int pos2){
//    int temp = arr[pos1];
//    arr[pos1] = arr[pos2];
//    arr[pos2] = temp;
//}
//
//void MySort(int arr[], int n){
//    for(int i =0; i<n; i++){
//        int maxPos = FindMaxPos(arr, n-i);
//        Swap(arr, maxPos, n-i-1);
//        
//    }
//}
//
//
//
//void PrintArr(int arr[], int n){
//    for (int i =0; i<n ; i++){
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//
//
//int main(){
//    int arr[SIZE];
//    
//    for (int i=0; i<SIZE; i++){
//        
//        //srand(time(NULL));  // 每次執行時，重新找一個亂數起始值。讓每次執行時時間都不同
//        arr[i] = rand() %100 ; // 確保出來的數字是0~99
//    }
//    PrintArr(arr, SIZE);
//    MySort(arr, SIZE);
//    PrintArr(arr, SIZE);
//    
//    return 0;
//    
//}




////// 2-3, array sorting。有很多種不同的sorting方式。可以比較這些分別用的時間
//////    但這些的時間複雜度都是O(n^2)
//// logic:
//// insertion sort。像是玩大老2整理手牌的時候
//// 概念是利用另一個數列來存放已排序部分，逐一取出未排序數列中元素，從已排序數列由後往前找到適當的位置插入。運算流程如下
//// http://emn178.pixnet.net/blog/post/93791164-%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F%E6%B3%95%28insertion-sort%29
//// https://hellolynn.hpd.io/2017/06/22/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8Finsertion-sort/
//// 從左到右檢查是否符合從小到大的排序，碰到不合者，從右到左找縫隙插入。
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define SIZE 10
//
//
////4,3,2,1,5
//
//
//void PrintArr(int arr[], int n);
//
//void InsertionSort(int arr[], int n) {
//    int i, j;
//    int temp;
//    for (i = 1; i < n; i++) {
//        temp = arr[i];
//        for (j = i - 1; j >= 0 && arr[j]>temp; j--) {
//            arr[j + 1] = arr[j];
//            PrintArr(arr, n);
//            //getchar();
//        }
//        
//        arr[j + 1] = temp;
//        PrintArr(arr, n);
//    }
//}
//
//
//void PrintArr(int arr[], int n){
//    for (int i =0; i<n ; i++){
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//
//int main(){
//    int arr[SIZE];
//
//    for (int i=0; i<SIZE; i++){
//
//        //srand(time(NULL));  // 每次執行時，重新找一個亂數起始值。讓每次執行時時間都不同
//        arr[i] = rand() %100 ; // 確保出來的數字是0~99
//    }
//    PrintArr(arr, SIZE);
//    printf("qq \n");
//    InsertionSort(arr, SIZE);
//    //printf("qqq");
//    //PrintArr(arr, SIZE);
//
//    return 0;
//
//}






// 3, O( n*log(n) ) ?

// e.g.  merge(Arr1, Arr2)，其中Arr1,Arr2都是已經sorting好的
// O(n1+n2), n1,n2分別代表兩個Arr的大小

// merge sort  ( 先拆開，然後分別sort，最後再merge )
// T(n) = T(n/2) + T(n/2) + O(n/2+n/2)  // T(sort), T(sort), T(merge)
// xcode的資料夾裡頭有老師講解的圖片



// O(1) 代表要花的時間是一個常數。e.g. sorting 10個數字, sorting 5個數字，都是O(1)










