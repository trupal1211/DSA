#include<iostream>
using namespace std;

class node
{
    int data;
    node *prev;
    node *next;

    friend class linklist;

public:

    node(){}

    node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};

class linklist
{
    node *first;

public:

    linklist()
    {
        first=NULL;
    }


    // ----------------- insert Tail ----------------//

    void insertTail(int d)
    {
        node* nn=new node(d);

        if(first==NULL)
        {
            first=nn;
        }
        else
        {
            node* temp=first;

            while (temp->next!=NULL){
                temp=temp->next;
            }

            nn->prev=temp;
            temp->next=nn;            
        }
    }


     // ----------------- append -----------------//

    void append(linklist *l1,linklist *l2)
    {
        first = l1->first;
        node *temp = first;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = l2->first;
        l2->first->prev = temp ;

        cout<<temp->data<<" "<<temp->next->data<<" "<<temp->next->prev->data<<"\n";  //cross verfication
    }

    




    // ----------------- display ----------------//

    void display()
    {
        node *temp = first;

        if(temp==NULL)
        {
            cout<<"linklist is empty";
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        cout<<endl;
    }
};


int main()
{
    linklist l1,l2,l3;
    l1.insertTail(1);
    l1.insertTail(2);
    l2.insertTail(3);
    l2.insertTail(4);
    l3.append(&l1,&l2);
    l3.display();   
    

return 0;
}