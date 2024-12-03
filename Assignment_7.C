#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* next;
} *stack = NULL, *queue = NULL;

void PUSH(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = stack;
    stack = newNode;
}

void POP() {
    struct Node *temp = stack;
    if (temp == NULL) printf("Stack is Empty!\n");
    else {
        stack = stack->next;
        printf("Removed %d from STACK\n", temp->data);
        free(temp);
    }
}

void ENQUE(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *curr = queue;
    newNode->data = k;
    newNode->next = NULL;
    if (queue == NULL) queue = newNode;
    else {
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

void DELQUE() {
    struct Node *temp = queue;
    if (temp == NULL) printf("Queue is Empty!\n");
    else {
        queue = queue->next;
        printf("Removed %d from QUEUE\n", temp->data);
        free(temp);
    }
}

void TRAVERSE(struct Node *n) {
    if (n == NULL) printf("Empty!");
    else {
        while (n) {
            printf("%d ", n->data);
            n = n->next;
        }
        printf("\n");
    }
}

int main() {
    int on = 1, active = 0, res1, res2, item;
    while (on) {
        printf("Menu:\n1. STACK Operations\n2. QUEUE Operations\n3. EXIT\nEnter Choice: ");
        scanf("%d", &res1);
        switch (res1) {
            case 1:
                active = 1;
                while (active) {
                    printf("Stack Operations:\n1. PUSH\n2. POP\n3. PEEK\n4. TRAVERSE\n5. BACK\nEnter Choice: ");
                    scanf("%d", &res2);
                    switch (res2) {
                        case 1:
                            printf("Enter Element: ");
                            scanf("%d", &item);
                            PUSH(item);
                            break;
                        case 2:
                            POP();
                            break;
                        case 3:
                            printf("Topmost element: %d\n", stack->data);
                            break;
                        case 4:
                            TRAVERSE(stack);
                            break;
                        case 5:
                            active = 0;
                            break;
                        default:
                            printf("Incorrect Choice!\n");
                    }
                }
                break;
            case 2:
                active = 1;
                while (active) {
                    printf("Queue Operations:\n1. ENQUE\n2. DELQUE\n3. TRAVERSE\n4. BACK\nEnter Choice: ");
                    scanf("%d", &res2);
                    switch (res2) {
                        case 1:
                            printf("Enter Element: ");
                            scanf("%d", &item);
                            ENQUE(item);
                            break;
                        case 2:
                            DELQUE();
                            break;
                        case 3:
                            TRAVERSE(queue);
                            break;
                        case 4:
                            active = 0;
                            break;
                        default:
                            printf("Incorrect Choice!\n");
                    }
                }
                break;
            case 3:
                on = 0;
                break;
            default:
                printf("Incorrect Choice!\n");
        }
    }
}