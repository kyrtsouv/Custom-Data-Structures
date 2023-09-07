#include "AVL.h"

AVL::AVL() { root = NULL; }

AVL::~AVL()
{
    delete root;
}

void AVL::fixHeight(SubAVL *root)
{
    if (root->left != NULL)
        fixHeight(root->left);
    if (root->right != NULL)
        fixHeight(root->right);
    root->height = max((root->left != NULL) ? root->left->height : -1, (root->right != NULL) ? root->right->height : -1) + 1;
}

void AVL::insert(const string &pair)
{
    this->root = this->insert(this->root, pair);
}

SubAVL *AVL::insert(SubAVL *root, const string &pair)
{
    if (root == NULL)
    {
        return new SubAVL(pair);
    }
    if (pair == root->pair)
    {
        root->times++;
        return root;
    }
    if (pair < root->pair)
    {
        root->left = insert(root->left, pair);
    }
    if (pair > root->pair)
    {
        root->right = insert(root->right, pair);
    }

    root->height = max((root->left != NULL) ? root->left->height : -1, (root->right != NULL) ? root->right->height : -1) + 1;
    if (root->left != NULL && root->right != NULL)
    {
        if (root->left->height > root->right->height + 1)
        {
            if (root->left->left != NULL && root->left->right != NULL)
            {
                if (root->left->left->height > root->left->right->height) // Απλή δεξιά περιστροφή.
                {
                    SubAVL *temp_node = root->left->right;
                    root->left->right = root;
                    root = root->left;
                    root->right->left = temp_node;
                }
                else // Διπλή LR περιστροφή.
                {
                    SubAVL *temp_node = root->left->right->left;
                    root->left->right->left = root->left;
                    root->left = root->left->right;
                    root->left->left->right = temp_node;

                    temp_node = root->left->right;
                    root->left->right = root;
                    root = root->left;
                    root->right->left = temp_node;
                }
                fixHeight(root);
            }
        }
        if (root->right->height > root->left->height + 1)
        {
            if (root->right->left != NULL && root->right->right != NULL)
            {
                if (root->right->right->height > root->right->left->height) // Απλή αριστερή περιστροφή.
                {
                    SubAVL *temp_node = root->right->left;
                    root->right->left = root;
                    root = root->right;
                    root->left->right = temp_node;
                }
                else // Διπλή RL περιστροφή.
                {
                    SubAVL *temp_node = root->right->left->right;
                    root->right->left->right = root->right;
                    root->right = root->right->left;
                    root->right->right->left = temp_node;

                    temp_node = root->right->left;
                    root->right->left = root;
                    root = root->right;
                    root->left->right = temp_node;
                }
                fixHeight(root);
            }
        }
    }

    return root;
}

int AVL::find(const string &pair)
{
    SubAVL *current_node = root;
    while (current_node != NULL)
    {
        if (pair == current_node->pair)
            return current_node->times;
        if (pair < current_node->pair)
            current_node = current_node->left;
        else
            current_node = current_node->right;
    }
    return 0;
}
