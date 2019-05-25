#include "node.h"

class List
{
    public:

    // Constructors.
    List();

    // Destructor.
    ~List();

    // Methods.
    void add(char symbol);
    void add(Node* node);
    void remove(Node* node);
    bool isEmpty();
    void print();

    // Getters and Setters.
    Node* getFirst();
    Node* getLast();
    Node* getNode(char symbol);
    int getLength();

    private:
    
    // Attributes.
    Node* first;
    Node* last;
    int length;

    // Methods.
    void shift(Node* node, Node* other);
    void sort(Node* node);
};
