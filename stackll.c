#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
}NODE;

NODE *head = NULL;

void push(int ele){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = head;
    head = newnode;
}

void pop(){
    NODE *temp = head; 
    if(head==NULL){
        printf("Stack Underflow");
        return;
    }
    head = head->next;
    free(temp);
}


void display(){
    NODE *temp = head;
    if(head==NULL){
        printf("Stack is Empty");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
   int ch, ele;
   
   while(1){
       printf("Enter your choice");
       printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
       scanf("%d",&ch);
       
       switch(ch){
           case 1 : printf("Enter an element : ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
           case 2 : pop();
                    break;
           case 3 : display();
                    break;
           case 4 : exit(0);
           
           default : printf("Invalid choice");                              
       }
   }
   
   return 0;
}
