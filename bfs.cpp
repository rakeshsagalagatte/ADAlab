#include<iostream>
#include<stdlib.h>

using namespace std;
int D[100];
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



void constructGraph(int binaryMatrics[][100],int n,char str[])
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
       byty:  cout << "If (" << str[i] <<"," << str[j] << ") are connected then Enter 1 else 0 :" ;
         cin >> binaryMatrics[i][j];
         if( binaryMatrics[i][j] < 0 )
          {   cout << "The Given input is not correct REENTER AGAIN !!!! " << endl; 
             goto byty;
             }
       }
     }
   }
  } 
}

int bfsOnePart(int A[],int n)
{
   char B[100];
    int k=0,h=0;
     B[k++] = 96 + i;
   while(i<n)
   {   
     for(int j=0;j<n;j++)
     {
         if(A[i][j]==1)
            B[k++] = 96 + j;
     }
    D[h] =  B[h];
    h++;
    i = B[h] - 96; 
   }  
   return h;
}

int main()
{
     int A[100][100],n;
      char str[100];
     cout << "Enter the number of vertices in the grafh : ";
     cin >> n;
      for(int i=1;i<=n;i++)
         str[i] = 96 + i;
       constructGraph(A,n,str);
      cout << endl << endl;
       display(A,n);
     int h = bfsOnePart( A, n);
     display(D,h);
     return 0;
}
