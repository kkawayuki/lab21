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
        name = names[rand() % 15];   // random member from array of names
        color = colors[rand() % 15]; // random member frpm array of colors
    }

    Goat(int a, string n, string c) // full parameter constructor
    {
        age = a;
        name = n;
        color = c;
    }

    /************************************************
     * Function: Prints out all goat fields with
     * a tab for formatting.
     *
     * Parameters: NONE
     * Return: NONE
     ************************************************/
    void printGoatFields() const // insert Goat field pun
    {
        cout << '\t' << name << " (" << color << ", " << age << ")\n";
    }

private:
    int age;
    string name;
    string color;

    const string names[ARRSIZE] = { // array of 15 strangely human names
        "John", "Michael", "Sarah", "Emily", "David",
        "Jessica", "James", "Jennifer", "Robert", "Laura",
        "Christopher", "Ashley", "Matthew", "Amanda", "Daniel"};

    const string colors[ARRSIZE] = { // array of 15 AI-generated oddly specific colors
        "White", "Black", "Brown", "Gray", "Golden",
        "Spotted", "Cream", "Beige", "Tan", "Chocolate",
        "Silver", "Ash", "Ivory", "Ebony", "Mahogany"};
};

// class: DoublyLinkedList
class DoublyLinkedList
{
private:
    // struct Node
    struct Node
    {
        Goat g; // each Node in linked list has a goat!
        Node *prev;
        Node *next;

        Node(const Goat &goat, Node *p = nullptr, Node *n = nullptr) // constructor, takes in goat as parameter
            : g(goat), prev(p), next(n)                              // brackets don't work for mine for some reason, g(goat) uses the copy constructor to fully assign relevant fields.
        {
        }
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

    /************************************************
     * Function: appends a Node to the back of the
     * linked list
     *
     * Parameters: &goat, reference to a randomly
     * generated goat object, used in this function
     * to populate the Goat that each Node contains.
     * Return: NONE
     ************************************************/
    void push_back(const Goat &goat)
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

    /************************************************
     * Function: appends a Node to the front of the
     * linked list
     *
     * Parameters: &goat, reference to a randomly
     * generated goat object, used in this function
     * to populate the Goat that each Node contains.
     * Return: NONE
     ************************************************/
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

    /* disabled for ease of use (I didn't have to modify these)

    void insert_after(int value, int position)
    {
        if (position < 0)
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp)
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }
    void delete_node(int value)
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

    */

    /************************************************
     * Function: prints all information from nodes
     * in the LinkedList from head to tail, able to
     * reference the Goat methods due to the
     * compositional relationship between
     * Node having a Goat.
     *
     * Parameters: NONE
     * Return: NONE
     ************************************************/
    void print()
    {
        Node *current = head;
        if (!current)
        {
            cout << "List is empty.";
            return;
        }

        while (current)
        {
            current->g.printGoatFields(); // print all information about goat
            current = current->next;      // move to next
        }
        cout << endl;
    }

    /************************************************
     * Function: prints all information from nodes
     * in the LinkedList from tail to head, using
     * Goat method printGoatFields().
     *
     * Parameters: NONE
     * Return: NONE
     ************************************************/
    void print_reverse()
    {
        Node *current = tail;
        if (!current)
        {
            cout << "List is empty.";
            return;
        }
        while (current)
        {
            current->g.printGoatFields(); // same deal in reverse order
            current = current->prev;      // go previous
        }
        cout << endl;
    }

    // destructor
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

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    srand(time(0)); // seed random

    // variable initializaition
    int size = (rand() % 15) + 5; // random size (5-20)
    DoublyLinkedList list;

    // populate Linked List
    for (int i = 0; i < size; i++)
    {
        Goat temp;
        list.push_back(temp);
    }

    // Output manipulation with full list
    cout << "Forward: \n";
    list.print();

    cout << "Backward: \n";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();

    cout << "List forward: ";
    list.print();

    return 0;
}
