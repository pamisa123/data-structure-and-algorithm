#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct  dll
{
    int info;
    struct dll *next;
};
struct dll *f=NULL,*r=NULL;
void main()
{
    struct dll *ptr,*temp;
    int choice,data;
    do
    {
        printf("Enter the choice:\n1.Inqueue\n2.Dequeue\n3.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                temp=(struct dll*)malloc(sizeof(struct dll));
                if(temp==NULL)
                {
                    printf("Queue is full\n");
                }
                else
                {
                    printf("Enter the data to be inqueue:\n");
                    scanf("%d",&data);
                    temp->info=data;
                    temp->next=NULL;
                    if(f==NULL)
                    {
                     f=r=temp;
                    }
                    else
                    {
                        r->next=temp;
                        r=temp;
                    }
                }
                break;
            }
            case 2:
            {
                if(f==NULL)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    temp=f;
                    f=f->next;
                    printf("Dequeue data is %d",temp->info);
                    free(temp);
                }
                break;
            }
            case 3:
            {
                if(f==NULL)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    temp=f;
                    while(temp!=NULL)
                    {
                        printf("%d ",temp->info);
                        temp=temp->next;
                    }
                 }
                break;
            }
            default:
                printf("Invalid Choice");
        }
    }while(choice<=4);
}
