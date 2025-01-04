#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 20

int TOP = -1, STACK[SIZE];

void PUSH(int k) {
    if (TOP == SIZE - 1) printf("Overflow\n");
    else STACK[++TOP] = k;
}

int POP() {
    if (TOP == -1) return -1;
    return STACK[TOP--];
}

void main() {
    char postfixExp[SIZE], c;
    int l, num, i, res, A, B;
    printf("Enter Postfix Expression: ");
    scanf("%s", &postfixExp);
    for (l = 0; postfixExp[l]; l++);
    postfixExp[l++] = ')';
    postfixExp[l++] = '\0';
    for (i = 0; postfixExp[i] != ')'; i++) {
        c = postfixExp[i];
        if (isdigit(c)) {
            num = c - '0';
            PUSH(num);
        }
        else {
            A = POP();
            B = POP();
            switch (c) {
                case '+':
                    res = B + A;
                    break;
                case '-':
                    res = B - A;
                    break;
                case '*':
                    res = B * A;
                    break;
                case '/':
                    if (A == 0) printf("Divide by 0 error\n"), exit(0);
                    res = B / A;
                    break;
                case '^':
                    if (A < 2) res = B; 
                    else while (A--) res = B * B;
            }
            PUSH(res);
        }
    }
    printf("Result: %d", POP());
}
