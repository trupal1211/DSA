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


    // ----------------- insert Head ----------------//

    void insertHead(int d)
     {
        node* nn=new node(d);

        if(first==NULL)
        {
            first=nn;
        }
        else
        {
           nn->next = first;
           first->prev = nn;

           first=nn;            
        }
    }


    // ----------------- insert After ----------------//

    void insertAfter(int x,int d)
    {
        node *check=first;
        int flag=0;

        while(check!=NULL)
        {
            if(check->data == x){
                flag=1;
                break;
            }
            check = check->next;
        }

        if(flag)
        {
            node *nn=new node(d);

            if(first == NULL)
            {
                first = nn ;
            }
            else
            {
                node* temp = first;

                while(temp->data != x){
                    temp = temp->next;
                }

                nn->next = temp->next;
                nn->prev = temp;

                temp->next = nn;
                temp->next->prev = nn;  
            }
        }
        else
        {
            cout<<x<<" data is not found for insert "<<d<<" after that\n";
        }
    }


    // ----------------- insert Before ----------------//

    void insertBefore(int x,int d)
    {
        node *check=first;
        int flag=0;

        while(check!=NULL)
        {
            if(check->data == x){
                flag=1;
                break;
            }
            check = check->next;
        }

        if(flag)
        {
            node *nn=new node(d);

            if(first == NULL)
            {
                first = nn ;
            }
            else
            {
                
                node* temp = first;
                
                if(temp->next == x)
                {
                    nn->next = first;
                    first->prev=nn;

                    first = nn;
                }
                else
                {

                    while(temp->data != x){   // also use temp->next->data
                        temp = temp->next;     
                    }

                    nn->next = temp;
                    nn->prev = temp->prev;

                    temp->prev = nn;  
                    temp->prev->next = nn;
                }
            }
        }
        else
        {
            cout<<x<<" data is not found for insert "<<d<<" Before that\n";
        }
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
    linklist l;
    l.insertTail(1);
    l.insertTail(2);
    l.insertAfter(2,3);
    l.insertBefore(1,0);
    l.display();
    

return 0;
}