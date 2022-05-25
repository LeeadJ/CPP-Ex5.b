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

            //Setters:
            void setData(const std::string& data);

            //Constructor:
            Node(const std::string& str);

            //Destructor:
            ~Node();

            //Functions:
            void addChild(const std::string& child);
            void printNode();
    };
}

