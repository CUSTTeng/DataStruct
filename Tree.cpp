/**********************************************
�ļ�����:  Tree.cpp
����ժҪ:  ������
��ǰ�汾:  ��

����		:  QT
�޸�����:  2013.6.27
***********************************************/
#include"public.h"

#ifdef TREE


#include<stdio.h>
#include<malloc.h>

#define ElemType int
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;


/***************************************** 
  ��������:  void CreatBiTree(BiTree &T)
  ��������:  ����������
  �������:  BiTree T  -- ������ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.2
  �޸���	  :  ����
*****************************************/

BiTree CreatBiTree(BiTree T)
{
	ElemType get = 0;

	printf("Enter the data\n");
	scanf("%d",&get);
	

	if(0==get) 
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(NULL==T)
		{
			return (BiTree)1;	
		}

		T->data = get;	
		T->lchild = CreatBiTree(T->lchild);
		T->rchild = CreatBiTree(T->rchild);
	}
		
	return T;

}


/***************************************** 
  ��������:  void ClearBiTree(BiTree *T)
  ��������:  ���������
  �������:  BiTree *T  -- ������ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.3
  �޸���	  :  ����
*****************************************/
void ClearBiTree(BiTree *T)
{
	if(NULL!=*T)
	{
		ClearBiTree(&(*T)->lchild);
		ClearBiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}


/***************************************** 
  ��������:  void PreTraverse(BiTree T)
  ��������:  ����������������
  �������:  BiTree T  -- ������ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.3
  �޸���	  :  ����
*****************************************/

void PreTraverse(BiTree T)
{
	if(NULL!=T)
	{
		printf("%d ",T->data);
		PreTraverse(T->lchild);
		PreTraverse(T->rchild);
	}
}


/***************************************** 
  ��������:  void InTraverse(BiTree T)
  ��������:  ����������������
  �������:  BiTree T  -- ������ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.3
  �޸���	  :  ����
*****************************************/

void InTraverse(BiTree T)
{
	if(NULL!=T)
	{
		InTraverse(T->lchild);
		printf("%d ",T->data);
		InTraverse(T->rchild);
	}
}

/***************************************** 
  ��������:  void PostTraverse(BiTree T)
  ��������:  ����������������
  �������:  BiTree T  -- ������ͷָ��
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.7.3
  �޸���	  :  ����
*****************************************/

void PostTraverse(BiTree T)
{
	if(NULL!=T)
	{
		PostTraverse(T->lchild);
		PostTraverse(T->rchild);
		printf("%d ",T->data);
	}
}


int main(void)
{
	BiTree pTree = NULL;
	pTree = CreatBiTree(pTree);
	PreTraverse(pTree);
	
	ClearBiTree(&pTree);
	PreTraverse(pTree);
	return 0;
}


#endif





























