#include<stdio.h>
#include<stdlib.h>
int main(){
    int row1,row2,col1,col2;
    
    int array1[10][10];
    int array2[10][10];
    int array3[10][10];
    printf("\nEnter row and column of first matrix:");
    scanf("%d",&row1);
    scanf("%d",&col1);

    printf("Enter row and column of second matrix:");
    scanf("%d",&row2);
    scanf("%d",&col2);

    if(col1!=row2){
        exit(0);
    }


    printf("\nEnter array elements of array1:");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d",&array1[i][j]);
        }
    }

    printf("\nEnter array elements of array2:");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            scanf("%d",&array2[i][j]);
        }
    }

    //multiply matrix
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
             array3[i][j] = 0;
            for(int k=0;k<col2;k++){
                array3[i][j] += array1[i][k]*array2[k][j];
            }            
        }
    }

    //printing array
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d ",array3[i][j]);
        }
        printf("\n");
    }
    
}