#include <stdio.h>  
#include <stdlib.h>  
#define SIZE 5  

int queue[SIZE];  
int front = -1, rear = -1;  

int isFull() {  
    if ((front == 0 && rear == SIZE - 1) ||  
        (front == rear + 1))  
        return 1;  
    return 0;  
}  

int isEmpty() {  
    if (front == -1)  
        return 1;  
    return 0;  
}  

void insert(int element) {  
    if (isFull()) {  
        printf("Queue is full.\n");  
        return;  
    }  
    if (front == -1) {  
        front = 0;  
    }  
    rear = (rear + 1) % SIZE;  
    queue[rear] = element;  
    printf("Inserted %d\n", element);  
}  
void delete() {  
    if (isEmpty()) {  
        printf("Queue underflow\n");  
        return;  
    }  
    printf("Deleted %d\n", queue[front]);  
    if (front == rear) {  
        front = rear = -1;  
    } else {  
        front = (front + 1) % SIZE;  
    }  
}  

void display() {  
    if (isEmpty()) {  
        printf("Queue is empty.\n");  
        return;  
    }  
    printf("Queue elements are: ");  
    int i = front;  
    while (i != rear) {  
        printf("%d ", queue[i]);  
        i = (i + 1) % SIZE;  
    }  
    printf("%d\n", queue[rear]);  
}  
int main() {  
    int choice, value;  
    while (1) {  
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch (choice) {  
            case 1:  
                printf("Enter value to be inserted: ");  
                scanf("%d", &value);  
                insert(value);  
                break;  
            case 2:  
                delete();  
                break;  
            case 3:  
                display();  
                break;  
            case 4:  
                exit(0);  
            default:  
                printf("Wrong choice.\n");  
        }  
    }  
    return 0;  
}
