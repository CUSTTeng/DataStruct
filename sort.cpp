/**********************************************
文件名称:  Sort.cpp
内容摘要:  五种排序算法
当前版本:  无

作者		:  秦涛
创建日期:  2013.7.3
修改日期:  2013.7.8
***********************************************/
#include"public.h"

#ifdef SORT 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
#define NUMBER 100000


/***************************************** 
  函数名称:  void RanNumCreat(ElemType *e)
  功能描述:  随机数组生成
  输入参数:  ElemType *e -- 数组头指针
  			      int n -- 数组长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.8
  修改人	  :  秦涛
*****************************************/
void RandNumCreat(ElemType *e,int n)
{	
	int temp = 0;
	int i = 0;

	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		temp = rand();
		*(e+i) = temp;
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
  修改人	  :  秦涛
*****************************************/
void Swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/***************************************** 
  函数名称:  void Traverse(ElemType *e,int n)
  功能描述:  遍历输出数组
  输入参数:  ElemType *e -- 数组头指针
  			      int n -- 数组长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.8
  修改人	  :  秦涛
*****************************************/
void Traverse(ElemType *e,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\n",*(e+i));

	}
}


/***************************************** 
  函数名称:  void Bubble(ElemType *e)
  功能描述:  冒泡法排序
  输入参数:  ElemType *e -- 数组头指针
  			      int n -- 数组长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.3
  修改人	  :  秦涛
*****************************************/
void BubbleSort(ElemType *e,int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(*(e+i)>*(e+j)) 
				Swap(e+i, e+j);
		}
}

/***************************************** 
  函数名称:  int FindMin(ElemType *e,int n)
  功能描述:  查找数组中的最小值
  输入参数:  ElemType *e -- 数组头指针
  			      int n -- 数组长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.8
  修改人	  :  秦涛
*****************************************/
int FindMin(ElemType *e,int n)
{
	int index = 0;
	int temp = *e;
	for(int i=1;i<n;i++)
	{
		if(temp>*(e+i)) 
		{
			temp = *(e+i);
			index = i;
		}

	}

	return index;
}


/***************************************** 
  函数名称:  void Insert(ElemType *e,int n)
  功能描述:  插入法排序
  输入参数:  ElemType *e -- 数组头指针
  			      int n -- 数组长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.8
  修改人	  :  秦涛
*****************************************/
void SelectSort(ElemType *e,int n)
{
	int index = 0;
	for(int i=0;i<n;i++)
	{
		index = FindMin(e+i,n-i);
		Swap(e+i,e+i+index);
		
	}

}

/***************************************** 
  函数名称:  void Partition(ElemType *n,int left,int right)
  功能描述:  位置确定
  输入参数:  ElemType *e -- 数组头指针
  			      int left -- 数组左边界
  			      int right -- 数组右边界
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.8
  修改人	  :  秦涛
*****************************************/
int Partition(ElemType *array,int left,int right)
{
	int temp = array[left];
	while(left<right)
	{
		while((left<right)&&(array[right]>=temp))
			right--;
		if(left<right)
			array[left++] = array[right];

		while ((left<right)&&(array[left]<=temp))
			left++;
		if(left<right)
			array[right--] = array[left];
	}

	array[left] = temp;
	return left;
}


/***************************************** 
  函数名称:  void QuickSort(ElemType *e,int n)
  功能描述:  快速法排序
  输入参数:  ElemType *e -- 数组头指针
  			      int left -- 数组左边界
  			      int right -- 数组右边界
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.7.8
  修改人	  :  秦涛
*****************************************/
void QuickSort(ElemType *array,int left,int right)
{
	int dp;
	if (left<right) 
	{
		dp=Partition(array,left,right);
		QuickSort(array,left,dp-1);
		QuickSort(array,dp+1,right);
	}
}




int main(void)
{
	int n = NUMBER;
	int randArry1[NUMBER] = {0};
	//int randArry2[NUMBER] = {10,9,8,7,6,5,4,3,2,1};
	int randArry2[7] ={49,38,65,97,76,13,27};
	clock_t start1,start2,end1,end2;
	double runTime1 = 0;
	double runTime2 = 0;
	
	RandNumCreat(randArry1,n);
	//RandNumCreat(randArry2,n);

	//	Traverse(randArry,n);
	printf("start\n");
	system("pause");

	start1 = clock();
	//BubbleSort(randArry1,n);
	end1 = clock();

	//Traverse(randArry,n);
	
	start2 = clock();
	QuickSort(randArry1,0,NUMBER-1);
	end2 = clock();
	//Traverse(randArry1,NUMBER);

	runTime1 = (double)(end1-start1)/CLOCKS_PER_SEC;
	runTime2 = (double)(end2-start2)/CLOCKS_PER_SEC;
	printf("selectsort=%f,quicksort=%f\n",runTime1,runTime2);

	return 0;
}







#endif

