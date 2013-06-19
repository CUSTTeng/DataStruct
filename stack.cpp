/* 栈 */
#include "public.h"
#ifdef  STACK

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
using namespace std;

#define Stack_Init_Size 100  	//堆栈初始化长度
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




void main()
{
	int a = 1;
	int b = 2;
	int c;
	c = (a = b+1);
	printf("%d\n",c);



}

#endif

