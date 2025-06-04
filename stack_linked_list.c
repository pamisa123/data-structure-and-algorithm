//Implementation of stack using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct  dll
{
    int info;
    struct dll *next;
};
struct dll *tos=NULL;
int main()
{
        struct dll *ptr,*temp;
        int choice,data;
        do
        {
            printf("Enter the choice:\n1.Push\n2.Pop\n3.Display\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                {
                    temp=(struct dll*)malloc(sizeof(struct dll));
                    printf("Enter the data to be pushed:\n");
                    scanf("%d",&data);
                    temp->info=data;
                    temp->next=NULL;
                    if(tos==NULL)
                    {
                        tos=temp;
                    }
                    else
                    {
                        temp->next=tos;
                        tos=temp;
                    }
                    break;
                }
                case 2:
                {
                    if(tos==NULL)
                    {
                        printf("Stack is empty\n");
                    }
                    else
                    {
                        temp=tos;
                        tos=tos->next;
                        printf("Popped data is :%d \n",temp->info);
                        free(temp);
                    }
                    break;
                }
                case 3:
                {
                    printf("the data in stack is:\t");
                    if(tos==NULL)
                    {
                        printf("Stack is empty\n");
                    }
                    else
                    {
                        temp=tos;
                        while(temp!=NULL)
                        {
                            printf("%d ",temp->info);
                            temp=temp->next;
                        }
                    }
                    printf("\n");
                    break;
                }
                default:
                    printf("Invalid Choice");
            }
    }while (choice<5);
    return 0;
}
