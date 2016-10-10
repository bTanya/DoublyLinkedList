#include "node.h"

Node::Node(const Node& node) {
    next = node.next;
    prev = node.prev;
    data = node.data;
}

IntNode::IntNode(void* data){
    int*  temp = reinterpret_cast<int*>(data);
    int   newData    = *temp;
    delete temp;
    this->data = newData;

}
int IntNode::getType() { return INT;}
void* IntNode::getData() {return &data;}
void IntNode::setData(int newData) {this->data = newData;}
void IntNode::printData(){  std::cout<<this->data<<" ";}

DoubleNode::DoubleNode(void* data){
    double*  temp = reinterpret_cast<double*>(data);
    double   newData    = *temp;
    delete temp;
    this->data = newData;

}

int DoubleNode::getType() { return DOUBLE;}
void* DoubleNode::getData() {return &data;}
void DoubleNode::setData(double newData) {this->data = newData;}
void DoubleNode::printData(){  std::cout<<this->data<<" ";}



StringNode::StringNode(void* data){
    std::string*  temp = reinterpret_cast<std::string*>(data);
    std::string   newData    = *temp;
    delete temp;
    this->data = newData;
}

int StringNode::getType () { return STRING;}
void* StringNode::getData() {return &data;}
void StringNode::setData(std::string newData) {this->data = newData;}
void StringNode::printData(){  std::cout<<this->data<<" ";}




Node* NodeFactory::createFormattedNode(void* data,int typeNode) {
    switch (typeNode) {
    case INT:
        return new IntNode(data);

    case DOUBLE:
        return new DoubleNode(data);

    case STRING:
        return new StringNode(data);

    default:
        throw("Invalid param");
        break;
    }
}

int CastNodeData::int_cast(void *data){
    try{
        int*  temp = reinterpret_cast<int*>(data);
        int   newData    = *temp;
        delete temp;
        return newData;
    }
    catch(...){
        std::cout<<"Incorrect data";
    }
}
double CastNodeData::double_cast(void *data){
    try{
        double*  temp = reinterpret_cast<double*>(data);
        double   newData    = *temp;
        delete temp;
        return newData;
    }
    catch(...){
        std::cout<<"Incorrect data";
    }
}
std::string CastNodeData::string_cast(void *data){
    try{
        std::string*  temp = reinterpret_cast<std::string*>(data);
        std::string   newData    = *temp;
        delete temp;
        return newData;
    }
    catch(...){
        std::cout<<"Incorrect data";
        return std::string("Incorrect data");
    }
}

