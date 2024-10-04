#pragma once

#include "hash-item.hpp"
#include "hash.hpp"
#include "linked-list.hpp"

class HashTable
{
    public:
    const int Capacity {500};

    HashItem** Items;
    int Size;
    int Count;
    IHash* Hash;
    LinkedList** Overflow;

    HashTable();
    ~HashTable();

    void printTable();
    void insert(char* key, char* value);
    char* search(char* key);
    void handleCollision(int index, HashItem* item);
};