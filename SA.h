#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <string>
#include "Structure.h"

using namespace std;

class SA : public Structure
{
public:
    SA(); // Αρχικοποιεί τον Ταξινομημένο Πίνακα.
    ~SA();
    void insert(const string &pair); // Χρησιμοποιεί την μέθοδο binarySearch για να βρει την θέση του ζεύγους. Αν το εντοπίσει αυξάνει το πλήθος εμφανίσεων του αλλιώς το εισάγει στην θέση που του αντιστοιχεί και μετακινεί όλα τα υπόλοιπα ζεύγη μια θέση δεξιά.
    int find(const string &pair);    // Χρησιμοποιεί την μέθοδο binarySearch για να βρει την θέση του ζεύγους. Αν το βρει επιστρέφει το πλήθος εμφανίσεων του αλλιώς επιστρέφει 0.
    string name() { return "Sorted Array"; };

private:
    string *pairs;                        // Κρατάει τα ζεύγη.
    int *times;                           // Κρατάει το πλήθος εμφανίσεων των ζευγών.
    int max;                              // Το τρέχων χρησιμοποιούμενο μέγεθος του πίνακα.
    int capacity;                         // Το μέγεθος του πίνακα.
    int binarySearch(const string &pair); // Ψάχνει το ζεύγος στον πίνακα με δυαδική αναζήτηση.
    void resize();                        // Διπλασιάζει το μέγεθος του πίνακα.
};

#endif