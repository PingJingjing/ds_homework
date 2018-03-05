#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node*next;
}Node,*List;

int main()
{
	Node head;
	InitList(&head);
	/*
	int i;
	for(i=0;i<5;i++)
	{
		Insert_head(&head,i);
	}*/
	
	int i;
	for(i=0;i<5;i++)
	{
		Insert_tail(&head,i);
	}
	Show(&head);
	
	Insert(&head,6,3);
	Show(&head);

	Delete_head(&head,2);
	Show(&head);

	Delete_tail(&head);
	Show(&head);

	Delete(&head);
	Show(&head);

	printf("%d\n",Adress(&head,3));
	
	Reserve(&head);
	Show(&head);

	return 0;
}
