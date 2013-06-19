/* 链表 */

#include "public.h"
#ifdef  LINK
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct LNote
{
  int data;
	struct LNote *next;
}LNote,*LinkList;


int Length_link(LinkList Head)						//链表长度计算
{
	int length = 0;
	LinkList L = Head;
	while(NULL!=L->next)
	{
		L = L->next;
		length++;
	}
	return length;
}

LinkList Create_Link(LinkList Head,int n)				//链表初始化
{
	if(n<0)
	{
		printf("非法长度\n");
		exit;
	}
	int value;
	Head = (LinkList)malloc(sizeof(LNote));
	Head->next = NULL;
	LinkList End = Head;
	for(int i=0;i<n;i++)
	{
		LinkList New = (LinkList)malloc(sizeof(LNote));
		if(NULL==New)
		{
			printf("分配内存失败\n");
		}
		printf("请输入参数\n");
		scanf("%d",&value);
		New->data = value;
		End->next = New;
		New->next = NULL;
		End = New;
	}
	return Head;
}


int Insert_Link(LinkList Head,int n,int e)					//链表插入元素
{
	if(n<1||n>Length_link(Head)+1)
	{
		printf("超过范围\n");
		return 0;
	}
	LinkList q = Head;
	for(int i=1;i<n;i++)
	{
		q = q->next;
	}
	LinkList p = (LinkList)malloc(sizeof(LNote));
	if(NULL==p)
	{
		printf("分配内存失败\n");
	}
	
	p->data = e;
	p->next = q->next;
	q->next = p;
	return 0;
}

int Delete_Link(LinkList Head,int n,int &e)						//链表删除元素
{
	if(n<1||n>Length_link(Head))
	{
		printf("超过范围\n");
		return 0;
	}
	LinkList q = Head;
	for(int i=1;i<n;i++)
	{
		q = q->next;
	}
	LinkList p = q->next;
	q->next = p->next;
	e = p->data;
	free(p);
	p = NULL;
	return 0;

}

int LocateElem(LinkList Head,int e)
{
	int locate = 1;
	LinkList L = Head->next;
	while(L&&L->data!=e)
	{
		L = L->next;
		locate++;
	}
	return locate;
}

void Merge_Link(LinkList La,LinkList Lb,LinkList Lc)				//顺序链表合并
{
	int i = 1;
	LinkList a = La->next;
	LinkList b = Lb->next;
	LinkList c = Lc->next;
	while((NULL!=La->next)&&(NULL!=Lb->next))
	{
		if((a->data)<=(b->data))
		{
			Insert_Link(Lc,i,a->data);
			a= a->next;
			La = La->next;
		}
		else
		{
			Insert_Link(Lc,i,b->data);
			b = b->next;
			Lb = Lb->next;
		}
		i++;
	}
	while(NULL!=La->next)
	{
		Insert_Link(Lc,i,a->data);
		a= a->next;
		La = La->next;
		i++;
	}
	while(NULL!=Lb->next)
	{
		Insert_Link(Lc,i,b->data);
		b= b->next;
		Lb = Lb->next;
		i++;
	}
}


/***************************************** 
  函数名称:  void Swap(int *a,int *b) 
  功能描述:  数据交换
  输入参数:  int *a --数据1
                             int * b --数据2
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.6.18
  修改人	  :  QT
*****************************************/
void Swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/***************************************** 
  函数名称:  void Sort_Link(LinkList Head) 
  功能描述:  链表排序
  输入参数:  LinkList Head --链表头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.6.18
  修改人	  :  QT
*****************************************/
void Sort_Link(LinkList Head)
{
	int n = 0;
	n = Length_link(Head);
	LinkList p = NULL;
	for(p = Head->next;p->next!=NULL;p = p->next)
		for(LinkList q = p->next;q!=NULL;q = q->next)
		{
			if((p->data)>(q->data)) 
				Swap(&p->data,&q->data);
			
		}
}


void print(LinkList Head)									//打印链表
{
	LinkList L = Head->next;
	while(NULL!=L)
	{
		printf("%d ",L->data);
		L = L->next;
	}
	printf("\n");
}




void main()
{
	LinkList La,Lb,Lc;
	int n;
	int e;
	int locate;
	printf("输入初始化长度\n");
	scanf("%d",&n);
	La = Create_Link(La,n);

	Sort_Link(La);
	print(La);

	

//	printf("%d\n",n);

//	printf("输入初始化长度\n");
//	scanf("%d",&n);
//	Lb = Create_Link(Lb,n);

	

	
//	Lc = Create_Link(Lc,0);
//	print(La);
//	print(Lb);
//	print(Lc);
//	Merge_Link(La,Lb,Lc);
//	print(Lc);
//	print(La);
//	print(La);

//	printf("链表长度%d\n",Length_link(La));
//	Insert_Link(La,6,10);
//	print(La);
//	printf("链表长度%d\n",Length_link(La));
//	Delete_Link(La,6,e);
//	print(La);
//	printf("链表长度%d\n",Length_link(La));
//	printf("%d\n",e);	
//	locate = LocateElem(La,1);
//	printf("%d\n",locate);
		
	
}

#endif

