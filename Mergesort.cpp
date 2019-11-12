#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <math.h>


using namespace std;
//int A[100],B[100],C[100];
void merge(int A[],int);

void Display(int A[],int n);
void  mergesort(int B[],int p,int C[],int q,int A[])
{
    int i=0,j=0,k=0;
    while(i < p && j< q)
    {
        if(B[i] <= C[j])
        {
          A[k] = B[i];
          i=i+1;
        }else
        {
          A[k] = C[j];
          j = j+1;
        }
         k=k+1;
    }

    if(i==p)
    {
      for(;j<q;j++,k++)
         A[k] = C[j];
    }else{
       for(;i<q;i++,k++)
         A[k] = B[i];
    }

}

void merge(int A[],int n)
{
    int B[100],C[100];
  int i,j,k;
  if(n>1)
  {
     for(i=0,j=0,k=0;k<n;k++)
     {
        if(k<floorl(n/2))
        {
          B[i] = A[k];
          i++;
        }else{
          C[j] = A[k];
          j++;
        }
     }
  merge(B,i);
  merge(C,j);
    mergesort(B,i,C,j,A);
  
  }

}

void Display(int A[],int n)
{
       for(int i=0;i<n;i++)
          cout << A[i] << "  ";
   cout << endl;
}


int main()
{
  int n,A[100];
  cout << "Enter the size of the array : ";
  cin >> n;
  srand(time(NULL));

  for(int i =0;i<n;i++)
     A[i] = rand()%1000;
  cout << " Array elements are : ";
  Display(A,n);
  merge(A,n);
  cout << " Sorted elements are : ";
  Display(A,n);
  return 0;
}

