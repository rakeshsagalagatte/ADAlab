#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

void heapsort(int array[],int n)
{
   int k,v,j; 
   int heap;  
   for(int i=floorf(n/2);i>=1;i--)
   {
      k=i;
      v=array[i];
      heap = 0;
     while(!heap&&2*k<=n)
     {
        j=2*k;
        if(j<n)
        {
         if(array[j]<array[j+1])
           j=j+1;
        }
        
        if(v>=array[j])
          heap = 1;
        else{
           array[k]=array[j];
           k=j;
        }  
     }
     array[k]=v;
   }
}

void heapify(int array[],int n,int heapfied[],int desend[],int i)
{
  
  if(1<=n){
   
   heapfied[n]= array[1];
   desend[i] = array[1];
   array[1] = array[n];
   heapsort(array,n);
   
   return(heapify(array,n-1,heapfied,desend,i+1));
  }
  return;
}

int main(){

int array[10000],heapfied[10000],desending[100000];
int n;
srand(time(NULL));
cout << endl << "Enter the size of an array : ";
cin >> n;
for(int i=1;i<=n;i++)
{
  array[i]=rand()%10000;
}
cout << endl << "before sorting : ";
for(int i=1;i<=n;i++)
   cout<< array[i] << " ";
   cout <<endl << "heap : ";
   heapsort(array,n);
   for(int i=1;i<=n;i++)
   cout<< array[i] << " ";
heapify(array,n,heapfied,desending,0);
   for(int i=1;i<=n;i++)
   cout<< array[i] << " ";

cout << endl << "After sorting " << endl << "ascending order : ";


for(int i=1;i<=n;i++)
   cout<< heapfied[i] << " ";
   cout <<endl << " Desending order ";  
   for(int i=0;i<n;i++)
   cout<< desending[i] << " ";
   cout << endl;
   return 0;
}
