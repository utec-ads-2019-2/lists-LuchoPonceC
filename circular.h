
#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            // TODO
            // Y caso vacío?
            return this->head->data;
        }

        T back() {
            // TODO
            // Y caso vacío?
            return this->head->prev->data;
        }

        void push_front(T value) {
            // TODO
            Node<T> *nuevo = new Node<T>(value);
            if(this->head == nullptr){
                this->head = nuevo;
                this->head->prev = nuevo;
            }
            else{
                nuevo->next = this->head;
                nuevo->prev = this->head->prev;
                this->head->prev = nuevo;
                (this->head->prev)->next = nuevo;
                this->head = nuevo; 
            }
            this->nodes++;
        }

        void push_back(T value) {
            // TODO
             Node<T> *nuevo = new Node<T>(value);
            if(this->head == nullptr){
                this->head = nuevo;
                this->head->prev = nuevo;

            }
            else{
                nuevo->prev = this->head->prev;
                nuevo->next = this->head;
                (this->head->prev)->next = nuevo;
                this->head->prev = nuevo;                
                

            }
            this->nodes++;
        }

        void pop_front() {
            // TODO
            // No es 
            if(this->head == nullptr){
                throw std::bad_alloc();
            }
            else{
                Node<T> *temp = this->head;
                if(this->head==this->head->prev){
                    this->head = nullptr;
                    
                }
                else{
                    (temp->next)->prev = this->head->prev;
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
                Node<T> *temp = this->head->prev;
                if(this->head==this->head->prev){
                    this->head = nullptr;
                
                }
                else{
                    (temp->prev)->next = this->head;
                    this->head->prev = temp->prev;
                }
                delete temp;
                this->nodes--;
            }
        }

        T operator[](int index) {
            // caso negativo? 
            // TODO
            index = index%this->nodes;
            Node<T> *temp = this->head;
            while(index>0){
                temp = temp->next;
                index--;
            }
            return temp->data;
            
        }

        bool empty() {
            // TODO
            return !(this->head);
        }

        int size() {
            // TODO
            return this->nodes;
        }

        void clear() {
            // TODO

             Node<T> *temp = this->head;
            Node<T> *rec = this->head;
            for(int i=0;i<this->nodes;i++){
                rec = rec->next;
                delete temp;
                temp = rec;
            }
            this->nodes = 0;
            this->head = nullptr;
            
        }

        void sort() {
            // TODO
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
            // TODO
            Node<T> *rec = this->head;

            Node<T> *temp;
            this->tail = this->head;
            while(rec->next!=this->head){
                temp = rec->prev;
                rec->prev = rec->next;
                rec->next = temp;
                rec = rec->prev;
            }
            rec->next = rec->prev;
            rec->prev = this->tail;
            this->head = rec;
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            // TODO
            // Cómo manejarías el caso de iterar con while?
            return BidirectionalIterator<T>(this->head->prev);
        }

        void merge(CircularLinkedList<T> list) {
            // TODO
            for (int i=0 ; i<list.size();i++){
                this->push_back(list[i]);
            }
        }

        void copy(T *arr, int &pos){
            Node<T> *temp = this->head;
            for(int i=0; i<this->nodes;i++){

                arr[pos] = temp->data;
                temp = temp->next;
                pos++;
            }
        }
        void paste(T *arr, int &pos, int type){
            Node<T> *temp = this->head;
            for(int i=0; i<this->nodes;i++){
                temp->data = arr[pos];
                temp = temp->next;
                pos+=type;
            }
        }
};

#endif