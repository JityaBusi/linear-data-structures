#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;
};

typedef struct node NODE;
NODE*head=NULL;
NODE*tail=NULL;

void insert_at_head(NODE *nn)
{
  if(head==NULL && tail==NULL)
  {
  head=nn;
  tail=nn;
 }
 else
 {
  head->prev=nn;
  nn->next=head;
  head=nn;
 }
}

void_inser_at_tail(NODE*nn)
{
	if(head==NULL && tail==NULL)
	{
		head=nn;
		tail=nn;
	}
}

void display_from_head()
{
if(head==NULL && tail==NULL)
{
printf("no nodes\n");
}
else
{
NODE *temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}
}


void display_from_tail()
{
if(head==NULL && tail==NULL)
{
printf("no nodes\n");
}
else
{
NODE *temp=tail;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}
printf("\n");
}
}


int main()
{
  int choice;
  while(1)
  {
  printf("enter\n1.insertion at head\n2.display from head\n3.display from tail\n");
  scanf("%d",&choice);
  if(choice==1)
  {
  //insert at head()
  NODE* nn=(NODE *)malloc(sizeof(NODE));
  int val;
  printf("enter the value");
  scanf("%d",&val);
  nn->data=val;
  nn->next=NULL;
  nn->prev=NULL;
  insert_at_head(nn);
 }
else if(choice==2)
{
display_from_head();
}
else if(choice==3)
{
display_from_tail();
}
else
{
printf("thank you");
}
}
}

