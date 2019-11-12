#include<iostream>
#include<stdlib.h>

using namespace std;

int binaryMatrics[100][100];
void Warshall(int n)
{
   int nowBinaryArray[100][100];
   
   for(int k=1;k<=n;k++)
   {
     for(int i=1;i<=n;i++)
     {
       for(int j=1;j<=n;j++)
       {
          nowBinaryArray[i][j] = binaryMatrics[i][j] || (binaryMatrics[i][k] && binaryMatrics[k][j]);
       }
     }
     for(int h=1;h<=n;h++)
     {
       for(int r = 1;r<=n;r++)
       {
         binaryMatrics[h][r] = nowBinaryArray[h][r]; 
       }
     }
   }
   
   
}

void constructGraph(int n,char str[])
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
         cout << "If (" << str[i] <<"," << str[j] << ") are connected then Enter 1 else 0 :" ;
         cin >> binaryMatrics[i][j];
       }
     }
   }
  } 
}

void display(int n)
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

int main()
{
   char str[100];
   int n;
   cout << "Enter the number of vertices which is producing non-trivial graph : ";
   cin >> n;
   for(int i=1;i<=n;i++)
      str[i] = 96 + i;
   constructGraph(n,str);
   Warshall(n);
   
   cout << endl << endl<< "Displaying Warshall algorithm result : " << endl;
   display(n);
   return 0;
}
