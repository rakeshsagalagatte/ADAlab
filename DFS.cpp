#include <iostream>
#include<stdlib.h>

using namespace std;

int count,countArray[100];
char stack[100];

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
         cout << "If (" << str[i] <<"," << str[j] << ") are connected then Enter 1 else 0 :" ;
         cin >> binaryMatrics[i][j];
       }
     }
   }
  } 
}

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


void DFS(int binaryMatrics[][100],int n,char str[])
{ int i=1,a;
          for(int j=1;j<=n;j++)
          {      
             if(i>n){
                 for(int h=1;h<=n;h++)
                 {
                    if(countArray[h]==0)
                    {
                      count += 1;
                      countArray[h] = count;
                      stack[count] = str[h];
                    }
                 }
                return;
            }else{
                       a=0;
                       if(binaryMatrics[i][j]==1&&countArray[i]==0)
                       { 
                         a=1;
                         binaryMatrics[i][j] =2;
                         count = count +1;
                         stack[count] = str[i];
                         countArray[i] = count;
                         i=j;
                         j=0;     
                       }else if(binaryMatrics[i][j]==1&&countArray[i]!=0)
                        {   a=1;
                            binaryMatrics[i][j] =2;
                            i=j;
                            j=0;
                        }else if(a==0&&j==n)
                        {
                             i++;
                             j=0;
                        }  
                  }             
    }
}

int main()
{
   int binaryMatrics[100][100],n;
   char str[100];
   cout << "Enter the number of vertices which is producing non-trivial graph : ";
   cin >> n;
   for(int i=1;i<=n;i++)
      str[i] = 96 + i;
   constructGraph(binaryMatrics,n,str);
   cout << endl << endl;
   display(binaryMatrics,n);
   DFS(binaryMatrics,n,str);
   cout << endl << "DFS traversal for above given graph is : " << endl ;
   for(int i=1;i<=n;i++)
   {
     cout << i << " --> "  << stack[i] << endl;
   }
   cout << endl;
   return 0;
}
