#include <stdio.h>
#define MAX 5
int FRONT = -1, REAR = -1;
char QUEUE[MAX];

void ENQUE(char key) {
    if (REAR == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (FRONT == -1 && REAR == -1) {
        FRONT = REAR = 0;
    }
    else {
        REAR += 1;
    }
    QUEUE[REAR] = key;
}

char DELQUE() {
    char value;
    if (FRONT > REAR || FRONT == -1) {
        printf("Queue Underflow\n");
        return NULL;
    }
    value = QUEUE[FRONT++];
    return value;
}

void DISPLAY() {
    int i;
    if (FRONT > REAR || FRONT == -1) {
        printf("Queue Underflow\n");
        return;
    }
    for (i = FRONT; i <= REAR; i++) {
        printf("%c ", QUEUE[i]);
    }
    printf("\n");
}

void main() {
    char key, delChar;
    int flag = 1, choice;
    do {
        printf("Menu:\n1. ENQUE\n2. DELQUE\n3. DISPLAY\n4. EXIT\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf(" %c", &key);
                ENQUE(key);
                break;
            case 2:
                delChar = DELQUE();
                if (delChar) printf("Deleted %c from QUEUE\n", delChar);
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