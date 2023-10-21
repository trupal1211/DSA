#include <iostream>
using namespace std;

class node
{
    int coff;
    int expo;
    node *next;

    friend class linklist;

public:
    node() {}

    node(int c, int e)
    {
        coff = c;
        expo = e;
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

    void insert(int c, int e)
    {
        node *nn = new node(c, e);

        if (first == NULL)
        {
            first = nn;
        }
        else
        {
            node *temp = first;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    void display()
    {
        if (first == NULL)
        {
            cout << "linklist is empty";
        }
        else
        {
            node *temp = first;

            while (temp != NULL)
            {
                cout << "+" << temp->coff << "x^" << temp->expo;
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void polyAdd(linklist *l1, linklist *l2, int t1, int t2)
    {
        int i = 0, j = 0;

        node *temp1 = l1->first;
        node *temp2 = l2->first;

        while (i < t1 && j < t2)
        {
            if (temp1->expo == temp2->expo)
            {
                insert((temp1->coff + temp2->coff), temp1->expo);
                temp1 = temp1->next;
                temp2 = temp2->next;
                i++;
                j++;
            }
            else if (temp1->expo > temp2->expo)
            {
                insert(temp1->coff, temp1->expo);
                temp1 = temp1->next;
                i++;
            }
            else if (temp1->expo < temp2->expo)
            {
                insert(temp2->coff, temp2->expo);
                temp2 = temp2->next;
                j++;
            }
        }

        while (i < t1)
        {
            insert(temp1->coff, temp1->expo);
            temp1 = temp1->next;
            i++;
        }

        while (j < t2)
        {
            insert(temp2->coff, temp2->expo);
            temp2 = temp2->next;
            j++;
        }

        display();
    }
};

int main()
{
    linklist l1, l2, l3;
    int t1, t2;
    int c, e;

    cout << "enter the number of term in poly 1\n";
    cin >> t1;
    cout << "enter the number of term in poly 2\n";
    cin >> t2;

    cout << "enter the polynomial 1's coff and expo\n";

    for (int i = 0; i < t1; i++)
    {
        cin >> c >> e;
        l1.insert(c, e);
    }

    cout << "enter the polynomial 1's coff and expo\n";

    for (int i = 0; i < t2; i++)
    {
        cin >> c >> e;
        l2.insert(c, e);
    }

    l3.polyAdd(&l1, &l2, t1, t2);

    return 0;
}