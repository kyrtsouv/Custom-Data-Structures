#ifndef UNSORTEDARRAY_H
#define UNSORTEDARRAY_H

#include <string>
#include "Structure.h"

using namespace std;

class UA : public Structure
{
public:
    UA(); // Αρχικοποιεί τον Αταξινόμητο Πίνακα.
    ~UA();
    void insert(const string &pair); // Χρησιμοποιεί την μέθοδο linearSearch για να βρει την θέση του ζεύγους. Αν η θέση είναι -1 το εισάγει στο τέλος αλλιώς αυξάνει το πλήθος εμφανίεσεων στην θέση που βρήκε.
    int find(const string &pair);    // Χρησιμοποιεί την μέθοδο linearSearch  για να βρει την θέση του ζεύγους. Αν η θέση είναι -1 το ζεύγος δεν υπάρχει και επιστρέφει 0 αλλιώς επιστρέφει τον αριθμό των εμφανίσεων.
    string name() { return "Unsorted Array"; };

private:
    string *pairs;                        // Κρατάει τα ζεύγη.
    int *times;                           // Κρατάει το πλήθος εμφανίσεων των ζευγών.
    int max;                              // Το τρέχων χρησιμοποιούμενο μέγεθος του πίνακα.
    int capacity;                         // Το μέγεθος του πίνακα.
    int linearSearch(const string &pair); // Ψάχνει το ζεύγος στον πίνακα με σειριακή αναζήτηση.
    void resize();                        // Διπλασιάζει το μέγεθος του πίνακα.
};

#endif