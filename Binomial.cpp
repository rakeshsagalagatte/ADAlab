#include<iostream>
#include<stdlib.h>

using namespace std;

int c[100][100];

int min(int i,int k)
{
  if(i<k)
    return i;
  else
    return k;  
}

void binomial(int n,int k)
{ 
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=min(i,k);j++)
    {
      if(j==0||j==i)
        c[i][j] = 1;
      else 
        c[i][j] = c[i-1][j-1] + c[i-1][j];  
    }
  }
}

 void Display(int n,int k)
 {
    for(int i=0;i<=n;i++)
    {
    for(int j=0;j<=min(i,k);j++)
    {
      cout << c[i][j] << " ";
        if(j==min(i,k))
           cout << endl;
    }
  }
 }

int main()
{
   cout << "Enter the n value : ";
   int n,k;
   cin >> n;
   th : cout << "Enter the k value : ";
   cin >> k;
   if(k>n)
    {
      cout << "The value of K must and should lessthan or equal to value of N .." << endl;
      goto th;
    }
   binomial(n,k);
   Display(n,k);
   return 0;
}
