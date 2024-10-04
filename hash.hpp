#pragma once

class IHash
{
    public:
    virtual int compute(char* value) = 0;
};

class ModuloHash : IHash
{
    private:
    int Capacity;

    public:
    ModuloHash(int capacity);
    int compute(char* value) override;
};