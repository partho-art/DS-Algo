#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root)

{
   if(root==NULL)
       return root;
    
    TreeNode<int>* maxsum=root;
    int n=root->children.size();
    int s=0;
        for(int i =0;i<n;i++)
        { 
            s+=root->children[i]->data;
        }
      int x=s+root->data;
      
     for(int i=0;i<n;i++)
         
        { 
         TreeNode<int>* subnode=maxSumNode(root->children[i]);
         int m=0;
          for(int i=0;i<subnode->children.size();i++)
        { 
            m+=subnode->children[i]->data;
        }
         int z=m+subnode->data;
         
         if(z>x)
          {
              maxsum=subnode;
          }
 
        }
    return maxsum;
    
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


