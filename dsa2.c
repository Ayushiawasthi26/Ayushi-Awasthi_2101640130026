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
void printlinkedlist(struct node* head){
	struct node* s;
	s=head;
	while(s!=NULL){
	
		printf("%d->",s->data);
		s=s->address;
		
	}
}
int main(){
	int choice,after;
	struct node* head;
	head=NULL;
	while(1)
	{
		int data;
		printf("\n Linked list menu");
		printf("\n 1.insert at beg");
		printf("\n 2.Insert at end");
		printf("\n 3.Insert at loc");
		printf("\n 4.Print linked list");
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
							printlinkedlist(head);
						}	
							else
								printf(" invalid choice");
	}
}
