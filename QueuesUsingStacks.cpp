#include <iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;

    public:
    void enqueue(int x){ //O(1)
        s1.push(x);
    }
    int dequeue(){  //O(n)
        if(s1.empty() and s2.empty()){
            cout << "Queue is empty \n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty(){
        if(s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.empty();
    return 0;
}