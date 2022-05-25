#include "OrgChart.hpp"
#include <queue>
#include <stack>
#include <algorithm>
#include<vector>
using namespace ariel;

//OrgChart Getters:
Node* OrgChart::getRootPtr() const {return this->_root;}

//Iterator Getters:
Node* OrgChart::Iterator::getCurrNodePtr() const {return this->_currNodePtr;}

std::vector<Node*>& OrgChart::Iterator::getIterNodeVec() {return this->_iterNodesVec;}

//Iterator Setter:
void OrgChart::Iterator::setIterNodeVec(const std::vector<Node*>& other){
    std::vector<Node*> newVec;
    newVec.reserve(other.size());
    for(Node* node : other){
        newVec.push_back(node);
    }
    this->_iterNodesVec=newVec;
}
//Iterator Constructor:
OrgChart::Iterator::Iterator() : _currNodePtr(NULL){}

OrgChart::Iterator::Iterator(Node* node, int type){
    if(node==NULL){
        this->_currNodePtr=NULL;
        return;
    }
    // 0=level(==BFS), 1=reverse(==reverse-BFS), 2=pre(==DFS)
    switch(type){
        case 0:
            init_BFS(node);
            break;
        case 1:
            init_reBFS(node);
            break;
        case 2:
            init_DFS(node);
            break;
        default:
            throw std::runtime_error("Iterator Constructor Error: Type entered not in range.");
    }
    //Setting the iterator pointer to the first node in its nodeVec:
    this->_currNodePtr=this->getIterNodeVec().front();
}

//Iterator Operators:
std::string OrgChart::Iterator::operator * () const {
    return this->getCurrNodePtr()->getData();
}

std::string* OrgChart::Iterator::operator -> () const{
    return &(this->getCurrNodePtr()->getData());
}

bool OrgChart::Iterator::operator == (const Iterator& other) const{
    return this->getCurrNodePtr() == other.getCurrNodePtr();
}
bool OrgChart::Iterator::operator != (const Iterator& other) const{
    return  !(*this==other);
}
OrgChart::Iterator& OrgChart::Iterator::operator ++ (){ //Prefix(++var)
    if(this->getIterNodeVec().size()==1){
        this->_currNodePtr=NULL;
    }
    else{
        std::vector<Node*>::iterator it = std::find(this->getIterNodeVec().begin(), this->getIterNodeVec().end(), this->getCurrNodePtr());
        int index = std::distance(this->getIterNodeVec().begin(), it);
        //Check if the index of the currNodePtr is pointing to the last element in the vector. If so, can't increment:
        if(index == this->getIterNodeVec().size()-1){
            // throw std::runtime_error("Iterator Operator ++ Error: Out of Range Error!");
            this->_currNodePtr=NULL;
        }
        else{
            this->_currNodePtr=this->getIterNodeVec().at((unsigned long)index+1);
        }
    }
    return *this;
}
OrgChart::Iterator OrgChart::Iterator::operator ++ (int){
    Iterator it = *this;
    ++*this;
    return it;
}


//These functions will load the iteration vector in the appropriate fashion.
void OrgChart::Iterator::init_BFS(Node* node){
    //already checked if node is NULL in Iterator Constructor:
    std::queue<Node*> nodeQ;
    nodeQ.push(node);
    //BFS algo:
    while(!nodeQ.empty()){
        Node* curr = nodeQ.front();
        this->getIterNodeVec().push_back(curr);
        for(Node* child : curr->getChildrenVec()){
            nodeQ.push(child);
        }
        nodeQ.pop();
    }
}

