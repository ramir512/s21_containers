#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include <list>
namespace s21 {

template <class T>
struct Iterator 
{
    // tags
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;  // or also value_type*
    using reference         = T&;  // or also value_type&
    

    // constructors
    Iterator(pointer ptr) : m_ptr(ptr) {}


    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }

    // Prefix increment
    Iterator& operator++() { m_ptr = m_ptr -> _next; return *this; }  

    // Postfix increment
    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }


    Iterator& operator--() { m_ptr = m_ptr -> _prev; return *this; }  
    Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }



    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
};

template <class T>
class list
{
    using value_type        = T;
    using reference         = T&;  // or also value_type&
    using pointer           = T*;
    using const_reference   = const T&;
    using iterator          = Iterator<T>;
    using const_iterator    = Iterator<T>;
    using size_type         = size_t;
    
    // private members:
    pointer _last;
    pointer _first;
    pointer _next;
    pointer _prev;

    pointer _elem;
    public:
        list()
        {
            _last = _first = _next = _prev = nullptr;
        }
        list(size_type n)
        {
            
        }
        begin() 
        {
            return Iterator(_first);
        }
        end()
        {
            return Iterator(_last);
        }

};
}
std::list<int> nums = {1, 2, 3, 4};
std::list<int>::iterator a = nums.end();
// 1. Make iterator and const iterator internal classes