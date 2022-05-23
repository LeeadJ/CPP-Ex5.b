#include<iostream>
#include<string>

namespace ariel{
    template<class T>
    class Node
    {
    private:
        Node<T>* _next;
        Node<T>* _prev;
        T* _dataPtr;
    public:
        //Constructor:
        Node(const T& obj) :_next(NULL), _prev(NULL){
            this->_dataPtr = new T(obj);
        }
        ~Node(){}

        //Getters:
        Node<T>* getNext() const {return this->_next;}
        Node<T>* getPrev() const {return this->_prev;}
        T* getDataPtr() const {return this->_dataPtr;}

        //Setters:
        void setNext(Node<T>* next) {this->_next=next;}
        void setPrev(Node<T>* prev) {this->_prev=prev;}
        void setData(const T& obj){this->_dataPtr = new T(obj);}

    };
}

