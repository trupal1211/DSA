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


  // ----------------- append -----------------//

   void append(linklist *l1,linklist *l2)
  {
    
    first = l1->first;
    node *temp = first;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = l2->first;
  }


  // ----------------- reverse -----------------//

  void reverse()
  {
      node *prev = NULL;
      node *forward = NULL;
      node *curr = first;
        
      if(curr == NULL || curr->next == NULL)
      {
        return;    
      }
        
      while(curr!=NULL)
      {
        forward=curr->next;   // increment forward for future access / track

        curr->next=prev;   // reverse point

        prev = curr;      // increment prev & curr  (in order)
        curr = forward;  
      }

      first = prev;     // at the end curr at the last and it is a starting point
  }


  void display()
  {
    node *temp = first;

    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }

    cout<<endl;
  }
};


int main()
{
    linklist l1,l2,l3;

    l1.insert(1);
    l1.insert(2);
    l1.display();
    
    l2.insert(3);
    l2.insert(4);
    l2.display();

    l3.append(&l1,&l2);
    l3.display();

    l3.reverse();
    l3.display();

}
