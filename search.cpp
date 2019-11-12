#include<iostream>
#include<stdlib.h>
#include<time.h>
//#include<sys/time.h> 
//    #include<omp.h>                
using namespace std;                              

 int basic=0;
int linearSearch(int linear[],int i,int key)
{
    basic++;
   // delay(100);
      if(i<0)
      {
       return -1;
      }else if(linear[i]==key){
         return i;
      }else {
      i--;
        return(linearSearch(linear,i,key));
        }
}

int BinarySearch(int binary[],int high,int key,int low)
{
   basic++;
    int a;
    if(high < low)
     return -1; 
    else if(high >low){
    a = (high+low)/2;
   if(binary[a]>key)
   {
      return (BinarySearch(binary,a-1,key,low));
   }else if(binary[a]<key)
   {
      return (BinarySearch(binary,high,key,a+1));
   }else if(binary[a]==key)
   {
      return a;
   }
  }
}



int main()
{
    srand(time(NULL));
   // clock_t s,e;
   int linear[100000],binary[100000],N;
   binary[0] = 1;
   cout << "Enter the size of the array : " << endl;
    cin >> N;
   for(int i=1;i<N;i++)
   {
     binary[i] =  binary[i-1] + 1;
     linear[i] = rand()%N;
   }
   int key;
   cout<< endl<< "Enter the key you are going to search in linear : ";
   cin >> key;
   // s= clock();
   int f = linearSearch(linear,N-1,key);
   // e=clock();
  // printf("The delay time is : %f\n",(e-s)/CLK_TCK );
   
   if(f!=-1)
   {
     cout <<endl << "The key linear key found at " << f << "th position." << endl << endl;
   }else {
    cout << endl << "**********************The key is not found in linear array***********************" << endl;
   }
   
   cout << "The number of Basic operation of linearSearch is : " << basic << endl << endl ;
   
   basic =0;
   cout << endl << "Enter the key you are going to search in binary : ";
   cin >> key;
   f = BinarySearch(binary,N-1,key,0);
  
   if(f!=-1)
   {
     cout <<endl << "The key found at " << f << "th position." << endl << endl;
   }else {
    cout << endl << "**********************The key is not found in binary array***********************" << endl;
   }
   cout << "The number of Basic operation of BinarySearch is : " << basic << endl << endl ;
   return 0;
   /*
    *   www.github.com/rakeshsagalagatte/ADALAB.git
    */
}
