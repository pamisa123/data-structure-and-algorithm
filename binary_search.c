#include<stdio.h>
#include<conio.h>
int binarysearch(int a[],int key,int n)
{
    int low=0,mid,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n,i,a[100],element,search;
    printf("enter the no.of elements:");
    scanf("%d",&n);
    printf("enter the sorted elements:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("enter the elements that is being searched:");
    scanf("%d",&element);
    search=binarysearch(a,element,n);
    if(search==-1)
    {
        printf("the element is not found");
    }
    else
    {
        printf("the element is found in index:%d",search);
    }
    return 0;

}
