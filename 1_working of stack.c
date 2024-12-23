#include <stdio.h>
#include <conio.h>
#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

void main() {
    int value, choice;
    clrscr();
    while (1) {
        printf("\n MENU:");
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. End");
        
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n Enter value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Wrong selection");
        }
    }
}

void push(int value) {
    if (top == SIZE - 1)
        printf("\n Stack is full");
    else {
        top++;
        stack[top] = value;
        printf("\n Insertion successful");
    }
}

void pop() {
    if (top == -1)
        printf("\n Stack is empty");
    else {
        printf("\n Deleted : %d", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("\n Stack is empty");
    else {
        printf("\n Stack elements are : \n");
        for (int i = top; i >= 0; i--)
            printf("%d \n", stack[i]);
    }
}
