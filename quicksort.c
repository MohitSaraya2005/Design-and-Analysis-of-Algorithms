#include <stdio.h>
#include <time.h>


void quickSort(int arr[], int low, int high){

    if(low < high)
    {
        int pivot=arr[low];

        int i=low+1;

        int j=high;

        int temp;

        while(1){
            while(arr[i]<pivot){
                i++;
            }

            while(arr[j]>pivot){
                j--;
            }

            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            else{break;}
        }

        arr[low]=arr[j];
        arr[j]=pivot;

        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

void main(){
    double cpu_time;
    clock_t start,end;

    int arr[]={1,4,3,2,5};
    start=clock();
    quickSort(arr, 0, 4);
    end=clock();

    cpu_time=((double)(end-start))/CLOCKS_PER_SEC;

    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%lf", cpu_time);
}