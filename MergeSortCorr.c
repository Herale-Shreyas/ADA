
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ct = 0;
void merge(int arr[], int l, int m, int r)
    {
        int left = m - l + 1;
        int right = r-m;
         
        int leftArr[left], rightArr[right];
        
        for(int i=0;i<left;i++)
        leftArr[i] = arr[l + i];
        for(int i=0; i < right; i++){
            rightArr[i] = arr[m+1+i];
        }
        int i=0, j=0, k=l;
         
        while(i < left && j < right){
            ct++;
            if(leftArr[i] < rightArr[j])
                arr[k++] = leftArr[i++];
            else
                arr[k++] = rightArr[j++];
        }
        
        while(i < left)
            arr[k++] = leftArr[i++];
        while (j < right)
            arr[k++] = rightArr[j++];
         
    }
void mergeSort(int arr[], int l, int r)
  {
        if(l < r){
            int mid = l + (r-l)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }

void worst_merge(int a[], int lf[], int rt[], int l, int m, int r)
{
  int i;
  for (i = 0; i <= m - l; i++)
  {
    a[i] = lf[i];
  }
  for (int j = 0; j < r - m; j++)
  {
    a[i + j] = rt[j];
  }
}
void split(int a[], int lf[], int rt[], int l, int m, int r)
{
  int i;
  for (i = 0; i <= m - l; i++)
  {
    lf[i] = a[i * 2];
  }
  for (i = 0; i < r - m; i++)
  {
    rt[i] = a[i * 2 + 1];
  }
}
void gen_worst_data(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    int lf[m - l + 1];
    int rt[r - m];
    split(a, lf, rt, l, m, r);
    gen_worst_data(lf, l, m);
    gen_worst_data(rt, m + 1, r);
    worst_merge(a, lf, rt, l, m, r);
  }
}

void main()
{
  srand(time(NULL));
  int n = 4, *a, i;

  {
    n *= 2;
    ct = 0;
    a = (int *)malloc(n * sizeof(int));

    // best case
    for (i = 0; i < n; i++)
      a[i] = i + 1;
      printf("\nArray before sorting\n");
      for(int i=0; i<n; i++) printf("%d ", a[i]);
    mergeSort(a, 0, n-1);
    
    printf("Array after sorting\n");
      for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("Count=%d\n", n, ct);

    // Average case
    ct = 0;
    for (i = 0; i < n; i++)
      a[i] = rand()%100;
      printf("\n\nArray before sorting\n");
      for(int i=0; i<n; i++) printf("%d ", a[i]);
    mergeSort(a, 0, n-1);

    printf("\nArray after sorting\n");
      for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("Count=%d\t", ct);

    // worst case
    ct = 0;
    for (i = 0; i < n; i++)
      a[i] = i + 1;
    gen_worst_data(a, 0, n - 1);
    printf("\n\nArray before sorting\n");
      for(int i=0; i<n; i++) printf("%d ", a[i]);
    mergeSort(a, 0, n-1);

    printf("\nArray after sorting\n");
      for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\nCount=%d\t", ct);
  
}
