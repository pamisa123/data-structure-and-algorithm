//impplementation of circular queue
#include<stdio.h>
#include<conio.h>
#define MAX 5
int main()
{
    int frontt=-1,rear=-1,i,data,choice,new_data,mycirqueue[MAX];

    do
    {
        printf("enter 1 for enqueue , 2 for dequeue,3 for display and 4 for exit: \t");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(frontt==(rear+1)%MAX)
            {
                printf("queue is full\n");
            }
            else if(rear==-1)
            {
                rear=0;
                frontt=0;
                printf("enter the new data:\t");
                scanf("%d",&new_data);
                mycirqueue[rear]=new_data;

            }
            else if(rear==MAX-1)
            {
                rear=0;
                printf("enter the new data:\t");
                scanf("%d",&new_data);
                mycirqueue[rear]=new_data;

            }
            else
            {
                rear++;
                printf("enter the new data:\t");
                scanf("%d",&new_data);
                mycirqueue[rear]=new_data;
            }
            break;
        case 2:
            if(frontt==-1)
            {
                printf("queue underflow");
            }
            else if(frontt==rear)
            {
                data=mycirqueue[frontt];
                frontt=-1;
                rear=-1;
                printf("the dequeue element is :%d\n",data);
            }
            else if(frontt==MAX-1)
            {
                data=mycirqueue[frontt];
                frontt=0;
                printf("the dequeue element is :%d",data);
            }
            else
            {
                data=mycirqueue[frontt];
                frontt++;
                printf("the dequeue element is:%d\n",data);
            }
            break;
        case 3:
            if (frontt == -1)
                {
                    printf("Queue is empty\n");
                }
            else
                {
                    printf("The content in circular queue is:\n");
                    if(frontt<rear)
                    {
                        for(i=frontt;i<=rear;i++)
                        {
                            printf("%d\t",mycirqueue[i]);
                        }
                    }
                    else
                    {
                        for(i=frontt;i<=MAX-1;i++)
                        {
                            printf("%d\t",mycirqueue[i]);
                        }
                        for(i=0;i<=rear;i++)
                        {
                            printf("%d\t",mycirqueue[i]);
                        }
                    }
                    printf("\n");
                }
                break;

        case 4:
            printf("EXISTING...");
            break;
        default:
            printf("Invalid choice");
        }
    }while(choice != 4);
    return 0;
}
