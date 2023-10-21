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


    // ----------------- delete Data ----------------//

    void deleteData(int x)
    {
        node *check = first;
        int flag=0;

        while(check!=0)
        {
            if(check->data == x){
            flag=1;
            break;
            }
            check=check->next;
        }

        if(flag)
        {
            node *temp=first;

            if(temp->data==x)
            {
                first=first->next;
                temp->next=NULL;
            }
            else
            {   
                while (temp->data!=x){
                    temp=temp->next;
                }

                temp->prev->next = temp->next;  
                temp->next->prev = temp->prev;        
            }            
        }
        else
        {
            cout<<x<<" data is not found for deletion\n";

        }
    }


    // ----------------- delete Tail ----------------//

    void deleteTail()
    {
            node *temp=first;
               
            if(temp->next == NULL)
            {
               first = NULL;
            }
            else
            {
                while(temp->next->next != NULL){
                     temp = temp->next;
                }

                temp->next->prev=NULL;
                temp->next = NULL;

                // while (temp->next!=NULL){ 
                //     temp=temp->next;
                // }

                // temp->prev->next=NULL;
                // temp->prev=NULL;                // check order 
            } 
    }


    // ----------------- delete Head ----------------//

    void deleteHead()
    {
            node *temp=first;
               
            if(temp->next == NULL)
            {
               first = NULL;
            }
            else
            {
                first->next->prev = NULL;
                first = first->next;

                // temp=temp->next;
                // temp->prev->next=NULL;
                // temp->prev=NULL;

                // first=temp;      
            } 
    }


    // ----------------- delete After ----------------//

    void deleteAfter(int x)
    {
        node *check = first;
        int flag=0;

        while(check!=0)
        {
            if(check->data == x){
                flag=1;
                break;
            }
            check=check->next;
        }

        if(flag)
        {
            node *temp=first;
               
                while (temp->data!=x){
                    temp=temp->next;
                }


                if(temp->next==NULL)   //last node
                {
                    cout<<"no node after "<<x<<" for deletion\n";
                }
                else
                {
                    temp->next->next->prev = temp;
                    temp->next = temp->next->next;
                } 
        }
        else
        {
            cout<<x<<" data is not found for delete it's after node data\n";
        }
    }


    // ----------------- delete Before ----------------//

    void deleteBefore(int x)
    {
        node *check = first;
        int flag=0;

        while(check!=0)
        {
            if(check->data == x){
                flag=1;
                break;
            }
            check=check->next;
        }

        if(flag)
        {
            node *temp=first;
            
                if(temp->data==x)    // 1st node
                {
                    cout<<"no node data Before "<<x<<" for deletion\n";
                }
                else if(temp->next->data==x)    // 2nd node match
                {
                    first=first->next;
                    
                    first->prev=NULL;
                    temp->next=NULL;
                }
                else
                {

                    while (temp->next->data!=x){
                    temp=temp->next;
                    }

                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;

                    // while(temp->data!=x)

                    // temp->prev=temp->prev->prev;
                    // temp->prev->next=temp;   // not , temp->prev->prev->next=temp; see upper line
                 } 
        }
        else
        {
            cout<<x<<" data is not found for delete it's after node data\n";
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
    l.insertTail(-1);
    l.insertTail(1);
    l.insertTail(2);
    l.insertTail(3);
  
    l.display();

    // l.deleteData(1);
    // l.deleteData(-1);
    // l.deleteData(7);
    //l.deleteAfter(1);
    l.deleteBefore(2);
    //l.deleteTail();
    //l.deleteHead();
    l.display();
    

return 0;
}