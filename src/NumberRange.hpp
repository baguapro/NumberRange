
#include <cstddef>

/* Author: Adrian Phung
 * Slight improvement on the Range class in: https://en.cppreference.com/w/cpp/iterator/iterator
 * Designed so that the range can be iniialised by a runtime value
 * Includes reverse iterators 
 *
 * HERE BE DRAGONS:
 * The library does no bounds checking it is the responsibility the client to make sure given 
 * values don’t overflow when iterating, this is espically true when the iteration steps are 
 * greater than one.
 *
 * Negitive ranges is currently not supported, it is the responsibility of the client to 
 * make sure ranges construction values do not flowing into negitive states during iteration
*/

namespace NumberRange
{

// Actual iterator class where most of the work is done
template<typename T>
class NumRangeIterator
{
public:
    // Iterator traits, previously from std::iterator.
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::bidirectional_iterator_tag;

    explicit NumRangeIterator(T NumRange,unsigned int step = 1)
        :num_range{NumRange}
        ,step_(step)
    { }

    // Dereferencable.
    reference operator*() const
    {
        return num_range;   
    }
    // Pre- and post-incrementable.
    NumRangeIterator& operator++()
    {
        num_range += step_;
        return *this;
    }
    
    NumRangeIterator operator++(int)
    {
        NumRangeIterator tmp = *this;
        num_range += step_;
        return tmp;
    }

    // Pre- and post-decrementable.
    NumRangeIterator& operator--()
    {
        num_range -= step_;
        return *this;
    }
    
    NumRangeIterator operator--(int)
    {
        NumRangeIterator tmp = *this;
        num_range -= step_;
        return tmp;
    }

    // Equality / inequality.
    bool operator==(const NumRangeIterator& rhs)
    {
        return (num_range >= rhs.num_range);   
    }
    
    bool operator!=(const NumRangeIterator& rhs)
    {
        return !(*this == rhs);   
    }
    
private:
    mutable T num_range;
    unsigned int step_;
};

// Reverse iterator class
template<typename T>
class NumRangeReverseItrator
{
public:
    // Iterator traits, previously from std::iterator.
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::bidirectional_iterator_tag;

    // Default constructible.
    NumRangeReverseItrator() = default;
    explicit NumRangeReverseItrator(T NumRange,unsigned int step = 1)
        :num_range{NumRange}
        ,step_(step)
    { }

    // Dereferencable.
    reference operator*() const
    {
        return num_range;   
    }
    
    // Pre- and post-incrementable.
    NumRangeReverseItrator& operator++()
    {
        num_range -= step_;
        return *this;
    }
    
    NumRangeReverseItrator operator++(int)
    {
        NumRangeReverseItrator tmp = *this;
        num_range -= step_;
        return tmp;
    }
    // Pre- and post-decrementable.
    NumRangeReverseItrator& operator--()
    {
        num_range += step_;
        return *this;
    }
    
    NumRangeReverseItrator operator--(int)
    {
        NumRangeReverseItrator tmp = *this;
        num_range += step_;
        return tmp;
    }

    // Equality / inequality.
    bool operator==(const NumRangeReverseItrator& rhs)
    {
        return (num_range < rhs.num_range);   
    }
    
    bool operator!=(const NumRangeReverseItrator& rhs)
    {
        return !(*this == rhs);   
    }
    
private:
    mutable T num_range;
    unsigned int step_;
};

// Provides the inerface to a number range that is compatable with STL algorithms
template<typename T = unsigned long long>
class NumberRange
{
public:
    using iterator = NumRangeIterator<T>;
    using reverse_iterator = NumRangeReverseItrator<T>;
        
    NumberRange(T range, T start = 0, unsigned int step = 1)
        :range_(range)
        ,start_(start)
        ,step_(step)
        { }
    
    iterator begin() const { return iterator(start_, step_); }
    iterator end() const { return iterator(range_); }
    
    reverse_iterator rbegin() const { return reverse_iterator(range_-1, step_); }
    reverse_iterator rend() const { return reverse_iterator(start_); }
    
private:
    T range_;
    T start_;
    unsigned int step_;
};

// Wrapper that provides an interface for using reverse iterators in range for loops
template<typename T>
struct ReverseIterator
{
    T &type;
    ReverseIterator(T &t) : type(t) { }
    
    typename T::reverse_iterator begin() { return type.rbegin(); }
    typename T::reverse_iterator end() { return type.rend(); }
};

}
