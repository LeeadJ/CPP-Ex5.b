#include "OrgChart.hpp"
#include <queue>
#include <stack>
using namespace ariel;

//OrgChart Getters:
Node* OrgChart::getRootPtr() const {return this->_root;}

//OrgChart Constructor:
OrgChart::OrgChart() : _root(NULL){}
// OrgChart::OrgChart(const OrgChart& otherChart){}

//OrgChart Destructor:
OrgChart::~OrgChart(){}

//OrgChart Functions:
//This will be implemented in BFS format
Node* OrgChart::find(const std::string& node) const{
    //Check if the chart is not empty:
    if(this->getRootPtr()==NULL){
        throw std::runtime_error("OrgChart find() Error: Chart is Empty!");
    }
    std::queue<Node*> nodeQ;
    nodeQ.push(this->getRootPtr());
    while(!nodeQ.empty()){
        Node* curr = nodeQ.front();
        if(curr->getData()==node){
            return curr;
        }
        //current node is not the wanted node, adding its children:
        for(Node* child : curr->getChildrenVec()){
            nodeQ.push(child);
        }
        //removing the current node from the queue:
        nodeQ.pop();
    }
    //if reached here, node is not in the chart:
    return NULL;
}

OrgChart& OrgChart::add_root(const std::string& r){
    if(this->getRootPtr()!=NULL){
        //Chart has root, change its name:
        this->_root->setData(r);
    }
    //Root is NULL:, initialize Root Node:
    this->_root = new Node(r);
    return *this;
}

OrgChart& OrgChart::add_sub(const std::string& parent, const std::string& child){
    //Check if the parent exists:
    if(this->find(parent)==NULL){
        throw std::runtime_error("OrgChart add_sub Error: Parent not in Chart!");
    }
    //If reached here, parent in chart:
    Node* pnt = this->find(parent);
    pnt->addChild(child);
    return *this;
    
}
// Iterator OrgChart::begin() const{}
// Iterator OrgChart::end() const{}
// Iterator OrgChart::begin_level_order() const{}
// Iterator OrgChart::end_level_order() const{}
// Iterator OrgChart::begin_reverse_order() const{}
// Iterator OrgChart::reverse_order() const{}
// Iterator OrgChart::begin_preorder() const{}
// Iterator OrgChart::end_preorder() const{}

