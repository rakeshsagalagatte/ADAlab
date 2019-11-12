#include<iostream>
#include <stdlib.h>

using namespace std;

int binaryMatrics[100][100];

  void constructGraph( int n,char str[])
 {
  int a=0;
  while(a <= (n*n))
  { 
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=n;j++)
     {   
           a++;
        if(a==n*n)
          return;
        if(i!=j)
        {
       Thg :  cout << "The distance from node " << str[i] <<" to node " << str[j] << " is : " ;
         cin >> binaryMatrics[i][j];
         if(binaryMatrics[i][j] < -1)
         {
            cout << "You are entered invalid Distance Please make sure that your distance must and should start from -1 to positive values "<< endl;
            goto Thg;
          }
        }
     }
   }
  } 
}



void display( int n)
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

void floyds( int n)
{
  int bore[100][100],a;
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      { 
        a=0;
       if(k!=i&&k!=j&&i!=j)
       {
        if((binaryMatrics[i][k]==-1||binaryMatrics[k][j]==-1)&& binaryMatrics[i][j]!=-1)
         {
           a=1;
           bore[i][j] = binaryMatrics[i][j]; 
         }
        else if((binaryMatrics[i][j]==-1)&& (binaryMatrics[i][k]!=-1&&binaryMatrics[k][j]!=-1))
         {
          a=1;
          bore[i][j] = binaryMatrics[i][k] + binaryMatrics[k][j]; 
         }
        else if(binaryMatrics[i][k]!=-1&&binaryMatrics[k][j]!=-1 && binaryMatrics[i][j]!=-1)
        {   a=1;
            if (binaryMatrics[i][j] < binaryMatrics[i][k] + binaryMatrics[k][j])
               bore[i][j] = binaryMatrics[i][j];
            else if (binaryMatrics[i][j] >= binaryMatrics[i][k] + binaryMatrics[k][j])
               bore[i][j] = binaryMatrics[i][k] + binaryMatrics[k][j]; 
         }
        }
        
            if(a==0) 
              bore[i][j] = binaryMatrics[i][j]; 
      }
    }
     for(int h=1;h<=n;h++)
     {
       for(int r = 1;r<=n;r++)
         binaryMatrics[h][r] = bore[h][r];
     }
   }
}

int main()
{
   int n;
   char str[100];
   cout << "Enter the number of vertices in the graph : ";
   cin >> n;
   for(int i=1;i<=n;i++)
      str[i] = 96 + i;
   cout << endl << "Construct the digraph, if incase any node is not directly or indirectly connected to any node gave values in '-1' "<< endl ;  
   constructGraph(n,str);
   cout << endl << endl << "Before algorithm ." << endl; 
   display(n);
   floyds(n);
   cout << endl << endl << "After algorithm ." << endl; 
   display(n);
   
   cout << endl;
   return 0;
}


