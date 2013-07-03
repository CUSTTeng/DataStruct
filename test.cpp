#include "public.h"
#ifdef TEST
#include<stdio.h>
#include<stdlib.h>

void test(int **p)
{
	*p = NULL;
}


int main(void)
{
	int *p =(int *)malloc(sizeof(int));

	test(&p);
	printf("%d\n",p);
	
	return 0;
}

#endif

 
