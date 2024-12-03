#include <stdio.h>
#define MAX 20

int binarySearch(int arr[], int n, int key) {
    int l = 0, h = n - 1, c = 0;
    while (l <= h) {
        c++;
        int m = (l + h) / 2;
        if (arr[m] == key) {
            printf("No of comparisons: %d\n", c);
            return m;
        }
        else if (arr[m] < key) l = m + 1;
        else h = m - 1;
    }
    printf("No of comparisons: %d\n", c);
    return -1;
}

int interpolationSearch(int arr[], int n, int key) {
    int l = 0, h = n - 1, c = 0;
    while (l <= h) {
        c++;
        int m = l + ((key - arr[l]) * (h - l)) / (arr[h] - arr[l]);
        if (arr[m] == key) {
            printf("No of comparisons: %d\n", c);
            return m;
        }
        else if (arr[m] < key) l = m + 1;
        else h = m - 1;
    }
    printf("No of comparisons: %d\n", c);
    return -1;
}

void main() {
    int arr[MAX], n, key, i, y = 1;
    printf("Total no. of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("Element to search: ");
    scanf("%d", &key);
    while (y) {
        printf("Searching techniques:\n1. Binary Search\n2. Interpolation Search\n3. Exit\nEnter choice: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                i = binarySearch(arr, n, key);
                if (i == -1) printf("Element %d not found\n", key);
                else printf("Element %d found at index %d\n", key, i);
                break;
            case 2:
                i = interpolationSearch(arr, n, key);
                if (i == -1) printf("Element %d not found\n", key);
                else printf("Element %d found at index %d\n", key, i);
                break;
            case 3:
                y = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}