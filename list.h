#ifndef LIST
#define LIST
#include "Node.h"
class List   //Создаем тип данных Список
{
private:

    unsigned int count;
    Node *head,*tail;
public:
    List():
        head(NULL),
        tail(NULL),
        count(0){};
    ~List();
    Node* getHead();
    Node* getTail();
    void output();
    void output_inverted();

    void push_back(int data);
    void push_back(double data);
    void push_back(std::string data);

    void push_front(int data);
    void push_front(double data);
    void push_front(std::string data);

    unsigned int getCount();
    bool empty();

    Node* find(int data);
    Node* find(double data);
    Node* find(std::string data);

    Node* erase(Node* pNode);
    bool pop_back();
    bool pop_front();
    void clear();

};

#endif // LIST

