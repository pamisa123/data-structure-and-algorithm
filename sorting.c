/*#include<stdio.h>
#include<conio.h>
int main()
{
    int choice,A[10],n,i,j;
    printf("enter how many data to be inserted");
    scanf("%d",&n);
    printf("enter the data to be inserted in array:\t");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int lb=0,ub=n-1;
    do
    {
        printf("\nEnter \n1.BUBBLE SORT \n2.SELECTION SORT \n3.INSERTION SORT\n4.MERGE SORT\n5.QUICK SORT\n6.HEAP SORT\n7.SHELL SORT:\t");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("BUBBLE SORT\n");
            for( int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-1;j++)
                {
                    if(A[j] > A[j+1])
                    {
                        int temp;
                        temp=A[j];
                        A[j]=A[j+1];
                        A[j+1]=temp;
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                 printf("%d\t",A[i]);
            }
            break;
        case 2:
            printf("SELECTION SORT\n");
            for(i=0;i<n-1;i++)
            {
                int p=i;
                for(j=i+1;j<n-1;j++)
                {
                    if(A[j]<A[p])
                    {
                        p=j;
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                 printf("%d\t",A[i]);
            }
            break;
        case 3:
            printf("INSERTION SORT\n");
            for(i=0;i<n;i++)
            {
                int key=A[i];
                j=i+1;
                while(j!=-1 && A[j]<key)
                {
                    A[j+1]=A[j];
                    j--;
                }
                A[i]=key;
            }
            for(i=0;i<n;i++)
            {
                 printf("%d\t",A[i]);
            }
            break;
        case 4:
            printf("MERGE SORT\n");
            mergesort(A,lb,ub);
            for(i=0;i<n;i++)
            {
                 printf("%d\t",A[i]);
            }
            break;
        case 5:
            printf("QUICK SORT\n");
            quicksort(A,0,n-1);
            for(i=0;i<n;i++)
            {
                printf("%d\t",A[i]);
            }
            break;
        case 6:
            printf("HEAP SORT\n");
            //heapsort(A,n);
            for(i=0;i<n;i++)
            {
                printf("%d\t",A[i]);
            }
            break;
        case 7:
            printf("SHELL SORT");
            //shellsort(A,n);
            for(i=0;i<n;i++)
            {
                printf("%d\t",A[i]);
            }
            break;
        default:
            printf("INVALID INPUT");
        }
    }while(choice<7);
    return 0;
}
void mergesort(int *A,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        Merge(A,lb,mid,ub);
    }
}
void Merge(int *A,int lb, int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int temp[10];
    while(i<=mid && j<=ub)
    {
        if(A[i]< A[j])
        {
            temp[k]=A[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=A[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            temp[k]=A[j];
            k++;
            j++;

        }
    }
    if(j>ub)
    {
        while(i<=mid)
        {
            temp[k]=A[i];
            k++;
            i++;
        }
    }
    int t=lb;
    while(t<=ub)
    {
        A[t]=temp[t];
        t++;
    }
}
void quicksort(int *A,int lb, int ub)
{
    if(lb<ub)
    {
        int l=partition(A,lb,ub);
        quicksort(A,lb,l-1);
        quicksort(A,l+1,ub);
    }
}
int partition(int *A ,int lb ,int ub)
{
    int pivot=A[lb];
    int e=ub;
    int s=lb;
    while(s<e)
    {
        while(A[s]<=pivot)
        {
            s++;
        }
        while(A[e]>pivot)
        {
            e--;
        }
        if(s<e)
        {
            int temp;           //swap A[s],A[e]
            temp=A[s];
            A[s]=A[e];
            A[e]=temp;
        }
    }
    int temp;
    temp=A[lb];
    A[lb]=A[e];
    A[e]=temp;
    return e;
}
//void mergesort(int *A,)
*/
//Sorting
#include<stdio.h>
#include<conio.h>
void Bubblesort(int A[],int n);
void Selectionsort(int A[],int n);
void Insertionsort(int A[],int n);
void mergeSort(int A[], int low, int high);
int partition(int A[],int lb,int ub);
void Quicksort(int A[],int lb,int ub);
void Heapsort(int A[],int n);
void heapify(int A[], int n, int i) ;
void merge(int A[], int mid, int low, int high);
void shellSort(int A[],int n);
void printlist(int A[], int n);
int main(){
    int n,i,j,c,A[10];
    printf("enter the no of data:");
    scanf("%d",&n);
    printf("Enter the data:");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("1.Bubble sort\n2.Selection sort\n3.Insertion\n4.Merge\n5.Quicksort\n6.Heap sort\n7.Shell sort\n");
    do{
        scanf("%d",&c);
     switch(c)
     {
        case 1:
            Bubblesort(A,n);
            break;
        case 2:
            Selectionsort(A,n);
            break;
        case 3:
            Insertionsort(A,n);
            break;
        case 4:
            mergeSort(A,0,n-1);
            printf("MergeSort: ");
            printlist(A,n);
            break;
        case 5:
            Quicksort(A,0,n-1);
            printf("Quick sort: ");
            for(i=0;i<n;i++)
            {
                printf("%d ",A[i]);
            }
            printf("\n");
            break;
        case 6:
            Heapsort(A,n);
            printf("Heap sort: ");
            printlist(A,n);
            break;
        case 7:
            shellSort(A,n);
            printf("shell sort: ");
            printlist(A,n);
            break;
     }
}while(c<=8);
}
void printlist(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void Bubblesort(int A[],int n)
{
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    printf("Bubble sort: ");
    printlist(A,n);
}
void Selectionsort(int A[],int n)
{
    int i,j,temp,p;
    for(i=0;i<n-1;i++)
    {
        p=i;
        for(j=i+1;j<n-1;j++)
        {
            if(A[j]<A[p])
            {
                p=i;
            }
            temp=A[p];
            A[p]=A[i];
            A[i]=temp;
        }
    }
    printf("Selection sort: ");
    printlist(A,n);
}
void Insertionsort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0 && A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
printf("Insertion sort: ");
printlist(A,n);
printf("\n");
}
int partition(int A[],int lb,int ub)
{
    int pivot=A[lb],s=lb,e=ub,temp;
    while(A[s]<=pivot)
    {
        s++;
    }
    while(A[e]>pivot)
    {
        e--;
    }
    if(s<e)
    {
        temp=A[s];
        A[s]=A[e];
        A[e]=temp;
    }
    temp=A[lb];
    A[lb]=A[e];
    A[e]=temp;
    return e;
}
void Quicksort(int A[],int lb,int ub)
{
    int l,i;
    if(lb<ub)
    {
        l=partition(A,lb,ub);
        Quicksort(A,lb,l-1);
        Quicksort(A,l+1,ub);
    }
}
void mergeSort(int A[], int low, int high){
    int mid;
    if(low<high)
    {

        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void Heapsort(int A[],int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}

void heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;
    if (largest != i)
    {
        int swap = A[i];
        A[i] = A[largest];
        A[largest] = swap;
        heapify(A, n, largest);
    }
}
void shellSort(int A[],int n)
{
    int interval,i,j,temp;
    for(interval=n/2;interval>0;interval/=2)
        {
        for(i=interval;i<n;i++)
        {
            temp=A[i];
            for( j=i ; j>=interval &&  A[j-interval]>temp ; j-=interval )
            {
                A[j]=A[j-interval];
            }
            A[j]=temp;
        }
    }
}
