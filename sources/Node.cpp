#include "Node.hpp"
using namespace ariel;
//Getters:
std::string Node::getData() const {return this->_data;}
std::vector<Node*>& Node::getChildrenVec() {return this->_children;}

//Constructor:
Node::Node(const std::string& str) {this->_data = std::move(str);}

//Destructor:
Node::~Node(){}

//Functions:
void Node::printNode(){
    std::cout<<"Node Data: " << this->getData() << std::endl;
    std::cout<< "Children Vec: {";
    int size = this->getChildrenVec().size();
    if(size>0){
        for(int i=0; i<size-1; i++){
            std::cout<< this->getChildrenVec().at(i)->getData()<< ", ";
        }
        std::cout<< this->getChildrenVec().at(size-1)->getData();
    }
    std::cout<< "}"<<std::endl;
}