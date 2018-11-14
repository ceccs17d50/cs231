#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp;
    int coeff;
    struct node *link;
};
void main()
{
    int choice,d,f,exp,g,s;
    struct node *head1,*head2,*head,*temp,*ptr1,*ptr2,*ptr;
    head1=(struct node*)malloc(sizeof(struct node));
    head2=(struct node*)malloc(sizeof(struct node));
    head=(struct node*)malloc(sizeof(struct node));
    head1->exp=0;
    head1->coeff=0;
    head1->link=NULL;
    head2->exp=0;
    head2->coeff=0;
    head2->link=NULL;
    head->exp=0;
    head->coeff=0;
    head->link=NULL;
    ptr=head;
    ptr1=head1;
    ptr2=head2;
    printf("First polyomial");
    do
    {
        
        printf("\nEnter the coefficient");
        scanf("%d",&f);
        printf("\nEnter the exponent");
        scanf("%d",&d);
        if(f==0)
        {
            printf("Coeffiecient cannot be zero");
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->exp=d;
            temp->coeff=f;
            temp->link=NULL;
            ptr1->link=temp;
            ptr1=ptr1->link;
            printf("\n1.Add more\n2.Continue\nEnter your choice");
            scanf("%d",&choice);
        }    

    }while(choice!=2);


    printf("Second Polynomial");
    do
    {
        
        printf("\nEnter the coefficient");
        scanf("%d",&f);
        printf("\nEnter the exponent");
        scanf("%d",&d);
        if(f==0)
        {
            printf("Coefficient cannot be zero");
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->exp=d;
            temp->coeff=f;
            temp->link=NULL;
            ptr2->link=temp;
            ptr2=ptr2->link;
            printf("\n1.Add more\n2.Continue\nEnter your choice ");
            scanf("%d",&choice);
        }    

    }while(choice!=2);
    ptr1=head1->link;
    ptr2=head2->link;
    ptr=head;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp==ptr2->exp)
        {
            d=ptr1->coeff;
            g=ptr2->coeff;
            s=d+g;
            temp=(struct node*)malloc(sizeof(struct node));
            temp->exp=ptr1->exp;
            temp->coeff=s;
            temp->link=NULL;
            ptr->link=temp;
            ptr=ptr->link;
            ptr2=ptr2->link;
            ptr1=ptr1->link;
        }
        else if(ptr1->exp>ptr2->exp)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->coeff=ptr1->coeff;
            temp->exp=ptr1->exp;
            temp->link=NULL;
            ptr->link=temp;
            ptr=ptr->link;
            ptr1=ptr1->link;
        }
        else if(ptr2->exp>ptr1->exp)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->coeff=ptr2->coeff;
            temp->exp=ptr2->exp;
            temp->link=NULL;
            ptr->link=temp;
            ptr=ptr->link;
            ptr2=ptr2->link;
        }
            
    }
        

    
    if(ptr1==NULL)
    {
        while(ptr2!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->coeff=ptr2->coeff;
            temp->exp=ptr2->exp;
            temp->link=NULL;
            ptr->link=temp;
            ptr2=ptr2->link;
        }
    } 
    else if(ptr2==NULL)
    {   
        while(ptr1!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->coeff=ptr1->coeff;
            temp->exp=ptr1->exp;
            temp->link=NULL;
            ptr->link=temp;
            ptr1=ptr1->link;
        }
    }
    printf("\n1.Display\n2.Exit");
    scanf("%d",&choice);
    ptr=ptr->link;
    if(choice==1)
    {
        printf("\nFirst Polynomial\nf(x)=");
        ptr1=head1->link;
        while(ptr1!=NULL)
        {
            printf("%dx%d",ptr1->coeff,ptr1->exp);
            printf("  +  ");
            ptr1=ptr1->link;
        }
        printf("0\n");
        
        printf("Second Polynomial\nf2(x)=");
        ptr2=head2->link;
        while(ptr2!=NULL)
        {
            printf("%dx%d",ptr2->coeff,ptr2->exp);
            printf("  +  ");
            ptr2=ptr2->link;
        }
        printf("0\n");
        
        printf("\nResultant\nf3(x)=");
        ptr=head->link;
        while(ptr!=NULL)
        {
            printf("%dx%d",ptr->coeff,ptr->exp);
            printf("  +  ");
            ptr=ptr->link;
        }
        printf("0\n");

    }
    else
    {

    }

    

    
    

    
        
        


    
    
}