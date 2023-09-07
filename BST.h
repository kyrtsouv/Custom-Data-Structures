#ifndef BST_H
#define BST_H

#include <string>
#include "Structure.h"

using namespace std;

class BST : public Structure
{
public:
    BST(); // Αρχικοποιεί ένα άδειο δένδρο.
    ~BST();
    void insert(const string &pair); // Ψάχνει τον κατάλληλο κόμβο για να εισάγει το ζεύγος ή να αυξήσει το πλήθος εμφανίσεων.
    int find(const string &pair);    // Ψάχνει στο κατάλληλο υποδένδρο το ζεύγος και επιστρέφει το πλήθος εμφανίσεων.
    string name() { return "Binary Search Tree"; };

private:
    string pair;       // Κρατάει το ζεύγος.
    int times;         // Κρατάει το πλήθος εμφανίσεων.
    bool isEmpty;      // Χρησιμοποιείται για να ξέρουμε αν το υποδένδρο είναι κενό.
    BST *left, *right; // Δείκτες στο αριστερό και το δεξί υποδένδρο.
};

#endif