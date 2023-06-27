#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;

void insert_at_head(NODE *nn)
{
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
		head=nn;
	}
}

void insert_at_tail(NODE *nn)
{
 	if(head==NULL)
 	{
 		head=nn;
	}
	 else
	{
	 	NODE *temp=head;
	 	while(temp->next!=NULL)
	 	{
	 		temp=temp->next;
		}
		 temp->next=nn;
	}	
}


void delete_at_head()
{
	if (head==NULL)
	{
		printf("No Nodes \n");
		return;
	}
	printf("deleted element is %d \n",head->data);
	NODE *dn=head;
	head=head->next;
	free(dn);
}

void delete_at_tail()
{
    if(head==NULL)
	{
		printf("no nodes \n");
	}
	else if(head->next==NULL) //list is containing single node
	{
		printf("deleted element is %d\n",head->data);
		head=NULL;
	}	
		else //if list is containing more than 1 node
		{
			NODE *temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			printf("deleted element is %d\n",temp->next->data);
			NODE *dn=temp->next;
			temp->next=NULL;
			free(dn);
		}
}


void insert_at_position(NODE *nn,int pos)
{
	if(pos==1)
	{
		insert_at_head(nn);
	}
	else
	{
		NODE *temp=head;
		int c=1;
		while(c<pos-1)
	{
		c++;
		temp=temp->next;
	}
	nn->next=temp->next;
	temp->next=nn;
	}
}


void display()
{
	if(head==NULL)
	{
		printf("NO NODES\n");
		return;
	}
	NODE *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


int main()
{
	while(1)
	{
		int choice;
		printf("enter\n 1.insert at head\n 2.insert at tail\n 3.delete at head\n 4.delete at tail\n 5.insert at position\n 6.delete at position\n 7.display\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			//insert at head
			int val;
			printf("enter the value");
			scanf("%d",&val);
			NODE *nn=(NODE *)malloc(sizeof (NODE));
			nn->data=val;
			nn->next=NULL;
			insert_at_head(nn);
			
		}
		else if(choice==2)
		{
			//insert at tail
			int val;
			printf("enter the value");
			scanf("%d",&val);
			NODE *nn=(NODE *)malloc(sizeof (NODE));
			nn->data=val;
			nn->next=NULL;
			insert_at_tail(nn);
		}
		else if(choice==3)
		{
			delete_at_head();
		}
		else if(choice==4)
		{
			//delete at tail
			delete_at_tail();
		}
		else if(choice==5)
		{
			//insert at position
			NODE *nn=(NODE *)malloc(sizeof(NODE));
			int val;
			printf("enter a value to be inserted");
			scanf("%d",&val);
			nn->data=val;
			nn->next=NULL;
			int pos;
			printf("enter the position to insert the node");
			scanf("%d",&pos);
			insert_at_position(nn,pos);
		}
		else if(choice==6)
		{
			//delete at position
	    }
		else if(choice==7)
		{
		 display();
		}
		else
		{
			printf("no");
		}
	}
}

