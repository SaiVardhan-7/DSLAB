#include<stdio.h>
#include<stdlib.h>

#define MAX 20
int deque[MAX];
int front = -1, rear = -1;

void insert_at_frontend(int ele){
   if(rear==MAX-1){
      printf("Queue Overflow\n");
   }
   else{
      if(front==-1){
         front++;
      }
      deque[++rear] = ele;
   }
}

void insert_at_rearend(int ele){
   if(front==-1){
      front++;
      rear++;
      deque[front] = ele;
   }
   else if(front==0){
      printf("Insertion not possible\n");
   }
   else{
      deque[--front] = ele;
   }
}

int delete_at_frontend(){
   if(front==-1){
      printf("Queue Underflow\n");
   }
   else if(front==rear){
      printf("Deleted element is %d",deque[front]);
      front--;
      rear--;
   }
   else{
      printf("Deleted element is %d",deque[front++]);
   }
   
   return 0;
}

int delete_at_rearend(){
   if(rear==-1){
      printf("Queue Underflow\n");
   }
   else if(front==rear){
      printf("Deleted element is %d",deque[front]);
      front = -1;
      rear = -1;
   }
   else{
      printf("Deleted element is %d",deque[rear--]); 
   }
   
   return 0;
}

void display(){
   if(front==-1){
      printf("Queue is Empty");
   }
   else{
      for(int i=front;i<=rear;i++){
         printf("%d->",deque[i]);
      }
      printf("NULL\n");
   }
}

int main(){
   int ch, ele;
   
   while(1){
      printf("1.insert_at_frontend\n2.insert_at_rearend\n3.delete_at_frontend\n4.delete_at_rearend\n5.Display\n6.EXIT\n");
      printf("Enter your choice : ");
      scanf("%d",&ch);
      
      switch(ch){
         case 1 : printf("Enter an element : ");
                  scanf("%d",&ele);
                  insert_at_frontend(ele);
                  break;
         case 2 : printf("Enter an element : ");
                  scanf("%d",&ele);
                  insert_at_rearend(ele);
                  break;                        
         case 3 : delete_at_frontend();
                  break;
         case 4 : delete_at_rearend();
                  break;         
         case 5 : display();
                  break;
         case 6 : exit(0);
         default : printf("Invalid choice");                    
      }
   }

}
