#define ASCII 256
#define BYTE_SIZE 8

#include <math.h>
#include <bits/stdc++.h> 
#include <fstream>
#include <sstream>

#include "huff.h"

// Public.

Huff::Huff()
{
    this->list = NULL;
}

/**
* Compress the specified file.
*
* @param filename The filename.
*/
void Huff::compress(string filename)
{
    string text = this->read(filename);
    List* list = this->buildList(text);
    Node* node = this->buildTrie(list);
    string* codes = this->buildCode(node);
    string trie = this->transform(node);
    string bitflow = this->transform(text, codes);
    string outputFilename = getFileWithoutExtension(filename, find(filename, '.')) + ".hfz";
    this->write(getFileExtension(filename, find(filename, '.')), trie, text.size(), bitflow, outputFilename);
}

/**
* Uncompress the specified file.
*
* @param filename The filename.
*/
void Huff::expand(string filename)
{
    string text = this->read(filename);
    string ext = this->readFileExtension(&text);
    Node* root = this->readTrie(&text);
    int size = this->readSize(&text);
    string bitflow = this->bytesToBitflow(text);
    string translated = this->translate(bitflow, size, root);
    this->write(translated, getFileWithoutExtension(filename, find(filename, '.')) + "." + ext);
}

// Private.

/**
* Read the content of the file.
* 
* @param filename The filename.
* @return The content of the file.
*/
string Huff::read(string filename)
{
    ifstream source;
    source.open(filename.c_str());

    if (!source)
    {
        cout << "File not found!\n";
        exit(-1);
    }

    if (!source.is_open())
    {
        cout << "It was not possible open the file!\n";
        exit(-1);
    }

    char head;

    stringstream buffer;
    buffer << source.rdbuf();

    source.close();

    return buffer.str();
}

/**
* Build a string list based on character occurrence.
* 
* @param text The source text.
* @return The list.
*/
List* Huff::buildList(string text)
{
    List* list = new List();

    for (int i = 0; i < text.size(); ++i)
    {
        list->add(text[i]);
    }

    return list;
}

/**
* Transform a bits sequency on correspondent string.
*
* @param bitflow The bits sequency.
* @return The correspondent string.
*/
string Huff::buildBytes(string bitflow)
{
    unsigned char byte = 0;
    unsigned int currbit = 0;
    std::string output = "";

    while (currbit < bitflow.size())
    {
        for (int i = 0; i < BYTE_SIZE; )
        {
            if (bitflow[currbit] == '1')
            {
                byte = byte << 1;
                byte = byte | 1;
            }
            else if (bitflow[currbit] == '0')
            {
                byte = byte << 1;
            }

            ++currbit;
            ++i;

            if (currbit >= bitflow.size())
            {
                int remaind = 8 - i;

                for (int j = 0; j < remaind; ++j)
                {
                    byte = byte << 1;
                }

                break;
            }
        }

        output += byte;
        byte = 0;
    }

    return output;
}

/**
* Build a trie based on specified list.
*
* @param list The reference to the list.
* @return The head node of the trie.
*/
Node* Huff::buildTrie(List *list)
{
    if (list == NULL)
    {
        throw "Argument is null!";
    }

    if (list->getLength() == 0)
    {
        throw "List is empty!";
    }

    while (list->getLength() > 1)
    {
        Node* first = list->getFirst();
        Node* second = list->getFirst()->getNext();

        int frequency = first->getFrequency() + second->getFrequency();

        Node* parent = new Node(frequency, first, second);

        list->remove(first);
        list->remove(second);
        list->add(parent);
    }

    return list->getFirst();
}

/**
* Build the codes table based on trie.
*
* @param root The head node of the trie.
* @return The codes table.
*/
string* Huff::buildCode(Node *root)
{
    string* codes = new string[ASCII];
    this->buildCode(codes, root, "");
    return codes;
}

/**
* Build the code table based on trie.
*
* @param codes The codes table.
* @param root The reference to the head node of the trie.
* @param code The current code under construction.
* @return The code table.
*/
void Huff::buildCode(string* codes, Node* node, string code)
{
    if (node->isLeaf())
    {
        codes[node->getSymbol()] = code;     
        return;
    }

    this->buildCode(codes, node->getLeft(), code + '0');
    this->buildCode(codes, node->getRight(), code + '1');
}

/**
* Show trie on screen.
*
* @param root The head node of the trie.
*/
void Huff::printTrie(Node* root)
{
    if (root->isLeaf())
    {
        root->print();
        return;
    }

    this->printTrie(root->getLeft());
    this->printTrie(root->getRight());
}

/**
* Show codes table on screen.
*
* @param codes The codes table.
*/
void Huff::printCode(string* codes)
{
    cout << "Symbol  Bits\n";

    for (int i = 0; i < ASCII; ++i)
    {
        if (codes[i] != "")
        {
            char c = (char)i;
            cout << "    " << c << "  " << codes[i] << "\n";
        }
    }
}

/**
* Write trie, original string size and bitflow on specified file.
*
* @param text The text to save.
* @param filename The name of target file.
*/
void Huff::write(string text, string filename)
{
    // Save on file.
    ofstream target;
    target.open(filename.c_str());
    target << text;
    target.close();
}

/**
* Write trie, original string size and bitflow on specified file.
*
* @param trie The trie converted on string format.
* @param size The original string size.
* @param bitflow The bits sequency built.
*/
void Huff::write(string fileext, string trie, int size, string bitflow, string filename)
{
    // Save file extension.
    string output = fileext + ",";

    // Save file extension.
    output += trie;

    // Save size of original string.
    stringstream ss;
    ss << size;
    output += ss.str();

    // Save bitflow.
    output += buildBytes(bitflow);

    // Save on file.
    this->write(output, filename);
}

