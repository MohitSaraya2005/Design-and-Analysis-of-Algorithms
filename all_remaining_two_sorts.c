#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int size)
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }   
}


void insertionSort(int arr[], int size)
{
    int j;
    int key;
    for(int i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void main()
{
    double cpu_time;
    clock_t start, end;
    int arr[]={1,4,3,2,5};

    start=clock();
    insertionSort(arr, 5);
    end=clock();

    cpu_time=((double)(start-end))/CLOCKS_PER_SEC;

    

    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%lf", cpu_time);

    start=clock();
    bubbleSort(arr, 5);
    end=clock();

    cpu_time=((double)(start-end))/CLOCKS_PER_SEC;

    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%lf", cpu_time);

}

