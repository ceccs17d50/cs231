#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rlink,*llink,*link;
};
void main()
{
    int key,d,choice,count;
    struct node *head,*ptr,*ptr1,*temp,*ptr2;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->rlink=head;
    head->llink=head;
    do
    {
        ptr=head;
        printf("\n\nMENU\n1.Insert at first\n2.Insert at End\n3.Insertion after\n4.Search\n5.delete first\n6.Delete last\n7.Delete an element\n8.Delete all\n9.Print\n0.Exit\nEnter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            printf("Enter the element");
            scanf("%d",&d);
            if(ptr->rlink==head)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr->rlink=temp;
                temp->llink=head;
                temp->rlink=head;
                ptr->llink=temp;
                temp->data=d;
            }
            else
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr1=ptr->rlink;
                temp->llink=head;
                temp->rlink=ptr1;
                ptr1->llink=temp;
                ptr->rlink=temp;
                temp->data=d;
            }
        }
        else if(choice==2)
        {
            
            ptr1=ptr->llink;
            printf("Enter the element");
            scanf("%d",&d);
            temp=(struct node*)malloc(sizeof(struct node));
            ptr1->rlink=temp;
            temp->llink=ptr1;
            temp->rlink=head;
            ptr->llink=temp;
            temp->data=d;
            
        }
        else if(choice==3)
        {
            printf("Enter the key");
            scanf("%d",&key);
            ptr=ptr->rlink;
            count=0;
            while(ptr!=head)
            {
                if(ptr->data==key)
                {
                    printf("Enter the element");
                    scanf("%d",&d);
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr1=ptr->rlink;
                    temp->llink=ptr;
                    ptr->rlink=temp;
                    temp->rlink=ptr1;
                    ptr1->llink=temp;
                    temp->data=d;
                    count+=1;

                }
                ptr=ptr->rlink;
                
            }
            if(count==0)
            {
                printf("Element not found");
            }

        }
        else if(choice==4)
        {
            ptr=ptr->rlink;
            printf("Enter the element");
            scanf("%d",&key);
            count=0;
            while(ptr!=head)
            {
                if(ptr->data==key)
                {
                    printf("Element found");
                    count+=1;
                }
                ptr=ptr->rlink;
            }
            if(count==0)
            {
                printf("Element not found");
            }
        }
        else if(choice==5)
        {
            ptr1=ptr->rlink;
            ptr2=ptr1->rlink;
            ptr2->llink=head;
            ptr->rlink=ptr2;
            free(ptr1);


        }
        else if(choice==6)
        {
            ptr1=ptr->llink;
            ptr2=ptr1->llink;
            ptr2->rlink=head;
            ptr->llink=ptr2;
            free(ptr1);;
            

        }
        else if(choice==7)
        {
            ptr=ptr->rlink;
            printf("Enter the element");
            scanf("%d",&key);
            while(ptr!=head)
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
                printf("Element not found");
            }
        }
        else if(choice==8)
        {
            
            ptr=ptr->rlink;
            while(ptr!=head)
            {
                ptr1=ptr;
                ptr=ptr->rlink;
                
                
                free(ptr1);
            }
            head->rlink=head;
            head->llink=head;

        }
        else if(choice==9)
        {
            ptr=ptr->rlink;
            if(ptr==head)
            {
                printf("Empty list!!");
            }
            else
            {
                printf("Header ->");
                while(ptr!=head)
                {
                    printf("%d ->",ptr->data);
                    ptr=ptr->rlink;
                }
                printf("Header");

            }
           
        }

    }
    while(choice!=0);
}
