#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

class Structure // Η κλάση Structure είναι η βάση για τις κλάσεις BST, AVL, HT, SA και UA και περιέχει τις κοινές τους μεθόδους.
{
public:
    virtual void insert(const string &pair){};                            // Εισάγει ένα ζεύγος στην δομή.
    virtual int find(const string &pair){};                               // Επιστρέφει πόσες φορές έχει εμφανιστεί το ζεύγος στο αρχείο εισόδου.
    virtual string name(){};                                              // Επιστρέφει το όνομα της δομής.
    Structure build(fstream &input_file, int pairs, fstream &output_file) // Εισάγει όλα τα ζεύγη από το ενδιάμεσο αρχείο στην δομή και εκτυπώνει στο αρχείο εξόδου τον συνολικό χρόνο κατασκευής.
    {
        input_file.clear();
        input_file.seekg(ios::beg);
        string pair;
        clock_t start = clock();
        for (int i = 0; i < pairs; i++)
        {
            getline(input_file, pair);
            insert(pair);
        }
        output_file << "Η δομή: " + name() + " κατασκευάστηκε σε: " << (float)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    };
    void search(string random_pairs[], fstream &output_file, int RANDOMS) // Αναζητά 1000 ζεύγη στην δομή και εμφανίζει το χρόνο που χρειάστηκε για να τα βρει.
    {
        clock_t start = clock();
        for (int i = 0; i < RANDOMS; i++)
            output_file << left << setw(30) << random_pairs[i] << " | " << find(random_pairs[i]) << endl;
        output_file << "Συνολικός χρόνος αναζήτησης στην " + name() + ":" << (float)(clock() - start) / CLOCKS_PER_SEC << " s" << endl;
    };
};

#endif