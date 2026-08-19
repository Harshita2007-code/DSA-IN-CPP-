#include <iostream>
using namespace std;

class circularqueue{
    private:
    int *arr;
    int capacity;
    int f,r,count;
    
    public:
    circularqueue(int size){
        capacity = size;
        arr = new int[capacity];
        f=0;
        r=-1;
        count =0;
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

    void enqueue(int x){
        if(isfull()){
            cout << "This is an overflow condition!!";
            return;
        }else{
            r=(r+1)% capacity;
            arr[r] = x;
            cout << "Inserted "<< x << " in the circular queue."<< endl;
            count ++; 
        }
    }

    void dequeue(){
        if(isempty()){
            cout << "This is an underflow condition!!";
        }else{
            int temp = arr[f];
            f = (f+1) % capacity;
            if(f>r){
                f =0;
                r= -1;
            }
            cout << "Deleted "<< temp << " from the circular queue."<< endl;
            count--;
        }
    }

    int size(){
        return count;
    }
};

int main(){
    circularqueue cq(3);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Size : "<< cq.size() << endl;
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    return 0;
}