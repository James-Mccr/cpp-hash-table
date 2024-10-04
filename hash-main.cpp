#include <iostream>
#include <cstdlib>
#include "hash-table.hpp"

int main(void)
{
    HashTable* table = new HashTable();

    table->printTable();

    char key[] = {'h','e','l','l','o', 0};
    char value[] = {'w','o','r','l','d',0};
    table->insert(key, value);

    table->printTable();

    char key2[] = {'e','h','l','l','o', 0};
    char value2[] = {'o','w','r','l','d',0};
    table->insert(key2, value2);

    table->printTable();

    std::cout << table->search(key2) << std::endl;

    free(table);
    return 0;
}