void OrgChart::Iterator::init_reBFS(Node* node){
    // //already checked if node is NULL in Iterator Constructor:
    std::queue<Node*> nodeQ;
    nodeQ.push(node);
    while(!nodeQ.empty()){
        Node* curr = nodeQ.front();
        //Inserting the top of the queue at the beggining of the vector, thus reversing its order: 
        this->getIterNodeVec().insert(this->getIterNodeVec().begin(), curr);
    //     // for(int i = curr->getChildrenVec().size() -1; i>=0; i--){
    //     //     nodeQ.push(curr->getChildrenVec().at((unsigned int)i));
    //     // }
    //     // int vecSize = curr->getChildrenVec().size();
        for(int i=0; i<curr->getChildrenVec().size(); i++){
            nodeQ.push(curr->getChildrenVec().at(curr->getChildrenVec().size()-1-(unsigned long)i));
        }
        nodeQ.pop();
    }
    // std::queue<Node*> nodeQ;
    // std::stack<Node*> nodeS;
    // nodeQ.push(node);
    // Node* curr = node;
    // while(!nodeQ.empty()){
    //     nodeS.push(curr);
    //     for(unsigned int i=0; i<curr->getChildrenVec().size(); i++){
    //         nodeQ.push(curr->getChildrenVec().at(curr->getChildrenVec().size()-i-1));
    //     }
    //     nodeQ.pop();
    //     curr = nodeQ.front();
    // }
    // while(!nodeS.empty()){
    //     this->getIterNodeVec().push_back(nodeS.top());
    //     nodeS.pop();
    // }
}
void OrgChart::Iterator::init_DFS(Node* node){
    // //already checked if node is NULL in Iterator Constructor:
    std::stack<Node*> nodeS;
    nodeS.push(node);
    while(!nodeS.empty()){
        Node* curr = nodeS.top();
        this->getIterNodeVec().push_back(curr);
        nodeS.pop();
    //     // for(int i =curr->getChildrenVec().size()-1; i>=0; i--){
    //     //     nodeS.push(curr->getChildrenVec().at((unsigned int)i));
    //     // }
        for(int i=0; i<curr->getChildrenVec().size(); i++){
            nodeS.push(curr->getChildrenVec().at(curr->getChildrenVec().size()-1-(unsigned long)i));
        }
    }
}



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
    if(this->_root==NULL){
        this->_root = new Node(r);
    }
    else{
        this->_root->getData() = r;
    }
    return *this;
}

OrgChart& OrgChart::add_sub(const std::string& parent, const std::string& child){
    //Check it the chart is not empty:
    if(this->getRootPtr()==NULL){
        throw std::runtime_error("OrgChart add_sub Error: The Chart is empty!");
    }
    //Check if the parent exists:
    if(this->find(parent)==NULL){
        throw std::runtime_error("OrgChart add_sub Error: Parent not in Chart!");
    }
    //If reached here, parent in chart:
    Node* pnt = this->find(parent);
    pnt->addChild(child);
    return *this;
    
}
OrgChart::Iterator OrgChart::begin() const{
    //Check it the chart is not empty:
    if(this->getRootPtr()==NULL){
        throw std::runtime_error("OrgChart add_sub Error: The Chart is empty!");
    }
    return Iterator{this->getRootPtr(), 0};
}

OrgChart::Iterator OrgChart::end() const{
    //Check it the chart is not empty:
    if(this->getRootPtr()==NULL){
        throw std::runtime_error("OrgChart add_sub Error: The Chart is empty!");
    }
    //Initializing a NULL iterator:
    return Iterator{};
}

//Similar to begin() and end() so no need to re-implement:
OrgChart::Iterator OrgChart::begin_level_order() const {return this->begin();}
OrgChart::Iterator OrgChart::end_level_order() const {return this->end();}

OrgChart::Iterator OrgChart::begin_reverse_order() const{
    //Check it the chart is not empty:
    if(this->getRootPtr()==NULL){
        throw std::runtime_error("OrgChart add_sub Error: The Chart is empty!");
    }
    Iterator it{this->getRootPtr(), 1};
    return it;
}
OrgChart::Iterator OrgChart::reverse_order() const{ return this->end();}


OrgChart::Iterator OrgChart::begin_preorder() const{
    //Check it the chart is not empty:
    if(this->getRootPtr()==NULL){
        throw std::runtime_error("OrgChart add_sub Error: The Chart is empty!");
    }
    return Iterator{this->getRootPtr(), 2};
}
OrgChart::Iterator OrgChart::end_preorder() const{return this->end();}

 //OrgChart Operators:
std::ostream& ariel::operator << (std::ostream& out, OrgChart& chart){
    if(chart.getRootPtr()==NULL){return out;}
    for(auto it = chart.begin_level_order(); it != chart.end_level_order(); it++){
        out <<"("<<it.getCurrNodePtr()->getData() << ") <--> ";
    }
    out << "||" << std::endl;
    return out;
      
}

