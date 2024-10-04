#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "hash-item.hpp"
#include "hash-table.hpp"
#include "hash.hpp"
#include "linked-list.hpp"

HashTable::HashTable()
{
    Items = (HashItem**) calloc(Capacity+1, sizeof(HashItem*));
    Size = Capacity;
    Count = 0;
    Hash = (IHash*) new ModuloHash(Capacity);
    Overflow = (LinkedList**) calloc(Capacity+1, sizeof(LinkedList*));
}

HashTable::~HashTable()
{
    for (int i = 0; i < Size; i++)
    {
        if (Items[i] != NULL)
            free(Items[i]);
        if (Overflow[i] != NULL)
            free(Overflow[i]);
    }
        
    free(Items);
    free(Hash);
    free(Overflow);
}

void HashTable::printTable()
{
    std::cout << "Printing hash table..." << std::endl;

    std::cout << "Count: " << Count << std::endl;
    std::cout << "Size: " << Size << std::endl;

    for (int i = 0; i < Size; i++)
    {
        if (Items[i] == NULL) continue;
        Items[i]->print();
        if (Overflow[i] == NULL) continue;
        Overflow[i]->print();
    }
}

void HashTable::handleCollision(int index, HashItem* item)
{
    if (Overflow[index] == NULL)
        Overflow[index] = new LinkedList(item);
    else
        Overflow[index]->insert(item);
}

void HashTable::insert(char* key, char* value)
{
    int index = Hash->compute(key);
    if (Items[index] == NULL)
    {
        HashItem* item = new HashItem(key, value);
        if (Count == Size)
        {
            std::cout << "Hash table is full! Cannot insert item." << std::endl;
            free(item);
            return;
        }

        std::cout << index << std::endl;
        Items[index] = item;
        Count++;
        return;
    }

    if (strcmp(Items[index]->Key, key) == 0)
        strcpy(Items[index]->Value, value);
    else
        handleCollision(index, new HashItem(key, value));
}

char* HashTable::search(char* key)
{
    int index = Hash->compute(key);
    if (Items[index] != NULL)
    {
        if (strcmp(key, Items[index]->Key) == 0)
            return Items[index]->Value;
        LinkedList* list = Overflow[index]->search(key);
        return list != NULL ? list->Item->Value : NULL;
    }
    return NULL;
}