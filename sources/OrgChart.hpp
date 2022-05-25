#pragma once
#include "Node.hpp"


namespace ariel{
    class OrgChart{
        private:
            Node* _root;
        
        public:
            //OrgChart Getters:
            Node* getRootPtr() const;

            class Iterator{
                private:
                    Node* _currNodePtr;
                    std::vector<Node*> _iterNodesVec;
                public:
                    //Iterator Getters:
                    Node* getCurrNodePtr() const;
                    std::vector<Node*>& getIterNodeVec();

                    //Iterator Setter:
                    void setIterNodeVec(const std::vector<Node*>& other);

                    //Iterator Constructor:
                    Iterator();
                    Iterator(Node* node, int type); // 0=level(==BFS), 1=reverse(==reverse-BFS), 2=pre(==DFS)
                    
                    //Iterator Operators:
                    std::string operator * () const;
                    std::string* operator -> () const;
                    bool operator == (const Iterator& other) const;
                    bool operator != (const Iterator& other) const;
                    Iterator& operator ++ ();
                    Iterator operator ++ (int);
                    //These functions will load the iteration vector in the appropriate fashion.
                    void init_BFS(Node* node);
                    void init_reBFS(Node* node);
                    void init_DFS(Node* node);
                    

            };

            //OrgChart Constructor:
            OrgChart();
               
            //OrgChart Destructor:
            ~OrgChart();

            //OrgChart Functions:
            Node* find(const std::string& node) const;
            OrgChart& add_root(const std::string& r);
            OrgChart& add_sub(const std::string& parent, const std::string& child);
            Iterator begin() const;
            Iterator end() const;
            Iterator begin_level_order() const;
            Iterator end_level_order() const;
            Iterator begin_reverse_order() const;
            Iterator reverse_order() const;
            Iterator begin_preorder() const;
            Iterator end_preorder() const;

            //OrgChart Operators:
            friend std::ostream& operator << (std::ostream& out, OrgChart& chart);
    };
}