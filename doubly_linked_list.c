//implementation of doubly linked list
#include<stdio.h>
#include<conio.h>
#define MAX 5
struct DLL
{
    int info;
    struct DLL *next,*prev;
};
struct DLL *head=NULL,*tail=NULL;
int main()
{
    int new_data,data,choice,d,position,i=1;
    struct DLL *ptr,*next,*prev,*temp;
    do
    {
        printf("Enter \n1).inserting new node at beginning,\n 2). inserting new node at end,\n 3). inserting after a particular node,\n 4). inserting before a particular node,\n 5). inserting at a particular position,\n 6). delete first node,\n 7). delete last node,\n 8). delete a particular node,\n 9). display,\n 10). exit:\t");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the new data:");
            scanf("%d",&new_data);
            ptr=(struct DLL *)malloc(sizeof(struct DLL));
            ptr->info=new_data;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(head==NULL)
            {
                head=ptr;
                tail=ptr;
            }
            else
            {
                ptr->next=head;
                head->prev=ptr;
                head=ptr;
            }
            break;
        case 2:
            printf("enter the new data:");
            scanf("%d",&new_data);
            ptr=(struct DLL *)malloc(sizeof(struct DLL));
            ptr->info=new_data;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(head==NULL)
            {
                head=ptr;
                tail=ptr;
            }
            else
            {
                tail->next=ptr;
                ptr->prev=tail;
                tail=ptr;
            }
            break;
        case 3:
            ptr=(struct DLL *)malloc(sizeof(struct DLL));
            printf("enter the new data:");
            scanf("%d",&new_data);
            ptr->info=new_data;
            ptr->next=NULL;
            ptr->prev=NULL;
            printf("enter the data of node after which the new data is to be inserted:");
            scanf("%d",&data);
            temp=head;
            while(temp->info!=data && temp!=NULL)
            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("particular node doesnot exist");
            }
            else if(temp->next==NULL)       //tail==NULL
            {
                temp->next=ptr;
                ptr->prev=temp;
                tail=ptr;
            }
            else
            {
                temp->next->prev=ptr;
                ptr->next=temp->next;
                ptr->prev=temp;
                temp->next=ptr;
            }
            break;
        case 4:
            ptr=(struct DLL *)malloc(sizeof(struct DLL));
            printf("enter the new data:");
            scanf("%d",&new_data);
            printf("enter the data before which new data is to be inserted:\t");
            scanf("%d",&data);
            ptr->info=new_data;
            ptr->next=NULL;
            ptr->prev=NULL;
            temp=head;
            while(temp!=NULL && temp->info!=data)
            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("particular node doesnot exist\n");
            }
            else if(temp==head)
            {
                temp->prev=ptr;
                ptr->next=temp;
                head=ptr;
            }
            else
            {
                ptr->prev=temp->prev;
                temp->prev->next=ptr;
                ptr->next=temp;
                temp->prev=ptr;
            }
            break;
        case 5:
            ptr=(struct DLL *)malloc(sizeof(struct DLL));
            printf("enter the new data:");
            scanf("%d",&new_data);
            printf("enter the position where the new data is to be inserted:\t");
            scanf("%d",&position);
            ptr->info=new_data;
            ptr->next=NULL;
            ptr->prev=NULL;
            temp=head;
            while(temp!=NULL && i<=position-1)
            {
                temp=temp->next;
                i++;
            }
            if(temp==NULL)
        	{
            	printf("particular position doesn't exist\n");
        	}
        	else if(temp==head)
        	{
            	ptr->next=head;
            	head->prev=ptr;
            	head=ptr;
        	}
        	else if(temp==tail)
        	{
            	tail->prev->next=ptr;
            	ptr->prev=temp->prev;
            	ptr->next=tail;
            	tail->prev=ptr;
        	}
        	else
        	{
            	temp->prev->next=ptr;
            	ptr->prev=temp->prev;
            	temp->prev=ptr;
            	ptr->next=temp;
        	}
        	break;
        case 6:
            if(head==NULL)
            {
                printf("empty linked list");
            }
            else if(head==tail)
            {
                ptr=head;
                head=NULL;
                tail=NULL;
                free(ptr);
            }
            else
            {
                ptr=head;
                head=head->next;
                free(ptr);
            }
            printf("Data deletion successfull\n");
            break;
        case 7:
            if(tail==NULL)
            {
                printf("empty");
            }
            else if(tail==head)
            {
                ptr=tail;
                tail=NULL;
                head=NULL;
                free(ptr);
            }
            else
            {
                ptr=tail;
                tail=tail->prev;
                tail->next=NULL;
                free(ptr);
            }
            printf("Data deletion successfull\n");
            break;
        case 8:
            printf("enter the data of the node to be deleted:");
            scanf("%d",&d);
            temp=head;
            while(temp->info!=d && temp!=NULL)
            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("particular node doesnot exist");
            }
            else if(temp==head)
            {
                head=head->next;
                head->prev=NULL;
                free(temp);
            }
            else if(temp==tail)
            {
                tail=tail->prev;
                tail->next=NULL;
                free(ptr);
            }
            else if(temp==head && temp==tail)
            {
                head=NULL;
                tail=NULL;
                free(temp);
            }
            else
            {
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                free(temp);
            }
            break;
        case 9:
            printf("the data in list is:");
            struct DLL *ptr=head;
            while(ptr!=NULL)
            {
                printf("%d\t",ptr->info);
                ptr=ptr->next;
            }
            printf("\n");
            break;
        case 10:
            printf("existing...");
            break;
        default:
            printf("invalid choice");
        }
    }while(choice<=10);
    return 0;
}
