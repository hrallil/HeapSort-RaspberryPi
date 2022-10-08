#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXCHAR 100000

int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] < a[m]) {
        m = j;
    }
    if (k < n && a[k] < a[m]) {
        m = k;
    }
    return m;
}

void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}

void heapsort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}

int main () {
    int dataSizes[] = {4000,6000,8000,10000,12000,14000};

    for(int i = 0; i < sizeof dataSizes / sizeof dataSizes[0]; i++){

        int a[dataSizes[i]];
        int n = sizeof a / sizeof a[0];
        for(int j = 0;j<n; j++){
            a[j] = j;
        }

        int k;
        printf("unsorted...\n");
        for (k = 0; k < n; k++)
            printf("%d%s", a[k], k == n - 1 ? "\n" : " ");

        printf("sorting...\n");
        heapsort(a, n);

        for (k = 0; k < n; k++)
            printf("%d%s", a[k], k == n - 1 ? "\n" : " ");

    }
    return 0;
}
