#include <iostream> 
using namespace std;

void tower(int n, char s, char a, char d){

    if(n==1){
        cout << "disk 1 moved from " << s<< " to " << d << endl;
        return;
    }

    tower(n-1, s, d, a);
    cout << "disk " << n << " moved from " << s << " to " << a << endl;
    tower(n-1, a, s, d);
}

int main(){
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    tower(n, 'A', 'B' ,'C');
    return 0;
}