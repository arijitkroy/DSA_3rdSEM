#include <stdio.h>
#define MAX 20
int TOP = -1;

void PUSH(int s[]) {
    int item;
    if (TOP == MAX - 1) printf("Stack Overflow\n");
    else {
        printf("Enter element: ");
        scanf("%d", &item);
        s[++TOP] = item;
    }
}

int POP(int s[]) {
    if(TOP == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s[TOP--];
}

void TRAVERSE(int s[]) {
    int i;
    if(TOP == -1) printf("Stack Underflow\n");
    else for (i = TOP; i >= 0; i--) printf("%d\n", s[i]);
}

void main() {
    int STACK[MAX], choice, item, flag = 1;
    while (flag) {
        printf("1. PUSH\n2. POP\n3. TRAVERSE\n4. EXIT\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                PUSH(STACK);
                break;
            case 2:
                item = POP(STACK);
                if (item != -1) printf("Popped %d from STACK\n", item);
                break;
            case 3:
                TRAVERSE(STACK);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid options!");
        }
    }
}
