#include <cmath>
#include <algorithm>

#include "HT.h"
using namespace std;

HT::HT()
{
    size = 0;
    capacity = 1000000;
    pairs = new string[capacity];
    times = new int[capacity]{0};
}

HT::~HT()
{
    delete[] pairs;
    delete[] times;
}

unsigned long long HT::hash1(const string &pair)
{
    int hash = 0;
    for (char c : pair)
        hash += (c << c);
    return hash;
}

unsigned long long HT::hash2(const string &pair)
{
    int hash = 0;
    for (int i = 0; i < pair.size(); i++)
        hash += (pair[i] << i);
    while (__gcd(hash, capacity) != 1)
        hash++;
    return hash;
}

void HT::insert(const string &pair)
{
    if (capacity == size)
        resize();
    unsigned long long h1 = hash1(pair);
    unsigned long long h2 = hash2(pair);
    unsigned long long index;
    unsigned long long i = 0;
    while (true)
    {
        index = (h1 + i * h2) % capacity;
        if (times[index] == 0)
        {
            pairs[index] = pair;
            times[index] = 1;
            size++;
            return;
        }
        if (pairs[index] == pair)
        {
            times[index]++;
            return;
        }
        i++;
    }
}

int HT::find(const string &pair)
{
    unsigned long long index;
    unsigned long long h1 = hash1(pair);
    unsigned long long h2 = hash2(pair);
    for (unsigned long long i = 0; i < capacity; i++)
    {
        index = (h1 + i * h2) % capacity;
        if (pairs[index] == pair)
        {
            return times[index];
        }
    }
    return 0;
}

void HT::resize()
{
    string *temp_pairs = new string[capacity * 2];
    int *temp_times = new int[capacity * 2]{0};
    for (int i = 0; i < capacity; i++)
    {
        if (times[i] != 0)
        {
            unsigned long long h1 = hash1(pairs[i]);
            unsigned long long h2 = hash2(pairs[i]);
            unsigned long long j = 0;
            unsigned long long index = (h1 + j * h2) % (capacity * 2);
            while (temp_times[index] != 0)
            {
                j++;
                index = (h1 + j * h2) % (capacity * 2);
            }
            temp_pairs[index] = pairs[i];
            temp_times[index] = times[i];
        }
    }
    delete[] pairs;
    delete[] times;
    pairs = temp_pairs;
    times = temp_times;
    capacity *= 2;
}