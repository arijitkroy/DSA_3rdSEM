#include <stdio.h>
#define MAX 20

void Tower(int n, int src, int aux, int end) {
    if (n == 1) printf("Move disk 1 from %c to %c\n", src, end);
    else {
        Tower(n - 1, src, end, aux);
        printf("Move disk %d from %c to %c\n", n, src, end);
        Tower(n - 1, aux, src, end);
    }
}

void main() {
    int n;
    printf("Enter no. of disks: ");
    scanf("%d", &n);
    Tower(n, 'A', 'B', 'C');
}