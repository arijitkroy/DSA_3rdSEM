#include <stdio.h>
#define SIZE 30
void insertAtPos(int arr[], int *n, int key, int pos) {
    for (int i = *n - 1; i >= pos - 1; i--) arr[i+1] = arr[i];
    arr[pos-1] = key;
    *n += 1;
}
void deleteAtPos(int arr[], int *n, int pos) {
    for (int i = pos - 1; i < *n - 2; i++) arr[i] = arr[i+1];
    *n -= 1;
}
void replaceAtPos(int arr[], int key, int pos) {
    arr[pos-1] = key;
}
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) if (arr[i] == key) return ++i;
    return -1;
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
void main() {
    int flag = 1, choice, array[SIZE], n, key, pos, res;
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }
    do {
        printf("\nCommand list:\n1. Insertion\n2. Deletion\n3. Replace\n4. \
        Linear Search\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter key and position: ");
                scanf("%d %d", &key, &pos);
                insertAtPos(array, &n, key, pos);
                printf("Success!");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(array, &n, pos);
                printf("Success!");
                break;
            case 3:
                printf("Enter key and position: ");
                scanf("%d %d", &key, &pos);
                replaceAtPos(array, key, pos);
                printf("Success!");
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                res = linearSearch(array, n, key);
                if (res == -1) printf("Key %d not found.", key);
                else printf("Key %d found at position %d.", key, res);
                break;
            case 5:
                display(array, n);
                break;
            case 6:
                flag = 0;
                break;
            default:
                printf("Invalid choice");
        }
    } 
    while (flag);
}