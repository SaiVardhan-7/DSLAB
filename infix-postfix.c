#include <stdio.h>
#include <ctype.h> // for isalnum()

char stack[100];
int top = -1;

int push(char ele) {
    stack[++top] = ele;
    return 0;
}

int pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int priority(char ch) {
    if (ch == '(') return 0;
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/' || ch == '%') return 2;
    return -1; // Default for other characters
}

int main() {
    char infix[100];
    char ch, x;
    int i;

    printf("Enter the Infix expression: ");
    fgets(infix, sizeof(infix), stdin);  // safer than gets()

    for (i = 0; infix[i] != '\0' && infix[i] != '\n'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            printf("%c ", ch);
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((x = pop()) != '(') {
                printf("%c ", x);
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                printf("%c ", pop());
            }
            push(ch);
        }
    }

    while (top != -1) {
        printf("%c ", pop());
    }

    return 0;
}

