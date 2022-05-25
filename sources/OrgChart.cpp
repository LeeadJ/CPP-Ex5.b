#include "OrgChart.hpp"
#include <queue>
#include <stack>
using namespace ariel;

//OrgChart Getters:
Node* OrgChart::getRootPtr() const {return this->_root;}

//Iterator Getters:
Node* OrgChart::Iterator::getCurrNodePtr() const{return this->_currNodePtr;}

std::vector<Node*>& OrgChart::Iterator::getIterNodeVec() {return this->_iterNodesVec;}

//Iterator Setter:
void OrgChart::Iterator::setIterNodeVec(const std::vector<Node*>& other){
    std::vector<Node*> newVec;
    for(Node* node : other){
        newVec.push_back(node);
    }
    this->_iterNodesVec=newVec;
}
//Iterator Constructor:
OrgChart::Iterator::Iterator() : _currNodePtr(NULL){}

OrgChart::Iterator::Iterator(Node* node, unsigned int type){
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
// std::string& OrgChart::Iterator::operator * () const{}
// std::string* OrgChart::Iterator::operator -> () const{}
// bool OrgChart::Iterator::operator == (const Iterator& other) const{}
// bool OrgChart::Iterator::operator != (const Iterator& other) const{}
// Iterator& OrgChart::Iterator::operator ++ (){}
// Iterator& OrgChart::Iterator::operator ++ (int){}/////???
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
    //already checked if node is NULL in Iterator Constructor:
    std::queue<Node*> nodeQ;
    nodeQ.push(node);
    while(!nodeQ.empty()){
        Node* curr = nodeQ.front();
        //Inserting the top of the queue at the beggining of the vector, thus reversing its order: 
        this->getIterNodeVec().insert(this->getIterNodeVec().begin(), curr);
        for(int i = curr->getChildrenVec().size() -1; i>=0; i--){
            nodeQ.push(curr->getChildrenVec().at(i));
        }
        nodeQ.pop();
    }
}
void OrgChart::Iterator::init_DFS(Node* node){
    //already checked if node is NULL in Iterator Constructor:
    std::stack<Node*> nodeS;
    nodeS.push(node);
    while(!nodeS.empty()){
        Node* curr = nodeS.top();
        this->getIterNodeVec().push_back(curr);
        nodeS.pop();
        for(int i=curr->getChildrenVec().size()-1; i>=0; i--){
            nodeS.push(curr->getChildrenVec().at(i));
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
    if(this->getRootPtr()!=NULL){
        //Chart has root, change its name:
        this->_root->setData(r);
    }
    //Root is NULL:, initialize Root Node:
    this->_root = new Node(r);
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
    // Iterator it;
    return Iterator();
}
// Iterator OrgChart::begin_level_order() const{}
// Iterator OrgChart::end_level_order() const{}
// Iterator OrgChart::begin_reverse_order() const{}
// Iterator OrgChart::reverse_order() const{}
// Iterator OrgChart::begin_preorder() const{}
// Iterator OrgChart::end_preorder() const{}

 //OrgChart Operators:
// std::ostream& ariel::operator << (std::ostream& out, OrgChart& chart){

// }

