#include <stdio.h>
#define MAX 20
int FRONT = -1, REAR = -1;

void ENQUE(char q[]) {
    char item;
    if (REAR == MAX - 1) printf("Queue Overflow\n");
    else if (FRONT == -1) FRONT = 0;
    else {
        printf("Enter element: ");
        scanf(" %c", &item);
        q[++REAR] = item;
    }
}

char DELQUE(char q[]) {
    if(FRONT == -1 && REAR == -1 || FRONT > REAR) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q[FRONT++];
}

void TRAVERSE(char q[]) {
    int i;
    if(FRONT == -1 && REAR == -1 || FRONT > REAR) printf("Queue Underflow\n");
    else for (i = FRONT; i <= REAR; i++) printf("%c ", q[i]);
}

void main() {
    int choice, flag = 1;
    char QUEUE[MAX], item;
    while (flag) {
        printf("\n1. ENQUE\n2. DELQUE\n3. TRAVERSE\n4. EXIT\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                ENQUE(QUEUE);
                break;
            case 2:
                item = DELQUE(QUEUE);
                if (item != -1) printf("Removed %c from QUEUE\n", item);
                break;
            case 3:
                TRAVERSE(QUEUE);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid options!");
        }
    }
}
