#include <stdio.h>
#define MAX 10
int TOP = -1, STACK[MAX];

void PUSH(int key) {
    if (TOP == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    TOP = TOP + 1;
    STACK[TOP] = key;
}

int POP() {
    int value;
    if (TOP == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    value = STACK[TOP--];
    return value;
}

void DISPLAY() {
    int i;
    if (TOP == -1) {
        printf("Stack is empty!\n");
        return;
    }
    for (i = TOP; i >= 0; i--)
        printf("%d\n", STACK[i]);
}

void main() {
    int key, p, flag = 1, choice;
    do {
        printf("Menu:\n1. PUSH\n2. POP\n3. DISPLAY\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &key);
                PUSH(key);
                break;
            case 2:
                p = POP();
                if (p != NULL) printf("Popped %d from the stack", p);
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (flag);
}