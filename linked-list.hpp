#pragma once

#include "hash-item.hpp"

class LinkedList
{
    public:
    HashItem* Item;
    LinkedList* Next;

    LinkedList(HashItem* item);
    ~LinkedList();

    void print();
    LinkedList* insert(HashItem* item);
    LinkedList* search(char* key);
};