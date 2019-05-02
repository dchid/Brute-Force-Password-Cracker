/*
 * This is David Chidester, Patrick Charlton, and Elijah Crockett's final project
 * for Analysis of Algorithms at Willamette University.
 * it is indended to be a rudimentary version of a password cracking tool such as
 * John the Ripper. It uses crunch as a dependancy and is intended primarily for
 * pedigogical purposes. If you need an actual tool for password cracking, use
 * John the Ripper instead.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"

using namespace std;

void bruteForce(string hash);
void wordList(string hash);
bool hashCompare(string plaintext, string hash);

int main(){
    cout << "Welcome to the C++ password cracker\n";
    cout << "please input the hashed password you'd like to crack\n";
    string inputHash;
    cin >> inputHash;
    cout << "you entered " + inputHash + "\n";
	cout << "Would you like to use a wordlist?\n(y/n)\n";
    
    char yesOrNo;
    
    bool inputInvalid = true;
    while (inputInvalid){
        cin >> yesOrNo;
        if (yesOrNo == 'y' || yesOrNo == 'Y'){
            cout << "Ok using wordlist\n";
            inputInvalid = false;
            wordList(inputHash);
        }
        else if (yesOrNo == 'n' || yesOrNo == 'N'){
            cout << "Ok brute forcing\n";
            inputInvalid = false;
            bruteForce(inputHash);
        }
        else cout << "Bad input: please type either 'y' or 'n'\n";
    }

	return 0;
}

//crack passwords using wordlist
void wordList(string hash){
    cout << "please enter your wordlist\n";
    string wordlist;
    cin >> wordlist;
    cout << "using " + wordlist + "\n";
    
    //reading in file
    std::ifstream file(wordlist);
    //testing if file opens
    if (!file){
        cout << "unable to open file\n";
        exit(1);
    }
    
        string plainText;
    // reading in wordlist line by line
    bool matchFound;
    while (std::getline(file, plainText) && matchFound == false){
        cout << plainText + "\n";
        matchFound = hashCompare(plainText, hash);
    }

    if (matchFound == true){
        cout << "The password is: ";
        cout << plainText + "\n";
    }
    else {
        cout << "not found\n";
    }
}

//brute force
void bruteForce(string hash){
    cout << "how long would you like your maximum string to be?\n";
    int maxLength;
    cin >> maxLength;
    //making a command to give to system
    string strcmd = "crunch 1 " + to_string(maxLength) + " -o output.txt";
    cout << "\ngenerating strings\n";
    const char *command = strcmd.c_str();
    system(command);

    //reading in file
    std::ifstream file("output.txt");
    //testing if file opens
    if (!file){
        cout << "unable to open file\n";
        exit(1);
    }

    string plainText;
    // reading in wordlist line by line
    bool matchFound;
    while (std::getline(file, plainText) && matchFound == false){
        cout << plainText + "\n";
        matchFound = hashCompare(plainText, hash);
    }

    if (matchFound == true){
        cout << "The password is: ";
        cout << plainText + "\n";
    }
    else{
        cout << "sorry, not match found\n";
    }
}

bool hashCompare(string plainText, string hash){

    //need to fix concurency issue with reading and writing
    string strcmd = "echo -n " + plainText + " | md5sum > hashedstr.txt";
    const char *command = strcmd.c_str();
    system(command);

    std::ifstream file("hashedstr.txt");

        // reading in wordlist line by line
    while (std::getline(file, plainText)){
        plainText = plainText.erase(33, 2);
        cout << plainText + "\n";
    }

    return !(plainText.compare(hash) == 0);
}
