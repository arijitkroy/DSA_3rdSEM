#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void insertAtBegin(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *curr = head;
    newNode->data = k;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void insertAtPos(int k, int pos) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *curr = head;
    int i = 0;
    newNode->data = k;
    newNode->next = NULL;
    while (curr) {
        i++;
        if (i == pos - 1) {
            newNode->next = curr->next;
            curr->next = newNode;
            break;
        }
        curr = curr->next;
    }
}

void deleteFromBegin() {
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node)), *temp = head;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    if (head == temp) head = NULL;
    else prev->next = NULL;
    free(temp);
}

void deleteFromPos(int pos) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *curr = head;
    int i = 1;
    while (i < pos - 1) {
        curr = curr->next;
        i++;
    }
    temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

void display() {
    struct Node *curr = head;
    if (curr == NULL) printf("LL is empty!");
    else {
        while (curr) {
            printf(" || %d | %u || ", curr->data, curr->next);
            if (curr->next) printf("-->");
            curr = curr->next;
        }
    }
}

int main() {
    int y = 1, ch, item, pos;
    while (y) {
        printf("Singly Linked List operations:\n1. Insert At Beginning\n2. Insert At End\n3. Insert At Any Position\n4. Delete From Beginning\n5. Delete From End\n6. Delete From Any Position\n7. Display\n8. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &item);
                insertAtBegin(item);
                break;
            case 2:
                printf("Enter Element: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;
            case 3:
                printf("Enter Element and Position: ");
                scanf("%d %d", &item, &pos);
                insertAtPos(item, pos);
                break;
            case 4:
                deleteFromBegin();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteFromPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                y = 0;
                break;
            default:
                printf("Invalid choice!");
        }
    }
}