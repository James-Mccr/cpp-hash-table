#include <cstdlib>
#include <cstring>
#include "hash-item.hpp"
#include "linked-list.hpp"

LinkedList::LinkedList(HashItem* item)
{
    Item = item;
    Next = NULL;
}

LinkedList::~LinkedList()
{
    if (Item != NULL) delete Item;
    if (Next != NULL) delete Next;
}

LinkedList* LinkedList::insert(HashItem* item)
{
    LinkedList* found = search(item->Key);
    if (found == NULL)
    {
        LinkedList* list = new LinkedList(item);
        Next = list;
        return list;
    }
    return found;
}

LinkedList* LinkedList::search(char* key)
{
    if (strcmp(key, Item->Key) == 0)
        return this;
    if (Next != NULL)
        return Next->search(key);
    return NULL;
}

void LinkedList::print()
{
    if (Item != NULL)
        Item->print();
    if (Next != NULL)
        Next->print();
}