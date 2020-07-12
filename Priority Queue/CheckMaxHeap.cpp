/*
Check Max-Heap
Send Feedback
Given an array of integers, check whether it represents max-heap or not.
Return true or false.
Input Format :
Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
true if it represents max-heap and false if it is not a max-heap
Constraints :
1 <= N <= 10^5
1 <= Ai <= 10^5
*/

#include <iostream>
using namespace std;

bool checkMaxHeap(int arr[], int n){

    int parent=0;
    int Lc=(2*parent)+1;
    int Rc=(2*parent)+2;
    while(Lc<n){
        if(arr[parent]<arr[Lc]){
            return false;
        }if(Rc<n && arr[parent]<arr[Rc]){
            return false;
        }
        parent++;
        Lc=(2*parent)+1;
        Rc=(2*parent)+2;
    }
    return true;
}


int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}
