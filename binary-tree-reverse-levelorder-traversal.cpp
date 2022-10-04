#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
        
        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

node *buildTree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1)
    return NULL;
    
    cout<<"Enter the value to the left of "<<data<<": ";
    root->left=buildTree(root->left);
    cout<<"Enter the value to the right of "<<data<<": ";
    root->right=buildTree(root->right);
    return root;
}

void reverseLevelOrderTraversal(node* root)
{
    if (root == NULL) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    list<node*> queue;
    queue.push_back(root);
    // create a stack to reverse level order nodes
    stack<int> stack;
 
    // pointer to store the current node
    node* curr = NULL;
 
    // loop till queue is empty
    while (queue.size())
    {
        // process each node in the queue and enqueue their children
        curr = queue.front();
        queue.pop_front();
 
        // push the current node into the stack
        stack.push(curr->data);
         
        // it is important to process the right node before the left node
        if (curr->right) {
            queue.push_back(curr->right);
        }
 
        if (curr->left) {
            queue.push_back(curr->left);
        }
    }
 
    // pop all nodes from the stack and print them
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
}
int main()
{
    node* root=NULL;
    root = buildTree(root);
    reverseLevelOrderTraversal(root);
    return 0;
}