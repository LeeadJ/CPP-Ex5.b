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

            //Setters:
            void setData(const std::string& str);

            //Constructor:
            Node(const std::string& str);

            //Functions:
            void printNode();
    };
}

