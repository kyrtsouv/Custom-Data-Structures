#include <fstream>
#include <string>
#include <ctime>
#include <random>

#include "BST.h"
#include "AVL.h"
#include "HT.h"
#include "SA.h"
#include "UA.h"
#include "Structure.h"

using namespace std;

#define RANDOMS 1000

void process(string &word);
void preprocess(int &pairs, ifstream &input, fstream &temp_file);
void getRandoms(string random_pairs[], const int &pairs, fstream &temp_file);

int main(int argc, char *argv[])
{
    //--------------1)Ανοίγουμε τα αρχεία εισόδου και εξόδου κι ελέγχουμε αν το αρχείο εισόδου άνοιξε σωστά.--------------//
    fstream output_file("output.txt", ios::out);
    ifstream input_file("small-file.txt");
    if (!input_file)
    {
        output_file << "File not opened";
        return 1;
    }

    //--------------2)Ανοίγουμε τα ενδιάμεσα αρχεία και αποθηκεύουμε στο temp_file τα ζεύγη των κατάλληλα επεξεργασμένων λέξεων.--------------//
    int pairs = 0;

    fstream search_file("search.txt", ios::out);
    fstream temp_file("tempfile.txt", ios::out);
    preprocess(pairs, input_file, temp_file);
    temp_file.close();
    input_file.close();

    //--------------3)Κρατάμε σε έναν πίνακα από string 1000 ζευγάρια που πήραμε με τυχαίο τρόπο από το temp_file.--------------//
    temp_file.open("tempfile.txt", ios::in);
    string random_pairs[RANDOMS];
    getRandoms(random_pairs, pairs, temp_file);

    //--------------4)Κατασκευάζουμε τις δομές, εισάγουμε όλα τα ζεύγη από το ενδιάμεσο αρχείο, ψάχνουμε τα 1000 ζεύγη από το στάδιο 3 και εκτυπώνουμε στο search_file πόσες φορές υπάρχουν και τον συνολικό χρόνο αναζήτησης.--------------//

    HT *ht = new HT();
    ht->build(temp_file, pairs, output_file);
    ht->search(random_pairs, search_file, RANDOMS);
    delete ht;

    BST *bst = new BST();
    bst->build(temp_file, pairs, output_file);
    bst->search(random_pairs, search_file, RANDOMS);
    delete bst;

    AVL *avl = new AVL();
    avl->build(temp_file, pairs, output_file);
    avl->search(random_pairs, search_file, RANDOMS);
    delete avl;

    UA *ua = new UA();
    ua->build(temp_file, pairs, output_file);
    ua->search(random_pairs, search_file, RANDOMS);
    delete ua;

    SA *sa = new SA();
    sa->build(temp_file, pairs, output_file);
    sa->search(random_pairs, search_file, RANDOMS);
    delete sa;

    search_file.close();

    //--------------5)Περνάμε τα στοιχεία αναζήτησης από το search_file στο τελικό αρχείο εξόδου.--------------//
    search_file.open("search.txt", ios::in);
    output_file << endl;
    while (!search_file.eof())
    {
        string word;
        getline(search_file, word);
        output_file << word << endl;
    }
    //--------------6)Κλείνουμε το temp_file και το search_file και τα σβήνουμε από τον δίσκο.--------------//
    search_file.close();
    remove("search.txt");
    temp_file.close();
    remove("tempfile.txt");
    output_file.close();

    return 0;
}

void process(string &word) // Αφαιρεί τα σημεία στίξης και αντικαθιστά τα κεφαλαία γράμματα με τα αντίστοιχα μικρά σε μια λέξη.
{
    string processed = "\0";
    for (int i = 0; i < word.length(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            processed.append(1, word[i] + 'a' - 'A');
        else if (word[i] >= 'a' && word[i] <= 'z')
            processed.append(1, word[i]);
    word = processed;
}

void preprocess(int &pairs, ifstream &input_file, fstream &temp_file) // Διαβάζει με τη σειρά τις λέξεις από το αρχείο εισόδου, αποθηκεύει τα ζεύγη των κατάλληλα επεξεργασμένων λέξεων στο ενδιάμεσο αρχείο και μετράει πόσα είναι.
{
    string word[2];
    do
    {
        input_file >> word[0];
        process(word[0]);
    } while (!input_file.eof() && word[0].empty());
    do
    {
        input_file >> word[1];
        process(word[1]);
    } while (!input_file.eof() && word[1].empty());
    do
    {
        temp_file << word[0] + " " + word[1] << "\n";
        pairs++;
        word[0] = word[1];
        do
        {
            input_file >> word[1];
            process(word[1]);
        } while (!input_file.eof() && word[1].empty());
    } while (!input_file.eof());
}

void getRandoms(string random_pairs[], const int &pairs, fstream &temp_file) // Επαναλαμβάνει 1000 φορές: προσπερνάει τυχαίο αριθμό γραμμών στο ενδιάμεσο αρχείο και αποθηκεύει το ζεύγος που βρίσκεται σε αυτήν τη γραμμή στον πίνακα random_pairs.
{
    int line;
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> distribution(0, pairs);
    for (int i = 0; i < RANDOMS; i++)
    {
        temp_file.clear();
        temp_file.seekg(ios::beg);
        for (int j = 0; j < (distribution(generator)); j++)
            getline(temp_file, random_pairs[i]);
    }
}
