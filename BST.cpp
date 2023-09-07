#include "BST.h"

BST::BST()
{
    isEmpty = true;
    pair = "";
    left = right = NULL;
}

BST::~BST()
{
    if (left != NULL)
        delete left;
    if (right != NULL)
        delete right;
}

void BST::insert(const string &pair)
{

    if (isEmpty)
    {
        this->pair = pair;
        isEmpty = false;
        times = 1;
        return;
    }
    if (pair == this->pair)
    {
        times++;
        return;
    }
    if (pair < this->pair)
    {
        if (left == NULL)
            left = new BST();
        left->insert(pair);
    }
    else
    {
        if (right == NULL)
            right = new BST();
        right->insert(pair);
    }
}

int BST::find(const string &pair)
{
    if (isEmpty)
        return 0;
    if (this->pair == pair)
        return this->times;
    if (pair < this->pair)
    {
        if (left == NULL)
            return 0;
        return left->find(pair);
    }
    else
    {
        if (right == NULL)
            return 0;
        return right->find(pair);
    }
}