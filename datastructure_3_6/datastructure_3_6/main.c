//
//  main.c
//  datastructure_3_6
//
//  Created by daniel.chang on 06/03/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.
//
//
//

// 筆記區
// function 如果是 return 0 ，表示函數不回傳值
// 如果印到 20!會爆炸，因為int 無法顯示這麼多位數。解決方法：自己寫一個type, 動態地讓這個type所需要的記憶體慢慢變大
// 變數只會活在 被包的大括弧裡面


////// 印出好幾個階層
////#include <stdio.h>
////
////int Factorial(int n){
////    int ans = 1;
////    int mul = 2;
////    
////    while(mul<= n){
////        ans = ans*mul;
////        mul = mul+1;
////    }
////    
////    
////    return ans;
////}
////
////
////
////
////int main(){
////    
////    int n = 1;
////
////    while(n<=10){
////        printf("%d! = %d\n", n,Factorial(n) );
////        n = n+1;
////    }
////    
////    getchar();
////    return 0;
////    
////}
//



//// 判斷是否為質數
//#include <stdio.h>
//#include <math.h>
//
//int IsPrime(int n){
//    int factor = 2;
//    
//    while (factor<=sqrt(n)){
//        if (n%factor ==0){
//            return 0;
//        }
//        factor = factor+1;
//    }
//    
//    return 1;
//}
//
//
//int main(){
//    
//    
//    // 從2開始檢查
//    int n = 2;
//    
//    while(n<=100){
//        if (IsPrime(n) ==1){
//            printf("%d is a prime number \n",n);
//        }
//        else{
//            printf("%d is NOT a prime number\n",n);
//        }
//        n = n+1;
//    }
//    
//    getchar();
//    return 0;
//    
//}



//// 從n+1開始檢查, 是不是Prime
//// 判斷是否為質數
//#include <stdio.h>
//#include <math.h>
//
//int IsPrime(int n){
//    int factor = 2;
//    
//    while (factor<=sqrt(n)){
//        if (n%factor ==0){
//            return 0;
//        }
//        factor = factor+1;
//    }
//    
//    return 1;
//}
//
//
//int NextPrime(int n){
//    // 這邊沒聽到
//}
//
//
//
//
//int main(){
//    int prime = 2;
//    for (int i=1;i<=100; i=i+1){
//        printf("the %dth prime is %d\n", i, prime);
//        prime = NextPrime(prime);
//    }
//}



////圓, 算PI, 第一種方法  。這邊沒聽完整
//// x越來越大, y越來越小
//#include <stdio.h>
//#include <math.h>
//
//int GetHeight(int r, int x){
//    return sqrt(r*r -x*x);
//}
//
//
//double PI1(int r){
//    double area = 0;
//    
//    for (int x=-1*r; x<=r; x=x+1){
//        for (int y=r; y>=-1*r; y=y-1){
//            int y = GetHeight(r,x);
//                area = area+y;
//            }
//        }
//    return area/(r*r);
//}
//
//
//
//int main() {
//    for (int i = 1; i<=10000 ; i=i+1){
//        printf("Pi = %f\n", PI1(i));
//    }
//    getchar();
//    
//    return 0;
//}



////圓, 算PI, 第二種方法, 在wikipedia有
//#include <stdio.h>
//#include <math.h>
//double PI2(int k){
//    
//    double sum = 0;
//    
//    for(double i=1; i<=k; i=i+1){
//        sum = sum+1 / (i*i) ;
//    }
//    
//    return sqrt(6.0*sum);
//}
//
//
//
//int main() {
//    for (int i = 1; i<=10000 ; i=i+1){
//        printf("Pi = %f\n", PI2(i));
//    }
//    getchar();
//
//    return 0;
//}




////圓, 算PI, 第三種方法, 在wikipedia有
//#include <stdio.h>
//double PI3(int k ){
//    double pi=0;
//    
//    for( int i=1; i<=k ; i++){
//        
//        if( i%2 ==0){
//            pi -= 4.0 /(2.0*(double)i-1.0);
//        }
//        else{
//            pi += 4.0 /(2.0*(double)i-1.0);
//        }
//    }
//    return pi;
//}
//
//int main() {
//    for (int i = 1; i<=10000 ; i=i+1){
//        printf("Pi = %f\n", PI3(i));
//    }
//
//    return 0;
//}



//圓, 算PI, 第四種方法, 在wikipedia有
#include <stdio.h>
double PI4(int k ){
    double pi=3;
    
    for( int i=1; i<=k ; i++){
        double first = 2.0*(double)i;
        if( i%2 ==0){
            pi -= 4.0/(first*(first+1)*(first+2));
        }
        else{
            pi += 4.0/(first*(first+1)*(first+2));
        }
    }
    return pi;
}

int main() {
    for (int i = 1; i<=10000 ; i=i+1){
        printf("Pi = %f\n", PI4(i));
    }
    
    return 0;
}










