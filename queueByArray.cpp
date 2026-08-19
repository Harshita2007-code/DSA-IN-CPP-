#include <iostream>
using namespace std;

int count = 0;

class ArrayQueue{
    private:
    int *arr;
    int capacity;
    int front, rear;

    public:
    ArrayQueue(int size){
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isempty(){
        if(front==-1) return true;
        else return false;        
    }

    bool isfull(){
        if(rear == capacity-1) return true;
        else return false;
    }

    void enqueue(int x){
        if(isfull()){
            cout << "Its an overflow condition!!!"<< endl;
        }
        if(isempty()) {
            front = 0;
        }
        rear += 1;
        arr[rear] = x;
        cout << "inserted " << x << " into the array." << endl;
        count ++;
    }

    void dequeue(){
        if(isempty()){
            cout << "Its an underflow condition!!" << endl;
            return;
        }
        int temp = arr[front];
        front +=1;
        count--;
        if(front > rear){
            front = -1;
            rear = -1;
        }
        cout << "deleted "<< temp << " from the array." << endl;
    }

    int size(){
        return count;
    }
};

int main(){
    ArrayQueue q(3);
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(200);
    cout << "Size of the array is " << q.size()<< endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}