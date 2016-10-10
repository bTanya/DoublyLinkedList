#ifndef NODE
#define NODE

#include <iostream>

enum TYPENODE{INT = 1, DOUBLE = 2, STRING = 3};
class Node
{
public:
    Node():
        next(NULL),
        prev(NULL){}
    Node(const Node &node);
    virtual ~Node(){}

    Node *next;
    Node *prev;
    virtual void* getData() = 0;
    virtual void setData(int){};
    virtual void setData(double){};
    virtual void setData(std::string){};
    virtual int getType() = 0;
    virtual void printData() = 0;
private:
    void* data;

};

class IntNode : public Node
{
public:

    IntNode(void* data);
    ~IntNode(){};
    int data;
    int getType();
    void* getData();
    void setData(int newData);
    void printData();
};

class DoubleNode: public Node
{
public:
    ~DoubleNode(){};
    DoubleNode(void* data);
    double data;
    int getType() ;
    void* getData() ;
    void setData(double newData);
    void printData();
};

class StringNode : public Node
{
public:
    ~StringNode(){};
    StringNode(void* data);

    std::string data;
    int getType ();
    void* getData() ;
    void setData(std::string newData);
    void printData();
};

class AbstractFactory {
public:
    virtual Node* createFormattedNode(void* data,int typeNode) = 0;
};

class NodeFactory : public AbstractFactory {
public:
    Node* createFormattedNode(void* data,int typeNode) ;
};

class CastNodeData{
public:
    static int int_cast(void* data);
    static double double_cast(void* data);
    static std::string string_cast(void* data);

};

#endif // NODE

