#include<stdio.h>
#include<stdlib.h>

int lengthOfNode();

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *head = NULL;

int create(){
   NODE *newnode, *tail;
   char ch;
   do{
      newnode = (NODE*)malloc(sizeof(NODE));
      printf("Enter data:");
      scanf("%d",&newnode->data);
      newnode->next = NULL;
      
      if(head==NULL){
         head = tail = newnode;
      }
      else{
         tail->next = newnode;
         tail = newnode;
      }
      printf("Do you want to continue (Y/N):");
      scanf(" %c",&ch);
   }while(ch=='y' || ch=='Y');
   
   return 0;
}

int insert_at_Beg(){
   NODE *newnode;
   newnode =(NODE*)malloc(sizeof(NODE));
   printf("Enter data to insert at beginning:");
   scanf("%d",&newnode->data);
   
   if(head==NULL){
      head = newnode;
      newnode->next = NULL;
   }
   else{
      newnode->next = head;
      head = newnode;
   }
   return 0;
}

int insert_at_End(){
   NODE *newnode, *temp = head;
   newnode = (NODE*)malloc(sizeof(NODE));
   printf("Enter data to insert at the End:");
   scanf("%d",&newnode->data);
   newnode->next = NULL;
   
   if(head==NULL){
      head = temp = newnode;
   }
   else{
      while(temp->next!=NULL){
         temp = temp->next;
      }
      
      temp->next = newnode;
      temp = newnode;
   }
   return 0;
}

int insert_at_Pos(){
   NODE *newnode, *prev=head, *temp;
   int pos;
   printf("Enter the position to insert:");
   scanf("%d",&pos);
   if(pos>0 && pos<=lengthOfNode()){
      newnode = (NODE*)malloc(sizeof(NODE));
      printf("Enter data to insert at position:");
      scanf("%d",&newnode->data);
   
      if(pos==1){
         newnode->next = head;
         head = newnode;
      }
      else{
     	 for(int i=1;i<pos-1;i++){
           prev = prev->next;
         }
         temp = prev->next;
     
         newnode->next = temp;
         prev->next = newnode;
      }
   }
   else{
      printf("Invalid Position\n");
   }
   return 0;
}

int delete_at_Beg(){
   if(head==NULL){
      printf("List is Empty");
      return 0; 
   }
   else{
      NODE *temp = head;
      
      head = head->next;
      free(temp);
   }
   return 0;
}

int delete_at_End(){
   if(head==NULL){
      printf("List is Empty");
      return 0; 
   }
   else{
      NODE *temp=head, *prev;
      while(temp->next!=NULL){
         prev = temp;
         temp = temp->next;
      }
      prev->next = NULL;
      free(temp);
   }
   return 0;
}

int delete_at_Pos(){
    NODE *prev = head, *temp;
    int pos;
    printf("Enter position to delete:");
    scanf("%d",&pos);
    if(pos>0 && pos<=lengthOfNode()){
       if(pos==1){
       delete_at_Beg();
       }
       else{
          for(int i=1;i<pos-1;i++){
             prev = prev->next;
          }
          temp = prev->next;
       
          prev->next = temp->next;
          free(temp);
       }
    }
    else{
       printf("Invalid Position\n");
    }
    return 0;
}

int lengthOfNode(){
    NODE *temp = head;
    int count = 0;
    while(temp!=NULL){
       count++;
       temp = temp->next;
    }
    return count;
}

void reverse(){
    NODE *prev = NULL, *current = head;
    
    while(current!=NULL){
        NODE *next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
}

void display(){
   NODE *temp = head;
   while(temp!=NULL){
       printf(" %d ->",temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}

int main(){
   create();
   display();
   
  /* insert_at_Beg();
   insert_at_End();
   insert_at_Pos();
   
   delete_at_Beg();
   delete_at_End();
   delete_at_Pos();*/
   
   //delete_at_Pos();
   
   printf("After Reversing : ");
   reverse();
   
   display();
   
   return 0;
}   





