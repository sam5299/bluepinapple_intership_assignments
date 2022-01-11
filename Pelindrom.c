#include<stdio.h>
#include<string.h>
int main(){
    char name[100];
    printf("\nEnter name:");
    scanf("%s",&name);
    int flag = 0;
    int length = strlen(name);
    for(int i=1;i<=length;i++){
        if(name[i-1]!=name[length-i]){
            flag = 1;
            break;
        }
    }
    if(!flag){
        printf("String is pelindrom");
    }
    else{
        printf("String is not pelindrom");
    }
}