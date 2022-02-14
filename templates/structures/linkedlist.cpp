#include "header.h"

template<typename T>
struct node
{
    T data;
    struct node* next;
    struct node* prev;
};

template<typename T>
class LinkedList
{
    public:
    node<T> *head, *tail;
    
    // Constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Print
    void display(node<T> *head)
    {
        if (head == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << head->data << " ";
            display(head->next);
        }
    }

    // Push Back
    void push_back(T n)
    {
        node<T> *temp = new node<T>;
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }

    // Push Front
    void push_front(T n)
    {
        node<T> *temp = new node<T>;
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;        
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            head = head->prev;
        }
    }

    // Pop Front
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
        }
        else
        {
            head = head->next;
            node<T> *temp = head->prev;
            delete temp;
        }
    }

    // Pop Back
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
        }
        else
        {
            tail = tail->prev;
            node<T> *temp = tail->next;
            delete temp;
        }
    }
};

signed main()
{
    LinkedList<int> l;
    l.push_back(0);
    l.push_front(2);
    l.push_front(9);
    l.display(l.head);
    l.pop_front();
    l.push_front(10);
    l.display(l.head);
    l.pop_back();
    l.push_back(100);
    l.push_back(11);
    l.display(l.head);
    return 0;
}