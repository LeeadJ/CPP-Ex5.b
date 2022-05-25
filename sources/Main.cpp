#include "Node.hpp"
#include "OrgChart.hpp"
#include<queue>
using namespace std;
using namespace ariel;
int main(){
    // Node a{"CEO"};
    // Node* b = new Node{"Leead"};
    // Node* c = new Node{"Maayan"};
    // Node* d = new Node{"Lavi"};
    // a.printNode();
    // a.getChildrenVec().push_back(b);
    // a.getChildrenVec().push_back(c);
    // a.getChildrenVec().push_back(d);
    // a.printNode();
    // if(!NULL){
    //     cout<<"HI"<<endl;
    // }

    OrgChart o;
    o.add_root("CEO");
    // cout<<"HI"<<endl;
    o.add_sub("CEO", "CTO");
    o.add_sub("CEO", "CFO");
    o.add_sub("CEO", "COO");
    o.add_sub("CTO", "VP_SW");
    o.add_sub("COO", "VP_BI");
    // o.add_sub("2", "2.2");
    // o.add_sub("4", "4.1");
    // o.add_sub("4.1", "4.1.1");

    //cout<<"BFS TEST"<<endl;
    // queue<Node*> nodeQ;
    // nodeQ.push(o.getRootPtr());
    // while(!nodeQ.empty()){
    //     Node* temp = nodeQ.front();
    //     temp->printNode();
    //     cout<<""<<endl;
    //     for(Node* child : temp->getChildrenVec()){
    //         nodeQ.push(child);
    //     }
    //     nodeQ.pop();
    // }
    
    // OrgChart::Iterator it{o.getRootPtr(), 2};
    // cout<<"HI"<<endl;
    // for(Node* node : it.getIterNodeVec()){
    //     node->printNode();
    //     cout<<""<<endl;
    // }
    // for(Node* n : it.getIterNodeVec()){
    //     cout<<"("<<n->getData()<<") <--> ";
    // }
    // cout<<"||"<<endl;

    // vector<int> vec = {1,2,3};
    // vec.insert(vec.begin(),9);
    // for(int i : vec){
    //     cout<<i<<endl;
    // }

    OrgChart::Iterator it = o.begin();
    OrgChart::Iterator it2 = o.end();
    bool a = it2.getCurrNodePtr()==NULL;
    // bool b = it == it2;
    // cout<<it.getCurrNodePtr()->getData()<<endl;
    // cout<<a<<endl;
    while(it.getCurrNodePtr() != NULL){
        cout<<it.getCurrNodePtr()->getData()<<endl;
        ++it;
    }
    
    // while(it != o.end()){
    //     cout<<"HI"<<endl;
    //     cout<<"("<<it.getCurrNodePtr()->getData()<<") <--> ";
    // }
    cout<<"||"<<endl;
    
    
    return 0;
}