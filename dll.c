#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *plink;
	int data;
	struct node *nlink;
}dll_node;

void insertFront(dll_node **first, int item)
{
	dll_node *temp = (dll_node *)malloc(sizeof(dll_node));
	//printf("*first = %p\n", first);
	temp->data = item;
	temp->nlink = NULL;
	temp->plink = NULL;
	//printf("herel\n");
	if(*first == NULL)
	{
		//printf("herei\n");
		*first = temp;
	}
	else
	{
		//printf("heree\n");
		temp->nlink = *first;
		(*first)->plink = temp;
		*first = temp;
	}
	//printf("*first = %p , %d, %p\n", first, (*first)->data, (*1first)->link);
	//printf("*temp = %p , %d, %p\n", temp, temp->data, temp->link);
}


void insertAfter(dll_node *cur, int item)
{
	dll_node *temp, *next;
	temp = (dll_node *)malloc(sizeof(dll_node*));
	next = (cur)->nlink;
	next->plink = temp;
	temp->data = item;
	temp->nlink = (cur)->nlink;
	temp->plink = cur;
	(cur)->nlink = temp;
}

dll_node* findNode(dll_node *first, int key)
{
	dll_node *cur = first;
	if(first == NULL)
	{
		printf("List Empty");
		return NULL;
	}
	else
	{
		while(cur != NULL && cur->data != key)
			cur = cur->nlink;
		if(cur == NULL)
		{
			printf("Key not present in the list\n");
			return NULL;
		}
		return cur;
	}
}

void insertEnd(dll_node **first, int item)
{
	dll_node *cur, *temp;
	temp = (dll_node *)malloc(sizeof(dll_node*));
	cur = *first;
	temp->data = item;
	temp->nlink = NULL;
	temp->plink = NULL;
	if(*first == NULL)
	{
		*first = temp;
		return;
	}
	while(cur->nlink != NULL)
		cur = cur->nlink;
	cur->nlink = temp;
	temp->plink = cur;
	//printf("*first = %p , %d, %p", cur, cur->data, cur->link);
}

void deleteNode(dll_node **cur, int item)
{
	dll_node *prev, *next, *temp;
	temp = *cur;
	if((*cur)->plink == NULL && (*cur)->nlink == NULL)
	{
		*cur = NULL;
		free(temp);
	}
	else if((*cur)->plink == NULL)
	{
		next = (*cur)->nlink;
		next->plink = NULL;
		*cur = (*cur)->nlink;
		free(temp);
	}
	else if((*cur)->nlink == NULL)
	{
		prev = (*cur)->plink;
		prev->nlink = NULL;
		free(temp);
	}
	else
	{
		next = (*cur)->nlink;
		prev = (*cur)->plink;
		next->plink = prev;
		prev->nlink = next;
		free(temp);
	}
}

void display(dll_node* first)
{
	dll_node* cur = first;
	if(cur == NULL)
		printf("List Empty\n");
	else
	{
    	while(cur != NULL)
    	{
    		printf("data: %d\t plink: %p\t nlink: %p\n", cur->data, cur->plink, cur->nlink);
    		cur = cur->nlink;
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
	dll_node *first = NULL, *temp = NULL;
	//insertFront(first, item);
	//printf("here\n");
	/*insertFront(&first, 5);
  	insertFront(&first, 4);
  	insertFront(&first, 3);
  	insertFront(&first, 2);*/
  	insertFront(&first, 1);
	//printf("*first = %p , %d, %p\n", first, first->data, first->link);
 	display(first);
	while(sel != 6)
	{
		//printf("*first = %p , %d, %p\n", first, first->data, first->link);
		printf("Select a linked list operation to perform\n");
		printf("1. Insert Front\n2. Insert After\n3. Insert End\n4. DeletePos\n5. Display\n6. Exit\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				insertFront(&first, insertItem());
				//printf("*first = %p ", first);
				break;
			case 2:
				printf("Enter key after which to insert\n");
				scanf("%d", &key);
				temp = findNode(first, key);
				if(temp != NULL)
					insertAfter(temp, insertItem());
				//insertKey(first, insertItem(), key);
				break;
			case 3:
				insertEnd(&first, insertItem());
				break;
			case 4:
				printf("Enter which element to delete\n");
				scanf("%d", &key);
				temp = findNode(first, key);
				if(temp != NULL)
				{
					if(temp == first)
						deleteNode(&first, key);
					else
						deleteNode(&temp, key);
				}
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
