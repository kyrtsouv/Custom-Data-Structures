#include "UA.h"

UA::UA()
{
    max = 0;
    capacity = 1000000;
    pairs = new string[capacity];
    times = new int[capacity]{0};
}

UA::~UA()
{
    delete[] pairs;
    delete[] times;
}

int UA::linearSearch(const string &pair)
{
    for (int i = 0; i < max; i++)
        if (pairs[i] == pair)
            return i;
    return -1;
}

void UA::insert(const string &pair)
{
    int temp_pos = linearSearch(pair);
    if (temp_pos != -1)
    {
        times[temp_pos]++;
        return;
    }
    pairs[max] = pair;
    times[max++] = 1;
}

int UA::find(const string &pair)
{
    int temp_pos = linearSearch(pair);
    if (temp_pos == -1)
        return 0;
    return times[temp_pos];
}

void UA::resize()
{
    capacity *= 2;
    string *temp_pairs = new string[capacity];
    int *temp_times = new int[capacity];
    for (int i = 0; i < max; i++)
    {
        temp_pairs[i] = pairs[i];
        temp_times[i] = times[i];
    }
    delete[] pairs;
    delete[] times;
    pairs = temp_pairs;
    times = temp_times;
}