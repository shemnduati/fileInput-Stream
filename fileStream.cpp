

// include header files
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// set namespace
using namespace std;


/// -------------------------------------------------------------------------
/// Main entry-point for this application
///
/// @returns Exit-code for the process - 0 for success, else an error code.
/// -------------------------------------------------------------------------
int main() {
    // Constant definition(s)
    int COLW = 19;                  // column width for output

    // Variable declarations(s)
    int exitState;                  // tracks the exit code for the process
    exitState = EXIT_SUCCESS;

    string inFile;                  // user supplied file name for open
    int aVowel = 0;                 // char count for a
    int eVowel = 0;                 // char count for e
    int iVowel = 0;                 // char count for i
    int oVowel = 0;                 // char count for o
    int uVowel = 0;                 // char count for u
    int vowelCount = 0;             // total vowelCount
    int charCount = 0;              // number of characters read
    double ratio = 0;               // percentage of vowels to characters

    char ch;                        // holds char read from file

    ifstream fin;                   // file stream input object

    /* ******* Input Phase *********************************************** */
    cout << "Enter file name for vowel count: ";
    cin >> inFile;

    /* ******* Processing Phase ****************************************** */
    // open file for read
    fin.open(inFile);

    // if the file can be opened for read, process the file
    if (fin.is_open()) {
        // count the number of non-whitespace characters
        while (fin >> ch) {
            ++charCount;                // update total character count
            switch (tolower(ch)) {
                case 'a':               // update vowel a count
                    ++aVowel;
                    break;
                case 'e':               // update vowel e count
                    ++eVowel;
                    break;
                case 'i':               // update vowel i count
                    ++iVowel;
                    break;
                case 'o':               // update vowel o count
                    ++oVowel;
                    break;
                case 'u':               // update vowel u count
                    ++uVowel;
                    break;
                default:
                    break;
            }
        }
        // calculate total number of vowels
        vowelCount = aVowel + eVowel + iVowel + oVowel + uVowel;

        // calculate percentage of vowels to characters
        // if there are no characters, there isn't a ratio 0
        if (charCount > 0) {
            ratio = (static_cast<double>(vowelCount)/charCount) * 100;
        }

        // close the input file
        fin.close();
    } else {
        exitState = EXIT_FAILURE;
    }

    /* ******* Output Phase ********************************************** */
    if (exitState == EXIT_FAILURE) {
        // there was no file
        cout << "Unable to Read File, exiting...\n" << endl;
    } else if (charCount < 1) {
        // no non-whitespace characters
        cout << "There were only whitespace characters in the file...\n"
             << endl;

        // set the exit state for no non-whitespace characters
        exitState = 2;
    } else if (vowelCount < 1) {
        // no vowels in file
        cout << "No vowels found...\n" << endl;

        // set the exit state for missing vowels
        exitState = 3;
    } else {
        // success! output findings!
        cout << "Total non-whitespace characters read: " << charCount
             << endl << endl;
        cout << "Total vowels read: " << vowelCount << endl
             << setw(COLW) << "'a' or 'A': " << aVowel << endl
             << setw(COLW) << "'e' or 'E': " << eVowel << endl
             << setw(COLW) << "'i' or 'I': " << iVowel << endl
             << setw(COLW) << "'o' or 'O': " << oVowel << endl
             << setw(COLW) << "'u' or 'U': " << uVowel << endl;

        cout << "\nOf all the non-whitespace characters read "
        << fixed << setprecision(2)
        << ratio << "% were vowels.\n" << endl;
    }

    return exitState;
}


