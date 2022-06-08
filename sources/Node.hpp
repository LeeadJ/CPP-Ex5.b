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
            std::string& getData() ;
            std::vector<Node*>& getChildrenVec();

            //Constructor:
            Node(const std::string& str);

            //Functions:
            void addChild(const std::string& child);
            void printNode();
    };
}

