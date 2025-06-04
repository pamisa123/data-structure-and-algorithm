//Implementation of doubly circular linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct CLL
{
    int info;
    struct CLL *next,*prev;
};
struct CLL *head=NULL,*tail=NULL;
int main()
{
    int choice,new_data;
    struct CLL *next,*prev,*ptr,*temp;
    do
    {
        printf("Enter \n1).inserting new node at beginning,\n 2). inserting new node at end,\n 3). delete first node,\n 4). delete last node,\n 5). display,\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                ptr=(struct CLL*)malloc(sizeof(struct CLL));
                printf("enter the new data to be inserted:");
                scanf("%d",&new_data);
                ptr->info=new_data;
                ptr->next=ptr;
                ptr->prev=ptr;
                if(head==NULL)
                {
                    head=ptr;
                    tail=ptr;
                }
                else
                {
                    ptr->next=head;
                    head->prev=ptr;
                    ptr->prev=tail;
                    tail->next=ptr;
                    head=ptr;
                }
                break;
            case 2:
                ptr=(struct CLL*)malloc(sizeof(struct CLL));
                printf("enter the new data:");
                scanf("%d",&new_data);
                ptr->info=new_data;
                ptr->next=ptr;
                ptr->prev=ptr;
                if(head ==NULL)
                {
                    tail=ptr;
                    head=ptr;
                }
                else
                {
                    ptr->next=head;
                    head->prev=ptr;
                    ptr->prev=tail;
                    tail->next=ptr;
                    tail=ptr;
                }
                break;
            case 3:
                temp==head;
                if (temp==NULL)
                {
                    printf("empty linked list");
                }
                else if(head==tail)
                {
                    head=NULL;
                    tail=NULL;
                    free(temp);
                }
                else
                {
                    head=head->next;
                    head->prev=tail;
                    tail->next=head;
                    free(temp);
                }
                printf("Data deletion successfull\n");
                break;

            case 4:
                temp==tail;
                if(temp==NULL)
                {
                    printf("empty linked list");
                }
                else if(tail==head)
                {
                    tail=NULL;
                    head=NULL;
                    free(temp);
                }
                else
                {
                    temp=tail;
                    tail=tail->prev;
                    tail->next=head;
                    head->prev=tail;
                    free(temp);
                }
                printf("Data deletion successfull\n");
                break;

            case 5:
                printf("the data in list is:");
                temp=head;
                if(temp==NULL)
                {
                    printf("Empty CLL");
                }
                else
                {
                    do
                    {
                            printf("%d\t",temp->info);
                            temp=temp->next;
                    }while(temp!=head);
                }
                printf("\n");

                break;
            case 6:
                printf("EXISTING...");
                break;
            default:
                printf("invalid input");
        }
    }while(choice<=6);
}
