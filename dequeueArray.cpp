#include<iostream>
using namespace std;

class arrayDequeue{
    private:
    int *arr;
    int capacity;
    int r,f, count;

    public:
    arrayDequeue(int size){
        capacity = size;
        arr = new int[capacity];
        f=0;
        r=-1;
        count = 0;
    }

    bool isfull(){
        if(count == capacity)
            return 1;
        else return 0;
    }

    bool isempty(){
        if(count==0) return 1;
        else return 0;
    }

    void enqueueRear(int x){
        if(isfull()){
            cout << "Overfloww!!";
        }else{
            r = (r+1)%capacity;
            arr[r] = x;
            cout << "Inserted "<< x << " into the double ended queue."<< endl;
            count ++;
        }
    }

    void enqueueFront(int x){
        if(isfull()){
            cout << "Overfloww!!";
        }else{
            f = ((f-1)+capacity) % capacity;
            if(isempty()){
                f = 0;
                r= 0;
            }
            arr[f] = x;
            cout << "Inserted "<< x << " into the double ended queue."<< endl;
            count ++;
        }
    }

    void dequeueFront(){
        if(isempty()){
            cout << "Underfloww!!";
        }else{
            int val = arr[f];
            f = (f+1)% capacity;
            count --;
            if(count == 0){
                f = 0;
                r = -1;
            }
            cout << "Deleted " << val << " from the double ended queue." << endl;
        }
    }

    void dequeueRear(){
        if(isempty()){
            cout << "Underflow!!";
        }else{
            int val = arr[r];
            r = ((r-1)+capacity) %capacity;
            if(count == 1){
                f = 0;
                r = -1;
            }
            cout << "Deleted " << val << " from the double ended queue." << endl;
            count --;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Double ended queue is empty." << endl;
            return;
        }
        cout << "Double ended queue: ";
        int i = f;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    int size(){
        return count;
    }
};

int main(){
    arrayDequeue dq(3);
    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueRear(30);

    dq.size();
    dq.display();

    dq.dequeueFront();
    dq.display();
    dq.enqueueFront(5);
    dq.display();
    dq.dequeueRear();
    dq.display();
    return 0;
}