#include <cstdlib>
#include <cstring>
#include <iostream>
#include "hash-item.hpp"

HashItem::HashItem(char* key, char* value)
{
    Key = (char*) malloc(strlen(key)+1);
    Value = (char*) malloc(strlen(value)+1);
    strcpy(Key, key);
    strcpy(Value, value);
}

HashItem::~HashItem()
{
    free(Key);
    free(Value);
}

void HashItem::print()
{
    std::cout << "Key: " << Key << std::endl;
    std::cout << "Value: " << Value << std::endl;
}