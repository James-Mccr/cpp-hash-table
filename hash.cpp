#include "hash.hpp"

int ModuloHash::compute(char* value)
{
    unsigned int sum{0};
    for (int i = 0; value[i]; i++)
        sum += value[i];
    return sum % Capacity;
}

ModuloHash::ModuloHash(int capacity)
{
    Capacity = capacity;
}