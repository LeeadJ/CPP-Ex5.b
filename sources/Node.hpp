#pragma once
#include<iostream>
#include<string>
#include<vector>

namespace ariel{
    class Node{
        private:
            std::string _data;
            std::vector<Node*> _children;
        
        public:
            //Getters:
            std::string getData() const;
            std::vector<Node*>& getChildrenVec();

            //Constructor:
            Node(const std::string& str);

            //Destructor:
            ~Node();

            //Functions:
            void printNode();
    };
}

