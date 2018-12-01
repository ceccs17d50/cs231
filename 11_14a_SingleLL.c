#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void main()
{
    int key,d,choice,count;
    struct node *head,*ptr,*ptr1,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->link=NULL;
    do
    {
        ptr=head;
        printf("\n\nMENU\n1.Insert at first\n2.Insert at End\n3.Insertion after\n4.Search\n5.delete first\n6.Delete last\n7.Delete an element\n8.Delete all\n9.Print\n0.Exit\nEnter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            printf("Enter the element");
            scanf("%d",&d);
            if(ptr->link==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                head->link=temp;
                temp->link=NULL;
                temp->data=d;
            }
            else
            {
                temp=(struct node*)malloc(sizeof(struct node));
                temp->link=ptr->link;
                ptr->link=temp;
                temp->data=d;
            }
        }
        else if(choice==2)
        {
            
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            
            if(ptr->link==NULL)
            {
            printf("Enter the element");
            scanf("%d",&d);
            temp=(struct node*)malloc(sizeof(struct node));
            temp->link=NULL;
            ptr->link=temp;
            temp->data=d;
            }
        }
        else if(choice==3)
        {
            printf("Enter the key");
            scanf("%d",&key);
            ptr=ptr->link;
            count=0;
            while(ptr!=NULL)
            {
                if(ptr->data==key)
                {
                    printf("Enter the element");
                    scanf("%d",&d);
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr1=ptr->link;
                    ptr->link=temp;
                    temp->link=ptr1;
                    temp->data=d;
                    count+=1;

                }
                ptr=ptr->link;
                
            }
            if(count==0)
            {
                printf("Element not found");
            }

        }
        else if(choice==4)
        {
            ptr=ptr->link;
            printf("Enter the element");
            scanf("%d",&key);
            count=0;
            while(ptr!=NULL)
            {
                if(ptr->data==key)
                {
                    printf("Element found");
                    count+=1;
                }
                ptr=ptr->link;
            }
            if(count==0)
            {
                printf("Element not found");
            }
        }
        else if(choice==5)
        {
            ptr=ptr->link;
            ptr1=ptr->link;
            head->link=ptr1;
            free(ptr);


        }
        else if(choice==6)
        {
            while(ptr->link!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->link;
                
            }
            ptr1->link=NULL;
            free(ptr);
            

        }
        else if(choice==7)
        {
            temp=ptr;
            ptr=ptr->link;
            printf("Enter the element");
            scanf("%d",&key);
            while(ptr!=NULL)
            {
                if(ptr->data!=key)
                {
                    temp=ptr;
                }
                else
                {
                    ptr1=ptr->link;
                    temp->link=ptr1;
                    free(ptr);
                    count+=1;
                }
                ptr=ptr->link;
            }
            if(count==0)
            {
                printf("Element not found");
            }
        }
        else if(choice==8)
        {
            temp=ptr;
            ptr=ptr->link;
            while(ptr!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->link;
                
                
                free(ptr1);
            }
            temp->link=NULL;

        }
        else if(choice==9)
        {
            ptr=ptr->link;
            if(ptr==NULL)
            {
                printf("Empty list!!");
            }
            else
            {
                printf("Header ->");
                while(ptr!=NULL)
                {
                    printf("%d ->",ptr->data);
                    ptr=ptr->link;
                }
                printf("Header");

            }
           
        }

    }
    while(choice!=0);
}
