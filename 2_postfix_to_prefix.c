#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 3

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char ch, temp;

    while ((ch = infix[i++]) != '\0') {
        switch (ch) {
            case '(':  /
                push(ch);
                break;

            case ')':  
                while ((temp = pop()) != '(') {
                    postfix[j++] = temp;
                }
                break;

            default:
                if (isalnum(ch)) {
                   postfix[j++] = ch;
                } else if (isOperator(ch)) {
                    
                    while (top != -1 && precedence(peek()) >= precedence(ch)) {
                        postfix[j++] = pop();
                    }
                    push(ch);
                }
                break;
        }
    }

    
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

return 0; }
