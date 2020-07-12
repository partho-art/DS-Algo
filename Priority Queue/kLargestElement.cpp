#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(input[i]);
    vector<int> v;
    for (int i = 0; i < k; i++) {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
    

}



int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
