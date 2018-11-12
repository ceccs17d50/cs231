
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rlink,*llink;
};

void main()
{
    int key,choice,d,count;
    struct node *head,*ptr,*ptr1,*ptr2,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->rlink=NULL;
    head->llink=NULL;
    do
    {
        ptr=head;
        printf("\n\nDouble Linked List\n1.Insert at first\n2.Insert at End\n3.Insertion in between\n4.Search\n5.delete first\n6.Delete last\n7.Delete an element\n8.Delete all\n9.Print\n0.Exit\nEnter your choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter key: ");
            scanf("%d",&d);
            if(ptr->rlink==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=NULL;
                temp->data=d;
            }
            else 
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr1=ptr->rlink;
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=ptr1;
                ptr1->llink=temp;
                temp->data=d;
            }
        }
        if(choice==2)
        {
            printf("Enter the element");
            scanf("%d",&d);
            while(ptr->rlink!=NULL)
            {
                ptr=ptr->rlink;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=d;
            temp->llink=ptr;
            temp->rlink=NULL;
            ptr->rlink=temp;
            
        }   
        if(choice==3)
        {
            printf("Enter the key");
            scanf("%d",&key);
            ptr=ptr->rlink;
            while(ptr!=NULL)
            {
                if(ptr->data==key)
                {
                    printf("Enter the element");
                    scanf("%d",&d);
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr1=ptr->rlink;
                    ptr->rlink=temp;
                    temp->llink=ptr;
                    temp->rlink=ptr1;
                    ptr1->llink=temp;
                    temp->data=d;
                }
                ptr=ptr->rlink;
            }

        }
        if(choice==4)
        { 
            if(ptr->rlink==NULL)
            {
                printf("Empty List");
            }
            {
                printf("Enter the key");
                scanf("%d",&key);
                ptr=ptr->rlink;
                count=0;
                while(ptr!=0)
                {
                    if(ptr->data==key)
                    {
                        printf("Element found\n");
                        count+=1;
                    }
                    ptr=ptr->rlink;
                }
                if(count==0)
                {
                    printf("Element not found\n");
                }

            }
        }
        if(choice==5)
        {
            ptr1=ptr->rlink;
            ptr2=ptr1->rlink;
            ptr2->llink=ptr;
            ptr->rlink=ptr2;
            free(ptr1);

        }
        if(choice==6)
        {
            
            while(ptr->rlink!=NULL)
            {
                ptr=ptr->rlink;
            }
            if(ptr->rlink==NULL)
            {
                ptr1=ptr->llink;
                ptr1->rlink=NULL;
                free(ptr);
            }
            
        }
        if(choice==7)
        {
            if(ptr->rlink==NULL)
            {
                printf("Empty list");
            }
            else
            {
                ptr=ptr->rlink;
                printf("Enter the key");
                scanf("%d",&key);
                count=0;
                while(ptr!=0)
                {
                    if(ptr->data==key)
                    {
                        ptr1=ptr->llink;
                        ptr2=ptr->rlink;
                        ptr1->rlink=ptr2;
                        ptr2->llink=ptr1;
                        free(ptr);
                        count+=1;
                    }
                    ptr=ptr->rlink;
                }
                if(count==0)
                {
                    printf("key not found");
                }
            }
        }
        if(choice==8)
        {
            ptr=ptr->rlink;
            
            while(ptr!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->rlink;
                free(ptr1);
            }
            head->rlink=NULL;

        }
        else if(choice==9)
        {
            ptr=ptr->rlink;
            printf("Header ->");
            while(ptr!=NULL)
            {
                printf("%d ->",ptr->data);
                ptr=ptr->rlink;
            }
            printf("NULL\n");
        
        }
    }
            
                
        
    
       
     
    while (choice!=0);   
}
