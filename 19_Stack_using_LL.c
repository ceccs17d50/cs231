#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void main()
{
    int d,choice;
    struct node *head,*ptr,*temp,*top;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->link=NULL;
    top=head;
    do
    {
        printf("\nOperations\n1.PUSH\n2.POP\n3.PRINT\n4.EXIT\nEnter the choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the element");
            scanf("%d",&d);
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=d;
            temp->link=top;
            top=temp;
        }
        else if(choice==2)
        {
            ptr=top;
            top=top->link;
            free(ptr);
        }
        else if(choice==3)
        {
            temp=top;
            if(temp->link==NULL)
            {
                printf("Empty list!!");
            }
            else
            {
            
                while(temp!=head)
                {
                    printf("%d ->",temp->data);
                    temp=temp->link;
                }
                printf("NULL");
            }        
            
        }
    }while(choice!=4);
}
