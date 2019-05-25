class Node
{
    public:

    // Constructors.
    Node();
    Node(char symbol, int frequency);
    Node(char symbol, int frequency, Node* prev, Node* next);
    Node(int frequency, Node* left, Node* right);
    Node(char symbol, int frequency, Node* prev, Node* next, Node* left, Node* right);

    // Destructor.
    ~Node();

    // Getters and Setters.
    void setSymbol(char symbol);
    char getSymbol();
    void setFrequency(int frequency);
    int getFrequency();
    void setPrev(Node* prev);
    Node* getPrev();
    void setNext(Node* next);
    Node* getNext();
    void setLeft(Node* left);
    Node* getLeft();
    void setRight(Node* right);
    Node* getRight();

    // Methods.
    void print();
    bool isLeaf();
    
    // Overloads.
    friend std::ostream& operator<< (std::ostream& stream, Node& node);

    private:

    // Attributes.
    char symbol;
    int frequency;
    Node* prev;
    Node* next;
    Node* left;
    Node* right;
};
