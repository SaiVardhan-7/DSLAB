#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_at_begin();
void insert_at_End();
void insert_at_position();
void delete_at_begin();
void delete_at_End();
void delete_at_position();

typedef struct node{
     struct node *prev;
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
       newnode->next = NULL;
       if(head==NULL){
          head = tail = newnode;
          newnode->prev = NULL;
       }
       else{
          tail->next = newnode;
          newnode->prev = tail;
          tail = newnode;
       }
       printf("Do you want to continue(Y/N) : ");
       scanf(" %c",&ch);
    }while(ch=='Y' || ch=='y');
}     

void display(){
    NODE *temp = head;
    if(head==NULL){
       printf("List is Empty");
    }
    else{
       while(temp!=NULL){
           printf("%d->",temp->data);
           temp = temp->next;
       }
       printf("NULL\n");
    }
}

void insert_at_begin(){
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data to insert at begin:");
    scanf("%d",&newnode->data);
    
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_at_End(){
    NODE *newnode, *temp = head;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data to insert at End:");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head==NULL){
      newnode->prev = NULL;
      head = newnode;
    }
    else{
      while(temp->next!=NULL){
          temp = temp->next;
      }
      
      newnode->prev = temp;
      temp->next = newnode;
      temp = newnode;
    }
}

void insert_at_position(){
    NODE *newnode, *temp = head;
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);

    if(pos==1){
       insert_at_begin();
    }
    else{
       for(int i=1;i<pos-1;i++){
          temp = temp->next;
       }
       newnode = (NODE*)malloc(sizeof(NODE));
       printf("Enter data to insert at position:");
       scanf("%d",&newnode->data);
       
       newnode->next = temp->next;
       newnode->prev = temp;
       temp->next->prev = newnode;
       temp->next = newnode;
    }
}

void delete_at_begin(){
   NODE *temp = head;
   if(head==NULL){
     printf("List is Empty");
   }
   else{
     head = head->next;
     head->prev = NULL;
     free(temp); 
   }
}

void delete_at_End(){
    NODE *temp = head;
    if(head==NULL){
      printf("List if Empty");
    }
    else{
      while(temp->next!=NULL){
         temp = temp->next;
      }
      temp->prev->next = NULL;
      free(temp);
    }
}

void delete_at_position(){
    NODE *temp = head;
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1){
      delete_at_begin();
    }
    else{
      for(int i=1;i<pos;i++){
         temp = temp->next;
      } 
      
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
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























