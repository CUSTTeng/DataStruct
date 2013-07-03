/**********************************************
文件名称:  queue.cpp
内容摘要:  队列处理
当前版本:  无

作者		:  QT
修改日期:  2013.6.18
***********************************************/

#include "public.h"
#ifdef QUEUE

#include<stdio.h>
#include<malloc.H>

#define QElemType int
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;		//队头指针
	QueuePtr rear;			//队尾指针
}LinkQueue;

int InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(NULL==Q.front)
	{
		return 1;
	}
	Q.front->next = NULL;
	return 0;
}

int EnQueue(LinkQueue &Q,QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(NULL==p)
	{
		return 1;
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 0;
}

int DeQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if((Q.front==Q.rear)||(NULL==p))
	{
		return 1;
	}
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear==p)
		Q.rear = Q.front;
	free(p);
	return 0;
}


int DestroyQueue(LinkQueue &Q)
{
	while(NULL!=Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return 0;
}

void print(LinkQueue Q)
{
	QueuePtr p = Q.front;
	while(p!=Q.rear)
	{
		printf("%d\n",p->next->data);
		p = p->next;
	}
}


int main()
{
	QElemType e = 0;
	LinkQueue queue;
	InitQueue(queue);
	for(int i=0;i<10;i++)
		EnQueue(queue,i);
	print(queue);

	DestroyQueue(queue);
	print(queue);

	return 0;
}




#endif



