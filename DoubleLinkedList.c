#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}node;

void createList(node **start,int n)
{
	int i;
	
	node *temp,*end,*newNode;
	
	for(i = 1;i<=n;i++)
	{
		newNode = (node *)malloc(sizeof(node));
		if(!newNode)
		{
			printf("\nmemory is not allocated");
			return;
		}
		else{
			printf("\ngive the data for node %d:",i);
			scanf("%d",&newNode->data);
			newNode->next = NULL;
			
			if(i==1)
			{
				*start = newNode;
				temp = newNode;
				newNode->prev = NULL;
				continue;
			}
			
			temp->next = newNode;
			newNode->prev = temp;
			temp = newNode;
		}
	}
	temp = end;
}
	
void DLLInsert(node **start,int data,int position)
{
	int k= 1;
	node *temp,*newNode;
	newNode = (node *)malloc(sizeof(node));
	if(!newNode){		//always check for memory errors
		printf("memory error");
		return;
	}
	newNode->data = data;
	
	if(position == 1)
	{
		newNode->next = *start;
		newNode->prev = NULL;
		
		if(*start)
		(*start)->prev = newNode;
	
		*start = newNode;
		return;
	}
	
	temp = *start;
	
	while((k<position-1)&& temp->next!=NULL){
		temp = temp->next;
		k++;
		
	}
	if(k!=position){
		printf("Desired position doesnot exist\n");
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	
	if(temp->next)//deletion for intermediate node
		temp->next->prev = newNode;
	
	temp->next = newNode;
	return;
}

void DLLDelete(node **start,int position)
{
	int k = 1;
	node *temp,*temp2;
	
	temp = *start;
	
	if(*start == NULL)
	{
		printf("list empty");
		return;
	}
	/*from the beginning */
	if(position == 1)
	{
		*start = (*start)->next;
		
		if(*start!=NULL)
			(*start)->prev = NULL;
		free(temp);
		return;
	}
	
		//traverse the list until arriving at the position from which we want to delete
		while(temp->next!=NULL &&(k<position))
		{
			temp = temp->next;
			k++;
		}
		
		if(k != position)//at the end
		{
			printf("\ndesired position doesnot exist");
		}
		
			temp2 =temp->prev;
			temp2->next = temp->next;
			
			if(temp->next)//deletion for intermediate node
				temp->next->prev = temp2;
			free(temp);
			return;
		
	
}

	
int ListLength(node *start)
{
	node *current = start;
	int count = 0;
	
	while(current !=NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}


void display(node *start)
{
	node *display;
	
	if(!start)
	{
		printf("no list ");
	}
	else 
	{
		printf("\ndisplaying the list......\n");
		display = start;
		
		while(display != NULL)
		{
			printf("%5d",display->data);
			display = display->next;
		}
	}
	
}			
		
int main()
{
	node *start;
	int n,choice,count,data ,position;
	
	while(1)
	{
		printf("\n\nchoose a option....\n1.creation\n2.insertion\n3.deletion\n4.traverse\n5.display\n6.exit\n\nyours choice \3:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n\ninput the number of nodes needed:");
					scanf("%d",&n);
					createList(&start,n);
					printf("\nlist has been created");
				break;
				
			case 2:printf("\n\ninput the data to add:");
					scanf("%d",&data);
					printf("\ninput the position:");
					scanf("%d",&position);
					DLLInsert(&start,data,position);
					printf("\ninserted");	
				break;
				
			case 3 :printf("\ninput the position to delete:");
					scanf("%d",&position);
					DLLDelete(&start,position);
					printf("\ndeleted");
				break;
				
			case 4: printf("\ncounting the number of nodes:");
					count = ListLength(start);
					printf("%d\n",count);
				break;
			
			case 5: display(start);
				break;
				
			case 6: exit(0);
				break;
				
			default:printf("enter the correct choice:");
		}
	}
}