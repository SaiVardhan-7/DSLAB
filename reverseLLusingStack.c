#include<stdio.h>
#include<stdlib.h>

#define MAX 20
int stack[MAX];
int top = -1;

void push(int ele){
   if(top==MAX-1){
      printf("Stack Overflow\n");
   }
   else{
      stack[++top] = ele;
   }
}

int pop(){
   if(top==-1){
      printf("Stack Underflow\n");
   }
   else{
      return stack[top--];
   }
}

typedef struct node{
   int data;
   struct node *next;
}NODE;

NODE *head = NULL;

void create(){
   NODE *tail, *newnode; 
   char ch;
   do{
      newnode = (NODE*)malloc(sizeof(NODE));
      printf("Enter data : ");
      scanf("%d",&newnode->data);
      newnode->next = NULL;
      if(head==NULL){
         head = tail = newnode;
      }
      else{
         tail->next = newnode;
         tail = newnode;
      }
      printf("Do you want to continue (Y/N): ");
      scanf(" %c",&ch);
   }while(ch=='Y' || ch=='y');
}

void reverse(){
   if(head==NULL){
      printf("List is Empty");
      return;
   }
   
   NODE *temp = head;
   while(temp!=NULL){
      push(temp->data);
      temp = temp->next;
   }
   
   temp = head;
   while(temp!=NULL){
      temp->data = pop();
      temp = temp->next;
   }
}

void display(){
   if(head==NULL){
      printf("List is Empty");
   }
   else{
   NODE *temp = head;
      while(temp!=NULL){
         printf("%d->",temp->data);
         temp = temp->next;
      }
      printf("NULL\n");
   }
}

int main(){
   create();
   display();
   reverse();
   display();
   
   return 0;
}

