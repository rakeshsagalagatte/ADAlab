#include<iostream>
#include<stdlib.h>

using namespace std;

/*int insertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = A[i];
        int j = i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j]
            j = j-1;
        }
        A[j+1] = key;
    }     
    return A;
}
*/

void display(int binaryMatrics[][100],int n)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout << binaryMatrics[i][j] << " ";
      if(j==n)
        cout << endl;
    }
  }
}


int reffrence(int reff[],int n,int j)
{
   for(int i=n;i>=1&&i>j;i++)
   {
      if(reff[i]==0)
         return i;
   }
   return 0;
}

void TopologicalOrder(int Graph[][100],int n,int stack[100])
{
 int reff[100];
   for(int i=1;i<=n;i++)
   {
      reff[i] =0;
   }
   int p=1;
   for(int i=1,j=n;i<=n;i++)
   {
      if(Graph[i][j]==1)
      {
        reff[j] =1;
        
      } 
      if(reff[j]==0 && i==n )
      {
        stack[p++] = j;
        reff[j]=1;
        for( int y=1;y<=n;y++)
             Graph[j][y] = 0;
      }  
      if(i==n&&j>0){
       if(reffrence(reff,n,j))
       {
           j = reffrence(reff,n,j);
           i=0;
       }else{
        j--;
        i=0;
        }
      } else if(j==1 && p-1 < n)
     {
         j = reffrence(reff,n,0);
         i=0;
     } 
      
   }
  
}

 void constructGraph(int Graph[][100],int n,char str[])
{
int a=0;
  while(a <= (n*n))
  { 
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=n;j++)
     {   a++;
        if(a==n*n)
          return;
       if(i!=j){
     th:    cout << "If " << str[i] <<" connected   to  " << str[j] << " then Enter 1 else 0 :  " ;
         cin >> Graph[i][j];
         if(Graph[i][j] > 1 ||  Graph[i][j] < 0)
            {
              cout << "In valid entry !!!!!  :( \n Enter Again .. \n ";
              goto th;
            }
       }
     }
   }
  } 
}

int main()
{
   cout << "Enter the number of vertices in the graph : ";
    int n,Graph[100][100],stack[100];
    char str[26];
   cin >> n;
  for(int i=1;i<=n;i++)
      str[i] = 96 + i;
   cout << "Construct the Directed Acyclic Graph " << endl ;
   constructGraph( Graph,n,str);
   cout << "Before  : \n";
   display(Graph,n);
   TopologicalOrder(Graph, n,stack);
   cout << "After : \n";
   display(Graph,n);
   cout << "The Tropological order of the Graph is : ";
   for(int i=1;i<=n;i++)
      cout << stack[i] << "    ";
   cout << endl;
   return 0;   
}
