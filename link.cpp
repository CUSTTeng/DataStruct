/**********************************************
�ļ�����:  link.cpp
����ժҪ:  ������
��ǰ�汾:  ��

����		:  ����
��������:  2013.6.18
�޸�����:  2013.7.2
�޸ļ�¼:  ��д�����������
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


int Length_link(LinkList Head)						//�����ȼ���
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

LinkList Create_Link(LinkList Head,int n)				//�����ʼ��
{
	if(n<0)
	{
		printf("�Ƿ�����\n");
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
			printf("�����ڴ�ʧ��\n");
		}
		printf("���������\n");
		scanf("%d",&value);
		New->data = value;
		End->next = New;
		New->next = NULL;
		End = New;
	}
	return Head;
}


int Insert_Link(LinkList Head,int n,int e)					//�������Ԫ��
{
	if(n<1||n>Length_link(Head)+1)
	{
		printf("������Χ\n");
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
		printf("�����ڴ�ʧ��\n");
	}
	
	p->data = e;
	p->next = q->next;
	q->next = p;
	return 0;
}

int Delete_Link(LinkList Head,int n,int &e)						//����ɾ��Ԫ��
{
	if(n<1||n>Length_link(Head))
	{
		printf("������Χ\n");
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

void Merge_Link(LinkList La,LinkList Lb,LinkList Lc)				//˳������ϲ�
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
  ��������:  void Swap(int *a,int *b) 
  ��������:  ���ݽ���
  �������:  int *a --����1
                             int * b --����2
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.6.18
  �޸���	  :  QT
*****************************************/
void Swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/***************************************** 
  ��������:  void Sort_Link(LinkList Head) 
  ��������:  ��������
  �������:  LinkList Head --����ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.6.18
  �޸���	  :  QT
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


//void print(LinkList Head)									//��ӡ����
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
  ��������:  pNote CreateLink(pNote L)
  ��������:  �����ʼ��
  �������:  pNote L -- ����ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.1
  �޸���	  :  ����
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
  ��������:  void InsertLink(pNote L,int n,ElemType *e)
  ��������:  ����Ԫ�ز���
  �������:  pNote L -- ����ͷָ��
  			      int n -- ɾ��Ԫ��λ��
  			      ElemType *e -- ɾ��Ԫ��ֵ
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.1
  �޸���	  :  ����
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
  ��������:  void DeleteLink(pNote L,int n,ElemType *e)
  ��������:  ����Ԫ��ɾ��
  �������:  pNote L -- ����ͷָ��
  			      int n -- ɾ��Ԫ��λ��
  �������:   ElemType *e -- ɾ��Ԫ��ֵ
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.1
  �޸���	  :  ����
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
  ��������:  int LengthLink(pNote L)
  ��������:  ����������
  �������:  pNote L -- ����ͷָ��
  �������:  ��
  ����ֵ	  :  ������
  
  �޸�����:  2013.7.1
  �޸���	  :  ����
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
  ��������:  void Sort_Link(LinkList Head) 
  ��������:  ��������
  �������:  LinkList Head --����ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.6.18
  �޸���	  :  QT
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
  ��������:  void Traverse(pNote L)
  ��������:  �����������
  �������:  pNote L -- ����ͷָ��
  �������:  ��
  ����ֵ	  :  ������
  
  �޸�����:  2013.7.1
  �޸���	  :  ����
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

