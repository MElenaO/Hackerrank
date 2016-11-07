#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void rotate (int index, int* array) {
    int temp = array[index];
    array[index] = array[index + 1];
    array[index + 1] = array[index + 2];
    array[index + 2] = temp;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    scanf("%d", &t);
    int n;
    int* array;
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        //Number of rotations for each index
        int rotations[n];
        array = malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            scanf("%d", &array[j]);
            rotations[j] = 0;
        }
        int index = 0;
        int possible = 1;

        while (index < (n - 1)) {
            if (array[index] > array[index + 1]) {
                //If the value in index is larger than in index + 1, we need to rotate to try to sort the values.
                //The rotate function will rotate from index to index + 2. Special case if index is n - 2, to avoid
                // going from n - 2 to n (outside the array)
                if (index == n - 2) {
                    index = n - 3;
                }
                rotate(index, array);
                
                //DEBUG!!!
               /* for (int j = 0; j < n; j++) {
                    printf("%d ", array[j]);
                }
                printf("\n");*/
                //DEBUG!!!
                //Increase the number of rotations for that index
                rotations[index]++;
                //If we have rotated 3 times, there is no possible rotation that sorts the 3 elements
                if(rotations[index] > 2) {
                    possible = 0;
                    break;
                }
            //If the values in index and index + 1 are sorted...
            } else {
                // If we needed to do a rotation for that index, reset the number of rotations for that index 
                // and also go back to the previous index, to see that after sorting the previous index is still smaller
                if (rotations[index] != 0) {
                    rotations[index] = 0;
                    if (index > 0) {
                        index--;
                    }
                //If we didn't rotate, the values are sorted and we go to the next index
                } else {
                    index++;
                }
            }
            
        }
        if (possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
