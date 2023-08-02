#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int count = 0;
int partition(int * arr,int low,int high)
{
//  int pivot =arr[beg];
//  int i=beg,j=end+1;
 int pivot = arr[low];
       int i = low, j = high;
       
        while(i < j) {
           while(arr[i] <= pivot && i <= high-1) {
               i++; count++;
           }
           while(arr[j] > pivot && j >= low + 1) {
               j--; count++;
           }
           if(i < j) swap(&arr[i], &arr[j]);
       }
       swap(&arr[low], &arr[j]);
       return j;
}

void quicksort(int *arr,int beg,int end)
{
 if(beg<end)
 {
  int split=partition(arr,beg,end);
  quicksort(arr,beg,split-1);
  quicksort(arr,split+1,end);
 }
}

void main()
{

    int *arr, n;

    srand(time(NULL));
    FILE *f;

    f = fopen("quick_time.txt", "w");

    n = 4;
    while (n < 1034)
    {
        arr = (int *)malloc(sizeof(int) * n);

        // Best case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = 5;
        quicksort(arr, 0, n - 1, &count);
        fprintf(f, "%d\t%d\t", n, count);
        // printf("%d\t%d\t", n, count);

        // AVG case
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        count = 0;
        quicksort(arr, 0, n - 1, &count);
        fprintf(f, "%d\t", count);
        // printf("%d\t%d\t", n, count);

        // worst case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        quicksort(arr, 0, n - 1, &count);
        fprintf(f, "%d\n", count);
        // printf("%d\t%d\n", n, count);

        n = n * 2;

        free(arr);
    }

    fclose(f);
    system("gnuplot>load 'quick_plot.txt'");
    system("gnuplot>load 'quick_plot1.txt'");
}
