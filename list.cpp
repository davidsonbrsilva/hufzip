#include <iostream>
#include "list.h"

// Constructors.

List::List()
{
    this->first = NULL;
    this->last = NULL;
    this->length = 0;
}

// Methods.

void List::add(char symbol)
{
    Node* node = this->getNode(symbol);

    if (node != NULL)
    {
        node->setFrequency(node->getFrequency() + 1);
        this->sort(node);
    }
    else
    {
        node = new Node(symbol, 1);
        this->add(node);
    }
}

void List::add(Node* node)
{
    if (this->isEmpty())
    {
        this->first = node;
        this->last = node;
        this->length = 1;
    }
    else
    {
        node->setNext(this->first);
        this->first->setPrev(node);
        this->first = node;
        this->length++;
        this->sort(node);
    }
}

void List::remove(Node* node)
{
    if (this->getLength() == 0)
    {
        return;
    }

    for (Node* aux = this->first; aux != NULL; aux = aux->getNext())
    {
        if (node == aux)
        {
            // Remove o único.
            if (this->getLength() == 1)
            {
                this->first = NULL;
                this->last = NULL;
                this->length--;
                node = NULL;
                break;
            }

            // Remove primeiro.
            if (node == this->first)
            {
                this->first = this->first->getNext();
                this->first->setPrev(NULL);
                node = NULL;
                this->length--;
                break;
            }

            // Remove último.
            if (node == this->last)
            {
                this->last = this->last->getPrev();
                this->last->setNext(NULL);
                node = NULL;
                this->length--;
                break;
            }

            // Remove no meio
            node->getPrev()->setNext(node->getNext());
            node->getNext()->setPrev(node->getPrev());
            node = NULL;
            this->length--;
            break;
        }
    }
}

Node* List::getLast()
{
    return this->last;
}

Node* List::getFirst()
{
    return this->first;
}

int List::getLength()
{
    return this->length;
}

bool List::isEmpty()
{
    return this->first == NULL && this->last == NULL;
}

Node* List::getNode(char symbol)
{
    for (Node* aux = this->first; aux != NULL; aux = aux->getNext())
    {
        if (aux->getSymbol() == symbol)
        {
            
            return aux;
        }
    }

    return NULL;
}

void List::shift(Node* node, Node* other)
{
    Node* beforeNode = NULL;
    Node* afterNode = NULL;
    Node* beforeOther = NULL;
    Node* afterOther = NULL;

    if (this->first == node)
    {
        this->first = other;
    }

    if (this->last == other)
    {
        this->last = node;
    }

    if (other->getPrev() != NULL)
    {
        beforeOther = other->getPrev();
    }

    if (other->getNext() != NULL)
    {
        afterOther = other->getNext();
    }

    if (node->getPrev() != NULL)
    {
        beforeNode = node->getPrev();
    }

    if (node->getNext() != NULL)
    {
        afterNode = node->getNext();
    }

    node->setNext(NULL);
    node->setPrev(NULL);
    other->setNext(NULL);
    other->setPrev(NULL);

    if (beforeOther != NULL)
    {
        if (beforeOther != node)
        {
            node->setPrev(beforeOther);
            beforeOther->setNext(node);
        }
        else
        {
            node->setPrev(other);
            other->setNext(node);
        }
    }

    if (afterOther != NULL)
    {
        node->setNext(afterOther);
        afterOther->setPrev(node);
    }
    
    if (beforeNode != NULL)
    {
        other->setPrev(beforeNode);
        beforeNode->setNext(other);
    }

    if (afterNode != NULL)
    {
        if (afterNode != other)
        {
            other->setNext(afterNode);
            afterNode->setPrev(other);
        }
        else
        {
            other->setNext(node);
            node->setPrev(other);
        }
    }
}

void List::print()
{
    for (Node* aux = this->getFirst(); aux != NULL; aux = aux->getNext())
    {
        aux->print();

        if (aux->getPrev() != NULL)
        {
            std::cout << "\t\tleft: " << *aux->getPrev();
        }
        else
        {
            std::cout << "\t\t\t\t";
        }

        if (aux->getNext() != NULL)
        {
            std::cout << "\t\tright: " << *aux->getNext();
        }
        else
        {
            std::cout << "\t\t\t\t";
        }

        std::cout << "\n";
    }
}

void List::sort(Node* node)
{
    bool needShift = false;
    Node* aux = node;

    if (aux->getNext() != NULL)
    {
        while (node->getFrequency() > aux->getNext()->getFrequency())
        {
            needShift = true;
            
            aux = aux->getNext();

            if (aux->getNext() == NULL)
            {
                break;
            }
        }

        if (needShift)
        {
            this->shift(node, aux);
        }
    }
}
