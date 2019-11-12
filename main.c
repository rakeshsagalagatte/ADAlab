#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<sys/time.h>         
//#include<omp.h>                
 int basic=0;
int linearSearch(int linear[],int i,int key)
{
    basic++;
   // delay(100);
      if(linear[i]==key)
      {
       return i;
      }else if(i<10000){
          i++;
         return(linearSearch(linear,i,key));
      }else
        return -1;
}

int BinarySearch(int binary[],int high,int key,int low)
{
   basic++;
   if(high < low)
    return -1;
  else if(high>low){
   if(binary[(high+low)/2]==key)
   {
      return (high+low)/2;
   }else if(binary[(high+low)/2]<key)
   {
      return(BinarySearch(binary,high,key,((high+low)/2)+1));
   }else if(binary[(high+low)/2]>key)
   {
      return(BinarySearch(binary,((high+low)/2)-1,key,low));
   }
  }
}



int main()
{
    srand(time(NULL));
   // clock_t s,e;
   int linear[100000],binary[100000];
   binary[0] = 1;
   int i;
   for(i=1;i<10000;i++)
   {
     binary[i] =  binary[i-1] + 1;
     linear[i] = rand()%10000;
   }
   int key;
   printf( "\nEnter the key you are going to search in linear : ");
   scanf("%d",&key);
  // s= clock();
   int f = linearSearch(linear,0,key);
  // e=clock();
  // printf("The delay time is : %f\n",(e-s)/CLK_TCK );
   if(f!=-1)
   {
     printf( "\nThe key linear key found at  %dth position.\n\n",f);
   }else {
    printf("\n**********************The key is not found in linear array***********************\n\n");
   }

   printf("\nThe Basic operation in linearSearch is : %d\n\n",basic);
   
   basic =0;
  printf("\nEnter the key you are going to search in binary : ");
   scanf("%d",&key);
   f = BinarySearch(binary,9999,key,0);
   if(f!=-1)
   {
     printf("\n\nThe key binary key found at %dth position.\n\n",f);
   }else {
    printf("\n\n**********************The key is not found in binary array***********************\n\n");
   }
   printf("\nThe Basic operation in BinarySearch is : %d\n\n",basic);
   
   /*
    *   www.github.com/rakeshsagalagatte/ADAlab.git
    */

   return 0;
}
