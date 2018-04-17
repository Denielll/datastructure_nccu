//"void" indicates that this function does not return anything
//Therefore, you do not need to write "return XXX;"




#include <string.h>
#include <stdio.h>
#include <math.h>





// hw1_2
int GetExponent(int n, int prime){
    int expo = 0;
    while(n%prime==0){
        expo ++;
        n = n/prime;
    }
    
    return expo;
}



void Factor(int n) {
    
    printf("%d = ", n  );
    int factor = 2;
    
    while (factor<=n){
        if (n%factor==0){
            
            if(GetExponent(n,factor) ==1 ){
                printf("%d",factor );
                n = n/factor;
            }else{
                printf("%d^%d", factor, GetExponent(n,factor));
                n = n/((int)pow(factor,GetExponent(n,factor)));
            }
            
            if(n>1){
                printf("*");
            }
            
        }
        factor = factor+1;
    }
    printf("\n");
}


// hw1_3


#define stars "*****************************"
#define space_stars "      *"


void repeat_space_stars ( int count )
{
    for (int i=0; i != count; i++ )
    {
        printf(space_stars);
    }
}




void InsertIntoBoard(int number){
    
    // convert int to string
    char number_[50];
    int num = number;
    sprintf(number_, "%d", num);
    
    
    
    // any room of improvement for this section ?
    if(number == 0 ){
        printf("      *");
    }else if (strlen(number_)==4){
        printf(" ");
        printf("%d",number);
        printf(" ");
        printf("*");
        
    }else if (strlen(number_)==3){
        printf("  ");
        printf("%d",number);
        printf(" ");
        printf("*");
        
    }else if (strlen(number_)==2){
        printf("  ");
        printf("%d",number);
        printf("  ");
        printf("*");
        
    }else{
        printf("   ");
        printf("%d",number);
        printf("  ");
        printf("*");
    }
}



void PrintBoard(int board[4][4]){
    for (int i=0; i<17; i++){
        if(i ==0 || i==4||i==8||i==12||i==16){
            printf("%.*s", 29, stars);
            printf("\n");
        }else if (i ==2 || i==6||i==10||i==14){
            printf("*");
            for(int index_=0; index_<4; index_++){
                InsertIntoBoard(board[(i-2)/4][index_]);
            }
            printf("\n");
            
        }else{
            printf("*");
            repeat_space_stars(4);
            printf("\n");
        }
    }
}





// test
int main() {
    Factor(13);
    //The terminal should print 24 = 2^3*3
    Factor(50);
    //The terminal should print 50 = 2*5^2
    Factor(364);
    //The terminal should print 120 = 2^3*3*5
    
    int board[4][4] = {
        { 2, 128, 16, 4 },
        { 16, 4096, 256, 128 },
        { 32, 2048, 16, 4 },
        { 0, 0, 16, 1024 }
    };
    
    PrintBoard(board);
    /*The terminal should print the following content
     *****************************
     *      *      *      *      *
     *   2  *  128 *  16  *   4  *
     *      *      *      *      *
     *****************************
     *      *      *      *      *
     *  16  * 4096 *  256 *  128 *
     *      *      *      *      *
     *****************************
     *      *      *      *      *
     *  32  * 2048 *  16  *   4  *
     *      *      *      *      *
     *****************************
     *      *      *      *      *
     *      *      *  16  * 1024 *
     *      *      *      *      *
     *****************************
     */
    
    
    return 0;
}
