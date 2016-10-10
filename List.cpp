#include <stdlib.h>
#include "list.h"

List::~List()
{
    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}
Node* List::getHead(){return this->head;}
Node* List::getTail(){return this->tail;}
void List::push_back(int data)
{
    ++count;
    NodeFactory *pfactory = new NodeFactory();
    Node* pdata = pfactory->createFormattedNode(reinterpret_cast<void*>(new int(data)),INT);

    if (head != NULL)
    {
        pdata->prev = tail;
        tail->next = pdata;
        tail = pdata;
    }
    else
    {
        pdata->prev = NULL;
        head = tail = pdata;
    }
}
void List::push_back(double data)
{
    ++count;
    NodeFactory *pfactory = new NodeFactory();
    Node* pdata = pfactory->createFormattedNode(reinterpret_cast<void*>(new double(data)),DOUBLE);

    if (head != NULL)
    {
        pdata->prev = tail;
        tail->next = pdata;
        tail = pdata;
    }
    else
    {
        pdata->prev = NULL;
        head = tail = pdata;
    }
}
void List::push_back(std::string data)
{
    ++count;
    NodeFactory *pfactory = new NodeFactory();
    Node* pdata = pfactory->createFormattedNode(reinterpret_cast<void*>(new std::string(data)),STRING);

    if (head != NULL)
    {
        pdata->prev = tail;
        tail->next = pdata;
        tail = pdata;
    }
    else
    {
        pdata->prev = NULL;
        head = tail = pdata;
    }
}

void List::push_front(int data)
{
    ++count;
    NodeFactory *pfactory = new NodeFactory();
    Node* pdata = pfactory->createFormattedNode(reinterpret_cast<void*>(new int(data)),INT);

    if (head != NULL)
    {
        pdata->next = head;
        head->prev = pdata;
        head = pdata;
    }
    else
    {
        pdata->prev = NULL;
        head = tail = pdata;
    }
}
void List::push_front(double data)
{
    ++count;
    NodeFactory *pfactory = new NodeFactory();
    Node* pdata = pfactory->createFormattedNode(reinterpret_cast<void*>(new double(data)),DOUBLE);

    if (head != NULL)
    {
        pdata->next = head;
        head->prev = pdata;
        head = pdata;
    }
    else
    {
        pdata->prev = NULL;
        head = tail = pdata;
    }
}
void List::push_front(std::string data)
{
    ++count;
    NodeFactory *pfactory = new NodeFactory();
    Node* pdata = pfactory->createFormattedNode(reinterpret_cast<void*>(new std::string(data)),STRING);

    if (head != NULL)
    {
        pdata->next = head;
        head->prev = pdata;
        head = pdata;
    }
    else
    {
        pdata->prev = NULL;
        head = tail = pdata;
    }
}

void List::output()
{
    Node *temp = head;
    while (temp!=NULL)
    {
        temp->printData();
        temp=temp->next;
    }
    std::cout<<"\n";
}
void List::output_inverted()
{
    Node *temp = tail;
    while (temp!=NULL)
    {
        temp->printData();
        temp=temp->prev;
    }
    std::cout<<"\n";
}
unsigned int List::getCount()
{
    return this->count;
}
bool List::empty()
{
    return count == 0;
}
Node* List::find(int data){
    Node* current = NULL;
    for (current = head; current;current = current->next)
        if(current->getType() == INT){
            int*  temp = reinterpret_cast<int*>(current->getData());
            int   newData    = *temp;
            delete temp;
            if (newData == data)
                break;
        }
    return current;
}
Node* List::find(double data){
    Node* current = NULL;
    for (current = head; current;current = current->next)
        if(current->getType() == DOUBLE){
            double*  temp = reinterpret_cast<double*>(current->getData());
            double   newData    = *temp;
            delete temp;
            if (newData == data)
                break;
        }
    return current;
}
Node* List::find(std::string data){
    Node* current = NULL;
    for (current = head; current;current = current->next)
        if(current->getType() == STRING){
            std::string*  temp = reinterpret_cast<std::string*>(current->getData());
            std::string   newData    = *temp;
            if (newData.compare(data) == 0)
                break;
        }
    return current;
}

Node* List::erase(Node* pNode)
{
    Node* eraseNode = pNode;
    if (pNode == NULL)
        return false;
    if (pNode == head){
        head = pNode->next;
        pNode->next->prev = NULL;
    }
    else if (pNode == tail){
        tail = pNode->prev;
        pNode->prev->next = NULL;
    }else {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }
    delete pNode;
    --count;
    return eraseNode;
}
bool List::pop_back()
{
    return erase(tail);
}
bool List::pop_front()
{
    return erase(head);
}
void List::clear()
{

    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }

}



