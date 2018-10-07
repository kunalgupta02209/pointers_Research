#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *link;
	int data;
}sll_node;

void insertLeft(sll_node **first, int item)
{
	sll_node *temp = (sll_node *)malloc(sizeof(sll_node));
	//printf("*first = %p\n", first);
	temp->data = item;
	temp->link = NULL;
	if(first == NULL)
		*first = temp;
	else
	{
		temp->link = *first;
		*first = temp;
	}
	//printf("*first = %p , %d, %p\n", first, (*first)->data, (*1first)->link);
	//printf("*temp = %p , %d, %p\n", temp, temp->data, temp->link);
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
	//printf("*first = %p , %d, %p", cur, cur->data, cur->link);
}

void insertKey(sll_node *first, int item, int key)
{
	sll_node *cur, *temp;
	temp = (sll_node *)malloc(sizeof(sll_node*));
	cur = first;
	temp->data = item;
	temp->link = NULL;
	if(first != NULL && first->data == key)
	{
		temp->link = cur->link;
		cur->link = temp;
		return;
	}
	while(cur != NULL && cur->data != key)
		cur = cur->link;
	if(cur == NULL)
	{
		printf("Key not present in the list\n");
		return;
	}
	temp->link = cur->link;
	cur->link = temp;
}

void delete(sll_node **first, int key)
{
	sll_node *prev, *cur;
	cur = *first;
	printf("%d\n", (*first)->data);
	if(*first != NULL && (*first)->data == key)
	{
		*first = (*first)->link;
		free(cur);
		return;
	}
	while (cur != NULL && cur->data != key)
    {
        prev = cur;
        cur = cur->link;
    }
    if(cur == NULL)
    {
    	printf("Key not present in list\n");
    	return;
    }
    prev->link = cur->link;
    free(cur);
}

void display(sll_node* first)
{
	sll_node* cur = first;
	if(cur == NULL)
		printf("List Empty\n");
	else
	{
    	while(cur != NULL)
    	{
    		printf("data: %d\t link: %p\n", cur->data, cur->link);
    		cur = cur->link;
    		//printf("link: %p\t data: %d\n", cur->link, cur->data);
    	}
    	//printf("link: %p\t data: %d\n", cur->link, cur->data);
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
	sll_node* first = NULL;
	//insertLeft(first, item);
	insertLeft(&first, 5);
  	insertLeft(&first, 4);
  	insertLeft(&first, 3);
	//printf("*first = %p , %d, %p\n", first, first->data, first->link);
 	display(first);
	while(sel != 6)
	{
		//printf("*first = %p , %d, %p\n", first, first->data, first->link);
		printf("Select a linked list operation to perform\n");
		printf("1. InsertLeft\n2. Insert Pos\n3. Insert End\n4. DeletePos\n5. Display\n6. Exit\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				insertLeft(&first, insertItem());
				//printf("*first = %p ", first);
				break;
			case 2:
				printf("Enter key after which to insert\n");
				scanf("%d", &key);
				insertKey(first, insertItem(), key);
				break;
			case 3:
				insertEnd(first, insertItem());
				break;
			case 4:
				printf("Enter which element to delete\n");
				scanf("%d", &key);
				delete(&first, key);
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
