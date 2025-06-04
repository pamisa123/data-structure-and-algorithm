
//implementation of queue
#include<stdio.h>
#include<conio.h>
int main()
{
    int choice,rear=-1,n,frontt=-1, i;

    printf("enter the size of the queue:\n");
    scanf("%d",&n);
    int myqueue[n],temp,new_data;
    do
    {
        printf("enter 1 for enqeue and 2 for dequeue and 3 for display and 4 for exit:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(rear==(n-1))
            {
                printf("overflow\n");
            }
            else if (rear==-1)
            {
                frontt=0;
                rear=0;
                printf("Enter the data:");
                scanf("%d",&new_data);
                myqueue[rear]=new_data;
            }
            else
            {
                printf("enter the data:");
                scanf("%d",&new_data);
                rear++;
                myqueue[rear]=new_data;
            }
            break;
        case 2:
            if(frontt==-1)
            {
                printf("underflow\n");
            }
            else if(frontt==rear)
            {
                temp=myqueue[frontt];
                frontt=-1;
                rear=-1;
                printf("the deleted data is :%d\n",temp);
            }
            else
            {
                temp=myqueue[frontt];
                frontt++;
                printf("the deleted data is :%d\n",temp);
            }

            break;
        case 3:
            printf("Queue:\n");
            for(i=frontt;i<=rear;i++)
            {
                printf("%d\t", myqueue[i]);
            }
            printf("\n");
        default:
            i=10;
        }
    }while(i!=10);
    return 0;
}
