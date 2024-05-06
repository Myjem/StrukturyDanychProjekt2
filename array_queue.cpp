#include "array_queue.h"
#include "queue_node.h"

using namespace std;

array_queue::array_queue(){}

void array_queue::insert(int v, int p)
{
    node newnode = {v , p};
    ArrayQueue.push_back(newnode);
}
node array_queue::extract_max()
{
    if(isEmpty())
    {
        cout << "kolejka jest pusta" << endl;
        return {-1 ,-1};
    }
    node max = ArrayQueue.get(0);
    int max_index = 0;
    for(int i  = 0; i < ArrayQueue.get_size(); i++)
    {
        if(ArrayQueue.get(i).priority > max.priority)
        {
            max = ArrayQueue.get(i);
            max_index = i;
        }
    }
    ArrayQueue.del(max_index);
    return max;
}
node array_queue::find_max()
{
    if(isEmpty())
    {
        cout << "kolejka jest pusta";
        return {-1 ,-1};
    }
    node max = ArrayQueue.get(0);
    for(int i  = 0; i < ArrayQueue.get_size(); i++)
    {
        if(ArrayQueue.get(i).priority > max.priority)
        {
            max = ArrayQueue.get(i);
        }
    }
    return max;
}

void array_queue::modify_key(node e,int p)
{
    int index = ArrayQueue.search(e);
    ArrayQueue.set(index, {e.value, p});
}
int array_queue::get_size()
{
    return ArrayQueue.get_size();
}
bool array_queue::isEmpty()
{
    if(ArrayQueue.get_size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void array_queue::print() 
{
    if (isEmpty()) 
    {
        cout << "Kolejka jest pusta" << endl;
        return;
    }
    for(int i = 0; i < ArrayQueue.get_size(); i++)
    {
        cout << "Wartosc: " << ArrayQueue.get(i).value << " Priorytet: " << ArrayQueue.get(i).priority << endl;
    }
}

array_queue::~array_queue() {}