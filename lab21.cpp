// COMSC-210 | lab 22 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <string>
#include <time.h>
#include <random>
using namespace std;

// global variables
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20, ARRSIZE = 15; // included array size

// class: Goat
class Goat
{
public:
    Goat() // default constructor
    {
        age = (rand() % 20) + 1;     // random variable (1-20)
        name = names[rand() % 15];   // random member of array of names
        color = colors[rand() % 15]; // random member of array of colors
    }

    Goat(int a, string n, string c) // full parameter constructor
    {
        age = a;
        name = n;
        color = c;
    }

    void printAll() const // to ensure variables set properly
    {
        cout << "Age: " << age << '\n';
        cout << "Name: " << name << '\n';
        cout << "Color: " << color << '\n';
    }

private:
    int age;
    string name;
    string color;

    const string names[ARRSIZE] = { // 15 uncharacteristically human names
        "John", "Michael", "Sarah", "Emily", "David",
        "Jessica", "James", "Jennifer", "Robert", "Laura",
        "Christopher", "Ashley", "Matthew", "Amanda", "Daniel"};

    const string colors[ARRSIZE] = {
        "White", "Black", "Brown", "Gray", "Golden",
        "Spotted", "Cream", "Beige", "Tan", "Chocolate",
        "Silver", "Ash", "Ivory", "Ebony", "Mahogany"};
};

// class: DoublyLinkedList
class DoublyLinkedList
{
friend Goat; //so that DoublyLinkedList can access Goat methods

private:
    struct Node
    {
        Goat g; //each member in linked list has a goat
        Node *prev;
        Node *next;

        Node(const Goat &goat ,Node* p = nullptr, Node* n = nullptr) //constructor, takes in goat as parameter
        : g(goat), prev(p), next(n)
        {}
    };

    Node *head;
    Node *tail;

public:
    // constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(const Goat &goat) //modified to push back goats
    {
        Node *newNode = new Node(goat);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(const Goat &goat)
    {
        Node *newNode = new Node(goat);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // void insert_after(int value, int position)
    // {
    //     if (position < 0)
    //     {
    //         cout << "Position must be >= 0." << endl;
    //         return;
    //     }

    //     Node *newNode = new Node(value);
    //     if (!head)
    //     {
    //         head = tail = newNode;
    //         return;
    //     }

    //     Node *temp = head;
    //     for (int i = 0; i < position && temp; ++i)
    //         temp = temp->next;

    //     if (!temp)
    //     {
    //         cout << "Position exceeds list size. Node not inserted.\n";
    //         delete newNode;
    //         return;
    //     }

    //     newNode->next = temp->next;
    //     newNode->prev = temp;
    //     if (temp->next)
    //         temp->next->prev = newNode;
    //     else
    //         tail = newNode; // Inserting at the end
    //     temp->next = newNode;
    // }

    // void delete_node(int value)
    {
        if (!head)
            return; // Empty list

        Node *temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
            return; // Value not found

        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next; // Deleting the head
        }

        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print()
    {
        Node *current = head;
        if (!current)
            return;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse()
    {
        Node *current = tail;
        if (!current)
            return;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main()
{
    srand(time(0)); // seed time-dependent random

    // variable initializaition
    DoublyLinkedList list;
    int size = (rand() % 15) + 5; // size of array random (5-20)
    for (int i = 0; i > size; i++)
    {
        //logic to push_front() goat objects
    }

    // for (int i = 0; i < size; ++i)
    //     list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
    // cout << "List forward: ";
    // list.print();

    // cout << "List backward: ";
    // list.print_reverse();

    // cout << "Deleting list, then trying to print.\n";
    // list.~DoublyLinkedList();
    // cout << "List forward: ";
    // list.print();

    return 0;
}
