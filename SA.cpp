#include "SA.h"

SA::SA()
{
    max = 0;
    capacity = 1000000;
    pairs = new string[capacity];
    times = new int[capacity];
}

SA::~SA()
{
    delete[] pairs;
    delete[] times;
}

int SA::binarySearch(const string &pair)
{
    int beg = 0, end = max, mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (pairs[mid] == pair)
            return mid;
        if (pairs[mid] > pair)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return mid;
}

void SA::insert(const string &pair)
{
    int temp_pos = binarySearch(pair);
    if (pairs[temp_pos] == pair)
    {
        times[temp_pos]++;
        return;
    }
    if (pairs[temp_pos].empty())
    {
        pairs[temp_pos] = pair;
        times[temp_pos] = 1;
        max++;
        return;
    }
    if (pairs[temp_pos] < pair)
        temp_pos++;
    for (int i = max; i > temp_pos; i--)
    {
        pairs[i] = pairs[i - 1];
        times[i] = times[i - 1];
    }
    pairs[temp_pos] = pair;
    times[temp_pos] = 1;
    max++;

    if (capacity == max)
        resize();
}

int SA::find(const string &pair)
{
    int temp_pos = binarySearch(pair);
    if (pairs[temp_pos] != pair)
        return 0;
    return times[temp_pos];
}

void SA::resize()
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