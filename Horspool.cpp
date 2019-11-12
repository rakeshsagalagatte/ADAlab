#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int Table[150],a=1;

void shiftTable(char Pattern[],int m)
{
   for(int i=2;i<=m;i++)
   {
      if(Table[Pattern[m-i]]==0)
      {
        Table[Pattern[m-i]]=i-1;
      }
   }
   for(int i=0;i<150;i++)
   {
     if(Table[i]==0)
     {
      Table[i]=m;
     }
   }
}
int Horspool(char Text[],char Pattern[],int n,int m)
{ 
   shiftTable(Pattern,m);
   int i = m-1;
  while(i<=n-1){
      int r=0; 
      while( r<=m-1&&Pattern[m-1-r]==Text[i-r])
            r= r+1;
      if(r==m)
         return i+2-m;
      else
         i=i+ Table[Text[i]];
          a++;     
      }       
   
  return -1;            
}

int main()
{
   char Text[100],Pattern[100];
   int n,m;
   for(int i=0;i<150;i++)
      Table[i] = 0;
   cout << endl <<"Wright Something as Text (And remmember give space as Underscore don't give space) : ";
   cin >> Text;
   cout << endl  <<"Wright a text which you wanna search in the above entered text go head  .(And remmember give space as Underscore don't give space) : ";
   cin >> Pattern;
   m = strlen(Pattern);
   n= strlen(Text);
   if(Horspool(Text,Pattern,n,m)==-1)
   {
      cout << endl << "The above pattern does not found."<<endl;
   }else{
   cout <<endl << "The pattern found at " <<Horspool(Text,Pattern,n,m) << "th position in the above entered text message ." <<endl;
   
   }
   cout <<"Number of comparision is " << a << endl;
}
