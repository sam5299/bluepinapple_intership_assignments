#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct wordmap
{
    char key[100];
    int value;
    struct wordmap *next;
}wordmap;

wordmap wordlist[27];


void init();
int checkWord(char word[],int);
int insertWord(char word[]);
int hashIndex(char word[]);
int addWord(char word[]);
//void showWords();
void printWordFrequency(char word[]);

void init(){
    for(int i=0;i<27;i++){
        wordlist[i].next = NULL;
    }
}

int hashIndex(char word[]){
    if(word[0]>=65 && word[0]<=90)
    {
        return word[0]-65;
    }
    else if(word[0]>=97 && word[0]<=122){
        return word[0]-97;
    }
    else{
        return 26;//all special characters
    }
}

int checkWord(char word[],int allowModify){
    wordmap *ptr;
    int index = hashIndex(word);
    //printf("\nindex:%d",index);
    if(wordlist[index].next==NULL) return 0;//not present
    else{
        ptr = wordlist[index].next;
        while(ptr){
            if(strcmp(ptr->key,word)==0){
                if(allowModify) ptr->value = ptr->value+1;
                else{
                    printf("\nWord:%s",ptr->key);
                    printf("\nFrequecny:%d",ptr->value);
                }
                return 1;
                break;
            }
            ptr = ptr->next;
        }
    }
    return 0;
}

void printWordFrequency(char word[]){
    int isPresent = checkWord(word,0);//just return do not modify
    if(!isPresent) printf("\nWord not present");
}

int addWord(char word[]){
    int ispresent = checkWord(word,1);
    wordmap *temp,*p;
    int index = 0;
    if(ispresent){
        return 1;
    }
    temp = (wordmap*)malloc(sizeof(wordmap));
    strcpy(temp->key,word);
    temp->value = 1;
    temp->next = NULL;
    index = hashIndex(word);
    if(wordlist[index].next==NULL){
        wordlist[index].next = temp;
    }else{
        p = wordlist[index].next;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return 1;
}

/*void showWords(){
    wordmap *temp;
    for(int i=0;i<27;i++){
        temp = wordlist[i].next;
        if(temp){
            while(temp){
                int result = checkWord(temp->key,0);
            temp = temp->next;
         }
        }
    }
}*/

int main(){
    char longstring[100000];
    char searchword[100000];
    char *ref;
    int flag = 1;
    int choice = 0;
    init();

    printf("\nEnter log string:");
    scanf("%[^\n]*c",&longstring);
    ref = strtok(longstring," ");
    while(ref!=NULL){
        addWord(ref);
        ref = strtok(NULL," ");
    }
    while(flag){
        printf("\n1.Search word");
        printf("\n0.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            printf("\nEnter word to search:");
            scanf("%s",&searchword);
            printWordFrequency(searchword);
            break;
        default:
            break;
        }
    }

}