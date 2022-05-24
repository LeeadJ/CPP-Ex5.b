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
                    Node* _currPtr;
                public:
                    //Iterator Getters:
                    Node* getCurrPtr() const;

                    //Iterator Constructor:
                    Iterator();
                    //Iterator Functions:
                    
                    //Iterator Operators:
                    std::string& operator * () const;
                    std::string* operator -> () const;
                    bool operator == (const Iterator& other) const;
                    bool operator != (const Iterator& other) const;
                    Iterator& operator ++ ();
                    Iterator operator ++ (int);
            };

            //OrgChart Constructor:
            OrgChart();
            OrgChart(const OrgChart& otherChart);
            
            //OrgChart Destructor:
            ~OrgChart();

            //OrgChart Functions:
            void add_root(const std::string& root);
            void add_sub(const std::string& parent, const std::string& child);
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