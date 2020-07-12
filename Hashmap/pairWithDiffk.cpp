/*
Pairs with difference K

You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
0 <= n <= 10^4
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4
*/

#include<iostream>
#include<map>
using namespace std;

void printPairs(int *input, int n, int k) {
	
  
map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[input[i]]++;
    }
    
    if(k==0)
    {
       
        for(int i=0;i<n;i++)
        {
            if(m[input[i]]>1)
            {
                int k=m[input[i]];
                int l=(k*(k-1))/2;
                for(int m=0;m<l;m++)
                cout<<input[i]<<" "<<input[i]<<endl;
                m[input[i]]=0;
            }
            
        }
        return;
    }
    
    
    
    for(int i=0;i<n;i++)
    {
        
        int a=input[i];
        
       
            if(m.count(a-k)>0)
        {
               
                for(int i=0;i<m[a-k]*m[a];i++)
               cout<<a-k<<" "<<a<<endl;
     
                
          }
        
         if(m.count(a+k)>0)
        {
             for(int i=0;i<m[a+k]*m[a];i++)
                cout<<a<<" "<<a+k<<endl;    
        }   
        m[a]=0;
            
        
    }
    return ;
}







int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
