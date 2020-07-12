/*
Palindrome Pair
Send Feedback
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
The function should return either true or false. You don't need to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The second line of the test case will contain 'n' number of words each separated by a single space.
Output Format :
Print either true or false
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1 :
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 1 :
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/


#include <bits/stdc++.h>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
			root->childCount++;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	

 bool isPalindrome(string str) { 
        
        int i = 0, len;
        len = str.length() - 1;
        while (i < len) { 
            if (str[i] != str[len]) 
                return false; 
            i++;
            len--; 
        }     
        return true; 
    }     
    
	bool findIfPalindromePair(vector<string> arr) {
		
        string str;
        string str1;
        string str2;
        for(int i = 0; i < arr.size(); i++) {
            insertWord(arr[i]);
        }
        int f = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i; j < arr.size(); j++) {
                
                str = arr[i];
                bool ans = isPalindrome(str);
                if(ans == true) {
                    f = 1;
                    return true;
                }                
                
                str1 = arr[i] + arr[j];
                bool ans1 = isPalindrome(str1);
                if(ans1 == true) {
                    f = 1;
                    return true;
                }
                
                str2 = arr[j] + arr[i];
                bool ans2 = isPalindrome(str2);
                   if(ans2 == true) {
                    f = 1;
                    return true;
                }
            }
        }
        if(f == 0) {
            return false;
        }
	}
};




int main()
{
	Trie t;
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> words[i];
	}
	bool ans = t.isPalindromePair(words);

	if (ans)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}