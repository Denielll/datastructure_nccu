//
//  main.c
//  datastructure_3_20
//
//  Created by daniel.chang on 20/03/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.




////1, 介紹字元,字串
//#include <stdio.h>
//int main() {
//    
//    char str[] = "trello"; // 字串要雙引號
//    char ch = 't';  // 字元要單引號
//    
//    
//    
//    // 事實上代入str時，只知道第一個element，且compiler自動會在字串最後加一個\0, 表字串結束
//    printf("%s \n", str );
//    printf("%c \n", ch);
//    
//    
//    return 0;
//    
//}




////2, 把小寫轉成大寫  ( 我沒完成 )
//#include <stdio.h>
//
//void Cap1(char str[]){
//    for (int i = 0; str[i] != '\0' ; i++){
//        
//        // check if str[i] is a lower case char
//        // 這段和 ASCII編碼有關
//        if(str[i]>=97 && str[i]<=122){
//            str[i] -= 32;
//        }
//    }
//}
//
//
//
//
//void Cap2(char str[]) {
//    char CAPLETTER[26];
//    for(int i = 0; i < 26; i++){
//        CAPLETTER[i] = i + 'A';
//    }
//    
//    
//    for(int i = 0; str[i] != '\0';i++){
//        //check if str[i] is a lower case char
//        if(str[i] >= 'a'/*97*/ && str[i] <= 'z'/*122*/){
//            // convert str[i] to the upper case
//            str[i] = CAPLETTER[str[i] - 'a'];
//        }
//    }
//    return;
//}
//
//
//
//int main() {
//
//    char str[] = "trello"; // 字串要雙引號
//    Cap2(str);
//    printf("%s \n",str);
//    return 0;
//
//}






////3, 時間複雜度解說
//int sum(int arr[], int n){
//    int ans = 0;
//    for(int i =0; i<n ; i++){
//        ans += arr[i];
//    }
//    
//    return ans;
//}
//
//// Line1 -> t1
//// int i = 0 -> t2
//// i<n -> t3*n
//// i++ -> t4*n
//// ans += arr[i] -> t5*n
//// return -> t6
//
//// is equal to
//
//// (t3+t4+t5)*n + (t1+t2+t6)
//// 事實上 t1~t6的數值不重要，重要的是那個 n
//// 因為一般來說當care演算法時，是計算量很大的時候，也就是n很大的時候
//
//// the time complexity of the section above can be writen as O(n)





//4, 貌似是老師給的關於質因數分解的提示
/*int main() {
 printf("1\n");
 
 int i,num,len=0;
 
 printf("2\n");
 while(scanf_s("%d",&num)!=EOF){
 printf("num = %d\n", num);
 
 for(i=2;i<num;i++){
 while(num%i==0){ //餘數為0，代表i為num的因數
 num/=i;
 len++;
 printf("        i = %d, num = %d\n", i, num);
 }
 printf("    num = %d\n", num);
 
 if(len!=0){
 if(num==1){ //num為i因數的len倍
 printf("%d^%d\n",i,len);
 } else if(len==1) {
 printf("%d * ",i);
 } else {
 printf("%d^%d * ",i,len);
 }
 len=0;
 }
 }
 if(num==1){
 // num is not a prime number
 }
 else{
 printf("%d\n",i);
 //num is a prime number
 }
 }
 
 printf("4");
 return 0;
 }*/




























