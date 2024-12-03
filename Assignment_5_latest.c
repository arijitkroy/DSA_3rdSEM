#include <stdio.h>
#include <ctype.h>
#define MAX 30
int TOP = -1;
char STACK[MAX];

int isEmpty() {
    return TOP == -1;
}

int isFull() {
    return TOP == MAX - 1;
}

char PEEK() {
    return STACK[TOP];
}

void PUSH(char k) {
    if (isFull()) printf("Stack overflow");
    else STACK[++TOP] = k;
}

char POP() {
    if (isEmpty()) return -1;
    return STACK[TOP--];
}

int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void main() {
    int i, j = 0;
    char exp[MAX], res[MAX], c, x;
    printf("Enter infix expression: ");
    scanf("%s", &exp);
    for (i = 0; exp[i]; i++) {
        c = exp[i];
        if (isalnum(c)) res[j++] = c;
        else if (c == '(') PUSH(c);
        else if (c == ')') {
            while (!isEmpty() && PEEK() != '(') res[j++] = POP();
            if (PEEK() == '(') POP();
        }
        else {
            while (!isEmpty() && priority(c) <= priority(PEEK())) {
                res[j++] = POP();
            }
            PUSH(c);
        }
    }
    while (!isEmpty()) res[j++] = POP();
    res[j] = '\0';
    printf("%s", res);
}