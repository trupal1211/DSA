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

  // ----------------- insert tail-----------------//

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

  // ----------------- insert head -----------------//

  void insertHead(int d)
  {
    node *nn = new node(d);

    if (first == NULL)
    {
      first = nn;
    }
    else
    {
      nn->next = first;
      first = nn;
    }
  }


   // ----------------- insert After -----------------//

  void insertAfter(int x, int d)
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
      node *nn = new node(d);

      node *temp = first;

      while (temp->data != x){
      temp = temp->next;
      }

      nn->next = temp->next;
      temp->next = nn;
    }
    else{
      cout<<x<<" data is not found for insert " <<d<<"  after that node\n";
    }
  }


   // ----------------- insert Before -----------------//

  void insertBefore(int x, int d)
  {
    node *check = first;
    int flag=0;

    while(check != NULL)
    {
      if(check->data == x ){
        flag = 1;
        break;
      }
      check = check->next;
    }

    if(flag)
    {
      node *nn = new node(d);

      node *temp = first;

      if(temp->data == x )
      {
        nn->next = temp;
        first = nn;
      }
      else
      {
        while (temp->next->data != x){
        temp = temp->next;
        }

        nn->next = temp->next;
        temp->next = nn;   
      }
    }
    else
    {
      cout<<x<<" data is not found for insert " <<d<<" before that node\n";
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
    l.insert(1);
    l.insert(2);
    l.insertHead(0);
    l.insertHead(-1);
    l.display();

    l.insertAfter(2,3);
    l.insertBefore(-1,-2);
    l.display();
    
    l.insertBefore(-3,-4);
    l.display();
}