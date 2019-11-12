#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int S,t=0;
static int cnt;
//void Nqueens(int chessBoard[][100],int,int);
//int spacePos(int chessBoard[][100],int,int);
void Display(int chessBoard[][100],int);

int spacePos(int chessBoard[][100] , int i , int j)
{
  if(i==1)
    return 1;
    
  int a=i-1,b=j-1;
   while(a>0 && b>0)
    {
      if(chessBoard[a--][b--]==1)
         return 0;
    }  
    
    a=i-1;
    b=j+1;
    
    while(a>0&&b<=S)
    {
      if(chessBoard[a--][b++]==1)
         return 0;
    }
    
    for (a=1;a<i;a++)
    {
      if(chessBoard[a][j]==1)
        return 0;
    }
    
    return 1;
}

void Nqueens(int chessBoard[][100],int N,int n)
{
  if(n==N+1)
  {
     cnt++;
     return ;
  }
  
  for (int i=1;i<=N;i++)
  {
     
         
     if(spacePos(chessBoard,n,i))
     {
        
        chessBoard[n][i] = 1;
        Nqueens(chessBoard,N,n+1);
        if(n==N)
         Display(chessBoard,N);
        
     }
     chessBoard[n][i] = 0;
  }
}

void Display(int chessBoard[][100] , int N)
{ t++;
  cout << endl << endl << "Solution number is  : " << t << endl;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
         cout << chessBoard[i][j] << " " ;
         if(j==N)
           cout << endl;
    }
  }
}

int main()
{
   int N;
   cout << "Enter the number of rows for square matrix : " ;
   cin >> N;
   S = N;
   int chessBoard[100][100];
   Nqueens(chessBoard,N,1);
   return 0;
   
}

