#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node*address;
}s;

void insertatfront(struct node** head, int data)
{
	struct node* Node=(struct node*)malloc(sizeof(struct node));
	Node->data=data;
	Node->address=*head;
	*head=Node;
}

void insertatend(struct node** head,int data)
{
	struct node* Node;
	Node=(struct node*)malloc(sizeof(struct node));
	Node->data=data;
	Node->address=NULL;
	if(head==NULL)
	{
		*head=Node;
	}
	struct node* s;
	s=*head;
	while(s->address!=NULL)
	{
		s=s->address;
		
	}
	s->address=Node;
}
void insertatloc(struct node** head,int data,int after)
{
	struct node* Node=(struct node*)malloc(sizeof(struct node));
	Node->data=data;
	Node->address=NULL;
	struct node* s;
	s=*head;
	while(s->data!=after){
		s=s->address;
	}
	Node->address=s->address;
	s->address=Node;
}

void deleteatbeg(struct node** head)
{
	struct node* temp;
	temp=*head;
	*head=temp->address;
	free(temp);
}

void deleteatend(struct node** head)
{
	struct node* s=*head;
	while(s->address->address!=NULL)
	{
		s=s->address;
	}
	free(s->address);
	s->address=NULL;
}

void deletefromposition(struct node** head,int pos)
{
	pos--;
	struct node* s=*head;
	while(pos>1)
	{
		s=s->address;
		pos--;
	}
	struct node* temp;
	temp=s->address;
	s->address=s->address->address;
	free(temp);
}

void middle(struct node* head)
{
	struct node* s=head;
	struct node* f=head;
	if(head!=NULL)
	{
	while(f!=NULL&&f->address!=NULL)
	{
		f=f->address->address;
		s=s->address;
	}
	printf("middle of linked list is:%d",s->data);
    }
}

void printlinkedlist(struct node* head)
{
	struct node* s;
	s=head;
	while(s!=NULL)
	{
		printf("%d->",s->data);
		s=s->address;	
	}
}

int main()
{
	int choice,after;
	struct node* head;
	head=NULL;
	while(1)
	{
		int data;
		printf("\n Linked list menu");
		printf("\n 1.Insert at beg");
		printf("\n 2.Insert at end");
		printf("\n 3.Insert at loc");
		printf("\n 4.Delete at end");
		printf("\n 5.Delete at beg");
		printf("\n 6.Delete from position");
		printf("\n 7.Middle node");
		printf("\n 8.Print linked list");
		printf("\n enter your choice=");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\n enter data:");
			scanf("%d",&data);
			insertatfront(&head,data);
	    }
     	else if(choice==2)
	   {
			printf("\n enter data:");
			scanf("%d",&data);
			insertatend(&head,data);
		}
		else if(choice==3)
		{
			printf("\n enter data:");
			scanf("%d",&data);
			printf("\n enter data_after:");
			scanf("%d",&after);
			insertatloc(&head,data,after);
		}
		else if(choice==4)
		{
			deleteatend(&head);
		}
		else if(choice==5)
		{
			deleteatbeg(&head);	
		}
		else if(choice==6)
		{
			int pos;
			printf("Enter the position:");
			scanf("%d",& pos);
			deletefromposition(&head,pos);
	    }
	    else if(choice==7)
		{
			middle(head);
		}

		else if(choice==8)
		{
			printlinkedlist(head);
		}	
		else
			printf(" invalid choice");
    }
}

