/**********************************************
文件名称:  Tree.cpp
内容摘要:  二叉树
当前版本:  无

作者		:  QT
修改日期:  2013.6.27
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
  函数名称:  void CreatBiTree(BiTree &T)
  功能描述:  二叉树创建
  输入参数:  BiTree T  -- 二叉树头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.2
  修改人	  :  秦涛
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
  函数名称:  void ClearBiTree(BiTree *T)
  功能描述:  二叉树清除
  输入参数:  BiTree *T  -- 二叉树头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.3
  修改人	  :  秦涛
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
  函数名称:  void PreTraverse(BiTree T)
  功能描述:  二叉树先序遍历输出
  输入参数:  BiTree T  -- 二叉树头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.3
  修改人	  :  秦涛
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
  函数名称:  void InTraverse(BiTree T)
  功能描述:  二叉树中序遍历输出
  输入参数:  BiTree T  -- 二叉树头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.3
  修改人	  :  秦涛
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
  函数名称:  void PostTraverse(BiTree T)
  功能描述:  二叉树后序遍历输出
  输入参数:  BiTree T  -- 二叉树头指针
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.3
  修改人	  :  秦涛
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





























