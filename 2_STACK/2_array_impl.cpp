#include <iostream>
using namespace std;

class stack
{
    int a[15];
    int front;
    int max_size;

public:
    stack()
    {
        front = -1;
        int max_size = 2;
    }

    void push(int d)
    {
        ++front;
        a[front] = d;
        cout << a[front] << " is inserted\n";
    }

    void pop()
    {
        cout << a[front] << " is retrieve\n";
        front--;
    }

    int empty()
    {
        return front == -1 ? 1 : 0;
    }

    int top()
    {
        return a[front];
    }

    int full()
    {
        return front >= max_size - 1 ? 1 : 0;
    }
};

int main()
{
    stack s;

    s.push(4);
    s.push(8);

    cout << s.full() << endl;

    s.pop();

    cout << s.empty() << endl;
    cout << s.top() << endl;

    s.pop();

    cout << s.empty() << endl;

    return 0;
}