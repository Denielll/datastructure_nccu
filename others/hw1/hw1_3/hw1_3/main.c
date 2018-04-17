//"void" indicates that this function does not return anything
//Therefore, you do not need to write "return XXX;"


#include <stdio.h>
#include <string.h>
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



void PrintBoard_empty(int board[4][4]){
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





int main(){
    
    int board[4][4] = {
        { 2, 128, 16, 4 },
        { 16, 4096, 256, 128 },
        { 32, 2048, 16, 4 },
        { 0, 0, 16, 1024 }
    };
    
    PrintBoard_empty(board);
    
    return 0;
    
    
}







