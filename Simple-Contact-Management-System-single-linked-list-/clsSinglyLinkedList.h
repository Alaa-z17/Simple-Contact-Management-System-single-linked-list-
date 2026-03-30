#pragma once
#include <iostream>
#include <stdexcept>
#include "clsNode.h"

using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* _head; 
    int _size;

public:
    SinglyLinkedList() : _head(nullptr), _size(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    // ------------------ Add operations ------------------
    void addFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = _head;
        _head = newNode;
        ++_size;
    }

    void addBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!_head) {
            _head = newNode;
        }
        else {
            Node<T>* temp = _head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        ++_size;
    }

    // ------------------ Update operation ------------------
    bool update(const T& oldValue, const T& newValue) {
        Node<T>* current = _head;
        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // ------------------ Find operation ------------------
    bool IsFound(const T& value) const {
        Node<T>* current = _head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }
    // ------------------ Find operation ------------------
    Node<T>* Find(const T& value) const {
        Node<T>* current = _head;
        while (current) {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }


    // ------------------ Delete operations ------------------
    void deleteFirst() {
        if (!_head)
            throw out_of_range("List is empty");
        Node<T>* temp = _head;
        _head = _head->next;
        delete temp;
        --_size;
    }

    void deleteLast() {
        if (!_head)
            throw out_of_range("List is empty");

        if (!_head->next) {
            delete _head;
            _head = nullptr;
        }
        else {
            Node<T>* current = _head;
            while (current->next->next)
                current = current->next;
            delete current->next;
            current->next = nullptr;
        }
        --_size;
    }

    bool deleteByValue(const T& value) {
        if (!_head) return false;

        if (_head->data == value) {
            deleteFirst();
            return true;
        }

        Node<T>* current = _head;
        while (current->next) {
            if (current->next->data == value) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                --_size;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // ------------------ Utility operations ------------------
    void display() const {
        Node<T>* current = _head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    int size() const { return _size; }

    bool isEmpty() const { return _head == nullptr; }

    void clear() {
        while (_head) {
            Node<T>* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size = 0;
    }
};