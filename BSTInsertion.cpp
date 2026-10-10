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

bool search(Node *root, int num){
    if(root == nullptr) return false;
    if(root->data == num){
        return true;
    }else if(num < root->data){
        return search(root->left, num);
    }else{
        return search(root->right, num);
    }
}
int mini=INT_MAX, maxi=INT_MIN;

int minMax(Node *root){
    if(!root){
        return 0;
    }
    
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

    cout << "Inorder:" << endl;
    inOrder(root);

    int num;
    cout << "Enter number to search: "<< endl;
    cin>>num;
    bool a = search(root,num);
    if(a) cout<<"TRUE";
    else cout << "FALSE";
    return 0;

}