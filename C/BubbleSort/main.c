#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 100000

void bubble_sort (int *a, int n) {
    int i, t, j = n, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = 1;
            }
        }
        j--;
    }
}

int main () {
    int dataSizesSorted[] = {30,90,120,270,570,1080};
    int dataSizesRev[] = {100,150,250,420,800};



    for(int i = 0; i < sizeof dataSizesSorted; i++){
        int a[dataSizesSorted[i]];
        int n = sizeof a / sizeof a[0];

        for(int j = n-1; j>=0; j--){
            a[j] = n-j;
        }

        int k;
        printf("unsorted...\n");
        for (k = 0; k < n; k++)
            printf("%d%s", a[k], k == n - 1 ? "\n" : " ");

        printf("Fist element is: %d \n",a[0]);
        printf("sorting...\n");
        bubble_sort(a, n);

        for (k = 0; k < n; k++)
            printf("%d%s", a[k], k == n - 1 ? "\n" : " ");

    }
    return 0;
}
