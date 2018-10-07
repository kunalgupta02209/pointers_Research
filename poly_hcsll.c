#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *link;
	int exp, coef;
}poly;


void insertEnd(poly **cur, int exp, int coef)
{
	poly *temp = (poly *)malloc(sizeof(poly*));
	temp->exp = exp;
	temp->coef = coef;
	(*cur)->link = temp;
}

poly* create_poly()
{
	poly* head = (poly *)malloc(sizeof(poly*));
	head->exp = -1;
	head->coef = 0;
	poly *cur = head;
	int n;
	printf("Enter the no. of terms in the polynomial\n");
	scanf("%d",&n);
	for(int i = 0; i< n; i++)
	{
		poly *temp = (poly *)malloc(sizeof(poly*));
		printf("Enter the coefficient and exponent\n");
		scanf("%d %d", &(temp->coef), &(temp->exp));
		cur->link = temp;
		cur = cur->link;
	}
	cur->link = head;
	return head;
}

poly* add(poly *head1, poly *head2)
{
	poly *head = (poly*)malloc(sizeof(poly*));
	head->exp = -1;
	head->coef = 0;
	poly *cur = head;
	poly *p1 = head1->link;
	poly *p2 = head2->link;
	while(1)
	{
		if(p1->exp == p2->exp && p1->exp == -1)
			break;
		if(p1->exp == p2->exp)
		{
			insertEnd(&cur, p1->exp, p1->coef+p2->coef);
			cur = cur->link;
			p1 = p1->link;
			p2 = p2->link;
		}
		else if(p1->exp > p2->exp)
		{
			insertEnd(&cur, p1->exp, p1->coef);
			cur = cur->link;
			p1 = p1->link;
		}
		else
		{
			insertEnd(&cur, p2->exp, p2->coef);
			cur = cur->link;
			p2 = p2->link;
		}
	}
	cur->link = head;
	return head;
}

void display(poly* head)
{
	poly* cur = head->link;
	if(cur == NULL)
		printf("List Empty\n");
	else
	{
    	while(cur != head)
    	{
    		printf("%dx^%d", cur->coef, cur->exp);
    		cur = cur->link;
    		if(cur != head)
    			printf(" + ");
    	}
    	printf("\n");
	}
}

int main()
{
	int sel = 0, key = 0;
	poly *poly1, *poly2, *sum;
	printf("Enter the first polynomial\n");
	poly1 = create_poly();
	printf("Enter the second polynomial\n");
	poly2 = create_poly();
	display(poly1);
	display(poly2);
	sum = add(poly1, poly2);
	display(sum);
}
