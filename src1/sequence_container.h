#ifndef SEC
#define SEC
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include <list>
#include <iostream>
namespace s21 {

template <class T>
class list;

template <class T>
struct ListNode {
    ListNode<T> *prev;
    ListNode<T> *next;
    T data;
    ListNode() {
        prev = nullptr;
        next = nullptr;
    }
};


template <class T>
struct ListIterator 
{   
    friend class list<T>;
    // tags
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = ListNode<T>*;  // or also value_type*
    using reference         = ListNode<T>&;  // or also value_type&
    // constructors
    ListIterator() {
    }
    ListIterator(pointer ptr) {
        _node = ptr;
    }
    value_type& operator*() const { return _node -> data; }
    //pointer operator*() const { return _node }
    pointer operator->() { return _node; }

    // Prefix increment
    ListIterator& operator++() { 
        _node = _node -> next;
        return *this;
    }

    // Postfix increment
    ListIterator operator++(int) { ListIterator tmp = *this; ++(*this); return tmp; }
    ListIterator& operator--() { _node = _node -> prev; return *this; }  
    ListIterator  operator--(int) { ListIterator tmp = *this; --(*this); return tmp; }
    friend bool operator== (const ListIterator& a, const ListIterator& b) { return a._node == b._node; };
    friend bool operator!= (const ListIterator& a, const ListIterator& b) { return a._node != b._node; };

    private:
        pointer _node;
};

template <class T>
class list
{
    using value_type        = T;
    using reference         = T&;  // or also value_type&
    using pointer           = T*;
    using const_reference   = const T&;
    using iterator          = ListIterator<T>;
    using const_iterator    = ListIterator<T>;
    using size_type         = size_t;
    
    // private members:
    ListNode<value_type> *_front;
    ListNode<value_type> *_back;

    public:
        list()
        {
            _front = _back = new ListNode<value_type>;
        }
        ~list()
        {
            
        }
        list(size_type n)
        {
        
            
        }
        iterator begin()
        {
            return iterator(_front);
        }

        iterator end()
        {
            return iterator(_back);
        }

        void erase(iterator pos) {
            //pos can be _front. In this case: ++pos -> prev = _front -> prev; delete _front;
            if (pos._node != _back) {pos -> next -> prev = pos -> prev;}
            if (pos != _front) {
                pos -> prev -> next = pos -> next;
            } else {_front = pos -> next;}
            delete pos._node;
            //pos can be neither _back or _front ++pos -> prev = _front -> prev; --pos -> next = po -> next; delete pos;
        }
        iterator insert(iterator pos, const_reference value) {
            ListNode<value_type> *node = new ListNode<value_type>;
            node -> data = value;
            node -> next = pos._node;
            
            if (pos._node == _front) {
                pos -> prev = node;
                _front = node;
            } else if (pos._node == _back) {
                pos -> prev -> next = node;
                pos -> prev = node;
            }
            return iterator(node);
        }
};
}
#endif