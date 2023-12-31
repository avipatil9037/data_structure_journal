#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void main ()
{
    int choice =0;
    clrscr();
    while(choice != 9)
    {
	printf("\nChoose one option from the following list\n");
	printf("\n1.Insert in begining");
	printf("\n2.Insert at last");
	printf("\n3.Insert at any random location");
	printf("\n4.Delete from Beginning");
	printf("\n5.Delete from last");
	printf("\n6.Delete node from specified location");
	printf("\n7.Show");
	printf("\n8.Exit");
	printf("\nEnter your choice?\n");
	scanf("\n%d",&choice);
	switch(choice)
	{
	    case 1:
	    beginsert();
	    break;
	    case 2:
	    lastinsert();
	    break;
	    case 3:
	    randominsert();
	    break;
	    case 4:
	    begin_delete();
	    break;
	    case 5:
	    last_delete();
	    break;
	    case 6:
	    random_delete();
	    break;
	    case 7:
	    display();
	    break;
	    case 8:
	    exit(0);
	    break;
	    default:
	    printf("=====Please enter valid choice=====");
	}
    }
    getch();
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));
    if(ptr == NULL)
    {
	printf("\n=====OVERFLOW=====");
    }
    else
    {
	printf("\nEnter value\n");
	scanf("%d",&item);
	ptr->data = item;
	ptr->next = head;
	head = ptr;
	printf("\n=====Node inserted=====");
    }

}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
	printf("\n=====OVERFLOW=====");
    }
    else
    {
	printf("\nEnter value?\n");
	scanf("%d",&item);
	ptr->data = item;
	if(head == NULL)
	{
	    ptr -> next = NULL;
	    head = ptr;
	    printf("\n=====Node inserted=====");
	}
	else
	{
	    temp = head;
	    while (temp -> next != NULL)
	    {
		temp = temp -> next;
	    }
	    temp->next = ptr;
	    ptr->next = NULL;
	    printf("\n=====Node inserted=====");

	}
    }
}
void randominsert()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
	printf("\n=====OVERFLOW=====");
    }
    else
    {
	printf("\nEnter element value");
	scanf("%d",&item);
	ptr->data = item;
	printf("\nEnter the location after which you want to insert ");
	scanf("\n%d",&loc);
	temp=head;
	for(i=0;i<loc;i++)
	{
	    temp = temp->next;
	    if(temp == NULL)
	    {
		printf("\n=====can't insert=====\n");
		return;
	    }

	}
	ptr ->next = temp ->next;
	temp ->next = ptr;
	printf("\n=====Node inserted=====");
    }
}
void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
	printf("\n=====List is empty=====\n");
    }
    else
    {
	ptr = head;
	head = ptr->next;
	free(ptr);
	printf("\n=====Node deleted from the begining=====\n");
    }
}
void last_delete()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
	printf("\n=====list is empty=====");
    }
    else if(head -> next == NULL)
    {
	head = NULL;
	free(head);
	printf("=====Only node of the list deleted=====\n");
    }

    else
    {
	ptr = head;
	while(ptr->next != NULL)
	{
	    ptr1 = ptr;
	    ptr = ptr ->next;
	}
	ptr1->next = NULL;
	free(ptr);
	printf("\n=====Deleted Node from the last======\n");
    }
}
void random_delete()
{
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++)
    {
	ptr1 = ptr;
	ptr = ptr->next;

	if(ptr == NULL)
	{
	    printf("\n=====Can't delete=====");
	    return;
	}
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDeleted node %d ",loc+1);
}
void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
	printf("\n=====Nothing to print=====\n");
    }
    else
    {
	printf("\n=====values are: =====\n");
	while (ptr!=NULL)
	{
	    printf("\n%d",ptr->data);
	    ptr = ptr -> next;
	}
    }
}