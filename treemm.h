#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

#include <list>
#include <iostream>

template <typename KeyType, typename ValueType>
class TreeMultimap
{
private:
    class Node;
    
  public:
    class Iterator
    {
      public:
        Iterator()
            :m_isValid(false) {}
        
        Iterator(typename std::list<ValueType>::iterator it, typename std::list<ValueType>::iterator end)
            :m_isValid(true), m_iterator(it), m_end(end)
        {}

        ValueType& get_value() const
        {
            return *m_iterator;
        }

        bool is_valid() const
        {
            return m_isValid;
        }

        void advance()
        {
            m_iterator++;
            if (m_iterator == m_end)
                m_isValid = false;
        }

      private:
        typename std::list<ValueType>::iterator m_iterator;
        typename std::list<ValueType>::iterator m_end;
        bool m_isValid;
    };

    TreeMultimap()
    {
        // Replace this line with correct code.
    }

    ~TreeMultimap()
    {
        delete m_head;
    }

    void insert(const KeyType& key, const ValueType& value)
    {
        
        // if we don't have a head, create one
        if (!m_head) {
            m_head = new Node(key, value);
            return;
        }
        
        // if we already have the key in our system, append the new value
        Node* keyNode = find(key, m_head);
        if (keyNode) {
            keyNode->append(value);
            return;
        }
        
        insertNew(key, value, m_head);
        
    }

    Iterator find(const KeyType& key) const
    {
        Node* n = find(key, m_head);
        if (!n) return Iterator();
        
        return Iterator(n->values.begin(), n->values.end());
    }

  private:
    class Node {
    public:
        Node(KeyType key, ValueType value) {
            this->key = key;
            values.push_back(value);
        }
        void append(ValueType value) {
            values.push_back(value);
        }
        KeyType key;
        std::list<ValueType> values;
        Node* less = nullptr;
        Node* greater = nullptr;
    };
    Node* m_head=nullptr;
    Node* find(const KeyType& key, Node* current) const {
        // MAKE THIS MORE EFFICIENT !!
        
        // base case
        if (!current) return nullptr;
        
        // if we found the correct value, return iterator to value
        if (current->key == key) return current;
        
        // recursive step
        Node* less = find(key, current->less);
        if (less) return less;
        Node* greater = find(key, current->greater);
        if (greater) return greater;
        
        return nullptr;
    }
    void insertNew(const KeyType& key, const ValueType& value, Node* current) {
        if (key < current->key) {
            if (!current->less) {
                current->less = new Node(key, value);
                return;
            }
            insertNew(key, value, current->less);
        } else {
            if (!current->greater) {
                current->greater = new Node(key, value);
                return;
            }
            insertNew(key, value, current->greater);
        }
    }
};

#endif // TREEMULTIMAP_INCLUDED
