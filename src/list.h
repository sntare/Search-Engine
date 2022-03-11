//
// Created by Miles Friedman on 10/5/21.testy
//

#ifndef INC_21F_PA02_STV_AND_MILES_LIST_H
#define INC_21F_PA02_STV_AND_MILES_LIST_H
#include <iterator>
#include <iostream>

using std::cout;
using std::endl;
namespace SAM {

    template<class T>
    class list {

        struct node {
            T data;
            node *next;
            node *prev = nullptr;
        };

    private:
        node *tail;
        node *head;
    public:
        list() {
            head = nullptr;
            tail = nullptr;
        }

        class LinkedListItr : public std::iterator<std::forward_iterator_tag, T> {
        protected:
            node *current;
        public:
            LinkedListItr() {
                current = nullptr;
            }

            LinkedListItr(node *node) {
                current = node;
            }

             T &operator*() {
                assert(current != nullptr);
                return current->data;
            }

            LinkedListItr operator++() {
                assert(current != nullptr);
                current = current->next;
                return *this;
            }

            LinkedListItr operator--() {
                assert (current != nullptr);
                current = current->prev;
                return *this;
            }

            bool operator==(const LinkedListItr right) {
                if (right.current == nullptr) {
                    if (current == nullptr) {
                        return true;
                    } else {
                        return false;
                    }
                }
                if (current == nullptr) return false;
                return (current->data == right.current->data);
            }

            bool operator!=(const LinkedListItr right) {
                if (right.current == nullptr) {
                    if (current == nullptr) {
                        return false;
                    } else {
                        return true;
                    }
                }
                if (current == nullptr) return true;
                return !(this == right);
            }
        };

        using iterator = LinkedListItr;


        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator();
        }

        void add_node(T newNode) {
            node *temp = new node;
            temp->data = newNode;
            temp->next = nullptr;
            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail->next->prev = tail;
                tail = tail->next;
            }
        }

        void print() {
            node *temp;
            temp = head;
            while (temp != nullptr) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    };

}

#endif //INC_21F_PA02_STV_AND_MILES_LIST_H
