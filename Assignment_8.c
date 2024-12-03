#include <stdio.h>
#include <malloc.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node *addNode(struct Node *p, int co, int ex) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *ptr;
    newNode->coeff = co;
    newNode->exp = ex;
    newNode->next = NULL;
    if (p == NULL) p = newNode;
    else {
        ptr = p;
        while (ptr->next) ptr = ptr->next;
        ptr->next = newNode;
    }
    return p;
}

struct Node *addPoly(struct Node *p1, struct Node *p2, struct Node *p3) {
    struct Node *ptr1 = p1, *ptr2 = p2;
    int x;
    while (ptr1 && ptr2) {
        if (ptr1->exp > ptr2->exp) {
            p3 = addNode(p3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if (ptr2->exp > ptr1->exp) {
            p3 = addNode(p3, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
        else {
            x = ptr1->coeff + ptr2->coeff;
            p3 = addNode(p3, x, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    if (ptr2 == NULL) {
        while (ptr1) {
            p3 = addNode(p3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    if (ptr1 == NULL) {
        while (ptr2) {
            p3 = addNode(p3, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    return p3;
}

void display(struct Node *p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
}

void main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *polyOut = NULL;
    int c, e, x, on = 1;
    while (on) {
        
        printf("\nCreation of First Polynomial:");
        do {
            printf("\nEnter coefficient and exponent: ");
            scanf("%d %d", &c, &e);
            poly1 = addNode(poly1, c, e);
            printf("\n-1 to Stop (Any key to Continue): ");
            scanf("%d", &x);
        } while (x != -1);
        printf("\nFirst Polynomial: ");
        display(poly1);

        printf("\nCreation of Second Polynomial:");
        do {
            printf("\nEnter coefficient and exponent: ");
            scanf("%d %d", &c, &e);
            poly2 = addNode(poly2, c, e);
            printf("\n-1 to Stop (Any key to Continue): ");
            scanf("%d", &x);
        } while (x != -1);
        printf("\nSecond Polynomial: ");
        display(poly2);

        printf("\nAddition of Polynomial: ");
        polyOut = addPoly(poly1, poly2, polyOut);
        display(polyOut);

        printf("\n0 to Stop (Any key to Continue): ");
        scanf("%d", &on);
    }
}