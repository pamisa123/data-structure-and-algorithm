#include<stdio.h>
#include<conio.h>
struct BST
{
    int info;
    struct BST *left,*right;
};
void preorder(struct BST *root);
void inorder(struct BST *root);
void postorder(struct BST *root);
struct BST *deletenode(struct BST *root ,int key);

struct BST *root=NULL;

int main()
{
    int choice,new_data,del;
    struct BST *ptr,*temp,*t;
    do
    {
        printf("enter \n 1).inserting node \n 2).preorder \n 3).inorder \n 4).postorder \n 5).delete the node \n 6.)exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the data to be inserted:\t");
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
            printf("PREORDER:\n");
            preorder(root);
            }
            break;
        case 3:
            {
                printf("INORDER:\n");
                inorder(root);
            }
            break;
        case 4:
            {
                printf("POSTORDER:\n");
                postorder(root);
            }
            break;
        case 5:
            {
                printf("enter the data to be deleted:");
                scanf("%d",&del);
                root=deletenode(root,del);
            }
            break;
        case 6:
            printf("EXISTING...");
            break;
        default:
            printf("INVALID INPUT\n");
        }
    }while(choice<5);
    return 0;
}
void preorder(struct BST *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct BST *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
void postorder(struct BST *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}
struct BST *minvalue(struct BST *node)
{
    struct BST *current =node;
    while(current && current->left !=NULL)
    {
        current =current->left;
    }
    return current;
}
struct BST *deletenode(struct BST *root, int key)
{
    if(root==NULL)
    {
            printf("NODE not found!");
            return root;
    }
    if(key< root->info)
    {
        root->left =deletenode(root->left,key);
    }
    else if(key >root->info)
    {
        root->right =deletenode(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct BST *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct BST *temp=root->left;
            free(root);
            return temp;
        }
        struct BST *temp=minvalue(root->right);
        root->info=temp->info;
        root->right=deletenode(root->right,temp->info);
    }
    return root;
}

