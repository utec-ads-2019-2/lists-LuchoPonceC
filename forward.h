#ifndef FORWARD_H
#define FORWARD_H
#define REVERSE -1
#define NORMAL 1
#include "list.h"
#include "iterators/forward_iterator.h"
#include <iostream>

template <typename T>
class ForwardList : public List<T> {
    
    public:
        ForwardList() : List<T>() {}

        T front() {
            if(this->head == nullptr){
                throw("Lista vacia");
            }
            return this->head->data;
        }

        T back() {
            Node<T> *temp = this->head;
            
      
            if(this->head==nullptr){
                throw("Lista vacia");
            }
            
            while((temp->next)!=nullptr){
                temp = temp->next;
            }
        
            return temp->data;

        }

        void push_front(T value) {
            // TODO
            Node<T> *nuevo = new Node<T>(value);
            if(this->head!=nullptr){
                nuevo->next = this->head;
            }
            this->head = nuevo;
            

        }

        void push_back(T value) {
            Node<T> *temp = this->head;
            Node<T> *nuevo = new Node<T>(value);
            if(temp == nullptr){
                this->head = nuevo;
            }
            else{
                while((temp->next)!=nullptr){
                    temp = temp->next;
                }
                temp->next = nuevo;
            }
            this->nodes++;
            


        }

        void pop_front() {
          
            if(this->head==nullptr){
                throw std::bad_alloc();
            }
            else{
                Node<T> *temp = this->head;
                if(this->head->next == nullptr){
                    this->head = nullptr;
                }
                else{
                    this->head = this->head->next;
                } 
                
                delete temp;
                this->nodes--;
                
            }
        }

        void pop_back() {

            if(this->head == nullptr){
                throw std::bad_alloc();
            }
            else{
                Node<T> *temp = this->head;

                if(this->head->next == nullptr){
                    delete temp;
                    this->head = nullptr;
                }
                else{
                    while((temp->next)->next!=nullptr){
                        temp = temp->next;
                    }
                    delete temp->next;
                    temp->next = nullptr;
                }
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
            return !(this->head);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf();
            this->nodes = 0;
            this->head = nullptr;
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
            T arr[this->nodes];
            int pos = 0;
            copy(arr,pos);
            pos--;
            paste(arr,pos,REVERSE);
           

        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {

            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            // TODO
            return ForwardIterator<T>(nullptr);
        }

        void merge(ForwardList<T> list) {
            // TODO
            for (ForwardIterator<T> iterator = list.begin(); iterator!=list.end();++iterator){
                this->push_back(*iterator);
            }

            
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

