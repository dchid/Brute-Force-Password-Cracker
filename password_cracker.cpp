/*
 * This is David Chidester, Patrick Charleton, and Elijah Crockett's final project
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

void bruteForce();
void wordList();
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
            wordList();
        }
        else if (yesOrNo == 'n' || yesOrNo == 'N'){
            cout << "Ok brute forcing\n";
            inputInvalid = false;
            bruteForce();
        }
        else cout << "Bad input: please type either 'y' or 'n'\n";
    }

	return 0;
}

//crack passwords using wordlist
void wordList(){
    cout << "please enter your wordlist\n";
    string wordlist;
    cin >> wordlist;
    cout << "using " + wordlist + "\n";
    
    string plainText;
    //testing that file is read in
    std::ifstream file(wordlist);
    if (!file){ //testing if file opens
        cout << "unable to open file\n";
        exit(1);
    }
    
    bool matchfound = hashCompare("ponies", "47346fc7580de7596d7df8d115a3545d");
    if (matchfound == true){
        cout << "The password is \n";
    }
    else {
        cout << "not found\n";
    }
 //   while (std::getline(file, s)){

}

//brute force
void bruteForce(){
    cout << "how long would you like your maximum string to be?\n";
    int maxLength;
    cin >> maxLength;
    //making a command to give to system
    string strcmd = "crunch 1 " + to_string(maxLength) + " -o output.txt";
    cout << "\ngenerating strings\n";
    const char *command = strcmd.c_str();
    system(command);
    wordList();
}

bool hashCompare(string plaintext, string hash){
    
    string strcmd = "echo -n " + plaintext + " | md5sum > hashedstr.txt";
    const char *command = strcmd.c_str();
    system(command);

    string hashedString = md5(plaintext);

    std:cout << hashedString + "\n" + hash;

    return plaintext.compare(hash) == 0;
}
