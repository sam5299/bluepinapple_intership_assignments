#include<stdio.h>
#include<stdlib.h>

typedef struct dict
{
    dict *left,*right;
    char key[100];
    int value;
}*dict;

void Insert();
void search(int);
void view();
void delete(int);

int main(){
    int ch = 0;
    int key = 0;
    while(ch!=4){
        printf("\nInsert\nSearch\nView\nDelete");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            Insert();
            break;
        case 2:
            search(key);
            break;
        case 3:
            view();
            break;
        case 4:
            delete(key);
            break;
        default:
            break;
        }
    }
}