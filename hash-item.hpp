#pragma once

class HashItem
{
    public:
    char* Key;
    char* Value;

    HashItem(char* key, char* value);
    ~HashItem();

    void print();
};