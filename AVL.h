#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include "Structure.h"

using namespace std;

class SubAVL;

class AVL : public Structure
{
public:
    AVL(); // Αρχικοποιεί το δένδρο.
    ~AVL();
    void insert(const string &pair); // Εισάγει ένα ζεύγος στο δένδρο καλώντας την private insert μέθοδο.
    int find(const string &pair);    // Ψάχνει στο κατάλληλο υποδένδρο το ζεύγος και επιστρέφει το πλήθος εμφανίσεων του.
    string name() { return "AVL Tree"; };

private:
    SubAVL *root;                                     // Δείκτης στο υποδένδρο.
    SubAVL *insert(SubAVL *root, const string &pair); // Χρησιμοποιείται για την εισαγωγή ενός ζεύγους στο δένδρο χωρίς να κάνουμε public την ρίζα.  Ψάχνει τον κατάλληλο κόμβο για να εισάγει το ζεύγος ή να αυξήσει το πλήθος εμφανίσεων. Επιδιορθώνει προσωρινά το ύψος του υποδένδρου, κάνει τις απαραίτητες περιστροφές και επιδιορθώνει μόνιμα το ύψος του υποδένδρου.
    void fixHeight(SubAVL *root);                     // Επιδιορθώνει το ύψος του υποδένδρου.
};

class SubAVL
{
private:
    string pair;          // Κρατάει το ζεύγος.
    int times;            // Κρατάει τις εμφανίσεις του ζεύγους.
    SubAVL *left, *right; // Δείκτες στο αριστερό και το δεξί υποδένδρο.
    int height;           // Κρατάει το ύψος του υποδένδρου.
    SubAVL(string pair)   // Κατασκευαστής για το υποδένδρο.
    {
        this->pair = pair;
        height = 0;
        times = 2;
        left = right = NULL;
    }
    ~SubAVL()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }
    friend class AVL;
};

#endif