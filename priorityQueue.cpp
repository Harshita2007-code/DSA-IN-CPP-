#include <iostream>
using namespace std;

struct element{
    int data;
    int priority;
};
element val;
class priorityQueue{
    private:
    element *arr;
    int capacity;
    int count;
    public:
    priorityQueue(int size){
        capacity = size;
        arr = new element[capacity];
        count = 0;
    }

    bool isempty(){
        if(count == 0) return 1;
        else return 0;
    }

    bool isfull(){
        if(count == capacity) return 1;
        else return 0;
    }

    void enqueue(int val, int p){
        if(isfull()){
            cout << "Overfloww condition!!"<< endl;
        }
        
        else {
            int i = count-1;
            while(i>=0 && arr[i].priority>p){
                arr[i+1] = arr[i];
                i--; 
            }
            arr[i+1].data = val;
            arr[i+1].priority = p;
            cout << "The value inserted is " << val << endl;
            count ++;
        }  
    }

    void dequeue(){
        if(isempty()){
            cout << "Underfloww condition!!";
        }else{
            int i= count -1;
            int value = arr[i].data;
            i -= 1;
            cout << "The value deleted is "<< value<< endl;
            count--;
        }
    }

    int peek(){
        return arr[count-1].data;
    }

    int size(){
        return count;
    }
};

int main(){
    priorityQueue pq(3);
    pq.enqueue(10,9);
    pq.enqueue(20,3);
    pq.enqueue(90,5);
    cout << "The element at the top is " << pq.peek()<< endl;
    cout << "Size : "<< pq.size() << endl;
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    
    return 0;
}