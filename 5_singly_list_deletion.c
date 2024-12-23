#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* create(struct Node* head, int data);
struct Node* deleteFirst(struct Node* head);
struct Node* deleteLast(struct Node* head);
struct Node* deleteSpecific(struct Node* head, int key);
void display(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a node\n");
        printf("2. Delete first element\n");
        printf("3. Delete specific element\n");
        printf("4. Delete last element\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            head = create(head, value);
            break;
        case 2:
            head = deleteFirst(head);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            head = deleteSpecific(head, key);
            break;
        case 4:
            head = deleteLast(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
struct Node* create(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("First element deleted successfully.\n");
    return head;
}
struct Node* deleteSpecific(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    if (head->data == key) {
        return deleteFirst(head);
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", key);
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Element %d deleted successfully.\n", key);
    }

    return head;
}
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("list is empty\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        printf("last element deleted \n");
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("last element deleted \n");
    return head;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
}
}
