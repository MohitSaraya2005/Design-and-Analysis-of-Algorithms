#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void merge(int arr[], int low, int mid, int high)
{
    int i=0;
    int j=low;
    int k=mid+1;
    int n=high-low+1;
    int* temp=(int*)malloc(sizeof(int)*n);

    while(j<=mid && k<=high)
    {
        if(arr[j]>arr[k])
        {
            temp[i]=arr[k];
            k++;
        }
        else{
            temp[i]=arr[j];
            j++;
        }
        i++;
    }

    while(j<=mid)
    {
        temp[i]=arr[j];
        i++;
        j++;
    }

    while (k<=high)
    {
        temp[i]=arr[k];
        i++;
        k++;
    }

    
    for(i=0;i<n;i++)
    {
        arr[i+low]=temp[i];
    }

}

void mergeSort(int arr[], int low, int high){
    if(low<high)
    {
        int mid=(low+high)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

void main()
{
    double cpu_time;
    clock_t start, end;
    int arr[]={1,4,3,2,5};

    start=clock();
    mergeSort(arr,0 ,4);
    end=clock();

    cpu_time=((double)(start-end))/CLOCKS_PER_SEC;

    

    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%lf", cpu_time);
}