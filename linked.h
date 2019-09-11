#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            // TODO
            if(this->head == nullptr){
                throw("Lista vacia");
            }
            return this->head->data;
        }

        T back() {
            // TODO
            if(this->head == nullptr){
                throw("Lista vacia");
            }
            return this->tail->data;
        }

        void push_front(T value) {
            // TODO
            Node<T> *nuevo = new Node<T>(value);
            if(this->head == nullptr){
                this->head = nuevo;
                this->tail = nuevo;
            }
            else{
                nuevo->next = this->head;
                this->head->prev = nuevo;
                this->head = nuevo; 
            }
            this->nodes++;
        }

        void push_back(T value) {
            // TODO
            Node<T> *nuevo = new Node<T>(value);
            if(this->head == nullptr){
                this->head = nuevo;
                this->tail = nuevo;
            }
            else{
                nuevo->prev = this->tail;
                this->tail->next = nuevo;
                this->tail = nuevo;
            }
            this->nodes++;
        }

        void pop_front() {
            if(this->head == nullptr){
                throw std::bad_alloc();
            }
            else{
                Node<T> *temp = this->head;
                if(this->head->next == nullptr){
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else{
                    (temp->next)->prev = nullptr;
                    this->head = temp->next;
                }
                delete temp;
                this->nodes--;
                
            }
            
        }

        void pop_back() {
            // TODO
            if(this->head == nullptr){
                throw std::bad_alloc();
            }
            else{
                Node<T> *temp = this->tail;
                if(this->head->next == nullptr){
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else{
                    (temp->prev)->next = nullptr;
                    this->tail = temp->prev;
                }
                delete temp;
                this->nodes--;
            }

        }

        T operator[](int index) {
             try{
                if(index<this->nodes){
                    Node<T> *temp = this->head;
                    while(index>0){
                        temp = temp->next;
                        index--;
                    }
                    return temp->data;
                }
                else{
                    throw index;
                }
            }
            catch(int index){
                std::cout<<"No puedes acceder a ese indice"<<std::endl;
            }
        }

        bool empty() {
            // TODO
            return !(this->head);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf();
            this->nodes = 0;
            this->head = nullptr;
            this->tail = nullptr;
        }

        void sort() {
            T arr[this->nodes];
            int pos = 0;
            copy(arr,pos);
            pos = 0;
            for(int i=0;i<this->nodes; i++){
                for(int j=0;j<this->nodes-i-1;j++){

                    if(arr[j]>arr[j+1]){
                        T temporal = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temporal; 
                    }
                }
            }
            paste(arr,pos,NORMAL);
            
        }
    
        void reverse() {
            

            Node<T> *rec = this->head;

            Node<T> *temp;
            this->tail = this->head;
            while(rec->next!=nullptr){
                temp = rec->prev;
                rec->prev = rec->next;
                rec->next = temp;
                rec = rec->prev;
            }
            rec->next = rec->prev;
            rec->prev = nullptr;
            this->head = rec;


        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }

        void copy(T *arr, int &pos){
            Node<T> *temp = this->head;
            while(temp!=nullptr){
                arr[pos] = temp->data;
                temp = temp->next;
                pos++;
            }
        }
        void paste(T *arr, int &pos, int type){
            Node<T> *temp = this->head;
            while(temp!=nullptr){
                temp->data = arr[pos];
                temp = temp->next;
                pos+=type;
            }
        }
};

#endif