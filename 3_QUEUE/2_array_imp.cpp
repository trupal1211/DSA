#include<iostream>
using namespace std;

class queue
{
    int a[10];
    int front;
    int rear;
    int max_size;

public:

void push(int d)
{
    if(front==-1)
      {front=0;}
    
    rear++;
    a[rear]=d;
    cout<<a[rear]<<" is inserted\n";
}

void pop()
{
    cout<<a[front]<<" is deleted\n";
    front++;
}

int empty()
{
    if(front==-1 || front>rear)
    {
        cout<<"queue is empty\n";
        return 1;
    }
    else 
       return 0;
}

int isfull()
{
    if(rear>=max_size-1)
    {
        cout<<"queue is full\n";
        return 1;
    }
    else
        return 0;
}


};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.isfull();

return 0;
}