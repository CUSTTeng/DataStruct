#include "public.h"
#ifdef TEST
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
using namespace std; 

typedef signed char i8;
typedef unsigned char u8;
typedef unsigned long u32;
typedef unsigned short int u16;
typedef signed short int i16;

#define HI 1
#define LO 0


void get_nextval(const char *T, int next[]) 

{ 

       // 求模式串T的next函数值并存入数组 next。

       int j = 0, k = -1; 

       next[0] = -1; 

       //while ( T[j/*+1*/] != '\0' ) 

       //{ 

       //       if (k == -1 || T[j] == T[k]) 

       //       { 

       //              ++j; ++k; 

       //              if (T[j]!=T[k]) 

       //                     next[j] = k; 

       //              else 

       //                     next[j] = next[k]; 

       //       }// if

       //       else 

       //              k = next[k]; 

       //}// while

       while ( T[j/*+1*/] != '\0' ) 

       { 

              if (k == -1 || T[j] == T[k]) 

              { 

                     ++j; ++k; 

                     if (T[j]!=T[k]) 

                            next[j] = k; 

                     else 

                            next[j] = next[k]; 

              }// if

              else 

                     k = next[k]; 

       }// while



    ////这里是我加的显示部分

    for(int  i=0;i<j;i++)

       {

            cout<<" "<<next[i];

       }

       cout<<endl;

}// get_nextval　



int main(void)
{
	char *p = "abcabd";
	int next[7] = {0};
	get_nextval(p,next);
	return 0;
}

#endif

 
