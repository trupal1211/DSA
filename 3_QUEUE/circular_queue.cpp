#include<iostream>
using namespace std;

class queue
{
    int a[4];
    int size;
    int front;
    int rear;

public:

queue()
{
    size=4;
    front=rear=-1;
}

void push(int d)
{
    if(front==-1)
    {
        front=rear=0;
        a[rear]=d;
        cout<<a[rear]<<" is inserted\n";
    }
    else if(front == ((rear+1)%size))
    {
        cout<<d<<" is not inserted  , queue is full\n";
    }
    else
    {
        rear=(rear+1)%size;
        a[rear]=d;
        cout<< a[rear] <<" is inserted\n";
    }
}

void pop()
{
    if(front == -1)
    {
        cout<<"queue is empty\n";
    }
    else if( front == rear )      // last element
    {
        cout<<a[front]<<" is deleted\n";
        front=rear=-1;
    }
    else
    {
        cout<<a[front]<<" is deleted\n";
        front=(front+1)%size;
    }
}

};

int main()
{

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}