#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Tree{
    char word[100];
    struct Tree *left;
    struct Tree *right;
}Tree;

Tree* insertWord(Tree*,char[]);
Tree* initTree(Tree*);
int preOrder(Tree*,int,char[]);
int search(Tree*);
Tree* position(Tree*,char);

int static gcount = 0;

int search(Tree *root){
    Tree *temp = NULL;
    int len = 0;
    gcount = 0;
    char search_word[100];
    printf("\nEnter length of word to search:");
    scanf("%d",&len);
    if(len<=0) return gcount;
    printf("\nEnter known character at position and unknown keep ?\n");
    for(int i=0;i<len;i++){
        printf("Enter character at %d position:",i);
        scanf("%s",&search_word[i]);
    }
    if(search_word[0] != '?'){
        temp = position(root,search_word[0]);
        return preOrder(temp,len,search_word);
    }
    return preOrder(root,len,search_word);

}

Tree *insertWord(Tree *root,char word[100]){
    for(int i=0;word[i]!='\0';i++){
        word[i] = tolower(word[i]);
    }
    if(root == NULL){
        Tree *new = (Tree *)malloc(sizeof(Tree));
        new->left = NULL;
        new->right = NULL;
        strcpy(new->word, word);
        return new;
    }
    if(strcmp(word,root->word) < 0)  
        root->left = insertWord(root->left,word);
    else if(strcmp(word,root->word) > 0) 
        root->right = insertWord(root->right,word);
    else return root;
    return root;
}

Tree* initTree(Tree *root){
    FILE *pointer;
    char word[100];
    pointer = fopen("worddata.txt","r");
    if(pointer == NULL){
        printf("\n Word dictionary failed to initlized...");
        exit(0);
    }
   
    while(fscanf(pointer,"%s",word) != EOF){
        root = insertWord(root,word);
    }
    printf("\n Dictionary loaded...\n");
    fclose(pointer);
    return root;
}

int preOrder(Tree *root,int len,char warr[]){
    int flag = 0;
    if(root==NULL) return gcount;
    if (len == strlen(root->word)) {
        for(int i=0;i<len;i++){
            if(warr[i]=='?') continue;
            if(warr[i]!=root->word[i]){flag = 1;break;}
        }
           if(!flag){
            printf("%s\t",root->word);
            gcount++;
           } 
        }
    preOrder(root->left,len,warr);
    preOrder(root->right,len,warr);
}

Tree* position(Tree *root,char first){
    if (root == NULL)
        return NULL;

    if (tolower(first) == root->word[0])
        return root;
    else if (tolower(first) < root->word[0])
        return position(root->left, first);
    else if (tolower(first) > root->word[0])
        return position(root->right, first);

}

int main(){
    Tree *root=NULL;
    int result = 0;
    int flag = 1;
    int choice = 0;
    root = initTree(root);
    while (flag)
    {
        printf("\nEnter your choice:");
        printf("\n1.Search for words by hints:");
        printf("\n2.Exit\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
               result = search(root); 
               if(result==0) printf("\nNo words found");
               break;
            case 2:
                flag = 0;
                break;
            default:
                flag = 0;
                break;
        }
    }
    
}