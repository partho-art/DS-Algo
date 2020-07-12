/*
Extract Unique characters
Send Feedback
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/
#include<iostream>
#include<unordered_map>
using namespace std;


char* uniqueChar(char *str){
    
    unordered_map<char,bool> m;
    char* out=new char[1000000];
    int i=0;
    int k=0;
    while(str[i]!='\0')
    {
        if(m.count(str[i])==0)
        {
            m[str[i]]=true;
            out[k]=str[i];
            k++;
        }
      i++;  
    }
    out[k]='\0';
    return out;
}




int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
