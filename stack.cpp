/**********************************************
文件名称:  stack.cpp
内容摘要:  栈处理
当前版本:  无

作者		:  秦涛
创建日期:  2013.6.18
修改日期:  2013.6.29
修改记录:  重写了栈处理程序
***********************************************/


#include "public.h"
#ifdef  STACK

#include<stdio.h>
#include<string.h>
//#include<stdlib.h>

/*
#define Stack_Init_Size 100		//堆栈初始化长度
#define Stack_Increment 10		//堆栈再次增加长度
typedef char ElemType;


typedef struct					//堆栈结构
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}Stack;


void InitStack(Stack &S)									//初始化栈
{
	S.base = (ElemType *)malloc(Stack_Init_Size*sizeof(ElemType));
	if(NULL==S.base)
	{
		printf("初始化失败\n");
		exit;
	}
	S.top = S.base;
	S.stacksize = Stack_Init_Size;
}

void Push(Stack &S,ElemType e)								//压栈
{
	if((S.top-S.base)>=S.stacksize)
	{
		S.base = (ElemType *)realloc(S.base,(S.stacksize+Stack_Increment)*sizeof(ElemType));
		if(NULL==S.base)
		{
			printf("初始化失败\n");
			exit;
		}
		S.top = S.base+S.stacksize;
		S.stacksize += Stack_Increment;
	}
	*(S.top)++ = e;
}

void Pop(Stack &S,ElemType &e)								//出栈
{
	if(S.top==S.base)
	{
		printf("栈空\n");
		exit;
	}
	e = *(--S.top);

}

int Length_Stack(Stack &S)								//堆栈长度
{
	return S.top-S.base;
}


void print(Stack S)
{
	while(S.top!=S.base)
	{
		S.top--;
		printf("%d\n",*S.top);
	}


}

void  Conversion()									//进制转换
{
	Stack S;
	InitStack(S);
	ElemType N,d;
	ElemType e;
	scanf("%d %d",&N,&d);
	while(N)
	{
		Push(S,N%d);
		N = N/d;
	}
	while(S.top!=S.base)
	{
		Pop(S,e);
		printf("%d",e);
	}
	printf("\n");


}

int  Match(char *p,Stack S)
{
	if(0==Length_Stack(S)) return 0;
	if(('['==*(S.top-1))&&(']'==*p)) return 1;
	if(('('==*(S.top-1))&&(')'==*p)) return 1;
	return 0;
}

void Pair()												//字符匹配
{
	Stack S;
	InitStack(S);
	char string[100];
	printf("请输入任意字符串\n");
	gets(string);
	char *p = string;
	int flag = 0;
	while(*p)
	{
		switch(*p)
		{
			case '[':
			case '(':
				Push(S,*p);
				flag = 1;
				break;
			case ']':
			case ')':
				if(Match(p,S))
				{
					Pop(S,*p);
				}
				break;
			default:
				break;
		}
		p++;
	}
	if(0==Length_Stack(S)&&flag)
		printf("括号匹配\n");
	else
		printf("括号不匹配\n");
}

int  Fib(int n)
{
	if((1==n)||(2==n))
		return 1;
	else
		return Fib(n-1) + Fib(n-2);

}


*/


typedef int ElemType;
#define ElemType int

typedef struct note
{
	ElemType data;
	struct note *next;
}Note,*pNote;

typedef struct stack 
{
	pNote top;
	pNote bottom;
}Stack;


void InitStack(Stack *S)
{
	S->top = (pNote)malloc(sizeof(Note));
	if(NULL==S->top) return;
	S->top->next = NULL;
	S->bottom = S->top;
}


void Push(Stack *S,ElemType e)
{
	pNote p = (pNote)malloc(sizeof(Note));
	if(NULL==p) return;
	p->data = e;

	p->next = S->top;
	S->top = p;
}


void Pop(Stack *S,ElemType *e)
{
	if(S->top!=S->bottom)
	{
		*e = S->top->data;
		S->top = S->top->next;
	}
}



void Traverse(Stack S)
{
	pNote p = S.top;
	while(p != S.bottom)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}



void main()
{
	ElemType e;
	Stack S;
	InitStack(&S);
	e = 1;
	Push(&S,e);
	Push(&S,2);
	Push(&S,3);
	Push(&S,4);
	Push(&S,5);
	Traverse(S);

	Pop(&S,&e);
	printf("%d\n",e);
	Pop(&S,&e);
	printf("%d\n",e);
	Pop(&S,&e);
	printf("%d\n",e);
	Traverse(S);
}

#endif

