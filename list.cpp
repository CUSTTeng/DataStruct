/*
���Ա�

*/
#include "public.h"
#ifdef  LIST

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
	int  *elem;			//�洢�ռ��ַ
	int length;			//��ǰ����
	int listsize;			//��ǰ����Ĵ洢����
}SqList;
	
int Init_List(SqList &L)			//���Ա��ʼ��
{
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem) 
	{
		printf("��ʼ���ڴ�ʧ��\n");
		return ERROR;
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int Insert_List(SqList &L,int i,int e)				//�����Ա�ָ��λ�ò���Ԫ��
{

	if(i<1||i>L.length+1) 
	{
		printf("����λ�ó���\n");
		return ERROR;
	}
	if(L.length>=L.listsize)
	{
		int *newbase = (int *)realloc(L.elem,LIST_INIT_SIZE+LISTINCREMENT);
		if(!newbase) printf("��ʼ���ڴ�ʧ��\n");	
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	int *q = &(L.elem[i-1]);
	for(int *p=&(L.elem[L.length-1]);p>=q;p--)
	{
		*(p+1) = *p;
	}

	*q = e;
	L.length++;
	return OK;
}

int Delete_List(SqList &L,int i,int &e)			//�����Ա�ָ��λ��ɾ��Ԫ��
{
	if(i<1||i>L.length)
	{
		printf("ɾ��λ�ó���\n");
		return ERROR;
	}

	int *q =&(L.elem[i-1]);
	e = *q;
	for(;q<&(L.elem[L.length-1]);q++)
	{
		*q = *(q+1);	
	}
	L.length--;
	return OK;
}

int Locate_List(SqList &L,int &e)			//�����Ա����ҵ�ָ��Ԫ��
{
	int i;
	for(i=1;i<=L.length;i++)
	{
		if(L.elem[i-1]==e)
		{
			return i; 
		}
	}
	if(i==L.length+1)
	{
		printf("�޸�����\n");
		return ERROR;
	}
}

void  Destroy_List(SqList &L)			//�������Ա�
{
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}

void Clear_List(SqList &L)			//������Ա��е�Ԫ��
{
	L.length = 0;
}


void Insert_Sq(SqList &L,int &x)			//��һ��Ԫ�ز���˳���
{
	for(int j=1;j<=L.length;j++)
	{
		if((x<=L.elem[j-1]))
		{
			Insert_List(L,j,x);
			break;

		}
	}
	if(j==L.length+1)
	{
		Insert_List(L,j,x);
	}
}

void Merge_List(SqList La,SqList Lb,SqList &Lc)
{
	int *pa,*pb,*pc;
	int *pa_last,*pb_last;
	
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length+Lb.length;
	pc = Lc.elem = (int *)malloc(sizeof(int)*Lc.listsize);
	if(!Lc.elem)
	{
		printf("��ʼ���ڴ�ʧ��\n");
	}
	pa_last = &La.elem[La.length-1];
	pb_last = &Lb.elem[Lb.length-1];

	while((pa<=pa_last)&&(pb<=pb_last))
	{
		if(*pa<=*pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa<=pa_last)
		*pc++ = *pa++;
	while(pb<=pb_last)
		*pc++ = *pb++;
}





int print(SqList &L)			//��ӡ����
{
	for(int i=0;i<L.length;i++)
	{
		printf("%d\n",L.elem[i]);
	}
	return OK;

}

int main()
{
	SqList La,Lb,Lc;			
	Init_List(La);			//��ʼ�����Ա�
	Init_List(Lb);
	for(int i=1;i<=5;i++)
	{
		Insert_List(La,i,i*2-1);
		Insert_List(Lb, i, (i-1)*2);
	}
	print(La);
	print(Lb);
	printf("------------------\n");

	Init_List(Lc);
	Merge_List(La,Lb,Lc);
	print(Lc);
	
	return OK;
}


#endif
