//"void" indicates that this function does not return anything
//Therefore, you do not need to write "return XXX;"



#include <stdio.h>
#include <math.h>

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





int main() {
    Factor(24);
    //The terminal should print 24 = 2^3*3
    Factor(50);
    //The terminal should print 50 = 2*5^2
    Factor(120);
    //The terminal should print 120 = 2^3*3*5
    return 0;
}
