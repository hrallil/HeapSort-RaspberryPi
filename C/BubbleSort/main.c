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

    int s = 30; // dataset size
    int num;
    int a[s];
    int n = sizeof a / sizeof a[0];
    FILE *fpt;
    FILE *fr;


    //   CSV file with data from 1 to s
    char filename[32];
    sprintf(filename,"revsortBubblSort%d.csv",s);
    fpt = fopen(filename, "w+"); //make file if not there
    printf("\n Writing... ");
    for (int i = s; i > 0; --i) {
        fprintf(fpt,"%d\n", i);
        printf("%d ",i);
    }

    fclose(fpt);


    sprintf(filename,"bubblSort%d.csv",s);
    fr = fopen(filename, "r");
    printf("\n Reading... ");
    for (int i = 0; i < s; ++i) {
        fgets(num, 100, fr);
        printf("%d",num);
        a[i] = atoi(num);
        printf("%d ",a[i]);
    }
    printf("\n");

    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");


    bubble_sort(a, n);

    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");

    return 0;
}
