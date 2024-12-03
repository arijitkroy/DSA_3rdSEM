#include <stdio.h>
#define MAX 30

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
}

void bubbleSort(int arr[], int n) {
    int i, j, tmp, p = 1, c = 0;
    for (i = 0; i < n - 1; i++) {
        printf("\nPass %d: ", p++);
        for (j = 0; j < n - i - 1; j++) {
            c++;
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        display(arr, n);
        printf("(No. of comparisons: %d)", c);
        c = 0;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, tmp, p = 1, c = 0, min, pos;
    for (i = 0; i < n - 1; i++) {
        printf("\nPass %d: ", p++);
        min = i;
        for (j = i + 1; j < n; j++) {
            c++;
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) {
            tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
        display(arr, n);
        printf("(No. of comparisons: %d)", c);
        c = 0;
    }
}

void insertionSort(int arr[], int n) {
    int i, j, tmp, p = 1, c = 0;
    for (i = 1; i < n; i++) {
        printf("\nPass %d: ", p++);
        tmp = arr[i];
        j = i - 1;
        while (j >= 0 && tmp < arr[j]) arr[j+1] = arr[j--], c++;
        arr[j+1] = tmp;
        display(arr, n);
        printf("(No. of comparisons: %d)", c);
        c = 0;
    }
}

int partition(int arr[], int p, int r) {
    int x = arr[p], i = p, j = r, tmp;
    while (i < j) {
        while (arr[i] <= x) i++;
        while (arr[j] > x) j--;
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[p];
    arr[p] = arr[j];
    arr[j] = tmp;
    return j;
}

void merge(int arr[], int l, int m, int h) {
    int i = l, j = m + 1, k = l, c[MAX];
    while (i <= m && j <= h) {
        if (arr[i] < arr[j]) c[k++] = arr[i++];
        else c[k++] = arr[j++];
    }
    while (i <= m) c[k++] = arr[i++];
    while (j <= h) c[k++] = arr[j++];
    for (i = l; i <= h; i++) arr[i] = c[i];
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int m = partition(arr, p, r);
        quickSort(arr, p, m - 1);
        quickSort(arr, m + 1, r);
    }
}

void mergeSort(int arr[], int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

void inputData(int arr[], int *n) {
    int i;
    printf("Total number of elements: ");
    scanf("%d", &(*n));
    for (i = 0; i < *n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void main() {
    int arr[MAX], n, i, y = 1, ch;
    while (y) {
        printf("\nSorting techniques:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n6. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                inputData(arr, &n);
                printf("Before Sort: ");
                display(arr, n);
                bubbleSort(arr, n);
                printf("\nAfter Sort: ");
                display(arr, n);
                break;
            case 2:
                inputData(arr, &n);
                printf("Before Sort: ");
                display(arr, n);
                selectionSort(arr, n);
                printf("\nAfter Sort: ");
                display(arr, n);
                break;
            case 3:
                inputData(arr, &n);
                printf("Before Sort: ");
                display(arr, n);
                insertionSort(arr, n);
                printf("\nAfter Sort: ");
                display(arr, n);
                break;
            case 4:
                inputData(arr, &n);
                printf("Before Sort: ");
                display(arr, n);
                mergeSort(arr, 0, n - 1);
                printf("\nAfter Sort: ");
                display(arr, n);
                break;
            case 5:
                inputData(arr, &n);
                printf("Before Sort: ");
                display(arr, n);
                quickSort(arr, 0, n - 1);
                printf("\nAfter Sort: ");
                display(arr, n);
                break;
            case 6:
                y = 0;
                break;
            default:
                printf("Invalid choice!");
        }
    }
}