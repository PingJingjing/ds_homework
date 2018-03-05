#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define bool int 
#define true -1
#define false -2

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;

void InitList(List plist)
{
	assert(plist!=NULL);
	if(plist == NULL)
	{
		return;
	}
	plist->next=NULL;
}
/*
bool Insert_head(List plist,int val)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=val;
	p->next=plist->next;
	plist->next=p;

	return true;
}
*/
bool Insert_tail(List plist,int val)
{
	Node *p;
	for(p=plist;p->next!=NULL;p=p->next);
	Node *q=(Node*)malloc(sizeof(Node));
	q->data=val;
	q->next=p->next;
	p->next=q;

	return true;
}

static Node *SearchPrio(List plist,int val)
{
	Node *p;
	for(p=plist;p->next!=NULL;p=p->next)
	{
		if(p->next->data == val)
		{
			return p;
		}
	}
}

bool Insert(List plist,int val,int pos)
{
	Node *p;
	Node *q=(Node*)malloc(sizeof(Node));
	int count=0;
	for(p=plist->next;p!=NULL;p=p->next)
	{
		count++;
		if(count+1 == pos)
		{
			q->data=val;
			q->next=p->next;
			p->next=q;
		}
	}
}

bool Delete_head(List plist)
{
	if(plist->next == NULL)
	{
		return false;
	}
	Node *p;
	p=plist->next;
    plist->next=p->next;
	free(p);

	return true;
}

bool Delete_tail(List plist)
{
	Node *p;
	for(p=plist;p->next!=NULL;p=p->next);
	Node *q=SearchPrio(plist,p->data);
	q->next=p->next;
	free(p);

	return true;
}

bool Delete(List plist,int pos)
{
	Node *p;
	Node *q;
	int count=0;
	for(p=plist->next;p!=NULL;p=p->next)
	{
		count++;
		if(count+1 == pos)
		{
			q=p->next;
			p->next=p->next->next;
			free(q);
			break;
		}
	}
	return true;
}

int Adress(List plist,int val)
{
	Node *p;
	for(p=plist->next;p!=NULL;p=p->next)
	{
		if(p->data == val)
		{
			return (int)p;
		}
	}
	return -2;
}


void Reserve(List plist)
{
	if(plist->next == NULL )
	{
		return;
	}
	else if(plist->next->next == NULL)
	{
		return;
	}
	Node *p=plist->next;
	Node *q;
	plist->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=plist->next;
		plist->next=p;
		p=q;
	}

}

void Show(List plist)
{
	Node *p;
	for(p=plist->next;p!=NULL;p=p->next)
	{
		printf("%d  %d\n",p->data,p);
	}
	printf("\n");
}
