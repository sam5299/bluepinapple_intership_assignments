#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static int NODE_COUNT = 0;
typedef struct  node
{
    int bookid;
    char bname[100];
    struct node *next;
}node;

node *create(node *);
node* printBooks(node *);
int count(node *);
node *insert(node *);
node* searchById(node*,int);
node* searchByName(node*,char arr[]);
node* search(node*,int);
node* insertAtPosition(node*,int);
node* deleteBook(node*,int);
void main(){
    node *HEAD=NULL;
    int flag = 1;
    int optionSelected = -1;
    int position = 0;
    int bid_search = 0;
    char bname_search[100];
    int searchby = 0;
    int bid = 0;
    int cnt = 0;
    char bname[100];
    while(flag){
        printf("\nChoose operation to perform:");
        printf("\n0:Exit");
        printf("\n1:Append book");
        printf("\n2:See all books");
        printf("\n3:Search books");
        printf("\n4:Insert at postion");
        printf("\n5:Delete at position\n");
        scanf("%d",&optionSelected);
        cnt = count(HEAD);
        switch (optionSelected)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            HEAD = insert(HEAD);
            break;
        case 2:
            HEAD = printBooks(HEAD);
            break;
        case 3:
            printf("\nEnter way to search book:");
            printf("\n1.Search by id:");
            printf("\n2.Search by name:\n");
            scanf("%d",&searchby);
            if(HEAD==NULL){
                printf("\nNo book to search");
            }
            else if(searchby==1 && HEAD!=NULL){
                int bookid = 0;
                printf("\nEnter book id to search:");
                scanf("%d",&bookid);
                HEAD = searchById(HEAD,bookid);
            }
            else if(searchby==2 && HEAD!=NULL){
                char name[100];
                printf("\nEnter book name to search:");
                scanf("%s",&name);
                HEAD = searchByName(HEAD,name);
            }
            else{
                printf("invalid option");
            }
            break;
        case 4:
            cnt = count(HEAD);
            if(cnt>0){
                HEAD = insertAtPosition(HEAD,cnt);
            }
            else{
                printf("\nNo previous positions available please add books");
            }
            break;
        case 5:
            printf("\nEnter position to delete:");
            scanf("%d",&position);
            HEAD = deleteBook(HEAD,position);
            break;
        default:
            printf("\n wrong input");
            flag=0;
            break;
        }
    }

}

node *insert(node *head){
    int bkid;
    int bname[100];
    int bookid = count(head)+1;
    node *temp,*q;
    if(head==NULL){
        head = (node*)malloc(sizeof(node));
        head->bookid = bookid;
        printf("\nBook id:%d",bookid);
        printf("\nEnter book name:");
        scanf("%s",&head->bname);
        head->next = NULL;
    }else{
        temp = (node*)malloc(sizeof(node));
        printf("\nbook id:%d",bookid);
        temp->bookid = bookid;
        printf("\nEnter book name:");
        scanf("%s",&temp->bname);
        temp->next = NULL;
        q = head;
        while(q->next!=NULL){
            q = q->next;
        }
        q->next = temp;
    }
    NODE_COUNT++;
    return head;
}

node* printBooks(node *head){
    node *q;
    if(head==NULL){
        printf("No books to print");
    }
    else{
        q = head;
        while (q->next!=NULL)
        {
            printf("\n-------------\nBook id:%d",q->bookid);
            printf("\nBook name:%s\n--------\n",q->bname);
            q = q->next;
        }
        printf("\nBook id:%d",q->bookid);
        printf("\nBook name:%s",q->bname);
        
    }
    return head;
}

int count(node *head){
    int id = 0;
    node *p;
    NODE_COUNT = 0;
    if(head == NULL) return id;
    p = head;
    while(p!=NULL){
        id = p->bookid;
        p = p->next;
        NODE_COUNT++;
    }
    //printf("value of counter %d",counter);
    return id;
}


node* searchById(node *head,int bid){
    if(head==NULL){
        printf("no book present");
        return head;
    } 
    node *p=head;
    while(p!=NULL){
        printf("%d book id",p->bookid);
        if(p->bookid == bid){
            printf("\n---book found below are details---");
            printf("\nBook id:%d",p->bookid);
            printf("\nBook name:%s",p->bname);
            return head;
            break;
        }
        p = p->next;
    }
    printf("\nBook with given id does not present");
    return head;
}

node* searchByName(node *head,char name[]){
    node *p;
    p = head;
    while(p!=NULL){
        if(strcmp(p->bname,name)==0){
            printf("\n---book found below are details---");
            printf("\nBook id:%d",p->bookid);
            printf("\nBook name:%s",p->bname);
            return head;
            break;
        }
        p = p->next;
    }
    printf("\nBook with given name does not present");
    return head;
}

node* insertAtPosition(node *head,int nodecount){
    int position = 0;
    node *p = head;
    printf("Enter postion to insert:");
    scanf("%d",&position);
    if(position>nodecount || position<=0){
        printf("invalid postion to insert");
        return head;
    }
    else{
        while(p!=NULL){
            if(p->bookid == position){
                printf("\nEnter bookname:");
                scanf("%s",&p->bname);
                break;
            }
            p = p->next;
        }

        return head;
    }
}

node* deleteBook(node *head,int position){
    node *temp,*p;
    if(position<0 || position>NODE_COUNT){
        printf("invalid position to delete");
        return head;
    }
    else if(position == 1){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else if(position == NODE_COUNT){
        temp = head;
        while(temp->next!=NULL){
            if(temp->next->next==NULL){
                p = temp->next;
                temp->next = NULL;
                free(p);
                break;
            }
        }
        return temp;
    }
    else{
        int count=0;
        temp = head;
        printf("\nhere");
        while(temp!=NULL){
            count++;
            if(count+1==position){
                p = temp->next;
                temp->next = temp->next->next;
                free(p);
                break;
            }
            temp = temp->next;
        }
        return head;
    }

}

