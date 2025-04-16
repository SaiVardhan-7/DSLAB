#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int stack[MAX];
int top = -1;

void push(int ele){
   if(top==MAX-1){
      printf("Stack Overflow\n");
      return;
   }
   stack[++top] = ele;
}

void pop(){
   if(top==-1){
      printf("Stack Underflow\n");
      return;
   }
   top--;
}

void display(){
   if(top==-1){
      printf("Stack is Empty");
      return;
   }
   for(int i=top;i>=0;i--){
      printf("%d->",stack[i]); 
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
