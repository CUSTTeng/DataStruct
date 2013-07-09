#include "public.h"
#ifdef TEST
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void test(int **p)
{
	*p = NULL;
}


int main(void)
{
	srand(time(NULL));
	
	for(int i=0;i<10;i++)
		printf("%d\n",rand()%100);
	

	printf("%");
	return 0;
}

#endif

 
