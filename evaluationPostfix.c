#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int ele) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ele;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);  // Exit the program if stack underflows
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isOperand(char ch) {
    return ch >= '0' && ch <= '9';
}

int main() {
    char postfix[20], ch;
    int op1, op2, i, r;

    printf("Enter the postfix expression : ");
    fgets(postfix, sizeof(postfix), stdin);

    for (i = 0; postfix[i] != '\0'  && postfix[i] != '\n'; i++) {
        ch = postfix[i];

        if (isOperand(ch)) {
            push(ch - '0'); // Convert char to integer and push onto stack
        } else {
            if (top < 1) {
                printf("Invalid Postfix Expression\n");
                return 1;
            }
            op2 = pop();
            op1 = pop();
            switch (ch) {
		 case '+':  r = op1 + op2;
		            break;
		 case '-':  r = op1 - op2;
		            break;
		 case '*':  r = op1 * op2;
		            break;
		 case '/':  if (op2 == 0) {
		                printf("Error: Division by zero\n");
		                return 1;
		            }
		            r = op1 / op2;
		            break;
		 case '%':  if (op2 == 0) {
		                printf("Error: Division by zero\n");
		                return 1;
		            }
		            r = op1 % op2;
		            break;
		 default :   printf("Invalid operator %c\n", ch);
		            return 1;
            }
            push(r);
        }
    }

    if (top != 0) {
        printf("Invalid Postfix Expression\n");
    } else {
        r = pop();
        printf("Result = %d\n", r);
    }

    return 0;
}

