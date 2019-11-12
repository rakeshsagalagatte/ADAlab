#include<iostream>
#include<stdlib.h>

using namespace std;

int comp(char *str1,char *str2)
{
   int i,j,k,a=0,b=0;
   char rt,st;
   for(i=0;*(str1+i)!='\0';i++);
    
   int len =i;
   for(i=0;*(str2+i)!='\0';i++);
   cout << "i = " << i << endl << "len = " << len << endl;
   if(len!=i)
     return -1;
   else{
       for(i=len-1;i>=0;i--)
       {
         if(*(str1+i)!= *(str2+i))
          {
             
            //find where it is
            for(j=i-1; *(str1+j) != *(str2+i) && j>=0;j--);
            
            if(j<-1)
              return -2;
            else{
              a+=1;
             
            while(j<len){
              for(k=0;k<len;k++)
              {
                if(k<j+1)
                {
                  rt = *(str1+j+1);
                  *(str1+j+1) = *(str1+k);
                  *(str1+k) = rt;
                
                }else if(k==j+1){
                   *(str1+k) = st;
                }
                cout << endl;
                for(b=0;*(str1+b)!='\0';b++)
                  cout  << *(str1+b);
                cout <<endl << "At " << endl  ;
              }
              j= j+1;
             } 
            }  
          }
          
          //cout << "Each round " << i;
        }
       
       }
     return a;  
 }
          
          

int main()
{
  char str1[100] = "hlole";//new char();//= (char * ) malloc(100 * sizeof(char));
   char str2[100] = "hello";//new char();// = (char * ) malloc(100 * sizeof(char));
   int i;
  /*cout << "Reading string 1 :  "; 
 
   for (i=0;*(str1+i-1)!= '\0';i++)
   {
        cin >> *(str1+i);    
     
   } 
  // gets(str1);
   
    cout << "Read string 2 : ";
   for (i=0;*(str2+i-1)!= '\0';i++)
   {
     cin >> *(str1+i); 
   }
   */
   
   int result = comp(str1,str2);
   
   cout<<endl << str1;
   
   
   cout << "\n \n Result is : " << result << endl;
   return 0;
}
   

