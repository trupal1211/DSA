#include <iostream>
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
    data = d;
    next = NULL;
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

  // ----------------- insert -----------------//

  void insert(int d)
  {
    node *nn = new node(d);

    if (first == NULL)
    {
      first = nn;
    }
    else
    {
      node *temp = first;

      while (temp->next != NULL){
        temp = temp->next;
      }

      temp->next = nn;
    }
  }



  // ----------------- delete Data -----------------//

  void deleteData(int x)
  {
    node *check = first;
    int flag=0;

    while(check != NULL)
    {
      if(check->data == x )
        flag = 1;
      
      check = check->next;
    }

    if(flag)
    {
        node* temp = first;

        if(temp->data == x)
        {
            temp = temp->next;
            first = temp;
        }
        else
        {
            while(temp->next->data != x ) {
                temp = temp->next;
            }

            temp->next=temp->next->next; 
        }
    }
    else
    {
      cout<<x<<" data is not found for delete \n";
    }
  }


  // ----------------- delete Tail -----------------//

  void deleteTail()
  {
    node *temp = first;

    if( (temp == NULL) || (temp->next == NULL) )   // order is important of condition
    {
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL){
             temp = temp->next;
        }

        temp->next = NULL;
    }
  }


  // ----------------- delete Head ----------------- //

  void deleteHead()
  {
    node *temp = first;

    if( (temp == NULL) || (temp->next == NULL) )   // order is important of condition
    {                                             // empty , only one node
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL){
             temp = temp->next;
        }

        temp = temp->next;
        first = temp;
    }    
  }


  // ----------------- delete After -----------------//

  void deleteAfter(int x)
  {
    node *check = first;
    int flag=0;

    while(check != NULL)
    {
      if(check->data == x )
        flag = 1;
      
      check = check->next;
    }

    if(flag)
    {
        node* temp = first;

        while (temp->data != x){
            temp = temp->next;
        }

        if(temp->next == NULL)
          cout<<"No data after "<<x<<" for deletion\n";
        else
          temp->next = temp->next->next; 
    }
    else
    {
      cout<<x<<" data is not found for delete their after data \n";
    }
  }



  // ----------------- delete Before -----------------//

  void deleteBefore(int x)
  {
     node *check = first;
    int flag=0;

    while(check != NULL)
    {
      if(check->data == x )
        flag = 1;
      
      check = check->next;
    }

    if(flag)
    {
        node* temp = first;

        if(temp->data==x || temp->next->data == x )
        {
            cout<<"no data before "<<x<<" to deletion\n";
        }
        else
        {
            while (temp->next->next->data != x){
                temp = temp->next;
            }

            temp->next = temp->next->next;
        }
    }
    else
    {
      cout<<x<<" data is not found for delete \n";
    }

  }



  // ----------------- display -----------------//

  void display()
  {
    if(first == NULL)
    {
        cout<<"linklist is empty";
    }
    else
    {
        node *temp = first;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    cout<<endl;
  }


  

};


int main()
{
    linklist l;
    // l.insert(1);
    // l.insert(2);
    // l.insert(3);
    // l.insert(4);
    // l.insert(5);
    // l.display();

    // l.deleteData(-1);
    // l.deleteData(5);
    l.deleteTail();
    // l.display();
    // l.deleteHead();
    // l.deleteAfter(5);
    // l.deleteBefore(1);

    l.display();

}