#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            // TODO
            this->current = other.current;
            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            // TODO
            return this->current != other.current;
        }

        BidirectionalIterator<T> operator++() {
            // TODO
            if(this->current){
                this->current = this->current->next;
            }
            return *this;
        }

        BidirectionalIterator<T> operator--() {
            // TODO
            if(this->current){
                this->current = this->current->prev;

            }
            return *this;
        }

        T operator*() {
            // TODO
            // Falta controlar el caso vacío
            return this->current->data;
        }
};

#endif