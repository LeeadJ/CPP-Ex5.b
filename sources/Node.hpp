#include<iostream>
#include<string>
#include<vector>

namespace ariel{
    class Node{
        private:
            std::string* _dataPtr;
            std::vector<Node*> _children;
        
        public:
            //Getters:
            std::string* getDataPtr() const {return this->_dataPtr;}
            std::vector<Node*>& getChildrenVec() {return this->_children;}

            //Setters:
            void setData(const std::string& str) {*(this->_dataPtr)=str;}

            //Constructor:
            Node(const std::string& str) {this->setData(str);}
    };
}

