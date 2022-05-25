#include "Node.hpp"
using namespace ariel;
//Getters:
std::string& Node::getData() {return this->_data;}
std::vector<Node*>& Node::getChildrenVec() {return this->_children;}

//Constructor:
Node::Node(const std::string& str) {this->_data=str;}

//Destructor:
Node::~Node(){}

//Functions:
//Addes a child to the Nodes children vector.
void Node::addChild(const std::string& child){
    Node* ch = new Node(child);
    this->_children.push_back(ch);
}

//User added function (for testing purpose):
void Node::printNode(){
    std::cout<<"Node Data: " << this->getData() << std::endl;
    std::cout<< "Children Vec: {";
    unsigned long size = this->getChildrenVec().size();
    if(size>0){
        for(unsigned long i=0; i<size-1; i++){
            std::cout<< this->getChildrenVec().at(i)->getData()<< ", ";
        }
        std::cout<< this->getChildrenVec().at(size-1)->getData();
    }
    std::cout<< "}"<<std::endl;
}