#include <stdio.h>
#include <malloc.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} *head = NULL;

struct Node *newNode(int key) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

struct Node *insert(struct Node *h, int key) {
    if (h == NULL) return newNode(key);
    if (h->data == key) return h;
    if (key < h->data) h->left = insert(h->left, key);
    else h->right = insert(h->right, key);
}

void preOrder(struct Node *h) {
    if (h != NULL) {
        printf("%d ", h->data);
        preOrder(h->left);
        preOrder(h->right);
    }
}

void inOrder(struct Node *h) {
    if (h != NULL) {
        inOrder(h->left);
        printf("%d ", h->data);
        inOrder(h->right);
    }
}

void postOrder(struct Node *h) {
    if (h != NULL) {
        postOrder(h->left);
        postOrder(h->right);
        printf("%d ", h->data);
    }
}

void main() {
    int y = 1, ch, key;
    while (y) {
        printf("\nBST Operations:\n1. Insert Node\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                head = insert(head, key);
                break;
            case 2:
                inOrder(head);
                break;
            case 3:
                preOrder(head);
                break;
            case 4:
                postOrder(head);
                break;
            case 5:
                y = 0;
                break;
            default:
                printf("Invalid choice");
        }
    }
}