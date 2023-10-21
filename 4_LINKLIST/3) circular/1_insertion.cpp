#include<iostream>
using namespace std;

class node
{
    int data;
    node *next;

    friend class linklist;

public:

    node(){}

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

class linklist
{
    node *first;

public:

    linklist()
    {
        first = NULL;
    }

    void insertTail(int d)
    {
        node *nn=new node(d);

        if(first==NULL)
        {
            first=nn;
            first->next=nn;
        }
        else
        {
            node *temp = first;

            while(temp->next!=first){
                temp=temp->next;
            }

            temp->next=nn;
            nn->next=first;
        }
    }

    void insertHead(int d)
    {
        node *nn=new node(d);

        if(first==NULL)
        {
            first=nn;
            first->next=nn;
        }
        else
        {
            node *temp=first;
            
            while(temp->next!=first){
                temp=temp->next;
            }
            
            nn->next=first;
            first=nn;

            temp->next=first;
        }
    }

    void deleteTail()
    {
        node *temp=first;

        while(temp->next->next != first){
            temp=temp->next;
        }

        temp->next=first;
    }

    void deleteData(int x)
    {
        node *temp=first;

        if(temp->data==x)
        {
            while(temp->next!=first)
            {
                temp=temp->next;
            }
            first=first->next;
            temp->next=first;
        }
        else
        {
            while(temp->next->data != x){
            temp=temp->next;
            }
 
           temp->next=temp->next->next;
        }        
    }    

    void display()
    {
        node *temp = first;

        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;            
        }     
        while(temp!=first);

        cout<<endl;
    }
};

int main()
{
    linklist l;
    l.insertTail(1);
    l.insertTail(2);
    l.insertTail(3);
    l.insertTail(4);
    l.deleteData(1);
    l.insertHead(1);
    l.display();


return 0;
}

