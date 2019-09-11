#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node<T>(T data){
    	this->data = data;
    	next = nullptr;
    	prev = nullptr;
    }
    Node<T>(){
    	next = nullptr;
    	prev = nullptr;
    }

    void killSelf() {
    	
        if(next){
        	next->killSelf();
        }

        delete this;

    }
};

#endif