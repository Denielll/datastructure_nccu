//  main.c
//  test
//
//  Created by daniel.chang on 24/04/2018.
//  Copyright © 2018 daniel.chang. All rights reserved.
//



// 這邊教的就是傳說中的 pointer ?
// 目標： 把記憶體中 addr位置儲存的值改為10




#include <stdio.h>



void ChangeInputTo10_fail(int i){
    i = i+1;
}



// 把 void* 想成是一種變數型態，為了儲存記憶體位置
void ChangeInputTo10_v1(void* addr){
    
    // 要事先指定 記憶體中存的值的型態是啥， (int*)告訴它把 addr存的型態當成 int
    *(int*)addr = 10;    // * addr 是這個位置儲存的"值"
}



// 和 ChangeInputTo10_v1 不同的地方是，這邊一開始就直接指定記憶體存的值的型態
//其實不加*也可以，但是code可讀性會很差，還有就是如果記憶體位置很大，則不加*會有問題
void ChangeInputTo10_v2(int* addr){
    
    *addr = 10;
}






void TestChangeInput(){
    int i = 6;
    
    //ChangeInputTo10_fail(i);
    //ChangeInputTo10_v1(&i);
    ChangeInputTo10_v2(&i);   // input 必須為i的記憶體位置，才可以成功改i的值
    printf("%d \n", i);
    
    
    return ;
}




int main() {
    
    TestChangeInput();
    
    return 0;
    
}








