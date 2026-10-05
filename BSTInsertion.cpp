#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node *insert(Node*root, int value){
    if(root== nullptr){
        return new Node(value);
    }
    if(root-> data > value){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}

void preOrder(Node *root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


int main(){
    Node *root = nullptr;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "ENter values: "<< endl;
    for(int i=1; i<=n; i++){
        cin >> x;
        root = insert(root, x);
    }

    inOrder(root);
    return 0;

}