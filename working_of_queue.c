#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void insert();
void delete();
void display();

int front = -1, rear = -1;
int queue[SIZE];

void main() {
    int choice = 1;
    while (choice != 4) {
        printf("\nEnter choice: \n1) Insert \n2) Delete \n3) Display \n4) Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(1); break;
            default: printf("Wrong choice\n"); break;
        }
    }
}

void insert() {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        int element;
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
        if (front == -1) {
            front = 0;
        }
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is underflow\n");
    } else {
        int del = queue[front];
        printf("Element deleted is: %d\n", del);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("No elements in queue\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
