#include <stdio.h>
#define MAX 5
int FRONT = -1, REAR = -1, CQUEUE[MAX];

void ENQUE(int key) {
    if ((FRONT == 0 && REAR == MAX - 1) || FRONT == REAR + 1) {
        printf("CQUEUE Overflow\n");
        return;
    }
    if (FRONT == -1 && REAR == -1) {
        FRONT = REAR = 0;
    }
    else {
        REAR = (REAR + 1) % MAX;
    }
    CQUEUE[REAR] = key;
}

int DELQUE() {
    int value;
    if (FRONT == -1) {
        printf("CQUEUE Underflow\n");
        return NULL;
    }
    else if (FRONT == REAR) {
        value = CQUEUE[FRONT];
        FRONT = REAR = -1;
    }
    else {
        value = CQUEUE[FRONT];
        FRONT = (FRONT + 1) % MAX;
    }
    return value;
}

void DISPLAY() {
    int i;
    if (FRONT == -1) {
        printf("CQUEUE Underflow\n");
        return;
    }
    else {
        i = FRONT;
        while (i != REAR) {
            printf("%d ", CQUEUE[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", CQUEUE[REAR]);
    }
}

void main() {
    int key, delChar, flag = 1, choice;
    do {
        printf("Menu:\n1. ENQUE\n2. DELQUE\n3. DISPLAY\n4. EXIT\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &key);
                ENQUE(key);
                break;
            case 2:
                delChar = DELQUE();
                if (delChar) printf("Deleted %d from CQUEUE\n", delChar);
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