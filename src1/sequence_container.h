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
    using const_iterator    = ListIterator<const T>;
    using size_type         = unsigned int;
    
    // private members:
    ListNode<value_type> *_front;
    ListNode<value_type> *_back;
    size_type _size;
    public:
        list() {
            _front = _back = new ListNode<value_type>;
            _size = 0;
        }
        ~list() {
            this -> clear();
            delete _back;
        }
        list(size_type n) {
            _front = _back = new ListNode<value_type>;
            _size = 0;
            while (n--) {
                value_type node = value_type();
                this -> push_back(node);
            }
        }
        list(std::initializer_list<value_type> const &items) {
            _front = _back = new ListNode<value_type>;
            _size = 0;
            for (auto i:items) {
                this -> push_back(i);
            }
        }

        list(const list &l) {
            _front = _back = new ListNode<value_type>;
            _size = 0;
            for (auto i:l) {
                this -> push_back(i);
            }
        }
        list(list&& l) noexcept: _front(std::move(l.end())), _front(std::move(l.begin())), _size(std::move(l.size())) {
            
        }
        list& operator=(list &&l) {
            return *this;
        }
        iterator begin() {
            return iterator(_front);
        }
        iterator begin() const{
            return iterator(_front);
        }
        iterator end(){
            return iterator(_back);
        }
        iterator end() const{
            return iterator(_back);
        }


        // -------------------------------------------- CAPACITY --------------------------------------------------------
        bool empty() {
            return !(bool)_size;
        }
        size_type size() {
            return _size;
        }
        size_type max_size() {
            return 1000000000;
        }

        // -------------------------------------------- MODIFIERS --------------------------------------------------------
        void clear() {
            iterator i = this -> begin();
            while (i._node != _back) {++i; delete i -> prev;}
            _front = _back;
        }
        void erase(iterator pos) {
            _size--;
            //pos can be _front. In this case: ++pos -> prev = _front -> prev; delete _front;
            if (pos._node != _back) {pos -> next -> prev = pos -> prev;}
            if (pos != _front) {
                pos -> prev -> next = pos -> next;
            } else {_front = pos -> next;}
            delete pos._node;
            //pos can be neither _back or _front ++pos -> prev = _front -> prev; --pos -> next = po -> next; delete pos;
        }
        iterator insert(iterator pos, const_reference value) {
            ++_size;
            ListNode<value_type> *node = new ListNode<value_type>;
            node -> data = value;
            node -> next = pos._node;
            
            if (pos._node == _front) {
                _front = node;
            } else {
                pos -> prev -> next = node;
                node -> prev = pos -> prev;
            }
            pos -> prev = node;
            return iterator(node);
        }
        void push_back(const_reference value) {
            this -> insert(iterator(_back), value);
        }
        void push_front(const_reference value) {
            this -> insert(iterator(_front), value);
        }
        void pop_back() {
            this -> erase(--iterator(_back));
        }
        void pop_front() {
            this -> erase(iterator(_front));
        }
        void swap(list& other) {
            ListNode<T>* tmp_front = _front;
            ListNode<T>* tmp_back = _back;
            size_type tmp_size = _size;
        }
};
}
#endif