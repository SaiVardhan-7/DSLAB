#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
}NODE;
NODE *front = NULL, *rear = NULL;

void enqueue(int ele){
   NODE *newnode = (NODE*)malloc(sizeof(NODE));
   newnode->data = ele;
   newnode->next = NULL;
   
   if(rear==NULL){
      front = rear = newnode;
   } 
   else{
      rear->next = newnode;
      rear = newnode;
   }
}

int dequeue(){
   if(front==NULL){
      printf("Queue Underflow");
   }
   else{
      NODE *temp = front;
      front = front->next;
      
      if(front==NULL){
         rear = NULL;
      }
      printf("Deleted node is %d\n",temp->data);
      free(temp);
   }
}

void display(){
   if(front==NULL){
      printf("Queue is Empty");
   }
   NODE *temp = front;
   while(temp!=NULL){
      printf("%d->",temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}

int main(){
   int ele, ch;
   
   while(1){
      printf("1.Enqueue\n2.Dequeue\n3.Display\n4.EXIT\n");
      printf("Enter your choice : ");
      scanf("%d",&ch);
      
      switch(ch){
         case 1 : printf("Enter an element : ");
                  scanf("%d",&ele);
                  enqueue(ele);
                  break;
         case 2 : dequeue();
                  break;
         case 3 : display();
                  break;
         case 4 : exit(0);
         default : printf("Invalid choice");                    
      }
   }
   
   return 0;
}


