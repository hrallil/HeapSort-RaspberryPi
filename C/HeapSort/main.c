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
    int s = 4000; // dataset size
    int num[MAXCHAR];
    int a[s];
    int n = sizeof a / sizeof a[0];
    FILE *fpt;
    FILE *fr;





    /*   CSV file with data from 1 to s
    fpt = fopen("heapSort16000.csv", "w+"); //make file if not there
    for (int i = 0; i < 16000; ++i) {
        fprintf(fpt,"%d\n", i);
    }
    fclose(fpt);
    */
    //file read

    for(int k = 0; k<7;k++){
        char filename[32];
        sprintf(filename,"heapSort%d.csv",s);
        fr = fopen(filename, "r");
        for (int i = 0; i < s; ++i) {
            fgets(num, MAXCHAR, fr);
            a[i] = atoi(num);
        }

        for(int j = 0;j<1;j++){
            fclose(fr);
            for(int i = 0; i<10000;i++)
                heapsort(a, n);
            // printf("spike!\n");
        }
        // printf("datachange\n");
        s+=2000;
    }
    return 0;
}