/**
* Transform trie on string.
*
* @param node The head node of the trie.
* @return The string constructed from the trie.
*/
string Huff::transform(Node* node)
{
    return this->transform(node, "");
}

/**
* Transform trie on string.
*
* @param node The head node of the trie.
* @param output The string state constructed from the trie before checking the current node.
* @return The string state constructed from the trie after checking the current node.
*/
string Huff::transform(Node* node, string output)
{
    if (node->isLeaf())
    {
        output += '1';
        output += node->getSymbol();
        return output;
    }

    output += '0';
    output = transform(node->getLeft(), output);
    output = transform(node->getRight(), output);
    return output;
}

/**
* Read the file extension from content of compressed file.
*
* @param text Content of compressed file.
* @return The file extension.
*/
string Huff::readFileExtension(string* text)
{
    string ext = "";
    
    int i;

    for (i = 0; (*text)[i] != ','; ++i)
    {
        ext += (*text)[i];
    }

    (*text).replace(0, i + 1, "");

    return ext;
}

/**
* Read the trie from content of compressed file.
*
* @param text Content of compressed file.
* @return The trie.
*/
Node* Huff::readTrie(string* text)
{
    int index = -1;
    Node* node = this->readTrie(*text, &index);
    index++;
    (*text).replace(0, index, "");
    return node;
}

/**
* Read the trie from content of compressed file.
*
* @param text Current content of compressed file.
* @param index Content head.
* @return The trie.
*/
Node* Huff::readTrie(string text, int* index)
{
    (*index)++;

    if (text[*index] == '1')
    {
        (*index)++;
        char symbol = text[*index];
        return new Node(symbol, 0, NULL, NULL, NULL, NULL);
    }

    return new Node('\0', 0, NULL, NULL, readTrie(text, index), readTrie(text, index));
}

/**
* Read the original bytes size from content of compressed file.
*
* @param text Content of compressed file.
* @return The original bytes size.
*/
int Huff::readSize(string* text)
{
    stringstream ss(*text);
    int size;

    ss >> size;
    ss.str("");
    ss.clear();

    ss << size;
    int index = ss.str().size();

    (*text) = (*text).replace(0, index, "");

    return size;
}

/**
* Convert the original text to bitflow.
*
* @param text The original text.
* @param text The built table.
* @return The compression bitflow.
*/
string Huff::transform(string text, string* table)
{
    string output = "";

    for (int i = 0; i < text.size(); ++i)
    {
        output += table[text[i]];
    }

    return output;
}

/**
* Transform the original filename in a file with hfz extension.
*
* @param filename The original filename.
* @return The modified filename.
*/
std::string Huff::getOutputFilename(std::string filename)
{
    std::string outputFilename = "";
    int endIndex = filename.size() - 1;

    while (endIndex >= 0)
    {
        if (filename[endIndex] == '.')
        {
            --endIndex;
            break;
        }

        --endIndex;
    }

    if (endIndex >= 0)
    {
        for (int i = 0; i <= endIndex; ++i)
        {
            outputFilename += filename[i];
        }
    }
    else
    {
        outputFilename = filename;
    }

    outputFilename += ".hfz";

    return outputFilename;
}

/**
* Transform the compressed bytes in a string of bitflow.
*
* @param bytes The compressed bytes.
* @return The bitflow.
*/
string Huff::bytesToBitflow(string bytes)
{
    string bits = "";

    for (int i = 0; i < bytes.size(); ++i)
    {
        for (int j = 0; j < BYTE_SIZE; ++j)
        {
            if ((bytes[i] & 256) == 256) // compare "c" with 1000 0000
            {
                bits += '1';
                
            }
            else
            {
                bits += '0';
            }

            bytes[i] = bytes[i] << 1; // left shift
        }
    }

    return bits;
}

/**
* Transform the bitflow in the original text.
*
* @param bitflow The bitflow.
* @param size The bytes size of original text.
* @param root The root node of trie.
* @return The original text.
*/
string Huff::translate(string bitflow, int size, Node* root)
{
    int bit = 0;
    string text = "";

    for (int i = 0; i < size; ++i)
    {
        Node* node = root;

        while (!node->isLeaf())
        {
            if (bitflow[bit] == '1')
            {
                node = node->getRight();
                
            }
            else
            {
                node = node->getLeft();
            }

            ++bit;
        }

        text += node->getSymbol();
    }

    return text;
}

/**
* Searches for the specified character and return its index. If not, return -1.
*
* @param filename The filename.
* @param charact The character.
* @return The character index.
*/
int Huff::find(string filename, char charact)
{
    int index = -1;

    for (int i = filename.size() - 1; i > 0; --i)
    {
        if (filename[i] == charact)
        {
            index = i;
            return index;
        }
    }

    return index;
}

/**
* Get the file extension from specified filename.
*
* @param filename The filename.
* @param index The index of separator to split the filename. Most common: doth.
* @return The file extension.
*/
string Huff::getFileExtension(string filename, int index)
{
    if (index != -1)
    {
        filename.replace(0, index + 1, "");
    }
    
    return filename;
}

/**
* Get the filename without its extension.
*
* @param filename The filename.
* @param index The index of separator to split the filename. Most common: doth.
* @return The filename without its extension.
*/
string Huff::getFileWithoutExtension(string filename, int index)
{
    if (index != -1)
    {
        filename.replace(index, filename.size() - 1, "");
    }

    return filename;
}