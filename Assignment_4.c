#include <stdio.h>
#define MAX 10
int FRONT = -1, REAR = -1;

void ENQUE(int cq[]) {
    int item;
    if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
        printf("CQUEUE Overflow\n");
        return;
    }
    else if (FRONT == -1 && REAR == -1) FRONT = REAR = 0;
    else REAR = (REAR + 1) % MAX;
    printf("Enter element: ");
    scanf("%d", &item);
    cq[REAR] = item;
}

int DELQUE(int cq[]) {
    int value;
    if(FRONT == -1) {
        printf("CQUEUE Underflow\n");
        return -1;
    }
    value = cq[FRONT];
    if (FRONT == REAR) FRONT = REAR = -1;
    else FRONT = (FRONT + 1) % MAX;
    return value;
    
}

void TRAVERSE(int cq[]) {
    int i;
    if(FRONT == -1 && REAR == -1) printf("CQUEUE Underflow\n");
    else {
        for (i = FRONT; i != REAR; i = (i + 1) % MAX) printf("%d ", cq[i]);
        printf("%d\n", cq[REAR]);
    }
}

void main() {
    int choice, flag = 1, CQUEUE[MAX], item;
    while (flag) {
        printf("\n1. ENQUE\n2. DELQUE\n3. TRAVERSE\n4. EXIT\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                ENQUE(CQUEUE);
                break;
            case 2:
                item = DELQUE(CQUEUE);
                if (item != -1) printf("Removed %d from CQUEUE\n", item);
                break;
            case 3:
                TRAVERSE(CQUEUE);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid options!");
        }
    }
}
