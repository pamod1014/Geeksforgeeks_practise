#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int row;
    int column;

    int n;
    scanf("%d", &n);
  	for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int min=i;
            if(j<min){
                min=j;
          }
          if(2*n-1-i-1<min){
            min=2*n-1-i-1;
          }
          if(2*n-1-j-1<min){
            min=2*n-1-j-1;
          }
          printf("%d ",n-min);   
            
        }
        printf("\n");
    }
    return 0;
}