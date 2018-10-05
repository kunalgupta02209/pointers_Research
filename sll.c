#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *link;
	int data;
}sll_node;

sll_node* insertLeft(sll_node *first, int item)
{
	sll_node *temp = (sll_node *)malloc(sizeof(sll_node*));
	temp->data = item;
	temp->link = NULL;
	if(first == NULL)
		first = temp;
	else
	{
		temp->link = first;
		first = temp;
	}
	//printf("*first = %p , %d, %p\n", first, first->data, first->link);
	//printf("*temp = %p , %d, %p\n", temp, temp->data, temp->link);
	return first;
}

void insertEnd(sll_node *first, int item)
{
	sll_node *cur, *temp;
	temp = (sll_node *)malloc(sizeof(sll_node*));
	cur = first;
	temp->data = item;
	temp->link = NULL;
	while(cur->link != NULL)
		cur = cur->link;
	cur->link = temp;
	//printf("*first = %p , %d, %p", first, first->data, first->link);
}

void insertKey(sll_node *first, int item, int key)
{
	sll_node *cur, *temp;
	temp = (sll_node *)malloc(sizeof(sll_node*));
	cur = first;
	temp->data = item;
	temp->link = NULL;
	if(first == NULL)
		return;
	while(1)
	{
		if(cur->link == NULL)
		{
			printf("Key not present in the list\n");
			break;
		}
		else if(cur-> data != key)
			cur = cur->link;
		else
		{
			temp->link = cur->link;
			cur->link = temp;
			break;
		}
	}
}

void display(sll_node *first)
{
	sll_node *cur = first;
	if(cur == NULL)
		printf("List Empty\n");
	else
	{
		printf("link: %p\t data: %d\n", cur->link, cur->data);
		cur = cur->link;
	}
}

int insertItem()
{
	int item;
	printf("Enter Item to insert\n");
	scanf("%d", &item);
	return item;
}


int main()
{
	int sel = 0, key = 0;
	sll_node *first = NULL;
	//insertLeft(first, item);
	while(sel != 6)
	{
		//printf("*first = %p , %d, %p\n", first, first->data, first->link);
		printf("Select a linked list operation to perform\n");
		printf("1. InsertLeft\n2. Insert Pos\n3. Insert End\n4. DeletePos\n5. Display\n6. Exit\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				first = insertLeft(first, insertItem());
				printf("*first = %p ", first);
				break;
			case 2:
				printf("Enter key after which to insert\n");
				scanf("%d", &key);
				insertKey(first, insertItem(), key);
				break;
			case 3:
				insertEnd(first, insertItem());
				break;
			case 5:
				display(first);
				break;
			case 6:
				break;
			default:
				printf("Wrong operation selection");
				break;

		}
	}
}
