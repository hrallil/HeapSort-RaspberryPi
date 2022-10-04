#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXCHAR 1000

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
    int s = 4000; // dataset size
    int num[MAXCHAR];
    int a[s];
    FILE *fpt;
    fpt = fopen("heapSort4000.csv", "w+"); //make file if not there




    /*   fill file with 1-s
    for (int i = 0; i < s; ++i) {
        fprintf(fpt,"%d\n", i);
    }
    fclose(fpt);
    */
    //file read
    FILE *fr;
    fr = fopen("heapSort4000.csv", "r");
    for (int i = 0; i < s; ++i) {
        fgets(num, MAXCHAR, fr);
        a[i] = atoi(num);
    }

    fclose(fr);

    int n = sizeof a / sizeof a[0];
    /*
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    printf("\n");
    printf("Sorting...\n");
    */
    for(int i = 0; i<10000;i++)
        heapsort(a, n);
    /*
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
        */
    return 0;
}
