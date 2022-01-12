#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book
{
    int bid;
    char bname[100];
    struct book *next;
}book;
book bookarray[26];
void init();
int showBooks();
int insert(int,char name[]);
int search(char name[]);
int hashIndex(char name[]);
int delete(char name[]);


int hashIndex(char bookname[]){
    if(bookname[0]>=65 && bookname[0]<=90){
        return bookname[0] - 65;
    }
    else if(bookname[0]>=97 && bookname[0]<=122){
        return bookname[0] - 97;
    }
    return -1;
}


void init(){
    printf("\ninitlizing array\n");
    for(int i=0;i<26;i++){
        bookarray[i].next = 0;
    }
}

int showBooks(){
    book *temp;
    for(int i=0;i<26;i++){
        temp = bookarray[i].next;
        if(temp){
            while(temp){
            printf("\n--------------------------");
            printf("\nBook Id:%d",temp->bid);
            printf("\nName:%s",temp->bname);
            printf("\n--------------------------\n");
            temp = temp->next;
         }
        }
    }
    return 0;
}

int search(char arr[]){
    int index = hashIndex(arr);
    book *temp;
    temp = bookarray[index].next;
    while(temp){
        if(strcmp(temp->bname,arr)==0){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int delete(char name[]){
    int result = search(name);
    int index = 0;
    if(result == 0){
        printf("\nBook not present");
        return 0;
    }
    else{
        index = hashIndex(name);
        book *current,*previous;
        current = bookarray[index].next;
        previous = bookarray[index].next;
        while(current){
            if(current->next==NULL && strcmp(current->bname,name)==0){
                bookarray[index].next = NULL;
                return 1;
            }
            else if(strcmp(current->bname,name)==0 && current->next==NULL){
                previous->next = NULL;
                free(current);
            }
            else if(strcmp(current->bname,name)==0){
                previous->next = current->next;
                free(current);
            }
            previous = current;
            current = current->next;
        }
        return 0;
    }
}

int insert(int id,char name[]){
    book *temp,*p;
    int index;
    if(search(name)==1) return 0;
    index = hashIndex(name);
    temp = (book *)malloc(sizeof(book));
    temp->bid = id;
    strcpy(temp->bname,name);
    temp->next = NULL;
    if(bookarray[index].next==NULL){
        bookarray[index].next = temp;
    }
    else{
        p = bookarray[index].next;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = temp;
    }   
    return 1;
}

int main(){
    init();
    int choise = 0;
    int result = 0;
    int loop = 1;
    int bookid;
    char bname[100];
    while(loop){
        printf("\nPlease enter operation to do:");
        printf("\n0.Exit");
        printf("\n1.Insert");
        printf("\n2.Show");
        printf("\n3.Search");
        printf("\n4.Delete\n");
        scanf("%d",&choise);
        switch (choise)
        {

        case 0:
            loop = 0;
            break;
        case 1:
            printf("\n Enter book id:");
            scanf("%d",&bookid);
            printf("\n Enter book name:");
            scanf("%s",&bname);
            result = insert(bookid,bname);
            if(result==-1)
            {printf("\ninvalid position");}
            else if(result==0){
                printf("already present");
            }
            else {printf("\ninsertion done");}
            break;
        case 2:
            result = showBooks();
            break;
        case 3:
            printf("\nEnter book name to search:");
            scanf("%s",&bname);
            result = search(bname);
            if(result==1) printf("\nBook is present");
            else printf("\nBook is not present");
            break;
        case 4:
            printf("\nEnter book name to delete:");
            scanf("%s",&bname);
            result = delete(bname);
            if(result) printf("deleted successfully");
            break;
        default:
            exit(0);
            break;
        }
    }
}