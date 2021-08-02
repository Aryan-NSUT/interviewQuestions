#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left) , height(root->right)) + 1;
}

int calDiameter(Node *root,int *height){
    if(root==NULL){
        *height = 0;
        return 0;
    }
    int lh = 0,rh= 0;
    int lDiameter = calDiameter(root->left,&lh);
    int rDiameter = calDiameter(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;
    return max(currDiameter,max(lDiameter,rDiameter));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<calDiameter(root,&height)<<endl;
}