/*
Code : Maximum Frequency Number

You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
0 <= N <= 10^8
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/

#include<iostream>
using namespace std;
#include<unordered_map>

int highestFrequency(int *input, int n) {
    int maxFrequency = -1;
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
		map[input[i]]++;
        maxFrequency = max(maxFrequency, map[input[i]]);
    }
    for(int i = 0; i < n; i++) {
        if(maxFrequency == map[input[i]])
            return input[i];
    }
    
}


int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}


