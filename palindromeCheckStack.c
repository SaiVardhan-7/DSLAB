#include<stdio.h>
#include<string.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char ele){
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

int isPalindrome(char str[]){
   int length = strlen(str);
   
   for(int i=0;i<length;i++){
      push(str[i]);
   }
   
   for(int i=0;i<length/2;i++){
      if(str[i]!=pop()){
         return 0;
      }
   }
   
   return 1;
}

int main(){
   char str[100];
   printf("Enter the string : ");
   scanf("%s",str);
   
   if(isPalindrome(str)){
      printf("%s is a Palindrome",str);
   }
   else{
      printf("%s is not a Palindrome",str);
   }
   
   return 0;
}   
   
   
   
   
   
   
 
