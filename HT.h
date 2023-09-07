#ifndef HT_H
#define HT_H

#include <string>
#include "Structure.h"

using namespace std;

class HT : public Structure
{
public:
    HT(); // Αρχικοποιεί τον πίνακα κατακερματισμού και μηδενίζει τον πίνακα των εμφανίσεων.
    ~HT();
    void insert(const string &pair); // Αφού ο πίνακας έχει πάντα ελεύθερο χώρο, ψάχνει με τις συναρτήσεις κατακερματισμού μέχρι να βρει την θέση του ζεύγους, οπότε και αυξάνει το πλήθος εμφανίσεων, ή μέχρι να βρει μια άδεια θέση.
    int find(const string &pair);    // Ψάχνει στον πίνακα μέχρι να τον ελέγξει όλο ή να βρει το ζεύγος οπότε και επιστρέφει τον αριθμό εμφανίσεων.
    string name() { return "Hash Table"; };

private:
    unsigned long long hash1(const string &pair); // Η συνάρτηση κατακερματισμού που χρησιμοποιείται για τον υπολογισμό του hash value.
    unsigned long long hash2(const string &pair); // Η συνάρτηση κατακερματισμού που χρησιμοποιείται για το offseting.
    string *pairs;                                // Κρατάει τα ζεύγη.
    int *times;                                   // Κρατάει το πλήθος εμφανίσεων των ζευγών.
    int size;                                     // Ο αριθμός των ζευγών.
    int capacity;                                 // Το μέγεθος του πίνακα.
    void resize();                                // Διπλασιάζει το μέγεθος του πίνακα κατακερματισμού.
};

#endif