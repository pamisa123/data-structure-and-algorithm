//bst tree
/*
#include<stdio.h>
#include<conio.h>
struct BST
{
    int info;
    struct BST *left,*right;
};
void preorder(struct BST * root);
void postorder(struct BST * root);
void inorder(struct BST * root);
struct BST * root=NULL;
int main()
{
    int choice,new_data;
    struct BST *ptr,*temp,*t;
    do
    {
        printf("\nenter \t1. INSERTING NODE \t2. INORDER \t3. POSTORDER \t4. PREORDER \t5. EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the newdata:\n");
            scanf("%d",&new_data);
            ptr=(struct BST *)malloc(sizeof(struct BST));
            ptr->info=new_data;
            ptr->left=NULL;
            ptr->right=NULL;
            if(root==NULL)
            {
                root=ptr;
            }
            else
            {
                temp=root;
                while(temp!=NULL)
                {
                    if(temp->info > new_data)
                    {
                        t=temp;
                        temp=temp->left;
                    }
                    else
                    {
                        t=temp;
                        temp=temp->right;
                    }
                }
                if(t->info > new_data)
                {
                    t->left=ptr;
                }
                else
                {
                    t->right=ptr;
                }
            }
            break;
        case 2:
            {
                printf("INORDER\n");
                inorder(root);
            }
            break;
        case 3:
            {
                printf("POSTORDER\n");
                postorder(root);
            }
            break;
        case 4:
            {
                printf("PREORDER\n");
                preorder(root);
            }
            break;
        default:
            {
                printf("invalid choice\n");
            }
        }
    }while(choice<5);
    return 0;
}
void inorder(struct BST * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
void preorder(struct BST * root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct BST * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}
*/
//sorting
/*
#include<conio.h>
#include<stdio.h>
int main()
{
    int choice,n,a[100],t,i,j,p,temp;
    do
    {
        printf("\nenter\t 1.inserting\t 2.bubble sort\t 3.selection sort\t 4.insertion sort\n ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the number of elements:");
            scanf("%d",&n);
            printf("enter the elements:");
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            break;
        case 2:
            printf("BUBBLE SORT\n");
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-1;j++)
                {
                    if(a[j]>a[j+1])
                    {
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                printf("%d\t",a[i]);
            }
            break;
        case 3:
            printf("SELECTION SORT\n");
            for(i=0;i<n-1;i++)
            {
                p=i;
                for(j=i+1;j<n-1;j++)
                {
                    if(a[j]>a[p])
                    {
                        p=j;
                    }
                    t=a[j];
                    a[j]=a[p];
                    a[p]=t;
                }
            }
            for(i=0;i<n;i++)
            {
                printf("%d\t",a[i]);
            }
            break;
        case 4:
            printf("INSERTION SORT\n");
            for(i=1;i<n-1;i++)
            {
                temp=a[i];
                j=i-1;
                while(j>=0 && temp>a[j])
                {
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=temp;
            }
            for(i=0;i<n;i++)
            {
                printf("%d\t",a[i]);
            }
            break;
        default:
            printf("invalid choice");
        }
    }while(choice<5);
    return 0;
}
*/
//circular queue
/*
#include<stdio.h>
#include<conio.h>
#define MAX 5
int main()
{
    int choice,front=-1,rear=-1,new_data,i,myqueue[MAX],d;
    do
    {
        printf("\n enter\t 1.enqueue\t 2.dequeue\t 3.display\t 4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the new data:\t");
            scanf("%d",&new_data);

            if(front==(rear+1)%MAX)
            {
                printf("the queue is already full");
            }
            else if(rear==-1)
            {
                rear=0;
                front=0;
                myqueue[rear]=new_data;
            }
            else if(rear==MAX-1)
            {
                rear=0;
                myqueue[rear]=new_data;
            }
            else
            {
                rear++;
                myqueue[rear]=new_data;
            }
            break;
        case 2:
            if(front==-1)
            {
                printf("queue is already empty");
            }
            else if(front==rear)
            {
                d=myqueue[front];
                front=-1;
                rear=-1;
                printf("poopped data is:%d",d);
            }
            else if(front==MAX-1)
            {
                d=myqueue[front];
                front=0;
                printf("poopped data is:%d",d);
            }
            else
            {
                d=myqueue[front];
                front++;
                printf("poopped data is:%d",d);
            }
            break;
        case 3:
            printf("the displayed elements are:");
            if(front==-1)
            {
                printf("empty");
            }
            else{
            if(front<rear)
            {
                for(i=front;i<=rear;i++)
                {
                    printf("%d\t",myqueue[i]);
                }
            }
            else
            {
                for(i=front;i<=MAX-1;i++)
                {
                    printf("%d\t",myqueue[i]);
                }
                for(i=0;i<=rear;i++)
                {
                    printf("%d\t",myqueue[i]);
                }
            }
            }
            break;
        case 4:
            printf("EXISTING");
            break;
        default:
            printf("invalid input");
        }
    }while(choice<5);
    return 0;
}
*/
