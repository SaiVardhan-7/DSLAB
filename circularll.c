#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *head = NULL;

void create(){
    NODE *newnode, *tail;
    char ch;
    do{
       newnode = (NODE*)malloc(sizeof(NODE));
       printf("Enter data:");
       scanf("%d",&newnode->data);
       
       if(head==NULL){
         head = tail = newnode;
         head->next = newnode; 
       }
       else{
         tail->next = newnode;
         tail = newnode;
         newnode->next = head;
       }
       printf("Do you want to continue (Y/N):");
       scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
}

void display(){
   NODE *temp = head;
   if(head==NULL){
     printf("List is Empty");
   }
   else{
     do{
       printf("%d ",temp->data);
       temp = temp->next;
     }while(temp!=head);
     printf("\n");
   }
}


void insert_at_begin(){
    NODE *newnode, *temp = head;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data to insert at begin:");
    scanf("%d",&newnode->data);  
    
    if(head==NULL){
      head = newnode;
      head->next = newnode;
    }
    else{
       while(temp->next!=head){
          temp = temp->next;
       }
       newnode->next = head;
       temp->next = newnode;
       head = newnode;
    }
}

void insert_at_End(){
    NODE *newnode, *temp = head;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data to insert at End:");
    scanf("%d",&newnode->data);
    
    if(head==NULL){
      head = newnode;
      head->next = newnode;
    }
    else{
       while(temp->next!=head){
          temp = temp->next;
       }
       newnode->next = head;
       temp->next = newnode;
    }
}

void insert_at_position(){
    NODE *newnode, *temp = head;
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data to insert at postion:");
    scanf("%d",&newnode->data);
    
    if(head==NULL){
        head = newnode;
        head->next = newnode; 
    }
    else{
       for(int i=1;i<pos-1;i++){
          temp = temp->next;
       }
       newnode->next = temp->next;
       temp->next = newnode;
    }
}

void delete_at_begin(){
    NODE *temp = head, *tail = head;
    if(head==NULL){
      printf("List is Empty"); 
    }
    else{
      while(tail->next!=head){
         tail = tail->next;
      }
      head = head->next;
      tail->next = head;
      free(temp);
    }
}

void delete_at_End(){
    NODE *prev, *temp = head;
    
    if(head==NULL){
      printf("List is Empty");
    }
    else{
      while(temp->next!=head){
         prev = temp;
         temp = temp->next;
      }
      prev->next = head; 
      free(temp);
    }
}

void delete_at_position(){
    NODE *temp = head, *prev;
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
   
    if(head==NULL){
      printf("List is Empty"); 
    }
    else{
       for(int i=1;i<pos;i++){
          prev = temp;
          temp = temp->next;
       }
       prev->next = temp->next;
       free(temp);
    }
}

int main(){
   create();
   display();
   
   insert_at_begin();
   insert_at_End();
   insert_at_position();
   
   delete_at_begin();
   delete_at_End();
   delete_at_position();
   
   display();
   
   return 0;
}

