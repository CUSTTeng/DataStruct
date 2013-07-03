/**********************************************
文件名称:  link.cpp
内容摘要:  链表处理
当前版本:  无

作者		:  秦涛
创建日期:  2013.6.18
修改日期:  2013.7.2
修改记录:  重写了链表处理程序
***********************************************/


#include "public.h"
#ifdef  LINK
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


/*
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
*/




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
//void Sort_Link(pNote L)
//{
//	int n = 0;
//	n = LengthLink(L);
//	pNote p = NULL;
//	for(p = L->next;p->next!=NULL;p = p->next)
//		for(pNote q = p->next;q!=NULL;q = q->next)
//		{
//			if((p->data)>(q->data)) 
//				Swap(&p->data,&q->data);
//			
//		}
//}


//void print(LinkList Head)									//打印链表
//{
//	LinkList L = Head->next;
//	while(NULL!=L)
//	{
//		printf("%d ",L->data);
//		L = L->next;
//	}
//	printf("\n");
//}





typedef int ElemType;

typedef struct note
{
	ElemType data;
	struct note *next;
}Note,*pNote;

pNote CreateLink(pNote L);
void InsertLink(pNote L,int n,ElemType e);
void DeleteLink(pNote L,int n,ElemType *e);
int LengthLink(pNote L);
void Traverse(pNote L);


/***************************************** 
  函数名称:  pNote CreateLink(pNote L)
  功能描述:  链表初始化
  输入参数:  pNote L -- 链表头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.1
  修改人	  :  秦涛
*****************************************/

pNote CreateLink(pNote L)
{
	int n = 0;
	int i = 0;

	L = (pNote)malloc(sizeof(Note));
	if(NULL==L) return (pNote)1;
	pNote head = L;
	
	printf("Enter length\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		pNote p = (pNote)malloc(sizeof(Note));
		if(NULL==p) return (pNote)1;
		printf("Enter data\n");
		scanf("%d",&p->data);
		p->next = NULL;
		head->next = p;
		head = p;
	}
	
	return L;

}


/***************************************** 
  函数名称:  void InsertLink(pNote L,int n,ElemType *e)
  功能描述:  链表元素插入
  输入参数:  pNote L -- 链表头指针
  			      int n -- 删除元素位置
  			      ElemType *e -- 删除元素值
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.1
  修改人	  :  秦涛
*****************************************/
void InsertLink(pNote L,int n,ElemType e)
{
	pNote p = L;
	if(n<1||n>(LengthLink(L)+1))
		printf("Enter error\n");
	while(1!=n)
	{
		p = p->next;
		n--;
	}
	pNote q = (pNote)malloc(sizeof(Note));
	if(NULL==q)
	{
		printf("Request error\n");
		return;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;


}



/***************************************** 
  函数名称:  void DeleteLink(pNote L,int n,ElemType *e)
  功能描述:  链表元素删除
  输入参数:  pNote L -- 链表头指针
  			      int n -- 删除元素位置
  输出参数:   ElemType *e -- 删除元素值
  返回值	  :  无
  
  修改日期:  2013.7.1
  修改人	  :  秦涛
*****************************************/

void DeleteLink(pNote L,int n,ElemType *e)
{
	pNote p = L;
	if(n<1||n>LengthLink(L))
		printf("Enter error\n");
	while(1!=n)
	{
		p = p->next;
		n--;
	}
	pNote q = p->next;
	p->next = p->next->next;
	*e = q->data;
	free(q);
	q = NULL;

}

/***************************************** 
  函数名称:  int LengthLink(pNote L)
  功能描述:  计算链表长度
  输入参数:  pNote L -- 链表头指针
  输出参数:  无
  返回值	  :  链表长度
  
  修改日期:  2013.7.1
  修改人	  :  秦涛
*****************************************/


int LengthLink(pNote L)
{
	int n = 0;
	pNote p = L;
	while(NULL!=p->next)
	{
		p = p->next;
		n++;
	}
	return n;




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
void SortLink(pNote L)
{
	int n = 0;
	n = LengthLink(L);
	pNote p = NULL;
	for(p = L->next;p->next!=NULL;p = p->next)
		for(pNote q = p->next;q!=NULL;q = q->next)
		{
			if((p->data)>(q->data)) 
				Swap(&p->data,&q->data);
			
		}
}





/***************************************** 
  函数名称:  void Traverse(pNote L)
  功能描述:  遍历输出链表
  输入参数:  pNote L -- 链表头指针
  输出参数:  无
  返回值	  :  链表长度
  
  修改日期:  2013.7.1
  修改人	  :  秦涛
*****************************************/
void Traverse(pNote L)
{
	pNote p = L;
	while(NULL!=p->next)
	{
		printf("%d\n",p->next->data);
		p = p->next;
	}
}




void main()
{
	int e = 0;
	int n = 0;
	pNote L = NULL;
	L= CreateLink(L);
	Traverse(L);

	printf("\n\n");

	SortLink(L);
	Traverse(L);
}

#endif

