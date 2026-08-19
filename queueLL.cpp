#include <iostream>
using namespace std;

int count;

class Node{
    public:
    int data;
    Node *next;
    
    Node (int val){
        data = val;
        next = nullptr;
    }
};

class LinkedQueue{
    private:
    Node *f, *r;
    public:
    LinkedQueue(){
        f = nullptr;
        r= nullptr;
        count =0;
    }

    void enqueue(int x){
        Node *newNode = new Node(x);
        if(f==nullptr){
            f=newNode;
            r= newNode;
        }else{
            r-> next = newNode;
            r = newNode;
        }
        count++;
        cout << "the value "<< x<< " is inserted into the list."<< endl;
    }

    void dequeue(){
        if(f== nullptr){
            cout << "ITs an underflow condition.." << endl;
        }
        Node *temp = f;
        int value = temp -> data;
        f = temp-> next;
        if(f==nullptr){
            r = nullptr;
        }
        delete temp ;
        count--;
        cout <<"The value "<< value<< " is deleted from the list." << endl;
    }

    int size(){
        return count;
    }

};

int main(){
    LinkedQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Size of the list: "<< count << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}