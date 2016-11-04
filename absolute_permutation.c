#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
If the absolute difference is zero, the position and permutation is the same.
For the other cases, take example of n=8:
n k
8 0 => 1 2 3 4 5 6 7 8
8 1 => 2 1 4 3 6 5 8 7
8 2 => 3 4 1 2 7 8 5 6
8 3 => -1
8 4 => 5 6 7 8 1 2 3 4
8 5 => -1
8 6 => -1
8 7 => -1
8 8 => -1

It is possible in the cases when n is divisible by k * 2. Then, we can print the values using two loops of length n/k and k. Taking the 8 2 example:
i = 0 j = 0 -> number = 1 + (i + 1) * k = 3
i = 0 j = 1 -> number++ = 4
i = 1 j = 0 -> number = 1 + (i - 1) * k = 1
i = 1 j = 1 -> number++ = 2
i = 2 j = 0 -> number = 1 + (i + 1) * k = 7
i = 2 j = 1 -> number++ = 8
i = 3 j = 0 -> number = 1 + (i - 1) * k = 5
i = 3 j = 1 -> number++ = 6

If n is odd, it is just possible to obtaine absolute permutation when k = 0.
*/
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        int k; 
        scanf("%d %d",&n,&k);
        if(k == 0) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", i);
            }
        } else if (n % (k * 2) == 0) {
            for (int i = 0; i < (n / k); i++) {
                int number;
                if (i % 2 == 0) {
                    number = 1 + (i + 1) * k;
                } else {
                    number = 1 + (i - 1) * k;
                }
                for (int j = 0; j < k; j++) {
                    //printf("i = %d j= %d number = %d\n", i, j, number);
                    printf("%d ", number);
                    number++;
                }
            }
          
                
        } else {
            printf("-1");  
        }
        printf("\n");    
            
        
    }
    return 0;
}
